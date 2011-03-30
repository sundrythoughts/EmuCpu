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
@file Instruction.hh
@brief Stores the information and function pointers for decoding and executing instructions.
*/

#ifndef SIM8086__INSTRUCTION_HH
#define SIM8086__INSTRUCTION_HH

#include "InstructionDisassembly.hh"
#include "InstructionTable.hh"
#include <vector>

#include "Types.hh"

class CpuComponents;
class InstructionPrivate;

/**
@class Instruction
@brief Store the information and function pointers for decoding and executing instructions.
*/
class Instruction {
	InstructionPrivate *p;

public:
	/** */
	Instruction ();

	/** */
	~Instruction ();

	/** @brief Connect to CpuComponents. */
	void connectTo (CpuComponents &cpu);

	/** @brief Connect to InstructionDecoder. */
	void connectTo (InstructionDecoder &dec);

	/** @brief Connect to ExecutionUnit. */
	void connectTo (ExecutionUnit &eu);

	/** @brief Get the OperandList. */
	OperandList& operands ();

	/** @brief Get the InstructionDisassembly. */
	InstructionDisassembly& disassembly ();

	/** @brief Decode Instruction. */
	void decode ();

	/** @brief Execute Instruction. */
	void execute ();

	/** @brief Set the value of the InstructionTableItem. */
	void setItem (const InstructionTableItem &item);

	/** @brief Get the value of the InstructionTableItem. */
	const InstructionTableItem& getItem ();

	/** @brief Reset the Instruction to the default value. */
	void reset ();

	/** @brief Is this instruction valid or not. */
	bool isNull () const;

	/** @brief Get the raw bytes for the Instruction. */
	const std::vector<uint8>& getBytes () const;

	/** @brief Get the raw bytes for the Instruction. */
	std::vector<uint8>& getBytes ();

	/** @brief Get raw byte of Instruction at index. */
	uint8 getByte (size_t i) const;

	/** @brief Add bytes to the raw bytes of the Instruction. */
	template<typename T>
	void addBytes (const T &val);

	/** @brief Set the addressing mode. */
	int32 setAddrMode (int32 am);

	/** @brief Get the addressing mode. */
	int32 getAddrMode () const;

}; //end class Instruction

template<typename T>
void
Instruction::addBytes (const T &val) {
	uint8 *b = (uint8*)&val;
	for (size_t i = 0; i < sizeof(T); ++i) {
		getBytes ().push_back (*b);
		++b;
	}
}

#endif //SIM8086__INSTRUCTION_HH

