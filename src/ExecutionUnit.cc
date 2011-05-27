/*
 * emucpu -- Emulates processors
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
#include "IOPorts.hh"

#include "Defines.hh"
#include "OperandList.hh"
#include "NumberWrapper.hh"
#include "Utility.hh"

#include "Immediate.hh"

//#include "InstructionExecuter.hh"

#include <iostream>
//#include <cstdio>
#include <vector>

class ExecutionUnitPrivate {
public:
	quint16 m_regs[Jaf::REG_COUNT_16];
	Register<quint8> m_regs8[Jaf::REG_COUNT_8];
	Register<quint16> m_regs16[Jaf::REG_COUNT_16];

	CpuComponents *m_cpu;
	BusInterfaceUnit *m_biu;
	ArithmeticLogicUnit *m_alu;
	Instruction *m_inst;
	IOPorts *m_io_ports;

	sigc::signal<void, quint16, quint16, quint16> m_signal_stack_push;
	sigc::signal<void> m_signal_stack_pop;
};

/** */
ExecutionUnit::ExecutionUnit () {
	p = new ExecutionUnitPrivate ();

	quint8 *m_a = (quint8*)&p->m_regs[Jaf::REG_AX];
	quint8 *m_b = (quint8*)&p->m_regs[Jaf::REG_BX];
	quint8 *m_c = (quint8*)&p->m_regs[Jaf::REG_CX];
	quint8 *m_d = (quint8*)&p->m_regs[Jaf::REG_DX];

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
	p->m_regs8[Jaf::REG_AL].signalEmitSignalValueChanged ().connect (sigc::mem_fun (p->m_regs16[Jaf::REG_AX], &Register<quint16>::emitSignalValueChanged));
	p->m_regs8[Jaf::REG_AH].signalEmitSignalValueChanged ().connect (sigc::mem_fun (p->m_regs16[Jaf::REG_AX], &Register<quint16>::emitSignalValueChanged));
	p->m_regs8[Jaf::REG_BL].signalEmitSignalValueChanged ().connect (sigc::mem_fun (p->m_regs16[Jaf::REG_BX], &Register<quint16>::emitSignalValueChanged));
	p->m_regs8[Jaf::REG_BH].signalEmitSignalValueChanged ().connect (sigc::mem_fun (p->m_regs16[Jaf::REG_BX], &Register<quint16>::emitSignalValueChanged));
	p->m_regs8[Jaf::REG_CL].signalEmitSignalValueChanged ().connect (sigc::mem_fun (p->m_regs16[Jaf::REG_CX], &Register<quint16>::emitSignalValueChanged));
	p->m_regs8[Jaf::REG_CH].signalEmitSignalValueChanged ().connect (sigc::mem_fun (p->m_regs16[Jaf::REG_CX], &Register<quint16>::emitSignalValueChanged));
	p->m_regs8[Jaf::REG_DL].signalEmitSignalValueChanged ().connect (sigc::mem_fun (p->m_regs16[Jaf::REG_DX], &Register<quint16>::emitSignalValueChanged));
	p->m_regs8[Jaf::REG_DH].signalEmitSignalValueChanged ().connect (sigc::mem_fun (p->m_regs16[Jaf::REG_DX], &Register<quint16>::emitSignalValueChanged));
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
	p->m_io_ports = &cpu.getIOPorts ();
}

sigc::signal<void, quint16, quint16, quint16>&
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

Register<quint8>&
ExecutionUnit::getReg8 (size_t index) {
	return p->m_regs8[index]; //FIXME - no bounds checking
}

void
ExecutionUnit::setReg8 (size_t index, quint8 val) {
	p->m_regs8[index] = val; //FIXME - no bounds checking
}

Register<quint16>&
ExecutionUnit::getReg16 (size_t index) {
	return p->m_regs16[index]; //FIXME - no bounds checking
}

void
ExecutionUnit::setReg16 (size_t index, quint16 val) {
	p->m_regs16[index] = val; //FIXME - no bounds checking
}

Register<quint16>&
ExecutionUnit::getRegAX () {
	return p->m_regs16[Jaf::REG_AX];
}

