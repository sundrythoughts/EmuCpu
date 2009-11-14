/*
 * sim8086 -- Emulates an Intel 8086 processor
 * Copyright (C) 2009  Joseph Freeman (jfree143dev AT gmail DOT com)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


/**
@file ExecutionUnit.hh
@brief Manage the general registers, flag register, and instruction execution.
*/

#ifndef JAF__EXECUTION_UNIT_HH
#define JAF__EXECUTION_UNIT_HH

#include "Register.hh"
#include <sigc++/sigc++.h>

class CpuComponents;
class OperandList;
class ExecutionUnitPrivate;

/**
@class ExecutionUnit
@brief Manage the general registers, flag register, and instruction execution.
*/
class ExecutionUnit {
	ExecutionUnitPrivate *p;

public:
	/** */
	ExecutionUnit ();

	/** */
	ExecutionUnit (const ExecutionUnit &src);

	/** */
	~ExecutionUnit ();

	/** Create a connection to the Cpu */
	void connectTo (CpuComponents &cpu);

	/** */
	sigc::signal<void, unsigned short, unsigned short, unsigned short>& signalStackPush ();

	/** */
	sigc::signal<void>& signalStackPop ();

	/** */
	void reset ();

	/** Get an 8-bit register given its index */
	Register<unsigned char>& getReg8 (size_t index);

	/** Set an 8-bit register given its index */
	void setReg8 (size_t index, unsigned char val);

	/** Get a 16-bit register given its index */
	Register<unsigned short>& getReg16 (size_t index);

	/** Set a 16-bit register given its index */
	void setReg16 (size_t index, unsigned short val);

	/** */
	Register<unsigned short>& getRegAX ();

	/** */
	void setRegAX (unsigned short val);

	/** */
	Register<unsigned char>& getRegAH ();

	/** */
	void setRegAH (unsigned char val);

	/** */
	Register<unsigned char>& getRegAL ();

	/** */
	void setRegAL (unsigned char val);

	/** */
	Register<unsigned short>& getRegBX ();

	/** */
	void setRegBX (unsigned short val);

	/** */
	Register<unsigned char>& getRegBH ();

	/** */
	void setRegBH (unsigned char val);

	/** */
	Register<unsigned char>& getRegBL ();

	/** */
	void setRegBL (unsigned char val);

	/** */
	Register<unsigned short>& getRegCX ();

	/** */
	void setRegCX (unsigned short val);

	/** */
	Register<unsigned char>& getRegCH ();

	/** */
	void setRegCH (unsigned char val);

	/** */
	Register<unsigned char>& getRegCL ();

	/** */
	void setRegCL (unsigned char val);

	/** */
	Register<unsigned short>& getRegDX ();

	/** */
	void setRegDX (unsigned short val);

	/** */
	Register<unsigned char>& getRegDH ();

	/** */
	void setRegDH (unsigned char val);

	/** */
	Register<unsigned char>& getRegDL ();

	/** */
	void setRegDL (unsigned char val);

	/** */
	Register<unsigned short>& getRegDI ();

	/** */
	void setRegDI (unsigned short val);

	/** */
	Register<unsigned short>& getRegSI ();

	/** */
	void setRegSI (unsigned short val);

	/** */
	Register<unsigned short>& getRegBP ();

	/** */
	void setRegBP (unsigned short val);

	/** */
	Register<unsigned short>& getRegSP ();

	/** */
	void setRegSP (unsigned short val);

	/** */
	void resetRegFlags (unsigned short val = 2);

	/** */
	Register<unsigned short>& getRegFlags ();

	/** */
	void setRegFlags (unsigned short val);

	/** */
	bool getRegFlagsAF () const;

	/** */
	void setRegFlagsAF (bool val);

	/** */
	bool getRegFlagsCF () const;

	/** */
	void setRegFlagsCF (bool val);

	/** */
	bool getRegFlagsDF () const;

	/** */
	void setRegFlagsDF (bool val);

	/** */
	bool getRegFlagsIF () const;

	/** */
	void setRegFlagsIF (bool val);

	/** */
	bool getRegFlagsOF () const;

	/** */
	void setRegFlagsOF (bool val);

	/** */
	bool getRegFlagsPF () const;

	/** */
	void setRegFlagsPF (bool val);

	/** */
	bool getRegFlagsSF () const;

	/** */
	void setRegFlagsSF (bool val);

	/** */
	bool getRegFlagsTF () const;

	/** */
	void setRegFlagsTF (bool val);

	/** */
	bool getRegFlagsZF () const;

	/** */
	void setRegFlagsZF (bool val);

