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


#include "InstructionDecoder.hh"
#include "ExecutionUnit.hh"
#include "BusInterfaceUnit.hh"
#include "Memory.hh"

int main (int argc, char **argv) {
	Memory mem (1048576);
	BusInterfaceUnit biu;
	biu.connect_to (mem);
	ExecutionUnit eu;
	eu.connect_to (biu);
	InstructionDecoder id;
	id.connect_to (eu);
	id.connect_to (biu);

	id.m_instruction_bytes.push_back (0x8C);
	id.m_instruction_bytes.push_back (0xC3);
//	id.m_instruction_bytes.push_back (0x00);

	id.get_instruction ();
}