void
ExecutionUnit::setRegAX (quint16 val) {
	p->m_regs16[Jaf::REG_AX] = val;
}

Register<quint8>&
ExecutionUnit::getRegAH () {
	return p->m_regs8[Jaf::REG_AH];
}

void
ExecutionUnit::setRegAH (quint8 val) {
	p->m_regs8[Jaf::REG_AH] = val;
}

Register<quint8>&
ExecutionUnit::getRegAL () {
	return p->m_regs8[Jaf::REG_AL];
}

void
ExecutionUnit::setRegAL (quint8 val) {
	p->m_regs8[Jaf::REG_AL] = val;
}

Register<quint16>&
ExecutionUnit::getRegBX () {
	return p->m_regs16[Jaf::REG_BX];
}

void
ExecutionUnit::setRegBX (quint16 val) {
	p->m_regs16[Jaf::REG_BX] = val;
}

Register<quint8>&
ExecutionUnit::getRegBH () {
	return p->m_regs8[Jaf::REG_BH];
}

void
ExecutionUnit::setRegBH (quint8 val) {
	p->m_regs8[Jaf::REG_BH] = val;
}

Register<quint8>&
ExecutionUnit::getRegBL () {
	return p->m_regs8[Jaf::REG_BL];
}

void
ExecutionUnit::setRegBL (quint8 val) {
	p->m_regs8[Jaf::REG_BL] = val;
}

Register<quint16>&
ExecutionUnit::getRegCX () {
	return p->m_regs16[Jaf::REG_CX];
}

void
ExecutionUnit::setRegCX (quint16 val) {
	p->m_regs16[Jaf::REG_CX] = val;
}

Register<quint8>&
ExecutionUnit::getRegCH () {
	return p->m_regs8[Jaf::REG_CH];
}

void
ExecutionUnit::setRegCH (quint8 val) {
	p->m_regs8[Jaf::REG_CH] = val;
}

Register<quint8>&
ExecutionUnit::getRegCL () {
	return p->m_regs8[Jaf::REG_CL];
}

void
ExecutionUnit::setRegCL (quint8 val) {
	p->m_regs8[Jaf::REG_CL] = val;
}

Register<quint16>&
ExecutionUnit::getRegDX () {
	return p->m_regs16[Jaf::REG_DX];
}

void
ExecutionUnit::setRegDX (quint16 val) {
	p->m_regs16[Jaf::REG_DX] = val;
}

Register<quint8>&
ExecutionUnit::getRegDH () {
	return p->m_regs8[Jaf::REG_DH];
}

void
ExecutionUnit::setRegDH (quint8 val) {
	p->m_regs8[Jaf::REG_DH] = val;
}

Register<quint8>&
ExecutionUnit::getRegDL () {
	return p->m_regs8[Jaf::REG_DL];
}

void
ExecutionUnit::setRegDL (quint8 val) {
	p->m_regs8[Jaf::REG_DL] = val;
}

Register<quint16>&
ExecutionUnit::getRegDI () {
	return p->m_regs16[Jaf::REG_DI];
}

void
ExecutionUnit::setRegDI (quint16 val) {
	p->m_regs16[Jaf::REG_DI] = val;
}

Register<quint16>&
ExecutionUnit::getRegSI () {
	return p->m_regs16[Jaf::REG_SI];
}

void
ExecutionUnit::setRegSI (quint16 val) {
	p->m_regs16[Jaf::REG_SI] = val;
}

Register<quint16>&
ExecutionUnit::getRegBP () {
	return p->m_regs16[Jaf::REG_BP];
}

void
ExecutionUnit::setRegBP (quint16 val) {
	p->m_regs16[Jaf::REG_BP] = val;
}

Register<quint16>&
ExecutionUnit::getRegSP () {
	return p->m_regs16[Jaf::REG_SP];
}

void
ExecutionUnit::setRegSP (quint16 val) {
	p->m_regs16[Jaf::REG_SP] = val;
}

void
ExecutionUnit::resetRegFlags (quint16 val) {
	setRegFlags (val);
}

Register<quint16>&
ExecutionUnit::getRegFlags () {
	return p->m_regs16[Jaf::REG_FLAGS];
}

