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


#ifndef JAF__OPERAND_HH
#define JAF__OPERAND_HH

#include "Defines.hh"
#include <vector>

class Operand {
	size_t m_op_size;
	std::vector<Value> m_op_vec;


public:
	Operand () :  {
		m_op_size = Jaf::OP_SIZE_NONE;
	}

	~Operand () {
		
	}

	OperandType get_operand_type () const {
		return _op_type;
	}

	GValue* get_value () const {
		return _value;
	}

	
};

class OperandVector : public std::vector<Operand*> {

public:
	void add_operand (Operand::OperandType t, GValue *v) {
		push_back (new Operand (t, v));
	}

	~OperandVector () {
		size_t i;
		for (i = 0; i < size (); ++i) {
			delete (*this)[i];
		}
	}
};

#endif //JAF__OPERAND_HH

