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
@file InstructionDisassembly.hh
@brief Store the disassembly of the instruction.
*/

#ifndef EMUCPU__INSTRUCTION_DISASSEMBLY_HH
#define EMUCPU__INSTRUCTION_DISASSEMBLY_HH

#include <string>
#include <vector>
//#include <iostream>
#include <QtGlobal>

class InstructionDisassemblyPrivate;

/**
@class InstructionDisassembly
@brief Store the disassembly of the instruction.
*/
class InstructionDisassembly {
	InstructionDisassemblyPrivate *p;

public:
	InstructionDisassembly ();

	~InstructionDisassembly ();

	/** @brief Get the segment and offset. */
	const std::string& getSegmentOffset () const;

	/** @brief Set the segment and offset. */
	void setSegmentOffset (quint16 seg, quint16 off);

	/** @brief Get the machine code. */
	const std::string& getMachineCode () const;

	/** @brief Set the machine code. */
	void setMachineCode (const std::vector<quint8> &code);

	/** @brief Get the addressing mode. */
	const std::string& getAddressingMode () const;

	/** @brief Set the addressing mode. */
	void setAddressingMode (const std::string &s);

	/** @brief Get the assembly. */
	const std::string& getAssembly () const;

	/** @brief Set the assembly. */
	void setAssembly (const std::string s);

	/** @brief Clear the current disassembly. */
	void clear ();

	/** @brief Convert everything to a single std::string. */
	std::string toString () const;

}; //end class InstructionDisassembly

#endif //EMUCPU__INSTRUCTION_DISASSEMBLY_HH

