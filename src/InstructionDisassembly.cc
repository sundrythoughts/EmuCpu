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


#include "InstructionDisassembly.hh"
#include <sstream>
#include <iomanip>

const std::string&
InstructionDisassembly::getSegmentOffset () const {
	return m_seg_off;
}

void
InstructionDisassembly::setSegmentOffset (unsigned short seg, unsigned short off) {
	std::ostringstream oss;
	oss << std::setfill ('0') << std::setw (4) << std::hex << seg;
	oss << ":";
	oss << std::setfill ('0') << std::setw (4) << std::hex << off;

	m_seg_off = oss.str ();
}

const std::string&
InstructionDisassembly::getMachineCode () const {
	return m_machine_code;
}

void
InstructionDisassembly::setMachineCode (const std::vector<unsigned char> &code) {
	std::ostringstream oss;
	for (size_t i = 0; i < code.size (); ++i) {
		oss << std::setfill ('0') << std::setw (2) << std::hex << (size_t)code[i];
	}

	m_machine_code = oss.str ();
}

const std::string&
InstructionDisassembly::getAddressingMode () const {
	return m_addr_mode;
}

void
InstructionDisassembly::setAddressingMode (const std::string &s) {
	m_addr_mode = s;
}

const std::string&
InstructionDisassembly::getAssembly () const {
	return m_assembly;
}

void
InstructionDisassembly::setAssembly (const std::string s) {
	m_assembly = s;
}

void
InstructionDisassembly::clear () {
	m_seg_off.clear ();
	m_machine_code.clear ();
	m_addr_mode.clear ();
	m_assembly.clear ();
}

std::string
InstructionDisassembly::toString () const {
	return m_seg_off + "\t" + m_machine_code + "\t" + m_assembly + "\t" + m_addr_mode;
}