void
ExecutionUnit::setRegFlags (quint16 val) {
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
		quint16 ret;
		p->m_alu->opAdc (ops.dest ().get<quint16> (), ops.src ().get<quint16> (), ret);
		ops.dest ().get<quint16> () = ret;
	}
	else {
		quint8 ret;
		p->m_alu->opAdc (ops.dest ().get<quint8> (), ops.src ().get<quint8> (), ret);
		ops.dest ().get<quint8> () = ret;
	}
}

void
ExecutionUnit::execADD () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		quint16 ret;
		p->m_alu->opAdd (ops.dest ().get<quint16> (), ops.src ().get<quint16> (), ret);
		ops.dest ().get<quint16> () = ret;
	}
	else {
		quint8 ret;
		p->m_alu->opAdd (ops.dest ().get<quint8> (), ops.src ().get<quint8> (), ret);
		ops.dest ().get<quint8> () = ret;
	}
}

void
ExecutionUnit::execAND () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		quint16 ret;
		p->m_alu->opAnd (ops.dest ().get<quint16> (), ops.src ().get<quint16> (), ret);
		ops.dest ().get<quint16> () = ret;
	}
	else {
		quint8 ret;
		p->m_alu->opAnd (ops.dest ().get<quint8> (), ops.src ().get<quint8> (), ret);
		ops.dest ().get<quint8> () = ret;
	}
}

void
ExecutionUnit::execCALL () {
	realPush (p->m_biu->getRegIP ());
	execJMPSHORT ();
}

void
ExecutionUnit::execCALLFAR () {
	realPush (p->m_biu->getSegRegCS ());
	realPush (p->m_biu->getRegIP ());
	execJMPFAR ();
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
		p->m_alu->opCmp (ops.dest ().get<quint16> (), ops.src ().get<quint16> ());
	}
	else {
		p->m_alu->opCmp (ops.dest ().get<quint8> (), ops.src ().get<quint8> ());
	}
}

void
ExecutionUnit::execCMPS () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		p->m_alu->opCmp (ops.dest ().get<quint16> (), ops.src ().get<quint16> ());
	}
	else {
		p->m_alu->opCmp (ops.dest ().get<quint8> (), ops.src ().get<quint8> ());
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
		quint16 ret;
		p->m_alu->opDec (ops.dest ().get<quint16> (), ret);
		ops.dest ().get<quint16> () = ret;
	}
	else {
		quint8 ret;
		p->m_alu->opDec (ops.dest ().get<quint8> (), ret);
		ops.dest ().get<quint8> () = ret;
	}
}

void
ExecutionUnit::execDIV () {
	OperandList &ops = p->m_inst->operands ();

	bool inter;
	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		inter = p->m_alu->opDiv (ops.dest ().get<quint16> ());
	}
	else {
		inter = p->m_alu->opDiv (ops.dest ().get<quint8> ());
	}

	if (!inter) {
		ops.src ().free ();
		ops.src ().init<quint8> (new Immediate<quint8> (0), true);
		execINT ();
	}
}

void
ExecutionUnit::execHLT () {
	p->m_cpu->setHalt (true);
}

void
ExecutionUnit::execIN () {
	OperandList &ops = p->m_inst->operands ();

	quint16 port = ops.src ().get<quint16> ();
	if (port != 1 || ops.operandSize () != Jaf::OP_SIZE_8) {
		return;
	}

	while (p->m_io_ports->charInputQueue ().empty () && !p->m_cpu->getHalt ()) {
		//FIXME this is very ineffecient
	}

	if (p->m_cpu->getHalt () && p->m_io_ports->charInputQueue ().empty ()) {
		return;
	}

	ops.dest ().get<quint8> () =  p->m_io_ports->charInputQueue ().front ();
	p->m_io_ports->charInputQueue ().pop ();
}

void
ExecutionUnit::execINC () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		quint16 ret;
		p->m_alu->opInc (ops.dest ().get<quint16> (), ret);
		ops.dest ().get<quint16> () = ret;
	}
	else {
		quint8 ret;
		p->m_alu->opInc (ops.dest ().get<quint8> (), ret);
		ops.dest ().get<quint8> () = ret;
	}
}

