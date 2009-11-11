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


#include "ExecutionUnit.hh"

#include "CpuComponents.hh"
#include "BusInterfaceUnit.hh"
#include "ArithmeticLogicUnit.hh"
#include "Instruction.hh"

#include "Defines.hh"
#include "OperandList.hh"
#include "NumberWrapper.hh"
#include "Utility.hh"

//#include "InstructionExecuter.hh"

#include <iostream>
//#include <cstdio>
#include <vector>


class ExecutionUnitPrivate {
public:
	unsigned short m_regs[Jaf::REG_COUNT_16];
	Register<unsigned char> m_regs8[Jaf::REG_COUNT_8];
	Register<unsigned short> m_regs16[Jaf::REG_COUNT_16];

	CpuComponents *m_cpu;
	BusInterfaceUnit *m_biu;
	ArithmeticLogicUnit *m_alu;
	Instruction *m_inst;

	sigc::signal<void, unsigned short, unsigned short, unsigned short> m_signal_stack_push;
	sigc::signal<void> m_signal_stack_pop;
};

/** */
ExecutionUnit::ExecutionUnit () {
	p = new ExecutionUnitPrivate ();

	unsigned char *m_a = (unsigned char*)&p->m_regs[Jaf::REG_AX];
	unsigned char *m_b = (unsigned char*)&p->m_regs[Jaf::REG_BX];
	unsigned char *m_c = (unsigned char*)&p->m_regs[Jaf::REG_CX];
	unsigned char *m_d = (unsigned char*)&p->m_regs[Jaf::REG_DX];

	p->m_regs8[Jaf::REG_AL].reinitialize (m_a[0]);
	p->m_regs8[Jaf::REG_AH].reinitialize (m_a[1]);
	p->m_regs8[Jaf::REG_BL].reinitialize (m_b[0]);
	p->m_regs8[Jaf::REG_BH].reinitialize (m_b[1]);
	p->m_regs8[Jaf::REG_CL].reinitialize (m_c[0]);
	p->m_regs8[Jaf::REG_CH].reinitialize (m_c[1]);
	p->m_regs8[Jaf::REG_DL].reinitialize (m_d[0]);
	p->m_regs8[Jaf::REG_DH].reinitialize (m_d[1]);

	p->m_regs16[Jaf::REG_AX].reinitialize (p->m_regs[Jaf::REG_AX]);
	p->m_regs16[Jaf::REG_BX].reinitialize (p->m_regs[Jaf::REG_BX]);
	p->m_regs16[Jaf::REG_CX].reinitialize (p->m_regs[Jaf::REG_CX]);
	p->m_regs16[Jaf::REG_DX].reinitialize (p->m_regs[Jaf::REG_DX]);
	p->m_regs16[Jaf::REG_DI].reinitialize (p->m_regs[Jaf::REG_DI]);
	p->m_regs16[Jaf::REG_SI].reinitialize (p->m_regs[Jaf::REG_SI]);
	p->m_regs16[Jaf::REG_BP].reinitialize (p->m_regs[Jaf::REG_BP]);
	p->m_regs16[Jaf::REG_SP].reinitialize (p->m_regs[Jaf::REG_SP]);
	p->m_regs16[Jaf::REG_FLAGS].reinitialize (p->m_regs[Jaf::REG_FLAGS]);

	//initialize registers values
	reset ();

	//connect 8-bit register signals to their 16-bit parents
	p->m_regs8[Jaf::REG_AL].signalEmitSignalValueChanged ().connect (sigc::mem_fun (p->m_regs16[Jaf::REG_AX], &Register<unsigned short>::emitSignalValueChanged));
	p->m_regs8[Jaf::REG_AH].signalEmitSignalValueChanged ().connect (sigc::mem_fun (p->m_regs16[Jaf::REG_AX], &Register<unsigned short>::emitSignalValueChanged));
	p->m_regs8[Jaf::REG_BL].signalEmitSignalValueChanged ().connect (sigc::mem_fun (p->m_regs16[Jaf::REG_BX], &Register<unsigned short>::emitSignalValueChanged));
	p->m_regs8[Jaf::REG_BH].signalEmitSignalValueChanged ().connect (sigc::mem_fun (p->m_regs16[Jaf::REG_BX], &Register<unsigned short>::emitSignalValueChanged));
	p->m_regs8[Jaf::REG_CL].signalEmitSignalValueChanged ().connect (sigc::mem_fun (p->m_regs16[Jaf::REG_CX], &Register<unsigned short>::emitSignalValueChanged));
	p->m_regs8[Jaf::REG_CH].signalEmitSignalValueChanged ().connect (sigc::mem_fun (p->m_regs16[Jaf::REG_CX], &Register<unsigned short>::emitSignalValueChanged));
	p->m_regs8[Jaf::REG_DL].signalEmitSignalValueChanged ().connect (sigc::mem_fun (p->m_regs16[Jaf::REG_DX], &Register<unsigned short>::emitSignalValueChanged));
	p->m_regs8[Jaf::REG_DH].signalEmitSignalValueChanged ().connect (sigc::mem_fun (p->m_regs16[Jaf::REG_DX], &Register<unsigned short>::emitSignalValueChanged));
}

