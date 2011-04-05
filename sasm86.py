#!/usr/bin/env python
##################################################
# SASM86 POC (Proof-of-Concept)
# Jordan Jueckstock
#------------------------------
# Does exactly the same thing as Georg Zimmer's
# original "ASM86" (or Mini-ASM), but uses NASM
# as a back-end assembler, thereby skipping all
# the cyclical address-resolution nonsense needed
# when using DEBUG as a back-end...
#
# SASM86 itself does a bare-minimum of parsing on
# the ASM file, passing everything but SETREG and
# ORG directives on into NASM (see the "Converter"
# class comments for details).  After NASM is
# done, SASM86 uses the information it initially
# gathered from the source file PLUS the wonderful
# map file that NASM generates to resolve any
# addresses (for SETREG) and to package up the
# data/machine code into a valid Sim86 OBJ.
#
# Not bad for a Saturday's worth of work!
##################################################


##################################################
# System/Library Module Imports
##################################################

import sys, subprocess
import os, shutil, os.path as path
import struct, shlex


##################################################
# Global Constants
##################################################

# SASM86 banner text; displayed on assembly...
SASM86_BANNER = "SASM86: A NASM-Powered Mini-Assembler for CpS 310\n"

# The "base name" for all temp files
FILE_BASE = 'temp.sasm86'

# The extent for ASSEMBLY output file
ASM_FILE = FILE_BASE + '.asm'

# The extent for BINARY output file
BIN_FILE = FILE_BASE + '.bin'

# For LIST file (if used)
LIST_FILE = FILE_BASE + '.lst'

# For MAP file
MAP_FILE = FILE_BASE + '.map'

# For translated errors
ERROR_FILE = FILE_BASE + '.err'

# Full path to NASM executable
NASM_PATH = ('nasm', 'nasm.exe')[os.name == 'nt']  # Use '.exe' if on win32

# Command-line options
NASM_OPTION_TEMPLATE = '-f bin -o %s %s -l %s -%c %s'

# Function to get full command-line text
def NASM_COMMAND(useOldFlags=False):
  flagChar = ('Z', 'E')[useOldFlags]  # If running on 0.9x, use '-E' instead of '-Z'
  return NASM_OPTION_TEMPLATE % (BIN_FILE, ASM_FILE, LIST_FILE, flagChar, ERROR_FILE)

# MAP-file region header strings
MAP_SUMMARY_REGION = '-- Sections (summary)'
MAP_SYMBOLS_REGION = '-- Symbols'
MAP_SECTION_REGION = '---- Section %s'

# Order of registers in the header
REGISTER_ORDER = ['AX', 'BX', 'CX', 'DX', 'SP', 'BP',
                  'SI', 'DI', 'CS', 'DS', 'SS', 'ES',
                  'IP', 'FLAGS']

# Default value for unspecified registers
REGISTER_DEFAULT = 0x0000

# Register-name -> segment number mapping
SEG_REG_MAPPING = {'CS': 0, 'DS': 1, 'SS': 2, 'ES': 3}


##################################################
# Utilities
##################################################

def parseNum(string):
    '''General-purpose string->number parser.
        
    Recognizes the following pre/suffixes:
        * 0x??? or $??? or ???h -> hex
        * ???o or ???q -> octal
        * ???b -> binary
        * else -> decimal or ERROR
    (All suffix letters are case-insensitive.)
    [Meant for use parsing SETREG directives.]
    '''
    up = string.upper()
    base = 10
    if up.startswith('0X'):
        base = 16
        up = up[2:]
    elif up.startswith('$'):
        base = 16
        up = up[1:]
    elif up.endswith('H'):
        base = 16
        up = up[:-1]
    elif up.endswith('O') or up.endswith('Q'):
        base = 8
        up = up[:-1]
    elif up.endswith('B'):
        base = 2
        up = up[:-1]

    # TRY to convert--on failure, simply return the original string
    try:
        retVal = int(up, base)
    except ValueError:
        retVal = string

    # If the value doesn't fit in 16-bits, ERROR!
    if (type(retVal) is not str) and ((retVal & 0xFFFF) != retVal):
        raise ValueError("'%s' doesn't fit in 16-bits!" % string)
        
    return retVal       

def usingOldNASM():
    '''Run NASM with the "-v" flag and sniff its version.
    
        If the resulting version starts with 0, use the '-E'
    flag for redirecting the error log; use '-Z' otherwise...
      
    Returns TRUE if NASM is version 0.x; FALSE otherwise...
    '''
    pipe = os.popen('%s -v' % NASM_PATH)
    version = pipe.readline().split()[2][0]  # First char of 3rd word
    pipe.close()
    return (False, True)[version == '0']

