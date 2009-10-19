#include "CpuComponents.hh"

class CpuComponentsPrivate {
public:
	Memory m_mem;
	ExecutionUnit m_eunit;
	ArithmeticLogicUnit m_alu;
	BusInterfaceUnit m_biu;
	InstructionDecoder m_decoder;
	Loader m_loader;

	bool m_halt;
};

CpuComponents::CpuComponents () {
	p = new CpuComponentsPrivate ();

	//p->m_mem.connectTo (*this);
	p->m_eunit.connectTo (*this);
	p->m_alu.connectTo (*this);
	p->m_biu.connectTo (*this);
	p->m_decoder.connectTo (*this);
	p->m_loader.connectTo (*this);
}

CpuComponents::~CpuComponents () {
	delete p;
}

ExecutionUnit&
CpuComponents::getExecutionUnit () {
	return p->m_eunit;
}

BusInterfaceUnit&
CpuComponents::getBusInterfaceUnit () {
	return p->m_biu;
}

Memory&
CpuComponents::getMemory () {
	return p->m_mem;
}

ArithmeticLogicUnit&
CpuComponents::getArithmeticLogicUnit () {
	return p->m_alu;
}

InstructionDecoder&
CpuComponents::getInstructionDecoder () {
	return p->m_decoder;
}

Loader&
CpuComponents::getLoader () {
	return p->m_loader;
}

bool
CpuComponents::getHalt () {
	return p->m_halt;
}

void
CpuComponents::setHalt (bool b) {
	p->m_halt = b;
}