ExecutionUnit::~ExecutionUnit () {
	delete p;
}

void
ExecutionUnit::connectTo (CpuComponents &cpu) {
	p->m_cpu = &cpu;
	p->m_biu = &cpu.getBusInterfaceUnit ();
	p->m_alu = &cpu.getArithmeticLogicUnit ();
	p->m_inst = &cpu.getInstruction ();
}

sigc::signal<void, unsigned short, unsigned short, unsigned short>&
ExecutionUnit::signalStackPush () {
	return p->m_signal_stack_push;
}

sigc::signal<void>&
ExecutionUnit::signalStackPop () {
	return p->m_signal_stack_pop;
}

void
ExecutionUnit::reset () {
	resetRegFlags ();
}

Register<unsigned char>&
ExecutionUnit::getReg8 (size_t index) {
	return p->m_regs8[index]; //FIXME - no bounds checking
}

void
ExecutionUnit::setReg8 (size_t index, unsigned char val) {
	p->m_regs8[index] = val; //FIXME - no bounds checking
}

Register<unsigned short>&
ExecutionUnit::getReg16 (size_t index) {
	return p->m_regs16[index]; //FIXME - no bounds checking
}

void
ExecutionUnit::setReg16 (size_t index, unsigned short val) {
	p->m_regs16[index] = val; //FIXME - no bounds checking
}

Register<unsigned short>&
ExecutionUnit::getRegAX () {
	return p->m_regs16[Jaf::REG_AX];
}

