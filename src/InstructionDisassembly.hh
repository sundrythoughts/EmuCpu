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
@file InstructionDisassembly.hh
@brief Store the disassembly of the instruction.
*/

#ifndef JAF__INSTRUCTION_DISASSEMBLY_HH
#define JAF__INSTRUCTION_DISASSEMBLY_HH

#include <string>
#include <vector>
//#include <iostream>

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

	/** */
	const std::string& getSegmentOffset () const;

	/** */
	void setSegmentOffset (unsigned short seg, unsigned short off);

	/** */
	const std::string& getMachineCode () const;

	/** */
	void setMachineCode (const std::vector<unsigned char> &code);

	/** */
	const std::string& getAddressingMode () const;

	/** */
	void setAddressingMode (const std::string &s);

	/** */
	const std::string& getAssembly () const;

	/** */
	void setAssembly (const std::string s);

	/** */
	void clear ();

	/** */
	std::string toString () const;

}; //end class InstructionDisassembly

#endif //JAF__INSTRUCTION_DISASSEMBLY_HH