void
ExecutionUnit::execINT () {
	OperandList &ops = p->m_inst->operands ();

	quint16 vect_offset = 4 * ops.src ().get<quint8> ();
	quint16 int_off = p->m_biu->getMemoryData<quint16> (0, vect_offset);
	quint16 int_seg = p->m_biu->getMemoryData<quint16> (0, vect_offset + 2);

	realPush (getRegFlags ());
	setRegFlagsIF (false);
	setRegFlagsTF (false);
	realPush (p->m_biu->getSegRegCS ());
	realPush (p->m_biu->getRegIP ());

	p->m_biu->getSegRegCS () = int_seg;
	p->m_biu->getRegIP () = int_off;
}

void
ExecutionUnit::execINTO () {
	OperandList &ops = p->m_inst->operands ();

	if (!getRegFlagsOF ()) {
		return;
	}

	ops.src ().init<quint8> (new Immediate<quint8> (4), true);
	execINT ();
}

void
ExecutionUnit::execIRET () {
	realPop (p->m_biu->getRegIP ());
	realPop (p->m_biu->getSegRegCS ());
	realPop (getRegFlags ());
}

void
ExecutionUnit::execJMP () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		p->m_biu->getRegIP () = ops.dest ().get<quint16> ();
	}
	else {
		p->m_biu->getRegIP () = ops.dest ().get<quint8> ();
	}
}

void
ExecutionUnit::execJMPSHORT () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		p->m_biu->getRegIP () += ops.dest ().get<qint16> ();
	}
	else {
		p->m_biu->getRegIP () += ops.dest ().get<qint8> ();
	}
}

void
ExecutionUnit::execJMPFAR () {
	OperandList &ops = p->m_inst->operands ();

	p->m_biu->getSegRegCS () = ops.dest ().get<quint16> ().getSegment ();
	p->m_biu->getRegIP () = ops.dest ().get<quint16> ().getOffset ();
}

void
ExecutionUnit::execJNA () {
	if (getRegFlagsCF () == true || getRegFlagsZF () == true) {
		execJMPSHORT ();
	}
}

void
ExecutionUnit::execJNAE () {
	if (getRegFlagsCF () == true) {
		execJMPSHORT ();
	}
}

void
ExecutionUnit::execJNB () {
	if (getRegFlagsCF () == false) {
		execJMPSHORT ();
	}
}

void
ExecutionUnit::execJNBE () {
	if (getRegFlagsCF () == false && getRegFlagsZF () == false) {
		execJMPSHORT ();
	}
}

void
ExecutionUnit::execJC () {
	if (getRegFlagsCF () == true) {
		execJMPSHORT ();
	}
}

void
ExecutionUnit::execJCXZ () {
	if (getRegCX () == 0) {
		execJMPSHORT ();
	}
}

void
ExecutionUnit::execJE () {
	if (getRegFlagsZF () == true) {
		execJMPSHORT ();
	}
}

void
ExecutionUnit::execJG () {
	if (getRegFlagsSF () == getRegFlagsOF () && getRegFlagsZF () == false) {
		execJMPSHORT ();
	}
}

void
ExecutionUnit::execJGE () {
	if (getRegFlagsSF () == getRegFlagsOF ()) {
		execJMPSHORT ();
	}
}

void
ExecutionUnit::execJL () {
	if (getRegFlagsSF () != getRegFlagsOF ()) {
		execJMPSHORT ();
	}
}

void
ExecutionUnit::execJLE () {
	if (getRegFlagsSF () != getRegFlagsOF () || getRegFlagsZF () == true) {
		execJMPSHORT ();
	}
}

void
ExecutionUnit::execJNC () {
	if (getRegFlagsCF () == false) {
		execJMPSHORT ();
	}
}

void
ExecutionUnit::execJNE () {
	if (getRegFlagsZF () == false) {
		execJMPSHORT ();
	}
}

void
ExecutionUnit::execJNO () {
	if (getRegFlagsOF () == false) {
		execJMPSHORT ();
	}
}

void
ExecutionUnit::execJNS () {
	if (getRegFlagsSF () == false) {
		execJMPSHORT ();
	}
}

void
ExecutionUnit::execJNP () {
	if (getRegFlagsPF () == false) {
		execJMPSHORT ();
	}
}

