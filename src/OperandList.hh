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
@file OperandList.hh
@brief Stores the operands for the Instruction.
*/


#ifndef EMUCPU__OPERAND_LIST_HH
#define EMUCPU__OPERAND_LIST_HH

//#include "InstructionTable.hh"
#include "NumberWrapper.hh"
#include <string>
#include <vector>

#include "Types.hh"

/**
@class OperandList
@brief Stores the operands for the Instruction.
*/
class OperandList {
	//InstructionTableItem *m_inst;
	//std::vector m_machine_code;
	bool m_op_size;
	//std::vector<NumberWrapper> m_ops;
	NumberWrapper m_ops[2];

public:
	/** */
	OperandList ();

	/** */
	~OperandList ();

	/** @brief Get the operand size: false for 8-bit, true for 16-bit. */
	bool operandSize () const;

	/** @brief Set the operand size: false for 8-bit, true for 16-bit. */
	void setOperandSize (bool s);

	/** @brief Get the source operand. */
	NumberWrapper& src ();

	/** @brief Get the destination operand. */
	NumberWrapper& dest ();

	/** @brief Set the operand list to its default state. */
	void reset ();
};

#endif //EMUCPU__OPERAND_LIST_HH