void
ExecutionUnit::setRegAX (unsigned short val) {
	p->m_regs16[Jaf::REG_AX] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegAH () {
	return p->m_regs8[Jaf::REG_AH];
}

void
ExecutionUnit::setRegAH (unsigned char val) {
	p->m_regs8[Jaf::REG_AH] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegAL () {
	return p->m_regs8[Jaf::REG_AL];
}

void
ExecutionUnit::setRegAL (unsigned char val) {
	p->m_regs8[Jaf::REG_AL] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegBX () {
	return p->m_regs16[Jaf::REG_BX];
}

void
ExecutionUnit::setRegBX (unsigned short val) {
	p->m_regs16[Jaf::REG_BX] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegBH () {
	return p->m_regs8[Jaf::REG_BH];
}

void
ExecutionUnit::setRegBH (unsigned char val) {
	p->m_regs8[Jaf::REG_BH] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegBL () {
	return p->m_regs8[Jaf::REG_BL];
}

void
ExecutionUnit::setRegBL (unsigned char val) {
	p->m_regs8[Jaf::REG_BL] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegCX () {
	return p->m_regs16[Jaf::REG_CX];
}

void
ExecutionUnit::setRegCX (unsigned short val) {
	p->m_regs16[Jaf::REG_CX] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegCH () {
	return p->m_regs8[Jaf::REG_CH];
}

void
ExecutionUnit::setRegCH (unsigned char val) {
	p->m_regs8[Jaf::REG_CH] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegCL () {
	return p->m_regs8[Jaf::REG_CL];
}

void
ExecutionUnit::setRegCL (unsigned char val) {
	p->m_regs8[Jaf::REG_CL] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegDX () {
	return p->m_regs16[Jaf::REG_DX];
}

void
ExecutionUnit::setRegDX (unsigned short val) {
	p->m_regs16[Jaf::REG_DX] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegDH () {
	return p->m_regs8[Jaf::REG_DH];
}

void
ExecutionUnit::setRegDH (unsigned char val) {
	p->m_regs8[Jaf::REG_DH] = val;
}

Register<unsigned char>&
ExecutionUnit::getRegDL () {
	return p->m_regs8[Jaf::REG_DL];
}

void
ExecutionUnit::setRegDL (unsigned char val) {
	p->m_regs8[Jaf::REG_DL] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegDI () {
	return p->m_regs16[Jaf::REG_DI];
}

void
ExecutionUnit::setRegDI (unsigned short val) {
	p->m_regs16[Jaf::REG_DI] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegSI () {
	return p->m_regs16[Jaf::REG_SI];
}

void
ExecutionUnit::setRegSI (unsigned short val) {
	p->m_regs16[Jaf::REG_SI] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegBP () {
	return p->m_regs16[Jaf::REG_BP];
}

void
ExecutionUnit::setRegBP (unsigned short val) {
	p->m_regs16[Jaf::REG_BP] = val;
}

Register<unsigned short>&
ExecutionUnit::getRegSP () {
	return p->m_regs16[Jaf::REG_SP];
}

void
ExecutionUnit::setRegSP (unsigned short val) {
	p->m_regs16[Jaf::REG_SP] = val;
}

void
ExecutionUnit::resetRegFlags (unsigned short val) {
	setRegFlags (val);
}

Register<unsigned short>&
ExecutionUnit::getRegFlags () {
	return p->m_regs16[Jaf::REG_FLAGS];
}

void
ExecutionUnit::setRegFlags (unsigned short val) {
	p->m_regs16[Jaf::REG_FLAGS] = val;
}

bool
ExecutionUnit::getRegFlagsAF () const {
	return Utility::getBit (p->m_regs16[Jaf::REG_FLAGS], 4);
}

void
ExecutionUnit::setRegFlagsAF (bool val) {
	if (val) {
		Utility::setBit (p->m_regs16[Jaf::REG_FLAGS], 4);
	}
	else {
		Utility::clearBit (p->m_regs16[Jaf::REG_FLAGS], 4);
	}
}

bool
ExecutionUnit::getRegFlagsCF () const {
	return Utility::getBit (p->m_regs16[Jaf::REG_FLAGS], 0);
}

void
ExecutionUnit::setRegFlagsCF (bool val) {
	if (val) {
		Utility::setBit (p->m_regs16[Jaf::REG_FLAGS], 0);
	}
	else {
		Utility::clearBit (p->m_regs16[Jaf::REG_FLAGS], 0);
	}
}

bool
ExecutionUnit::getRegFlagsDF () const {
	return Utility::getBit (p->m_regs16[Jaf::REG_FLAGS], 10);
}

void
ExecutionUnit::setRegFlagsDF (bool val) {
	if (val) {
		Utility::setBit (p->m_regs16[Jaf::REG_FLAGS], 10);
	}
	else {
		Utility::clearBit (p->m_regs16[Jaf::REG_FLAGS], 10);
	}
}

bool
ExecutionUnit::getRegFlagsIF () const {
	return Utility::getBit (p->m_regs16[Jaf::REG_FLAGS], 9);
}

void
ExecutionUnit::setRegFlagsIF (bool val) {
	if (val) {
		Utility::setBit (p->m_regs16[Jaf::REG_FLAGS], 9);
	}
	else {
		Utility::clearBit (p->m_regs16[Jaf::REG_FLAGS], 9);
	}
}

bool
ExecutionUnit::getRegFlagsOF () const {
	return Utility::getBit (p->m_regs16[Jaf::REG_FLAGS], 11);
}

void
ExecutionUnit::setRegFlagsOF (bool val) {
	if (val) {
		Utility::setBit (p->m_regs16[Jaf::REG_FLAGS], 11);
	}
	else {
		Utility::clearBit (p->m_regs16[Jaf::REG_FLAGS], 11);
	}
}

bool
ExecutionUnit::getRegFlagsPF () const {
	return Utility::getBit (p->m_regs16[Jaf::REG_FLAGS], 2);
}

void
ExecutionUnit::setRegFlagsPF (bool val) {
	if (val) {
		Utility::setBit (p->m_regs16[Jaf::REG_FLAGS], 2);
	}
	else {
		Utility::clearBit (p->m_regs16[Jaf::REG_FLAGS], 2);
	}
}

bool
ExecutionUnit::getRegFlagsSF () const {
	return Utility::getBit (p->m_regs16[Jaf::REG_FLAGS], 7);
}

void
ExecutionUnit::setRegFlagsSF (bool val) {
	if (val) {
		Utility::setBit (p->m_regs16[Jaf::REG_FLAGS], 7);
	}
	else {
		Utility::clearBit (p->m_regs16[Jaf::REG_FLAGS], 7);
	}
}

bool
ExecutionUnit::getRegFlagsTF () const {
	return Utility::getBit (p->m_regs16[Jaf::REG_FLAGS], 8);
}

void
ExecutionUnit::setRegFlagsTF (bool val) {
	if (val) {
		Utility::setBit (p->m_regs16[Jaf::REG_FLAGS], 8);
	}
	else {
		Utility::clearBit (p->m_regs16[Jaf::REG_FLAGS], 8);
	}
}

bool
ExecutionUnit::getRegFlagsZF () const {
	return Utility::getBit (p->m_regs16[Jaf::REG_FLAGS], 6);
}

void
ExecutionUnit::setRegFlagsZF (bool val) {
	if (val) {
		Utility::setBit (p->m_regs16[Jaf::REG_FLAGS], 6);
	}
	else {
		Utility::clearBit (p->m_regs16[Jaf::REG_FLAGS], 6);
	}
}

void
ExecutionUnit::execNotImplemented () {
	std::cerr << "execNotImplemented (): this instruction is not implemented or doesn't exist" << std::endl;
}

void
ExecutionUnit::execADC () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		unsigned short ret;
		p->m_alu->opAdc (ops.dest ().get<unsigned short> (), ops.src ().get<unsigned short> (), ret);
		ops.dest ().get<unsigned short> () = ret;
	}
	else {
		unsigned char ret;
		p->m_alu->opAdc (ops.dest ().get<unsigned char> (), ops.src ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned char> () = ret;
	}
}

void
ExecutionUnit::execADD () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		unsigned short ret;
		p->m_alu->opAdd (ops.dest ().get<unsigned short> (), ops.src ().get<unsigned short> (), ret);
		ops.dest ().get<unsigned short> () = ret;
	}
	else {
		unsigned char ret;
		p->m_alu->opAdd (ops.dest ().get<unsigned char> (), ops.src ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned char> () = ret;
	}
}

void
ExecutionUnit::execAND () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		unsigned short ret;
		p->m_alu->opAnd (ops.dest ().get<unsigned short> (), ops.src ().get<unsigned short> (), ret);
		ops.dest ().get<unsigned short> () = ret;
	}
	else {
		unsigned char ret;
		p->m_alu->opAnd (ops.dest ().get<unsigned char> (), ops.src ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned char> () = ret;
	}
}

void
ExecutionUnit::execCBW () {
	if (getRegAL () < 0x80) {
		setRegAH (0);
	}
	else {
		setRegAH (0xFF);
	}
}

void
ExecutionUnit::execCLC () {
	setRegFlagsCF (false);
}

void
ExecutionUnit::execCLD () {
	setRegFlagsDF (false);
}

void
ExecutionUnit::execCLI () {
	setRegFlagsIF (false);
}

void
ExecutionUnit::execCMC () {
	p->m_alu->opCmc ();
}

void
ExecutionUnit::execCMP () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		p->m_alu->opCmp (ops.dest ().get<unsigned short> (), ops.src ().get<unsigned short> ());
	}
	else {
		p->m_alu->opCmp (ops.dest ().get<unsigned char> (), ops.src ().get<unsigned char> ());
	}
}

void
ExecutionUnit::execCMPS () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		p->m_alu->opCmp (ops.dest ().get<unsigned short> (), ops.src ().get<unsigned short> ());
	}
	else {
		p->m_alu->opCmp (ops.dest ().get<unsigned char> (), ops.src ().get<unsigned char> ());
	}

	if (getRegFlagsDF ()) {
		getRegSI () -= ops.src ().size ();
		getRegDI () -= ops.dest ().size ();
	}
	else {
		getRegSI () += ops.src ().size ();
		getRegDI () += ops.dest ().size ();
	}
}

void
ExecutionUnit::execCWD () {
	if (getRegAX () < 0x8000) {
		setRegDX (0);
	}
	else {
		setRegDX (0xFFFF);
	}
}

void
ExecutionUnit::execDEC () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		unsigned short ret;
		p->m_alu->opDec (ops.dest ().get<unsigned short> (), ret);
		ops.dest ().get<unsigned short> () = ret;
	}
	else {
		unsigned char ret;
		p->m_alu->opDec (ops.dest ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned char> () = ret;
	}
}

void
ExecutionUnit::execDIV () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		p->m_alu->opDiv (ops.dest ().get<unsigned short> ());
	}
	else {
		p->m_alu->opDiv (ops.dest ().get<unsigned char> ());
	}
}

void
ExecutionUnit::execHLT () {
	p->m_cpu->setHalt (true);
}

void
ExecutionUnit::execINC () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		unsigned short ret;
		p->m_alu->opInc (ops.dest ().get<unsigned short> (), ret);
		ops.dest ().get<unsigned short> () = ret;
	}
	else {
		unsigned char ret;
		p->m_alu->opInc (ops.dest ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned char> () = ret;
	}
}

void
ExecutionUnit::execJMP () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		p->m_biu->getRegIP () += ops.dest ().get<short> ();
	}
	else {
		p->m_biu->getRegIP () += ops.dest ().get<char> ();
	}
}

