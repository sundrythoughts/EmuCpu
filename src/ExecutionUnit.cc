#include "ExecutionUnit.hh"

#include "CpuComponents.hh"
#include "BusInterfaceUnit.hh"
#include "ArithmeticLogicUnit.hh"

#include "Defines.hh"
#include "OperandList.hh"
#include "NumberWrapper.hh"
#include "Utility.hh"

//#include "InstructionExecuter.hh"

//#include <iostream>
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

/** */
void
ExecutionUnit::connectTo (CpuComponents &cpu) {
	p->m_cpu = &cpu;
	p->m_biu = &cpu.getBusInterfaceUnit ();
	p->m_alu = &cpu.getArithmeticLogicUnit ();
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
	return Utility::get_bit (p->m_regs16[Jaf::REG_FLAGS], 4);
}

void
ExecutionUnit::setRegFlagsAF (bool val) {
	if (val) {
		Utility::set_bit (p->m_regs16[Jaf::REG_FLAGS], 4);
	}
	else {
		Utility::clear_bit (p->m_regs16[Jaf::REG_FLAGS], 4);
	}
}

bool
ExecutionUnit::getRegFlagsCF () const {
	return Utility::get_bit (p->m_regs16[Jaf::REG_FLAGS], 0);
}

void
ExecutionUnit::setRegFlagsCF (bool val) {
	if (val) {
		Utility::set_bit (p->m_regs16[Jaf::REG_FLAGS], 0);
	}
	else {
		Utility::clear_bit (p->m_regs16[Jaf::REG_FLAGS], 0);
	}
}

bool
ExecutionUnit::getRegFlagsDF () const {
	return Utility::get_bit (p->m_regs16[Jaf::REG_FLAGS], 10);
}

void
ExecutionUnit::setRegFlagsDF (bool val) {
	if (val) {
		Utility::set_bit (p->m_regs16[Jaf::REG_FLAGS], 10);
	}
	else {
		Utility::clear_bit (p->m_regs16[Jaf::REG_FLAGS], 10);
	}
}

bool
ExecutionUnit::getRegFlagsIF () const {
	return Utility::get_bit (p->m_regs16[Jaf::REG_FLAGS], 9);
}

void
ExecutionUnit::setRegFlagsIF (bool val) {
	if (val) {
		Utility::set_bit (p->m_regs16[Jaf::REG_FLAGS], 9);
	}
	else {
		Utility::clear_bit (p->m_regs16[Jaf::REG_FLAGS], 9);
	}
}

bool
ExecutionUnit::getRegFlagsOF () const {
	return Utility::get_bit (p->m_regs16[Jaf::REG_FLAGS], 11);
}

void
ExecutionUnit::setRegFlagsOF (bool val) {
	if (val) {
		Utility::set_bit (p->m_regs16[Jaf::REG_FLAGS], 11);
	}
	else {
		Utility::clear_bit (p->m_regs16[Jaf::REG_FLAGS], 11);
	}
}

bool
ExecutionUnit::getRegFlagsPF () const {
	return Utility::get_bit (p->m_regs16[Jaf::REG_FLAGS], 2);
}

void
ExecutionUnit::setRegFlagsPF (bool val) {
	if (val) {
		Utility::set_bit (p->m_regs16[Jaf::REG_FLAGS], 2);
	}
	else {
		Utility::clear_bit (p->m_regs16[Jaf::REG_FLAGS], 2);
	}
}

bool
ExecutionUnit::getRegFlagsSF () const {
	return Utility::get_bit (p->m_regs16[Jaf::REG_FLAGS], 7);
}

void
ExecutionUnit::setRegFlagsSF (bool val) {
	if (val) {
		Utility::set_bit (p->m_regs16[Jaf::REG_FLAGS], 7);
	}
	else {
		Utility::clear_bit (p->m_regs16[Jaf::REG_FLAGS], 7);
	}
}

bool
ExecutionUnit::getRegFlagsTF () const {
	return Utility::get_bit (p->m_regs16[Jaf::REG_FLAGS], 8);
}

void
ExecutionUnit::setRegFlagsTF (bool val) {
	if (val) {
		Utility::set_bit (p->m_regs16[Jaf::REG_FLAGS], 8);
	}
	else {
		Utility::clear_bit (p->m_regs16[Jaf::REG_FLAGS], 8);
	}
}

bool
ExecutionUnit::getRegFlagsZF () const {
	return Utility::get_bit (p->m_regs16[Jaf::REG_FLAGS], 6);
}

void
ExecutionUnit::setRegFlagsZF (bool val) {
	if (val) {
		Utility::set_bit (p->m_regs16[Jaf::REG_FLAGS], 6);
	}
	else {
		Utility::clear_bit (p->m_regs16[Jaf::REG_FLAGS], 6);
	}
}

void
ExecutionUnit::execNotImplemented (OperandList &ops) {
	std::cerr << "execNotImplemented (): this instruction is not implemented or doesn't exist" << std::endl;
}

void
ExecutionUnit::execADD (OperandList &ops) {
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
ExecutionUnit::execAND (OperandList &ops) {
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
ExecutionUnit::execDEC (OperandList &ops) {
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
ExecutionUnit::execHLT (OperandList &ops) {
	p->m_cpu->setHalt (true);
}

void
ExecutionUnit::execINC (OperandList &ops) {
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
ExecutionUnit::execJE (OperandList &ops) {
	if (getRegFlagsZF () != true) {
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
ExecutionUnit::execJMP (OperandList &ops) {
	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		p->m_biu->getRegIP () += ops.dest ().get<short> ();
	}
	else {
		p->m_biu->getRegIP () += ops.dest ().get<char> ();
	}
}

void
ExecutionUnit::execJNE (OperandList &ops) {
	if (getRegFlagsZF () != false) {
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
ExecutionUnit::execMOV (OperandList &ops) {
	if (ops.operandSize () == Jaf::OP_SIZE_16) {
		ops.dest ().get<unsigned short> () = ops.src ().get<unsigned short> ();
	}
	else {
		ops.dest ().get<unsigned char> () = ops.src ().get<unsigned char> ();
	}
}

void
ExecutionUnit::execNOP (OperandList &ops) {
	//does nothing
}

void
ExecutionUnit::execOR (OperandList &ops) {
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
ExecutionUnit::execSUB (OperandList &ops) {
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
ExecutionUnit::execXCHG (OperandList &ops) {
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

