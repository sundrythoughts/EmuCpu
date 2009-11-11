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

#ifndef JAF__INSTRUCTION_HH
#define JAF__INSTRUCTION_HH

#include "InstructionDisassembly.hh"
#include "InstructionTable.hh"
#include <vector>

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

	/** */
	void connectTo (CpuComponents &cpu);

	/** */
	void connectTo (InstructionDecoder &dec);

	/** */
	void connectTo (ExecutionUnit &eu);

	/** */
	OperandList& operands ();

	/** */
	InstructionDisassembly& disassembly ();

	/** */
	void decode ();

	/** */
	void execute ();

	/** */
	void setItem (const InstructionTableItem &item);

	/** */
	const InstructionTableItem& getItem ();

	/** */
	void reset ();

	/** */
	bool isNull () const;

	/** */
	const std::vector<unsigned char>& getBytes () const;

	/** */
	std::vector<unsigned char>& getBytes ();

	/** */
	unsigned char getByte (size_t i) const;

	/** */
	template<typename T>
	void addBytes (const T &val);

}; //end class Instruction

template<typename T>
void
Instruction::addBytes (const T &val) {
	unsigned char *b = (unsigned char*)&val;
	for (size_t i = 0; i < sizeof(T); ++i) {
		getBytes ().push_back (*b);
		++b;
	}
}

#endif //JAF__INSTRUCTION_HH