void
ExecutionUnit::execJO () {
	if (getRegFlagsOF () == true) {
		execJMPSHORT ();
	}
}

void
ExecutionUnit::execJPE () {
	if (getRegFlagsPF () == true) {
		execJMPSHORT ();
	}
}

void
ExecutionUnit::execJS () {
	if (getRegFlagsSF () == true) {
		execJMPSHORT ();
	}
}

void
ExecutionUnit::execLAHF () {
	//FIXME - make sure this works for high byte of flags
	quint16 f = getRegFlags ();
	f &= 0xFFD7;
	f |= 0x0002;
	setRegAH (f);
}

void
ExecutionUnit::execLDS () {
	OperandList &ops = p->m_inst->operands ();

	quint16 segment = ops.src ().get<quint16> ().getSegment ();
	quint16 offset = ops.src ().get<quint16> ().getOffset ();

	ops.dest ().get<quint16> () = p->m_biu->getMemoryData<quint16> (segment, offset);
	p->m_biu->getSegRegDS () = p->m_biu->getMemoryData<quint16> (segment, offset + 2);
}

void
ExecutionUnit::execLEA () {
	OperandList &ops = p->m_inst->operands ();

	ops.dest ().get<quint16> () = ops.src ().get<quint16> ().getOffset ();
}

void
ExecutionUnit::execLES () {
	OperandList &ops = p->m_inst->operands ();

	quint16 segment = ops.src ().get<quint16> ().getSegment ();
	quint16 offset = ops.src ().get<quint16> ().getOffset ();

	ops.dest ().get<quint16> () = p->m_biu->getMemoryData<quint16> (segment, offset);
	p->m_biu->getSegRegES () = p->m_biu->getMemoryData<quint16> (segment, offset + 2);
}

void
ExecutionUnit::execLOOP () {
	OperandList &ops = p->m_inst->operands ();

	getRegCX () -= 1;

	if (getRegCX () ==0) {
		return;
	}

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		p->m_biu->getRegIP () += ops.dest ().get<qint16> ();
	}
	else {
		p->m_biu->getRegIP () += ops.dest ().get<qint8> ();
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
		ops.dest ().get<quint16> () = ops.src ().get<quint16> ();
	}
	else {
		ops.dest ().get<quint8> () = ops.src ().get<quint8> ();
	}
}

void
ExecutionUnit::execMOVS () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		ops.dest ().get<quint16> () = ops.src ().get<quint16> ();
	}
	else {
		ops.dest ().get<quint8> () = ops.src ().get<quint8> ();
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
		p->m_alu->opMul (ops.dest ().get<quint16> ());
	}
	else {
		p->m_alu->opMul (ops.dest ().get<quint8> ());
	}
}

void
ExecutionUnit::execNEG () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		quint16 ret;
		p->m_alu->opNeg (ops.dest ().get<quint16> (), ret);
		ops.dest ().get<quint16> () = ret;
	}
	else {
		quint8 ret;
		p->m_alu->opNeg (ops.dest ().get<quint8> (), ret);
		ops.dest ().get<quint8> () = ret;
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
		ops.dest ().get<quint16> () = 0xFF - ops.dest ().get<quint16> ();
	}
	else {
		ops.dest ().get<quint8> () = 0xFFFF - ops.dest ().get<quint8> ();
	}
}

void
ExecutionUnit::execOR () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		quint16 ret;
		p->m_alu->opOr (ops.dest ().get<quint16> (), ops.src ().get<quint16> (), ret);
		ops.dest ().get<quint16> () = ret;
	}
	else {
		quint8 ret;
		p->m_alu->opOr (ops.dest ().get<quint8> (), ops.src ().get<quint8> (), ret);
		ops.dest ().get<quint8> () = ret;
	}
}

void
ExecutionUnit::execOUT () {
	OperandList &ops = p->m_inst->operands ();

	//FIXME - this is only for 310
	quint16 port = ops.dest ().get<quint16> ();
	if (port == 2) { //terminal output
		if (ops.operandSize () == Jaf::OP_SIZE_8) {
			p->m_io_ports->signalCharOutput ().emit (ops.src ().get<quint8> ());
		}
	}
	else if (port == 3) { //sound output
		quint16 cx_div_bx = getRegCX () / getRegBX ();
		p->m_io_ports->signalSoundOutput ().emit (getRegAX (), cx_div_bx);
	}
}

