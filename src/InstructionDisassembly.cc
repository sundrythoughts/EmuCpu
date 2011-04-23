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


#include "InstructionDisassembly.hh"
#include <sstream>
#include <iomanip>

class InstructionDisassemblyPrivate {
public:
	std::string m_seg_off;
	std::string m_machine_code;
	std::string m_addr_mode;
	std::string m_assembly;
};

InstructionDisassembly::InstructionDisassembly () {
	p = new InstructionDisassemblyPrivate ();
}

InstructionDisassembly::~InstructionDisassembly () {
	delete p;
}

const std::string&
InstructionDisassembly::getSegmentOffset () const {
	return p->m_seg_off;
}

void
InstructionDisassembly::setSegmentOffset (uint16 seg, uint16 off) {
	std::ostringstream oss;
	oss << std::setfill ('0') << std::setw (4) << std::hex << seg;
	oss << ":";
	oss << std::setfill ('0') << std::setw (4) << std::hex << off;

	p->m_seg_off = oss.str ();
}

const std::string&
InstructionDisassembly::getMachineCode () const {
	return p->m_machine_code;
}

void
InstructionDisassembly::setMachineCode (const std::vector<uint8> &code) {
	std::ostringstream oss;
	for (size_t i = 0; i < code.size (); ++i) {
		oss << std::setfill ('0') << std::setw (2) << std::hex << (size_t)code[i];
	}

	p->m_machine_code = oss.str ();
}

const std::string&
InstructionDisassembly::getAddressingMode () const {
	return p->m_addr_mode;
}

void
InstructionDisassembly::setAddressingMode (const std::string &s) {
	p->m_addr_mode = s;
}

const std::string&
InstructionDisassembly::getAssembly () const {
	return p->m_assembly;
}

void
InstructionDisassembly::setAssembly (const std::string s) {
	p->m_assembly = s;
}

void
InstructionDisassembly::clear () {
	p->m_seg_off.clear ();
	p->m_machine_code.clear ();
	p->m_addr_mode.clear ();
	p->m_assembly.clear ();
}

std::string
InstructionDisassembly::toString () const {
	return p->m_seg_off + "\t" + p->m_machine_code + "\t" + p->m_assembly + "\t\t" + p->m_addr_mode;
}

