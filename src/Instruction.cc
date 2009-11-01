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

Instruction::Instruction () : m_decoder (0), m_eunit (0), m_inst_item (0) {
}

void
Instruction::connectTo (InstructionDecoder &dec) {
	m_decoder = &dec;
}

void
Instruction::connectTo (ExecutionUnit &eu) {
	m_eunit = &eu;
}

OperandList&
Instruction::operands () {
	return m_operands;
}

void
Instruction::decode () {
	m_inst_item->decode (*m_decoder);
}

void
Instruction::execute () {
	m_inst_item->execute (*m_eunit, m_operands);
}

void
Instruction::setItem (const InstructionTableItem &item) {
	m_inst_item = &item;
}

const InstructionTableItem&
Instruction::getItem () {
	return *m_inst_item;
}

void
Instruction::reset () {
	m_operands.reset ();
	m_inst_item = 0;
	m_inst_bytes.clear ();
}

const std::vector<unsigned char>&
Instruction::getBytes () const {
	return m_inst_bytes;
}