def runNASM(usingOldNasm=False):
    '''Trigger NASM to crunch a temporary ASM file.

    Generate output to the given bin/map/list files.
    Returns NASM exit code (should be 0).
    '''
    return subprocess.call([NASM_PATH] + NASM_COMMAND(usingOldNasm).split())

class ConversionError(Exception):
    '''Represents an exception thrown during ASM conversion.
    
    (Includes original-source line number for faster
    debugging...)
    '''
    def __init__(self, line, msg):
        Exception.__init__(self, "%d: %s" % (line, msg))

class ResolutionError(Exception):
    '''Represents an exception thrown during address/module resolution.'''
    pass

class PackagingError(Exception):
    '''Represents an exception thrown during OBJ packaging.'''
    pass

class ObjModule(object):
    '''Simple, "structure" class that represents an OBJ module.
    
    Contains:
        * segReg (str)
        * offset (int)
        * size (int)
        * bytes (str; can be empty)
        * binOffset (int) -- for cutting up BIN file
    '''
    __slots__ = ['segReg', 'offset', 'size', 'bytes', 'binOffset']

    def dump(self, outFile):
        '''Emit OBJ stream to output file.
        
        Uses the struct module to bundle up our contents
        and spit them out (as pure binary blob) to the
        given file-object.
        '''
        # Write segment number as a byte (unsigned)
        outFile.write(struct.pack('B', SEG_REG_MAPPING[self.segReg]))
        
        # Write the offset & size (16-bit, little-endian, unsigned)
        outFile.write(struct.pack('<H', self.offset))
        outFile.write(struct.pack('<H', self.size))
        
        # Write out the raw bytes
        outFile.write(self.bytes)


##################################################
# Auxiliary Application Classes
##################################################

class Converter(object):
    '''Class for generating NASM-compatible source from ASM file.
        
        
    Given a file object (passed in on creation),
    reads assembly code in line by line and generates
    a temporary assembly file consisting of the original
    verbatim with the following changes:
        * [MAP] & [BITS] directives (at the bottom, to preserve line numbers)
        * all "SETREG" directives commented out
        * all "ORG" directives converted to SECTIONs
    '''
    def __init__(self, inFile, outFile=None):
        '''Initialize for conversion; output defaults to ASM_FILE.'''
        self._in = inFile
        
        # Handle default output file
        if outFile is None:
            outFile = open(ASM_FILE, 'w')
            self._closeSelf = True
        else:
            self._closeSelf = False
        
        self._out = outFile

    def _scanSetReg(self):
        '''Process SETREG directives in ASM source.
        
        Scan the file for SETREG directives, capturing them
        in our dictionary table; converts those with hard
        numbers in them, otherwise just uses symbol; throws
        error if a reg is redifined OR if a SEG reg is set to
        a non-numeric.
        '''
        # For rewinding later
        start = self._in.tell()
        lineNum = 0
        regTable = {}

        # Scan the lines...
        for line in self._in:
            lineNum += 1
            line = line.strip()         # Clear out left/right WS
            S = shlex.shlex(line)
            S.commenters = ';'  # Ignore anything in ASM comments...  [bugfix by JPJ, 12/10/2008]
            tokens = [t for t in S]  # Grab tokens (use shlex for parsing)
            if tokens and tokens[0].upper() == 'SETREG':
                # Ah-ha!
                try: 
                    reg = tokens[1].upper()
                    val = parseNum(tokens[3])

                    # Check for redefinition
                    if reg in regTable:
                        raise Exception("Cannot redefine register!")

                    # Check for non-integer SEG reg values
                    if (reg in ('CS', 'DS', 'SS', 'ES')) and (type(val) is str):
                        raise Exception("Cannot set segment register to a symbol!")

                    # Go ahead and assign it...
                    regTable[reg] = val

                # Wrap any errors
                except Exception, ex:
                    raise ConversionError(lineNum, ex.message)

        # OK, we're done...rewind the file
        self._in.seek(start)

        # Return the table
        return regTable

    def _emit(self, *args):
        '''Wrapper to print to our output stream, painlessly.'''
        string = ' '.join(str(a) for a in args)
        if string[-1] != '\n':
            string += '\n'
        self._out.write(string)

    def convert(self):
        '''Actually process and generate source (2 passes).

        Scans the file (2 passes) and returns spits the results
        out to the output file object--a new, NASM-ready ASM
        file!

        Returns a tuple:
            * dictionary of section names -> segment-registers (or None)
            * SETREG dictionary
        '''
        # First, parse the entire file for SETREG directives...
        regTable = self._scanSetReg()

        # Start looping through the file lines, ignoring SETREG,
        # converting ORG, and echoing the rest verbatim
        lineNum = 0
        orgNum = 0
        orgTable = {}
        try:
            for line in self._in:
                test = line.strip().upper()

                # Skip SETREG
                if test.startswith('SETREG'):
                    self._emit('; -- disabled for NASM -- ' + line)
                    continue

                # Convert ORG
                if test.startswith('ORG'):
                    orgNum += 1
                    orgName = '.%d' % orgNum

                    # We have to parse this baby--there might be a SEG
                    # register specified--store in the ORG table
                    tokens = [t for t in shlex.shlex(test)]
                    if tokens[1] in ('CS', 'DS', 'SS', 'ES'):
                        orgTable[orgName] = tokens[1]
                        offset = parseNum(tokens[3])
                    else:
                        orgTable[orgName] = 'CS'    # Defaults to CS here
                        offset = parseNum(tokens[1])

                    # Generate a SECTION with the right VSTART
                    self._emit('SECTION\t%s\tALIGN=1 VSTART=%d' % (orgName, offset), ('; -- NASM equivalent of "%s"' % line.strip()))
                    continue

                # Echo the rest
                self._emit(line)

            # If we're at the end (out of the loop) and have no ORGs, scream
            if orgNum == 0:
                raise Exception('Found no ORG--at least one ORG directive must exist!')

        # Catch any exceptions and re-raise w/line-number
        except Exception, ex:
            raise ConversionError(lineNum, ex.message)

        # Why put directives here??? This preserves the original line numbers, so NASM error messages are more helpful!!!
        self._emit("[MAP ALL %s]" % MAP_FILE)
        self._emit("[BITS 16]")

        # If we opened the output file ourselves, close it!
        if self._closeSelf:
            self._out.close()
        
        # Return the SETREG map (on success)
        return (orgTable, regTable)