void
ExecutionUnit::execJNA () {
	if (getRegFlagsCF () != true && getRegFlagsZF () != true) {
		return;
	}

	execJMP ();
}

void
ExecutionUnit::execJNAE () {
	if (getRegFlagsCF () != true) {
		return;
	}

	execJMP ();
}

void
ExecutionUnit::execJNB () {
	if (getRegFlagsCF () != false) {
		return;
	}

	execJMP ();
}

void
ExecutionUnit::execJNBE () {
	if (getRegFlagsCF () != false && getRegFlagsZF () != false) {
		return;
	}

	execJMP ();
}

void
ExecutionUnit::execJC () {
	if (getRegFlagsCF () != true) {
		return;
	}

	execJMP ();
}

void
ExecutionUnit::execJCXZ () {
	if (getRegFlagsCF () != false) {
		return;
	}

	execJMP ();
}

void
ExecutionUnit::execJE () {
	if (getRegFlagsZF () == false) {
		return;
	}

	execJMP ();
}

void
ExecutionUnit::execJG () {
	if (getRegFlagsSF () != getRegFlagsOF () || getRegFlagsZF () != false) {
		return;
	}

	execJMP ();
}

void
ExecutionUnit::execJGE () {
	if (getRegFlagsSF () != getRegFlagsOF ()) {
		return;
	}

	execJMP ();
}

