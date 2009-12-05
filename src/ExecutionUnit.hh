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

	/** Create a connection to the CpuComponents. */
	void connectTo (CpuComponents &cpu);

	/** Sigc++ signal emitted when data is pushed on the stack. */
	sigc::signal<void, unsigned short, unsigned short, unsigned short>& signalStackPush ();

	/** Sigc++ signal emitted when data is popped off the stack. */
	sigc::signal<void>& signalStackPop ();

	/** Reset the ExecutionUnit. */
	void reset ();

	/** Get an 8-bit register given its RegisterIndex8 index. */
	Register<unsigned char>& getReg8 (size_t index);

	/** Set an 8-bit register given its RegisterIndex8 index. */
	void setReg8 (size_t index, unsigned char val);

	/** Get a 16-bit register given its RegisterIndex16 index. */
	Register<unsigned short>& getReg16 (size_t index);

	/** Set a 16-bit register given its RegisterIndex16 index. */
	void setReg16 (size_t index, unsigned short val);

	/** Get register AX. */
	Register<unsigned short>& getRegAX ();

	/** Set register AX. */
	void setRegAX (unsigned short val);

	/** Get register AH. */
	Register<unsigned char>& getRegAH ();

	/** Set register AH. */
	void setRegAH (unsigned char val);

	/** Get register AL. */
	Register<unsigned char>& getRegAL ();

	/** Set register AL. */
	void setRegAL (unsigned char val);

	/** Get register BX. */
	Register<unsigned short>& getRegBX ();

	/** Set register BX. */
	void setRegBX (unsigned short val);

	/** Get register BH. */
	Register<unsigned char>& getRegBH ();

	/** Set register BH. */
	void setRegBH (unsigned char val);

	/** Get register BL. */
	Register<unsigned char>& getRegBL ();

	/** Set register BL. */
	void setRegBL (unsigned char val);

	/** Get register CX. */
	Register<unsigned short>& getRegCX ();

	/** Set register CX. */
	void setRegCX (unsigned short val);

	/** Get register CH. */
	Register<unsigned char>& getRegCH ();

	/** Set register CH. */
	void setRegCH (unsigned char val);

	/** Get register CL. */
	Register<unsigned char>& getRegCL ();

	/** Set register CL. */
	void setRegCL (unsigned char val);

	/** Get register DX. */
	Register<unsigned short>& getRegDX ();

	/** Set register DX. */
	void setRegDX (unsigned short val);

	/** Get register DH. */
	Register<unsigned char>& getRegDH ();

	/** Set register DH. */
	void setRegDH (unsigned char val);

	/** Get register DL. */
	Register<unsigned char>& getRegDL ();

	/** Set register DL. */
	void setRegDL (unsigned char val);

	/** Get register DI. */
	Register<unsigned short>& getRegDI ();

	/** Set register DI. */
	void setRegDI (unsigned short val);

	/** Get register SI. */
	Register<unsigned short>& getRegSI ();

	/** Set register SI. */
	void setRegSI (unsigned short val);

	/** Get register BP. */
	Register<unsigned short>& getRegBP ();

	/** Set register BP. */
	void setRegBP (unsigned short val);

	/** Get register SP. */
	Register<unsigned short>& getRegSP ();

	/** Set register SP. */
	void setRegSP (unsigned short val);

	/** Reset the Flags register to a particular value. */
	void resetRegFlags (unsigned short val = 2);

	/** Get register FLAGS. */
	Register<unsigned short>& getRegFlags ();

	/** Set register FLAGS. */
	void setRegFlags (unsigned short val);

	/** Get register FLAGS AF. */
	bool getRegFlagsAF () const;

	/** Set register FLAGS AF. */
	void setRegFlagsAF (bool val);

	/** Get register FLAGS CF. */
	bool getRegFlagsCF () const;

	/** Set register FLAGS CF. */
	void setRegFlagsCF (bool val);

	/** Get register FLAGS DF. */
	bool getRegFlagsDF () const;

	/** Set register FLAGS DF. */
	void setRegFlagsDF (bool val);

	/** Get register FLAGS IF. */
	bool getRegFlagsIF () const;

	/** Set register FLAGS IF. */
	void setRegFlagsIF (bool val);

	/** Get register FLAGS OF. */
	bool getRegFlagsOF () const;

	/** Set register FLAGS OF. */
	void setRegFlagsOF (bool val);

	/** Get register FLAGS PF. */
	bool getRegFlagsPF () const;

	/** Set register FLAGS PF. */
	void setRegFlagsPF (bool val);

	/** Get register FLAGS SF. */
	bool getRegFlagsSF () const;

	/** Set register FLAGS SF. */
	void setRegFlagsSF (bool val);

	/** Get register FLAGS TF. */
	bool getRegFlagsTF () const;

	/** Set register FLAGS TF. */
	void setRegFlagsTF (bool val);

	/** Get register FLAGS ZF. */
	bool getRegFlagsZF () const;

	/** Set register FLAGS ZF. */
	void setRegFlagsZF (bool val);

	/** Executed when an opcode is reserved. */
	void execNotImplemented ();

	/** UNIMPLEMENTED */
	void execAAA ();

	/** UNIMPLEMENTED */
	void execAAD ();

	/** UNIMPLEMENTED */
	void execAAM ();

	/** UNIMPLEMENTED */
	void execAAS ();

	/** Add with carry. */
	void execADC ();

	/** Add. */
	void execADD ();

	/** And. */
	void execAND ();

	/** Call near. */
	void execCALL ();

	/** Call far. */
	void execCALLFAR ();

	/** Convert byte to word. */
	void execCBW ();

	/** Clear carry flag. */
	void execCLC ();

	/** Clear direction flag. */
	void execCLD ();

	/** Clear interrupt flag. */
	void execCLI ();

	/** Complement carry flag. */
	void execCMC ();

	/** Compare. */
	void execCMP ();

	/** UNIMPLEMENTED */
	void execCMPS ();

	/** Convert word to double word. */
	void execCWD ();

	/** UNIMPLEMENTED */
	void execDAA ();

	/** UNIMPLEMENTED */
	void execDAS ();

	/** Decrement. */
	void execDEC ();

	/** Divide. */
	void execDIV ();

	/** UNIMPLEMENTED */
	void execESC ();

	/** Halt. */
	void execHLT ();

	/** UNIMPLEMENTED */
	void execIDIV ();

	/** UNIMPLEMENTED */
	void execIMUL ();

	/** Input a byte/word from a port. */
	void execIN ();

	/** Increment. */
	void execINC ();

	/** */
	void execINT ();

	/** */
	void execINTO ();

	/** */
	void execIRET ();

	/** Jump on not above. */
	void execJNA ();

	/** Jump on not above or equal to. */
	void execJNAE ();

	/** Jump on not below. */
	void execJNB ();

	/** Jump on not below or equal to. */
	void execJNBE ();

	/** Jump on carry. */
	void execJC ();

	/** Jump on CX equal to zero. */
	void execJCXZ ();

	/** Jump on equal to. */
	void execJE ();

	/** Jump on greater than. */
	void execJG ();

	/** Jump on greater than or equal to. */
	void execJGE ();

	/** Jump on less than. */
	void execJL ();

	/** Jump on less than or equal to. */
	void execJLE ();

	/** Unconditional jump near. */
	void execJMP ();

	/** Unconditional jump short. */
	void execJMPSHORT ();

	/** Unconditional jump far. */
	void execJMPFAR ();

	/** Jump on not carry. */
	void execJNC ();

	/** Jump on not equal to. */
	void execJNE ();

	/** Jump on not overflow. */
	void execJNO ();

	/** Jump on not sign. */
	void execJNS ();

	/** Jump on not parity. */
	void execJNP ();

	/** Jump on overflow. */
	void execJO ();

	/** Jump on parity equal. */
	void execJPE ();

	/** Jump on sign. */
	void execJS ();

	/** Load register AH from register FLAGS. */
	void execLAHF ();

	/** UNIMPLEMENTED */
	void execLDS ();

	/** Load effective address. */
	void execLEA ();

	/** UNIMPLEMENTED */
	void execLES ();

	/** UNIMPLEMENTED */
	void execLOCK ();

	/** UNIMPLEMENTED */
	void execLODS ();

	/** Loop. */
	void execLOOP ();

	/** Loop while equal. */
	void execLOOPE ();

	/** Loop while not equal. */
	void execLOOPNE ();

	/** Mov byte/word to/from memory. */
	void execMOV ();

	/** UNIMPLEMENTED */
	void execMOVS ();

	/** Multiply. */
	void execMUL ();

	/** Negate (two's complement). */
	void execNEG ();

	/** No operation. */
	void execNOP ();

	/** Logical not (one's complement). */
	void execNOT ();

	/** Logical or. */
	void execOR ();

	/** Output a byte/word to a port. */
	void execOUT ();

	/** Pop from stack. */
	void execPOP ();

	/** Pop from stack into FLAGS register. */
	void execPOPF ();

	/** Push to stack. */
	void execPUSH ();

	/** Push FLAGS register to stack. */
	void execPUSHF ();

	/** Rotate carry left. */
	void execRCL ();

	/** Rotate carry right. */
	void execRCR ();

	/** UNIMPLEMENTED */
	void execREP ();

	/** UNIMPLEMENTED */
	void execREPNE ();

	/** Return near. */
	void execRET ();

	/** Return far. */
	void execRETFAR ();

	/** Rotate left. */
	void execROL ();

	/** Rotate right. */
	void execROR ();

	/** Store register AH into register FLAGS. */
	void execSAHF ();

	/** Shift left. */
	void execSHL ();

	/** Shift arithmetic right. */
	void execSAR ();

	/** Subtract with borrow. */
	void execSBB ();

	/** UNIMPLEMENTED */
	void execSCAS ();

	/** Do a segment override. */
	void execSEG ();

	/** Shift right. */
	void execSHR ();

	/** Set carry flag. */
	void execSTC ();

	/** Set direction flag. */
	void execSTD ();

	/** Set interrupt flag. */
	void execSTI ();

	/** UNIMPLEMENTED */
	void execSTOS ();

	/** Subtract. */
	void execSUB ();

	/** Test. */
	void execTEST ();

	/** UNIMPLEMENTED */
	void execWAIT ();

	/** Exchange. */
	void execXCHG ();

	/** UNIMPLEMENTED */
	void execXLAT ();

	/** Xor. */
	void execXOR ();

private:
	void realPush (unsigned short num);

	void realPop ();

	void realPop (INumberReadableWritable<unsigned short> &num);

}; //end class ExecutionUnit

#endif //JAF__EXECUTION_UNIT_HH