class Resolver(object):
    '''Class to resolve label references in SETREGs after assembly.
        
    Parses a NASM MAP file to determine addresses of sections
    and symbols.  Uses the mapfile and orgTable from Converter
    to flesh out all symbolic names required for 2 things:
        * a module list (segment reg, offset, size)
        * a new regTable
    '''
    def __init__(self, orgTable, mapFile=None):
        '''Initialize resolver from MAP file.
        
        Create the resolver by parsing the MAP file
        and looking for symbols/sections.
        '''
        self._org = orgTable

        # Handle auto-file
        if mapFile is None:
            mapFile = open(MAP_FILE, 'r')
            self._closeSelf = True
        else:
            self._closeSelf = False
        self._in = mapFile

        self._sections = self._getSections()
        self._symbols = self._getSymbols()

        # Close it if we opened it
        if self._closeSelf:
            self._in.close()

    def _findRegion(self, caption):
        '''Scan the mapfile for the specified NASM MAP region.
            
        There's no way to rewind properly, so make
        sure you don't use this to look for something
        that could legitimately not be there...
        '''
        search = caption.upper()
        
        for line in self._in:
            if line.upper().startswith(search):
                return

        # We got to the end without finding it...
        raise Exception("Couldn't find NASM MAP-file region '%s'" % caption)

    def _getSections(self):
        '''Retrieve module start/length info from MAP file.
            
        Scan through the section-summary region of
        the MAP file to get module start/length information.
        '''
        # Find the main section-summary region
        self._findRegion(MAP_SUMMARY_REGION)

        # Read in the table
        table = {}
        skip = 2
        for line in self._in:
            # Skip 2 lines
            if skip > 0:
                skip -= 1
                continue
            
            # End on a blank line
            if not line.strip():
                break

            # Split out fields--convert 1st 4 to hex numbers
            fields = line.strip().split()
            fields[0:4] = [int(f, 16) for f in fields[0:4]]

            # Assign to table for easy reference backwards
            table[fields[5].strip()] = fields[0:4]

        # Return the table
        return table

    def _getSymbols(self):
        '''Build a symbol dictionary from the MAP file.
        
        Compile all symbols from all sections (or rather, their
        virtual-addresses) into a dictionary.
        '''
        # Skip ahead to the main symbols section first
        self._findRegion(MAP_SYMBOLS_REGION)

        # Find each section below this area, and rip out the symbols
        table = {}
        while True:
            # Scan for the header of a symbol listing table
            for line in self._in:
                fields = line.split()
                if fields and fields[0].upper() == 'REAL':
                    break
            else:
                # Never found (another) symbol section...
                break
            
            # Scoop out the symbols
            for line in self._in:
                # Split out fields
                fields = line.strip().split()
                if not fields:
                    # Must have finished this table...
                    break
                
                # Grab name, then virtual address
                # But make sure we don't have 2 identical symbols!!!
                name = fields[2].strip()
                if name in table:
                  raise ResolutionError("Encountered symbol '%s' twice!" % name)
                table[name] = int(fields[1], 16)
            
        # Return the table
        return table

    def module(self, sectionName):
        '''Generates an ObjModule instance for the given sectionName.'''
        if sectionName not in self._org:
            raise ResolutionError("'%s': no such module/section!" % sectionName)

        # Create the module object
        obj = ObjModule()
        
        # Look up the segment for that section
        obj.segReg = self._org[sectionName]

        # And the offset in target RAM
        obj.offset = self._sections[sectionName][0]

        # Size and bytes (empty for now)
        obj.size = self._sections[sectionName][3]
        obj.bytes = ''

        # Offset in BIN file right now
        obj.binOffset = self._sections[sectionName][1]

        # Return it
        return obj

    def symbol(self, symbolName):
        '''Returns the virtual address of the symbol.'''
        if symbolName not in self._symbols:
            raise ResolutionError("'%s': no such symbol!" % symbolName)
        return self._symbols[symbolName]

