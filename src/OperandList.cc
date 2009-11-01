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


#include "OperandList.hh"

OperandList::OperandList () {
	//m_ops.resize (2);
}


OperandList::~OperandList () {
	//m_ops.clear ();
}


bool
OperandList::operandSize () const {
	return m_op_size;
}


void
OperandList::setOperandSize (bool s) {
	m_op_size = s;
}


NumberWrapper&
OperandList::src () {
	return m_ops[1];
}

NumberWrapper&
OperandList::dest () {
	return m_ops[0];
}

void
OperandList::reset () {
	//m_ops.clear ();
	//m_ops.resize (2);
	m_ops[0].free ();
	m_ops[1].free ();
}