void
ExecutionUnit::execPOP () {
	OperandList &ops = p->m_inst->operands ();

	realPop ( (!ops.src ().isNull () ? ops.src () : ops.dest ()).get<quint16> () );
}

void
ExecutionUnit::execPOPF () {
	realPop ( getRegFlags () );
}

void
ExecutionUnit::execPUSH () {
	OperandList &ops = p->m_inst->operands ();

	realPush ( (!ops.src ().isNull () ? ops.src () : ops.dest ()).get<quint16> () );
}

void
ExecutionUnit::execPUSHF () {
	realPush ( getRegFlags () );
}

void
ExecutionUnit::execRCL () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		quint16 ret;
		p->m_alu->opRcl (ops.dest ().get<quint16> (), ops.src ().get<quint8> (), ret);
		ops.dest ().get<quint16> () = ret;
	}
	else {
		quint8 ret;
		p->m_alu->opRcl (ops.dest ().get<quint8> (), ops.src ().get<quint8> (), ret);
		ops.dest ().get<quint8> () = ret;
	}
}

void
ExecutionUnit::execRCR () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		quint16 ret;
		p->m_alu->opRcr (ops.dest ().get<quint16> (), ops.src ().get<quint8> (), ret);
		ops.dest ().get<quint16> () = ret;
	}
	else {
		quint8 ret;
		p->m_alu->opRcr (ops.dest ().get<quint8> (), ops.src ().get<quint8> (), ret);
		ops.dest ().get<quint8> () = ret;
	}
}

void
ExecutionUnit::execRET () {
	OperandList &ops = p->m_inst->operands ();

	realPop (p->m_biu->getRegIP ());

	if (!ops.src ().isNull ()) {
		getRegSP () += ops.src ().get<quint16> ();
	}
}

void
ExecutionUnit::execRETFAR () {
	OperandList &ops = p->m_inst->operands ();

	realPop (p->m_biu->getRegIP ());
	realPop (p->m_biu->getSegRegCS ());

	if (!ops.src ().isNull ()) {
		getRegSP () += ops.src ().get<quint16> ();
	}
}

void
ExecutionUnit::execROL () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		quint16 ret;
		p->m_alu->opRol (ops.dest ().get<quint16> (), ops.src ().get<quint8> (), ret);
		ops.dest ().get<quint16> () = ret;
	}
	else {
		quint8 ret;
		p->m_alu->opRol (ops.dest ().get<quint8> (), ops.src ().get<quint8> (), ret);
		ops.dest ().get<quint8> () = ret;
	}
}

void
ExecutionUnit::execROR () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		quint16 ret;
		p->m_alu->opRor (ops.dest ().get<quint16> (), ops.src ().get<quint8> (), ret);
		ops.dest ().get<quint16> () = ret;
	}
	else {
		quint8 ret;
		p->m_alu->opRor (ops.dest ().get<quint8> (), ops.src ().get<quint8> (), ret);
		ops.dest ().get<quint8> () = ret;
	}
}

void
ExecutionUnit::execSAHF () {
	//FIXME - make sure this works for high byte of flags
	quint16 f = getRegFlags ();
	f &= (0xFF00 + getRegAH ());
	f &= 0xFFD7;
	f |= 0x0002;
	setRegFlags (f);
}

void
ExecutionUnit::execSAR () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		quint16 ret;
		p->m_alu->opSar (ops.dest ().get<quint16> (), ops.src ().get<quint8> (), ret);
		ops.dest ().get<quint16> () = ret;
	}
	else {
		quint8 ret;
		p->m_alu->opSar (ops.dest ().get<quint8> (), ops.src ().get<quint8> (), ret);
		ops.dest ().get<quint8> () = ret;
	}
}