class Packager(object):
    '''Class that handles final assembly of the OBJ file.
    
    The final piece of the puzzle: given the register and
    module tables, snip the right strings of bytes out of
    the raw BIN file and package a real live OBJ file!!!
    '''
    def __init__(self, regTable, moduleList, binFile=None):
        self._regs = regTable
        self._modules = moduleList

        # Handle the default file case
        if binFile is None:
            binFile = open(BIN_FILE, 'rb')
            self._closeSelf = True
        else:
            self._closeSelf = False

        self._in = binFile

    def _getRegBlock(self):
        '''Build the 28-byte register block header.  Return as string.'''
        regVals = []

        for r in REGISTER_ORDER:
            # Default case if not specified
            if r not in self._regs:
                regVals.append(REGISTER_DEFAULT)
            else:
                regVals.append(self._regs[r])
        
        # Create the packing--14 Little-Endian unsigned 16-bit words in a row
        # NOTE: this means you cannot assign EXPLICITLY negative
        #   numbers to registers using SETREG...
        return struct.pack('<14H', *regVals)

    def _loadModules(self):
        '''Extract load modules from BIN file.
        
        Using the input file object as the BIN file,
        snip out the necessary bytes and load each
        module's "bytes" member accordingly...
        '''
        # For each module
        for m in self._modules:
            # Skip to this offset in the fild
            self._in.seek(m.binOffset)

            # Grab this many bytes
            m.bytes = self._in.read(m.size)

        # If we opened the BIN file ourselves--close it!
        if self._closeSelf:
            self._in.close()
    
    def package(self, outFile):
        '''Final generation of the OBJ file.
        
        Spits a completely packaged OBJ file to the
        passed-in file-object (SHOULD BE OPENED IN
        BINARY MODE!!!!)
        '''
        # Catch all exceptions and reraise as our own
        try:
            # Write out the registers for us, please!
            outFile.write(self._getRegBlock())

            # And the number of modules
            outFile.write(struct.pack('B', len(self._modules)))

            # Load the bytes into the modules
            self._loadModules()

            # Now, dump each of the modules in turn
            for m in self._modules:
                m.dump(outFile)

        except Exception, ex:
            raise PackagingError(ex.message) 


##################################################
# Main Application Class
##################################################

