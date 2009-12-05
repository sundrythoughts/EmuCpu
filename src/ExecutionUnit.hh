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

	/** @brief Create a connection to the CpuComponents. */
	void connectTo (CpuComponents &cpu);

	/** @brief Sigc++ signal emitted when data is pushed on the stack. */
	sigc::signal<void, unsigned short, unsigned short, unsigned short>& signalStackPush ();

	/** @brief Sigc++ signal emitted when data is popped off the stack. */
	sigc::signal<void>& signalStackPop ();

	/** @brief Reset the ExecutionUnit. */
	void reset ();

	/** @brief Get an 8-bit register given its RegisterIndex8 index. */
	Register<unsigned char>& getReg8 (size_t index);

	/** @brief Set an 8-bit register given its RegisterIndex8 index. */
	void setReg8 (size_t index, unsigned char val);

	/** @brief Get a 16-bit register given its RegisterIndex16 index. */
	Register<unsigned short>& getReg16 (size_t index);

	/** @brief Set a 16-bit register given its RegisterIndex16 index. */
	void setReg16 (size_t index, unsigned short val);

	/** @brief Get register AX. */
	Register<unsigned short>& getRegAX ();

	/** @brief Set register AX. */
	void setRegAX (unsigned short val);

	/** @brief Get register AH. */
	Register<unsigned char>& getRegAH ();

	/** @brief Set register AH. */
	void setRegAH (unsigned char val);

	/** @brief Get register AL. */
	Register<unsigned char>& getRegAL ();

	/** @brief Set register AL. */
	void setRegAL (unsigned char val);

	/** @brief Get register BX. */
	Register<unsigned short>& getRegBX ();

	/** @brief Set register BX. */
	void setRegBX (unsigned short val);

	/** @brief Get register BH. */
	Register<unsigned char>& getRegBH ();

	/** @brief Set register BH. */
	void setRegBH (unsigned char val);

	/** @brief Get register BL. */
	Register<unsigned char>& getRegBL ();

	/** @brief Set register BL. */
	void setRegBL (unsigned char val);

	/** @brief Get register CX. */
	Register<unsigned short>& getRegCX ();

	/** @brief Set register CX. */
	void setRegCX (unsigned short val);

	/** @brief Get register CH. */
	Register<unsigned char>& getRegCH ();

	/** @brief Set register CH. */
	void setRegCH (unsigned char val);

	/** @brief Get register CL. */
	Register<unsigned char>& getRegCL ();

	/** @brief Set register CL. */
	void setRegCL (unsigned char val);

	/** @brief Get register DX. */
	Register<unsigned short>& getRegDX ();

	/** @brief Set register DX. */
	void setRegDX (unsigned short val);

	/** @brief Get register DH. */
	Register<unsigned char>& getRegDH ();

	/** @brief Set register DH. */
	void setRegDH (unsigned char val);

	/** @brief Get register DL. */
	Register<unsigned char>& getRegDL ();

	/** @brief Set register DL. */
	void setRegDL (unsigned char val);

	/** @brief Get register DI. */
	Register<unsigned short>& getRegDI ();

	/** @brief Set register DI. */
	void setRegDI (unsigned short val);

	/** @brief Get register SI. */
	Register<unsigned short>& getRegSI ();

	/** @brief Set register SI. */
	void setRegSI (unsigned short val);

	/** @brief Get register BP. */
	Register<unsigned short>& getRegBP ();

	/** @brief Set register BP. */
	void setRegBP (unsigned short val);

	/** @brief Get register SP. */
	Register<unsigned short>& getRegSP ();

	/** @brief Set register SP. */
	void setRegSP (unsigned short val);

	/** @brief Reset the Flags register to a particular value. */
	void resetRegFlags (unsigned short val = 2);

	/** @brief Get register FLAGS. */
	Register<unsigned short>& getRegFlags ();

	/** @brief Set register FLAGS. */
	void setRegFlags (unsigned short val);

	/** @brief Get register FLAGS AF. */
	bool getRegFlagsAF () const;

	/** @brief Set register FLAGS AF. */
	void setRegFlagsAF (bool val);

	/** @brief Get register FLAGS CF. */
	bool getRegFlagsCF () const;

	/** @brief Set register FLAGS CF. */
	void setRegFlagsCF (bool val);

	/** @brief Get register FLAGS DF. */
	bool getRegFlagsDF () const;

	/** @brief Set register FLAGS DF. */
	void setRegFlagsDF (bool val);

	/** @brief Get register FLAGS IF. */
	bool getRegFlagsIF () const;

	/** @brief Set register FLAGS IF. */
	void setRegFlagsIF (bool val);

	/** @brief Get register FLAGS OF. */
	bool getRegFlagsOF () const;

	/** @brief Set register FLAGS OF. */
	void setRegFlagsOF (bool val);

	/** @brief Get register FLAGS PF. */
	bool getRegFlagsPF () const;

	/** @brief Set register FLAGS PF. */
	void setRegFlagsPF (bool val);

	/** @brief Get register FLAGS SF. */
	bool getRegFlagsSF () const;

	/** @brief Set register FLAGS SF. */
	void setRegFlagsSF (bool val);

	/** @brief Get register FLAGS TF. */
	bool getRegFlagsTF () const;

	/** @brief Set register FLAGS TF. */
	void setRegFlagsTF (bool val);

	/** @brief Get register FLAGS ZF. */
	bool getRegFlagsZF () const;

	/** @brief Set register FLAGS ZF. */
	void setRegFlagsZF (bool val);

	/** @brief Executed when an opcode is reserved. */
	void execNotImplemented ();

	/** @brief UNIMPLEMENTED */
	void execAAA ();

	/** @brief UNIMPLEMENTED */
	void execAAD ();

	/** @brief UNIMPLEMENTED */
	void execAAM ();

	/** @brief UNIMPLEMENTED */
	void execAAS ();

	/** @brief Add with carry. */
	void execADC ();

	/** @brief Add. */
	void execADD ();

	/** @brief And. */
	void execAND ();

	/** @brief Call near. */
	void execCALL ();

	/** @brief Call far. */
	void execCALLFAR ();

	/** @brief Convert byte to word. */
	void execCBW ();

	/** @brief Clear carry flag. */
	void execCLC ();

	/** @brief Clear direction flag. */
	void execCLD ();

	/** @brief Clear interrupt flag. */
	void execCLI ();

	/** @brief Complement carry flag. */
	void execCMC ();

	/** @brief Compare. */
	void execCMP ();

	/** @brief UNIMPLEMENTED */
	void execCMPS ();

	/** @brief Convert word to double word. */
	void execCWD ();

	/** @brief UNIMPLEMENTED */
	void execDAA ();

	/** @brief UNIMPLEMENTED */
	void execDAS ();

	/** @brief Decrement. */
	void execDEC ();

	/** @brief Divide. */
	void execDIV ();

	/** @brief UNIMPLEMENTED */
	void execESC ();

	/** @brief Halt. */
	void execHLT ();

	/** @brief UNIMPLEMENTED */
	void execIDIV ();

	/** @brief UNIMPLEMENTED */
	void execIMUL ();

	/** @brief Input a byte/word from a port. */
	void execIN ();

	/** @brief Increment. */
	void execINC ();

	/** @brief Interrupt. */
	void execINT ();

	/** @brief Interrupt on overflow.  */
	void execINTO ();

	/** @brief Interrupt return. */
	void execIRET ();

	/** @brief Jump on not above. */
	void execJNA ();

	/** @brief Jump on not above or equal to. */
	void execJNAE ();

	/** @brief Jump on not below. */
	void execJNB ();

	/** @brief Jump on not below or equal to. */
	void execJNBE ();

	/** @brief Jump on carry. */
	void execJC ();

	/** @brief Jump on CX equal to zero. */
	void execJCXZ ();

	/** @brief Jump on equal to. */
	void execJE ();

	/** @brief Jump on greater than. */
	void execJG ();

	/** @brief Jump on greater than or equal to. */
	void execJGE ();

	/** @brief Jump on less than. */
	void execJL ();

	/** @brief Jump on less than or equal to. */
	void execJLE ();

	/** @brief Unconditional jump near. */
	void execJMP ();

	/** @brief Unconditional jump short. */
	void execJMPSHORT ();

	/** @brief Unconditional jump far. */
	void execJMPFAR ();

	/** @brief Jump on not carry. */
	void execJNC ();

	/** @brief Jump on not equal to. */
	void execJNE ();

	/** @brief Jump on not overflow. */
	void execJNO ();

	/** @brief Jump on not sign. */
	void execJNS ();

	/** @brief Jump on not parity. */
	void execJNP ();

	/** @brief Jump on overflow. */
	void execJO ();

	/** @brief Jump on parity equal. */
	void execJPE ();

	/** @brief Jump on sign. */
	void execJS ();

	/** @brief Load register AH from register FLAGS. */
	void execLAHF ();

	/** @brief UNIMPLEMENTED */
	void execLDS ();

	/** @brief Load effective address. */
	void execLEA ();

	/** @brief UNIMPLEMENTED */
	void execLES ();

	/** @brief UNIMPLEMENTED */
	void execLOCK ();

	/** @brief UNIMPLEMENTED */
	void execLODS ();

	/** @brief Loop. */
	void execLOOP ();

	/** @brief Loop while equal. */
	void execLOOPE ();

	/** @brief Loop while not equal. */
	void execLOOPNE ();

	/** @brief Mov byte/word to/from memory. */
	void execMOV ();

	/** @brief UNIMPLEMENTED */
	void execMOVS ();

	/** @brief Multiply. */
	void execMUL ();

	/** @brief Negate (two's complement). */
	void execNEG ();

	/** @brief No operation. */
	void execNOP ();

	/** @brief Logical not (one's complement). */
	void execNOT ();

	/** @brief Logical or. */
	void execOR ();

	/** @brief Output a byte/word to a port. */
	void execOUT ();

	/** @brief Pop from stack. */
	void execPOP ();

	/** @brief Pop from stack into FLAGS register. */
	void execPOPF ();

	/** @brief Push to stack. */
	void execPUSH ();

	/** @brief Push FLAGS register to stack. */
	void execPUSHF ();

	/** @brief Rotate carry left. */
	void execRCL ();

	/** @brief Rotate carry right. */
	void execRCR ();

	/** @brief UNIMPLEMENTED */
	void execREP ();

	/** @brief UNIMPLEMENTED */
	void execREPNE ();

	/** @brief Return near. */
	void execRET ();

	/** @brief Return far. */
	void execRETFAR ();

	/** @brief Rotate left. */
	void execROL ();

	/** @brief Rotate right. */
	void execROR ();

	/** @brief Store register AH into register FLAGS. */
	void execSAHF ();

	/** @brief Shift left. */
	void execSHL ();

	/** @brief Shift arithmetic right. */
	void execSAR ();

	/** @brief Subtract with borrow. */
	void execSBB ();

	/** @brief UNIMPLEMENTED */
	void execSCAS ();

	/** @brief Do a segment override. */
	void execSEG ();

	/** @brief Shift right. */
	void execSHR ();

	/** @brief Set carry flag. */
	void execSTC ();

	/** @brief Set direction flag. */
	void execSTD ();

	/** @brief Set interrupt flag. */
	void execSTI ();

	/** @brief UNIMPLEMENTED */
	void execSTOS ();

	/** @brief Subtract. */
	void execSUB ();

	/** @brief Test. */
	void execTEST ();

	/** @brief UNIMPLEMENTED */
	void execWAIT ();

	/** @brief Exchange. */
	void execXCHG ();

	/** @brief Xlat. */
	void execXLAT ();

	/** @brief Xor. */
	void execXOR ();

private:
	void realPush (unsigned short num);

	void realPop ();

	void realPop (INumberReadableWritable<unsigned short> &num);

}; //end class ExecutionUnit

#endif //JAF__EXECUTION_UNIT_HH