	/** */
	void execNotImplemented ();

	/** UNIMPLEMENTED */
	void execAAA ();

	/** UNIMPLEMENTED */
	void execAAD ();

	/** UNIMPLEMENTED */
	void execAAM ();

	/** UNIMPLEMENTED */
	void execAAS ();

	/** */
	void execADC ();

	/** */
	void execADD ();

	/** */
	void execAND ();

	/** UNIMPLEMENTED */
	void execCALL ();

	/** UNIMPLEMENTED */
	void execCALLFAR ();

	/** */
	void execCBW ();

	/** */
	void execCLC ();

	/** */
	void execCLD ();

	/** */
	void execCLI ();

	/** */
	void execCMC ();

	/** */
	void execCMP ();

	/** UNIMPLEMENTED */
	void execCMPS ();

	/** */
	void execCWD ();

	/** UNIMPLEMENTED */
	void execDAA ();

	/** UNIMPLEMENTED */
	void execDAS ();

	/** */
	void execDEC ();

	/** */
	void execDIV ();

	/** UNIMPLEMENTED */
	void execESC ();

	/** */
	void execHLT ();

	/** UNIMPLEMENTED */
	void execIDIV ();

	/** UNIMPLEMENTED */
	void execIMUL ();

	/** UNIMPLEMENTED */
	void execIN ();

	/** */
	void execINC ();

	/** UNIMPLEMENTED */
	void execINT ();

	/** UNIMPLEMENTED */
	void execINTO ();

	/** UNIMPLEMENTED */
	void execIRET ();

	/** */
	void execJNA ();

	/** */
	void execJNAE ();

	/** */
	void execJNB ();

	/** */
	void execJNBE ();

	/** */
	void execJC ();

	/** */
	void execJCXZ ();

	/** */
	void execJE ();

	/** */
	void execJG ();

	/** */
	void execJGE ();

	/** */
	void execJL ();

	/** */
	void execJLE ();

	/** */
	void execJMP ();

	/** */
	void execJMPSHORT ();

	/** */
	void execJMPFAR ();

	/** */
	void execJNC ();

	/** */
	void execJNE ();

	/** */
	void execJNO ();

	/** */
	void execJNS ();

	/** */
	void execJNP ();

	/** */
	void execJO ();

	/** */
	void execJPE ();

	/** */
	void execJS ();

	/** */
	void execLAHF ();

	/** UNIMPLEMENTED */
	void execLDS ();

	/** */
	void execLEA ();

	/** UNIMPLEMENTED */
	void execLES ();

	/** UNIMPLEMENTED */
	void execLOCK ();

	/** UNIMPLEMENTED */
	void execLODS ();

	/** */
	void execLOOP ();

	/** */
	void execLOOPE ();

	/** */
	void execLOOPNE ();

	/** */
	void execMOV ();

	/** UNIMPLEMENTED */
	void execMOVS ();

	/** */
	void execMUL ();

	/** */
	void execNEG ();

	/** */
	void execNOP ();

	/** */
	void execNOT ();

	/** */
	void execOR ();

	/** UNIMPLEMENTED */
	void execOUT ();

	/** */
	void execPOP ();

	/** */
	void execPOPF ();

	/** */
	void execPUSH ();

	/** */
	void execPUSHF ();

	/** */
	void execRCL ();

	/** */
	void execRCR ();

	/** UNIMPLEMENTED */
	void execREP ();

	/** UNIMPLEMENTED */
	void execREPNE ();

	/** UNIMPLEMENTED */
	void execRET ();

	/** UNIMPLEMENTED */
	void execRETFAR ();

	/** */
	void execROL ();

	/** */
	void execROR ();

	/** */
	void execSAHF ();

	/** */
	void execSHL ();

	/** */
	void execSAR ();

	/** */
	void execSBB ();

	/** UNIMPLEMENTED */
	void execSCAS ();

	/** UNIMPLEMENTED */
	void execSEG ();

	/** */
	void execSHR ();

	/** */
	void execSTC ();

	/** */
	void execSTD ();

	/** */
	void execSTI ();

	/** UNIMPLEMENTED */
	void execSTOS ();

	/** */
	void execSUB ();

	/** */
	void execTEST ();

	/** UNIMPLEMENTED */
	void execWAIT ();

	/** */
	void execXCHG ();

	/** UNIMPLEMENTED */
	void execXLAT ();

	/** */
	void execXOR ();

private:
	void realPush (unsigned short num);

	void realPop ();

	void realPop (INumberReadableWritable<unsigned short> &num);

}; //end class ExecutionUnit

#endif //JAF__EXECUTION_UNIT_HH