void
ExecutionUnit::execJL () {
	if (getRegFlagsSF () == getRegFlagsOF ()) {
		return;
	}

	execJMP ();
}

void
ExecutionUnit::execJLE () {
	if (getRegFlagsSF () == getRegFlagsOF () && getRegFlagsZF () != true) {
		return;
	}

	execJMP ();
}

void
ExecutionUnit::execJNC () {
	if (getRegFlagsCF () == false) {
		return;
	}

	execJMP ();
}

void
ExecutionUnit::execJNE () {
	if (getRegFlagsZF () == true) {
		return;
	}

	execJMP ();
}

void
ExecutionUnit::execJNO () {
	if (getRegFlagsOF () != false) {
		return;
	}

	execJMP ();
}

void
ExecutionUnit::execJNS () {
	if (getRegFlagsSF () != false) {
		return;
	}

	execJMP ();
}

void
ExecutionUnit::execJNP () {
	if (getRegFlagsPF () != false) {
		return;
	}

	execJMP ();
}

void
ExecutionUnit::execJO () {
	if (getRegFlagsOF () != true) {
		return;
	}

	execJMP ();
}

void
ExecutionUnit::execJPE () {
	if (getRegFlagsPF () != true) {
		return;
	}

	execJMP ();
}

void
ExecutionUnit::execJS () {
	if (getRegFlagsSF () != true) {
		return;
	}

	execJMP ();
}

