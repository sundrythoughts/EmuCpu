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


/**
@file InstructionTable.hh
@brief List of all the instructions in the 8086.
*/

#ifndef EMUCPU__INSTRUCTION_TABLE_HH
#define EMUCPU__INSTRUCTION_TABLE_HH

#include <vector>
#include "ExecutionUnit.hh"
#include "InstructionDecoder.hh"

#include "Types.hh"

/**
@class InstructionTableItem
@brief Holds information needed to decode and execute the instruction.
*/
class InstructionTableItem {
public:
	/** @brief Human readable instruction name. */
	const char *mnemonic;

	/** @brief Does the instruction have a ModRM byte or not. */
	bool has_modrm;

	/** @brief The InstructionGroups index of the instruction. */
	uint32 group;

	/** @brief Function pointer to the decode function. */
	void (InstructionDecoder::*decode_func) ();

	/** @brief Function pointer to the execute function. */
	void (ExecutionUnit::*execute_func) ();

	/** @brief Decode instruction. */
	void decode (InstructionDecoder &id) const {
		(id.*decode_func) ();
	}

	/** @brief Execute instruction. */
	void execute (ExecutionUnit &eu) const {
		(eu.*execute_func) ();
	}

}; //end class InstructionTableItem

/**
@class InstructionTable
@brief Holds the primary and secondary opcode tables.
*/
class InstructionTable {
	static const InstructionTableItem one_byte_opcode_instruction_extension_map[7][8];

	static const InstructionTableItem one_byte_opcode_instruction_map[256];

public:
	/** @brief Indexes for the row of the secondary opcode table. */
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

	/**
	@brief Get a reference to an element of the primary opcode table.
	@param i An opcode.
	*/
	static const InstructionTableItem& getOneByteOpcodeInstruction (size_t i);

	/**
	@brief Get a reference to an element of the secondary opcode table.
	@param row An InstructionGroups value.
	@param col REG field of the ModRM byte.
	*/
	static const InstructionTableItem& getOneByteOpcodeInstructionExtension (size_t row, size_t col);

}; //end class InstructionTable

#endif //EMUCPU__INSTRUCTION_TABLE_HH