class SASM86(object):
    '''All-in-one assembler class.
    
    Principle master class encapsulating the application.
    Uses Converted, Resolver, and Packager to convert
    a Sim86-style ASM file into a Sim86 OBJ.
    '''
    def __init__(self, inFileName, outFileName=None, keepTemps=False, listFile=False):
        '''Set up the assembler given certain input options.
        
        Initializes the settings for an assemble.  Can optionally
        generate an output name from the input name (unless the output
        name is given).  Sets flag for "keep temp files" or "delete them."
        Also sets flag/path to optional list file (copied from one of
        the temp files after packaging but before temp-file deletion.
        '''
        self._inFileName = inFileName

        # Handle auto-named output ('foo.asm' -> 'foo.obj')
        if outFileName is None:
            root, ext = path.splitext(inFileName)
            outFileName = root + '.obj'
        self._outFileName = outFileName

        # Flags
        self._keepTemps = keepTemps

        # Now, if listFile is TRUE, do another autonaming...
        # (Do NOT just say "if listFile:" because listFile may
        # contain a filename, which would evaluate to true...)
        if listFile == True:
            root, ext = path.splitext(inFileName)
            listFile = root + '.lst'
            
        self._listFile = listFile

    def _cleanup(self):
        '''Copy list file (if requested) and delete tempfiles (if requested).'''
        # If the list file doesn't already exist, ignore it, as we probably have bigger problems.
        if self._listFile and path.exists(LIST_FILE):
            shutil.copyfile(LIST_FILE, self._listFile)

        if not self._keepTemps:
            # Nuke 'em all...ignore those that don't exist (in an error condition)
            toNuke = [ASM_FILE, MAP_FILE, LIST_FILE, BIN_FILE, ERROR_FILE]
            for n in toNuke:
                if path.exists(n):
                    os.remove(n)

    def _dumpNasmErrors(self):
        '''If we detected a NASM error, dump its error output.
        
        Also, translate filenames to avoid confusing programmers.
        '''
        print >> sys.stderr, 'NASM says:\n' + '-'*60
        errFile = open(ERROR_FILE, 'r')
        for line in errFile:
            print >> sys.stderr, line.strip().replace(ASM_FILE, self._inFileName)
        print >> sys.stderr
    
    def assemble(self):
        '''Do it!!!'''
        # Open input file
        inFile = open(self._inFileName, 'r')
        
        # Convert SASM86-source to NASM-source (smart enough to use default temp-file names)
        C = Converter(inFile)
        orgTable, regTable = C.convert()

        # Done with this now
        inFile.close()

        # Run NASM (again, uses default temp-file names)
        nasmRet = runNASM(usingOldNASM())  # While at it, check version
        if nasmRet != 0:
            # Must have been an error--quit right here
            self._dumpNasmErrors()
            self._cleanup()
            raise Exception("NASM terminated with a non-zero exit code (%d)" % nasmRet)

        # Back-resolve all module/symbol addresses
        R = Resolver(orgTable)
        mods = [R.module(o) for o in orgTable]
        for k, v in regTable.items():
            if type(v) is str:
                regTable[k] = R.symbol(v)

        # Open the output file now, when any errors should have occurred already
        outFile = open(self._outFileName, 'wb') # MUST BE BINARY MODE UNDER DOS/WIN!!!
        
        # Package the OBJ into the output file
        P = Packager(regTable, mods)
        P.package(outFile)

        # Close the output file
        outFile.close()

        # Now, do cleanup and call it quits
        self._cleanup()
        return


##################################################
# Stand-alone Script Code
##################################################

# If this script is run as a program rather than imported as a library...
if __name__ == '__main__':
    from optparse import OptionParser
    
    # Set up a command-line argument interpreter
    parser = OptionParser("usage: %prog [options] FILE")

    # Add the "keep temp files" flag option
    parser.add_option('-k', '--keep-temps', action='store_true',
                      dest='keepTemps', default=False,
                      help="keep temp files after assembly")

    # Add the "suppress banner" flag option
    parser.add_option('-s', '--suppress-banner', action='store_true',
                      dest='noBanner', default=False,
                      help="do not display the SASM86 banner")

    # Add the "list-file [here]" flag/name option
    parser.add_option('-l', '--list-file', metavar='FILE', default=False,
                      dest='listFile', help="keep the list file (named FILE)")

    # Add the "explicit-output file" name option here
    parser.add_option('-o', '--output', metavar='FILE', default=None,
                      dest='outFileName', help="save OBJ output to FILE")


    # Actually parse our command-line arguments (if any)
    options, args = parser.parse_args()    

    # Make sure we have an input file
    if len(args) != 1:
        parser.error("Must specify input file!")
        sys.exit(-1)

    # Print our banner first.
    if not options.noBanner:
        print SASM86_BANNER

    # Create and run the assembler class
    try:
        SASM86(args[0], options.outFileName, options.keepTemps, options.listFile).assemble()
    except Exception, ex:
        print >> sys.stderr, "Assembly interrupted with error(s):"
        print >> sys.stderr, '\t' + str(ex)
        sys.exit(-1)

    # We made it!
    print "Assembly completed with no [detected] errors.   Happy debugging!"