void
ExecutionUnit::execLAHF () {
	//FIXME - make sure this works for high byte of flags
	unsigned short f = getRegFlags ();
	f &= 0xFFD7;
	f |= 0x0002;
	setRegAH (f);
}

void
ExecutionUnit::execLEA () {
	OperandList &ops = p->m_inst->operands ();

	ops.dest ().get<unsigned short> () = ops.src ().get<unsigned short> ().getOffset ();
}

void
ExecutionUnit::execLOOP () {
	OperandList &ops = p->m_inst->operands ();

	getRegCX () -= 1;

	if (getRegCX () ==0) {
		return;
	}

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		p->m_biu->getRegIP () += ops.dest ().get<short> ();
	}
	else {
		p->m_biu->getRegIP () += ops.dest ().get<char> ();
	}
}

void
ExecutionUnit::execLOOPE () {
	if (getRegFlagsZF () != true) {
		return;
	}

	execLOOP ();
}

void
ExecutionUnit::execLOOPNE () {
	if (getRegFlagsZF () != false) {
		return;
	}

	execLOOP ();
}

void
ExecutionUnit::execMOV () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		ops.dest ().get<unsigned short> () = ops.src ().get<unsigned short> ();
	}
	else {
		ops.dest ().get<unsigned char> () = ops.src ().get<unsigned char> ();
	}
}

void
ExecutionUnit::execMOVS () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		ops.dest ().get<unsigned short> () = ops.src ().get<unsigned short> ();
	}
	else {
		ops.dest ().get<unsigned char> () = ops.src ().get<unsigned char> ();
	}

	if (getRegFlagsDF ()) {
		getRegSI () -= ops.src ().size ();
		getRegDI () -= ops.dest ().size ();
	}
	else {
		getRegSI () += ops.src ().size ();
		getRegDI () += ops.dest ().size ();
	}
}

void
ExecutionUnit::execMUL () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		p->m_alu->opMul (ops.dest ().get<unsigned short> ());
	}
	else {
		p->m_alu->opMul (ops.dest ().get<unsigned char> ());
	}
}

void
ExecutionUnit::execNEG () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		unsigned short ret;
		p->m_alu->opNeg (ops.dest ().get<unsigned short> (), ret);
		ops.dest ().get<unsigned short> () = ret;
	}
	else {
		unsigned char ret;
		p->m_alu->opNeg (ops.dest ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned char> () = ret;
	}
}

