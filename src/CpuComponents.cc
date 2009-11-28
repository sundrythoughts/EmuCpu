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


#include "CpuComponents.hh"
#include <iostream>

class CpuComponentsPrivate {
public:
	Memory m_mem;
	ExecutionUnit m_eunit;
	ArithmeticLogicUnit m_alu;
	BusInterfaceUnit m_biu;
	InstructionDecoder m_decoder;
	Instruction m_inst;
	Loader m_loader;
	IOPorts m_io_ports;

	bool m_halt;
};

CpuComponents::CpuComponents () {
	p = new CpuComponentsPrivate ();

	p->m_eunit.connectTo (*this);
	p->m_alu.connectTo (*this);
	p->m_biu.connectTo (*this);
	p->m_decoder.connectTo (*this);
	p->m_inst.connectTo (*this);
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

Instruction&
CpuComponents::getInstruction () {
	return p->m_inst;
}

Loader&
CpuComponents::getLoader () {
	return p->m_loader;
}

IOPorts&
CpuComponents::getIOPorts () {
	return p->m_io_ports;
}

bool
CpuComponents::getHalt () {
	return p->m_halt;
}

void
CpuComponents::setHalt (bool b) {
	p->m_halt = b;
}

void
CpuComponents::reset () {
	p->m_mem.reset ();
	p->m_eunit.reset ();
	p->m_biu.reset ();
	p->m_decoder.reset ();
	p->m_inst.reset ();
	//p->m_loader.reset ();
}