void
ExecutionUnit::execSBB () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		quint16 ret;
		p->m_alu->opSbb (ops.dest ().get<quint16> (), ops.src ().get<quint16> (), ret);
		ops.dest ().get<quint16> () = ret;
	}
	else {
		quint8 ret;
		p->m_alu->opSbb (ops.dest ().get<quint8> (), ops.src ().get<quint8> (), ret);
		ops.dest ().get<quint8> () = ret;
	}
}

void
ExecutionUnit::execSHL () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		quint16 ret;
		p->m_alu->opShl (ops.dest ().get<quint16> (), ops.src ().get<quint8> (), ret);
		ops.dest ().get<quint16> () = ret;
	}
	else {
		quint8 ret;
		p->m_alu->opShl (ops.dest ().get<quint8> (), ops.src ().get<quint8> (), ret);
		ops.dest ().get<quint8> () = ret;
	}
}

void
ExecutionUnit::execSHR () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		quint16 ret;
		p->m_alu->opShr (ops.dest ().get<quint16> (), ops.src ().get<quint8> (), ret);
		ops.dest ().get<quint16> () = ret;
	}
	else {
		quint8 ret;
		p->m_alu->opShr (ops.dest ().get<quint8> (), ops.src ().get<quint8> (), ret);
		ops.dest ().get<quint8> () = ret;
	}
}

void
ExecutionUnit::execSEG () {
	OperandList &ops = p->m_inst->operands ();

	p->m_biu->setSegOverride (ops.dest ().get<quint16> ());
}

void
ExecutionUnit::execSUB () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		quint16 ret;
		p->m_alu->opSub (ops.dest ().get<quint16> (), ops.src ().get<quint16> (), ret);
		ops.dest ().get<quint16> () = ret;
	}
	else {
		quint8 ret;
		p->m_alu->opSub (ops.dest ().get<quint8> (), ops.src ().get<quint8> (), ret);
		ops.dest ().get<quint8> () = ret;
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
		p->m_alu->opTest (ops.dest ().get<quint16> (), ops.src ().get<quint16> ());
	}
	else {
		p->m_alu->opTest (ops.dest ().get<quint8> (), ops.src ().get<quint8> ());
	}
}

void
ExecutionUnit::execXCHG () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		quint16 tmp = ops.dest ().get<quint16> ();
		ops.dest ().get<quint16> () = ops.src ().get<quint16> ();
		ops.src ().get<quint16> () = tmp;
	}
	else {
		quint8 tmp = ops.dest ().get<quint8> ();
		ops.dest ().get<quint8> () = ops.src ().get<quint8> ();
		ops.src ().get<quint8> () = tmp;
	}
}

void
ExecutionUnit::execXLAT () {
	quint8 c = p->m_biu->getMemoryData<quint8> (p->m_biu->getSegRegDS (), getRegBX () + getRegAL ());
	setRegAL (c);
}

void
ExecutionUnit::execXOR () {
	OperandList &ops = p->m_inst->operands ();

	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		quint16 ret;
		p->m_alu->opXor (ops.dest ().get<quint16> (), ops.src ().get<quint16> (), ret);
		ops.dest ().get<quint16> () = ret;
	}
	else {
		quint8 ret;
		p->m_alu->opXor (ops.dest ().get<quint8> (), ops.src ().get<quint8> (), ret);
		ops.dest ().get<quint8> () = ret;
	}
}

void
ExecutionUnit::realPush (quint16 num) {
	getRegSP () -= sizeof(quint16);
	NumberWrapper mem;
	mem.init<quint16> (p->m_biu->getMemoryAddress<quint16> (p->m_biu->getSegRegSS (), getRegSP ()), true);
	mem.get<quint16> () = num;

	p->m_signal_stack_push.emit (p->m_biu->getSegRegSS (), getRegSP (), num);
}

void
ExecutionUnit::realPop () {
	getRegSP () += sizeof(quint16);

	p->m_signal_stack_pop.emit ();
}

void
ExecutionUnit::realPop (INumberReadableWritable<quint16> &num) {
	NumberWrapper mem;
	mem.init<quint16> (p->m_biu->getMemoryAddress<quint16> (p->m_biu->getSegRegSS (), getRegSP ()), true);
	num = mem.get<quint16> ();
	getRegSP () += sizeof(quint16);

	p->m_signal_stack_pop.emit ();
}