void
ExecutionUnit::execNOP () {
	//does nothing
}

void
ExecutionUnit::execNOT () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		ops.dest ().get<unsigned short> () = 0xFF - ops.dest ().get<unsigned short> ();
	}
	else {
		ops.dest ().get<unsigned char> () = 0xFFFF - ops.dest ().get<unsigned char> ();
	}
}

void
ExecutionUnit::execOR () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		unsigned short ret;
		p->m_alu->opOr (ops.dest ().get<unsigned short> (), ops.src ().get<unsigned short> (), ret);
		ops.dest ().get<unsigned short> () = ret;
	}
	else {
		unsigned char ret;
		p->m_alu->opOr (ops.dest ().get<unsigned char> (), ops.src ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned char> () = ret;
	}
}

void
ExecutionUnit::execPOP () {
	OperandList &ops = p->m_inst->operands ();

	realPop ( (!ops.src ().isNull () ? ops.src () : ops.dest ()).get<unsigned short> () );
}

void
ExecutionUnit::execPOPF () {
	realPop ( getRegFlags () );
}

void
ExecutionUnit::execPUSH () {
	OperandList &ops = p->m_inst->operands ();

	realPush ( (!ops.src ().isNull () ? ops.src () : ops.dest ()).get<unsigned short> () );
}

void
ExecutionUnit::execPUSHF () {
	realPush ( getRegFlags () );
}

void
ExecutionUnit::execRCL () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		unsigned short ret;
		p->m_alu->opRcl (ops.dest ().get<unsigned short> (), ops.src ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned short> () = ret;
	}
	else {
		unsigned char ret;
		p->m_alu->opRcl (ops.dest ().get<unsigned char> (), ops.src ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned char> () = ret;
	}
}

void
ExecutionUnit::execRCR () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		unsigned short ret;
		p->m_alu->opRcr (ops.dest ().get<unsigned short> (), ops.src ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned short> () = ret;
	}
	else {
		unsigned char ret;
		p->m_alu->opRcr (ops.dest ().get<unsigned char> (), ops.src ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned char> () = ret;
	}
}

void
ExecutionUnit::execROL () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		unsigned short ret;
		p->m_alu->opRol (ops.dest ().get<unsigned short> (), ops.src ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned short> () = ret;
	}
	else {
		unsigned char ret;
		p->m_alu->opRol (ops.dest ().get<unsigned char> (), ops.src ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned char> () = ret;
	}
}

void
ExecutionUnit::execROR () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		unsigned short ret;
		p->m_alu->opRor (ops.dest ().get<unsigned short> (), ops.src ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned short> () = ret;
	}
	else {
		unsigned char ret;
		p->m_alu->opRor (ops.dest ().get<unsigned char> (), ops.src ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned char> () = ret;
	}
}

void
ExecutionUnit::execSAHF () {
	//FIXME - make sure this works for high byte of flags
	unsigned short f = getRegFlags ();
	f &= (0xFF00 + getRegAH ());
	f &= 0xFFD7;
	f |= 0x0002;
	setRegFlags (f);
}

void
ExecutionUnit::execSAR () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		unsigned short ret;
		p->m_alu->opSar (ops.dest ().get<unsigned short> (), ops.src ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned short> () = ret;
	}
	else {
		unsigned char ret;
		p->m_alu->opSar (ops.dest ().get<unsigned char> (), ops.src ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned char> () = ret;
	}
}

void
ExecutionUnit::execSBB () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		unsigned short ret;
		p->m_alu->opSbb (ops.dest ().get<unsigned short> (), ops.src ().get<unsigned short> (), ret);
		ops.dest ().get<unsigned short> () = ret;
	}
	else {
		unsigned char ret;
		p->m_alu->opSbb (ops.dest ().get<unsigned char> (), ops.src ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned char> () = ret;
	}
}

