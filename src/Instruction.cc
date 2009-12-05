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


#include "Instruction.hh"

#include "CpuComponents.hh"
#include "InstructionDecoder.hh"
#include "ExecutionUnit.hh"
#include "OperandList.hh"

class InstructionPrivate {
public:
	CpuComponents *m_cpu;
	InstructionDecoder *m_decoder;
	ExecutionUnit *m_eunit;
	OperandList m_operands;
	const InstructionTableItem *m_inst_item;
	std::vector<unsigned char> m_inst_bytes;
	InstructionDisassembly m_disasm;
	int m_addr_mode;
};

Instruction::Instruction () {
	p = new InstructionPrivate ();
	p->m_decoder = 0;
	p->m_eunit = 0;
	p->m_inst_item = 0;
}

Instruction::~Instruction () {
	delete p;
}

void
Instruction::connectTo (CpuComponents &cpu) {
	p->m_decoder = &cpu.getInstructionDecoder ();
	p->m_eunit = &cpu.getExecutionUnit ();
}

void
Instruction::connectTo (InstructionDecoder &dec) {
	p->m_decoder = &dec;
}

void
Instruction::connectTo (ExecutionUnit &eu) {
	p->m_eunit = &eu;
}

OperandList&
Instruction::operands () {
	return p->m_operands;
}

InstructionDisassembly&
Instruction::disassembly () {
	return p->m_disasm;
}

void
Instruction::decode () {
	p->m_inst_item->decode (*p->m_decoder);
}

void
Instruction::execute () {
	p->m_inst_item->execute (*p->m_eunit);
}

void
Instruction::setItem (const InstructionTableItem &item) {
	p->m_inst_item = &item;
}

const InstructionTableItem&
Instruction::getItem () {
	return *p->m_inst_item;
}

void
Instruction::reset () {
	p->m_operands.reset ();
	p->m_inst_item = 0;
	p->m_inst_bytes.clear ();
}

bool
Instruction::isNull () const {
	return p->m_inst_item == 0;
}

const std::vector<unsigned char>&
Instruction::getBytes () const {
	return p->m_inst_bytes;
}

std::vector<unsigned char>&
Instruction::getBytes () {
	return p->m_inst_bytes;
}

unsigned char
Instruction::getByte (size_t i) const {
	return p->m_inst_bytes[i];
}

int
Instruction::setAddrMode (int am) {
	p->m_addr_mode = am;
}

int
Instruction::getAddrMode () const {
	return p->m_addr_mode;
}

