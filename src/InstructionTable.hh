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


/**
@file InstructionTable.hh
@brief List of all the instructions in the 8086.
*/

#ifndef JAF__INSTRUCTION_TABLE_HH
#define JAF__INSTRUCTION_TABLE_HH

#include <vector>
#include "ExecutionUnit.hh"
#include "InstructionDecoder.hh"

/**
@class InstructionTableItem
@brief Holds information needed to decode and execute the instruction.
*/
class InstructionTableItem {
public:
	const char *mnemonic;
	bool has_modrm;
	unsigned int group;
	void (InstructionDecoder::*decode_func) ();
	void (ExecutionUnit::*execute_func) (OperandList &ops);

	void decode (InstructionDecoder &id) const {
		(id.*decode_func) ();
	}

	void execute (ExecutionUnit &eu, OperandList &ops) const {
		(eu.*execute_func) (ops);
	}

}; //end class InstructionTableItem

/**
@class InstructionTable
@brief Holds the primary and secondary opcode tables.
*/
class InstructionTable {
public:
	enum {
		GROUP_0 = 0,
		GROUP_1,
		GROUP_2,
		GROUP_3,
		GROUP_4,
		GROUP_5,
		GROUP_6,
		GROUP_NONE,
		GROUP_RESERVED
	} InstructionGroups;

	

	static const InstructionTableItem one_byte_opcode_instruction_map[256];
	static const InstructionTableItem one_byte_opcode_instruction_extension_map[7][8];

}; //end class InstructionTable

#endif //JAF__INSTRUCTION_TABLE_HH

