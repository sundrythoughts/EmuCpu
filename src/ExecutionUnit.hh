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
	void execNotImplemented (OperandList &ops);

	/** */
	void execAAA ();

	/** */
	void execAAD ();

	/** */
	void execAAM ();

	/** */
	void execAAS ();

	/** */
	void execADC (OperandList &ops);

	/** */
	void execADD (OperandList &ops);

	/** */
	void execAND (OperandList &ops);

	/** */
	void execCALL ();

	/** */
	void execCALLFAR ();

	/** */
	void execCBW (OperandList &ops);

	/** */
	void execCLC (OperandList &ops);

	/** */
	void execCLD (OperandList &ops);

	/** */
	void execCLI (OperandList &ops);

	/** */
	void execCMC ();

	/** */
	void execCMP (OperandList &ops);

	/** */
	void execCMPS (OperandList &ops);

	/** */
	void execCWD (OperandList &ops);

	/** */
	void execDAA ();

	/** */
	void execDAS ();

	/** */
	void execDEC (OperandList &ops);

	/** */
	void execDIV ();

	/** */
	void execESC ();

	/** */
	void execHLT (OperandList &ops);

	/** */
	void execIDIV ();

	/** */
	void execIMUL ();

	/** */
	void execIN ();

	/** */
	void execINC (OperandList &ops);

	/** */
	void execINT ();

	/** */
	void execINTO ();

	/** */
	void execIRET ();

	/** */
	void execJNA (OperandList &ops);

	/** */
	void execJNAE (OperandList &ops);

	/** */
	void execJNB (OperandList &ops);

	/** */
	void execJNBE (OperandList &ops);

	/** */
	void execJC (OperandList &ops);

	/** */
	void execJCXZ (OperandList &ops);

	/** */
	void execJE (OperandList &ops);

	/** */
	void execJG (OperandList &ops);

	/** */
	void execJGE (OperandList &ops);

	/** */
	void execJL (OperandList &ops);

	/** */
	void execJLE (OperandList &ops);

	/** */
	void execJMP (OperandList &ops);

	/** */
	void execJMPFAR ();

	/** */
	void execJNC (OperandList &ops);

	/** */
	void execJNE (OperandList &ops);

	/** */
	void execJNO (OperandList &ops);

	/** */
	void execJNS (OperandList &ops);

	/** */
	void execJNP (OperandList &ops);

	/** */
	void execJO (OperandList &ops);

	/** */
	void execJPE (OperandList &ops);

	/** */
	void execJS (OperandList &ops);

	/** */
	void execLAHF (OperandList &ops);

	/** */
	void execLDS ();

	/** */
	void execLEA ();

	/** */
	void execLES ();

	/** */
	void execLOCK ();

	/** */
	void execLODS ();

	/** */
	void execLOOP ();

	/** */
	void execLOOPE ();

	/** */
	void execLOOPNE ();

	/** */
	void execMOV (OperandList &ops);

	/** */
	void execMOVS (OperandList &ops);

	/** */
	void execMUL ();

	/** */
	void execNEG ();

	/** */
	void execNOP (OperandList &ops);

	/** */
	void execNOT ();

	/** */
	void execOR (OperandList &ops);

	/** */
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
	void execRCL (OperandList &ops);

	/** */
	void execRCR (OperandList &ops);

	/** */
	void execREP ();

	/** */
	void execREPNE ();

	/** */
	void execRET ();

	/** */
	void execRETFAR ();

	/** */
	void execROL (OperandList &ops);

	/** */
	void execROR (OperandList &ops);

	/** */
	void execSAHF (OperandList &ops);

	/** */
	void execSHL ();

	/** */
	void execSAR ();

	/** */
	void execSBB (OperandList &ops);

	/** */
	void execSCAS ();

	/** */
	void execSEG (OperandList &ops);

	/** */
	void execSHR ();

	/** */
	void execSTC (OperandList &ops);

	/** */
	void execSTD (OperandList &ops);

	/** */
	void execSTI (OperandList &ops);

	/** */
	void execSTOS ();

	/** */
	void execSUB (OperandList &ops);

	/** */
	void execTEST ();

	/** */
	void execWAIT ();

	/** */
	void execXCHG (OperandList &ops);

	/** */
	void execXLAT ();

	/** */
	void execXOR (OperandList &ops);

}; //end class ExecutionUnit

#endif //JAF__EXECUTION_UNIT_HH