void
ExecutionUnit::execSHL () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		unsigned short ret;
		p->m_alu->opShl (ops.dest ().get<unsigned short> (), ops.src ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned short> () = ret;
	}
	else {
		unsigned char ret;
		p->m_alu->opShl (ops.dest ().get<unsigned char> (), ops.src ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned char> () = ret;
	}
}

void
ExecutionUnit::execSHR () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		unsigned short ret;
		p->m_alu->opShr (ops.dest ().get<unsigned short> (), ops.src ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned short> () = ret;
	}
	else {
		unsigned char ret;
		p->m_alu->opShr (ops.dest ().get<unsigned char> (), ops.src ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned char> () = ret;
	}
}

void
ExecutionUnit::execSEG () {
	OperandList &ops = p->m_inst->operands ();

	p->m_biu->setSegOverride (ops.dest ().get<unsigned short> ());
}

void
ExecutionUnit::execSUB () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		unsigned short ret;
		p->m_alu->opSub (ops.dest ().get<unsigned short> (), ops.src ().get<unsigned short> (), ret);
		ops.dest ().get<unsigned short> () = ret;
	}
	else {
		unsigned char ret;
		p->m_alu->opSub (ops.dest ().get<unsigned char> (), ops.src ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned char> () = ret;
	}
}

void
ExecutionUnit::execSTC () {
	setRegFlagsCF (true);
}

void
ExecutionUnit::execSTD () {
	setRegFlagsDF (true);
}

void
ExecutionUnit::execSTI () {
	setRegFlagsIF (true);
}

void
ExecutionUnit::execTEST () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		p->m_alu->opTest (ops.dest ().get<unsigned short> (), ops.src ().get<unsigned short> ());
	}
	else {
		p->m_alu->opTest (ops.dest ().get<unsigned char> (), ops.src ().get<unsigned char> ());
	}
}

void
ExecutionUnit::execXCHG () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		unsigned short tmp = ops.dest ().get<unsigned short> ();
		ops.dest ().get<unsigned short> () = ops.src ().get<unsigned short> ();
		ops.src ().get<unsigned short> () = tmp;
	}
	else {
		unsigned char tmp = ops.dest ().get<unsigned char> ();
		ops.dest ().get<unsigned char> () = ops.src ().get<unsigned char> ();
		ops.src ().get<unsigned char> () = tmp;
	}
}

void
ExecutionUnit::execXOR () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		unsigned short ret;
		p->m_alu->opXor (ops.dest ().get<unsigned short> (), ops.src ().get<unsigned short> (), ret);
		ops.dest ().get<unsigned short> () = ret;
	}
	else {
		unsigned char ret;
		p->m_alu->opXor (ops.dest ().get<unsigned char> (), ops.src ().get<unsigned char> (), ret);
		ops.dest ().get<unsigned char> () = ret;
	}
}

void
ExecutionUnit::realPush (unsigned short num) {
	getRegSP () -= sizeof(unsigned short);
	NumberWrapper mem;
	mem.init<unsigned short> (p->m_biu->getMemoryAddress<unsigned short> (p->m_biu->getSegRegSS (), getRegSP ()), true);
	mem.get<unsigned short> () = num;

	p->m_signal_stack_push.emit (p->m_biu->getSegRegSS (), getRegSP (), num);
}

void
ExecutionUnit::realPop () {
	getRegSP () += sizeof(unsigned short);

	p->m_signal_stack_pop.emit ();
}

void
ExecutionUnit::realPop (INumberReadableWritable<unsigned short> &num) {
	NumberWrapper mem;
	mem.init<unsigned short> (p->m_biu->getMemoryAddress<unsigned short> (p->m_biu->getSegRegSS (), getRegSP ()), true);
	num = mem.get<unsigned short> ();
	getRegSP () += sizeof(unsigned short);

	p->m_signal_stack_pop.emit ();
}

