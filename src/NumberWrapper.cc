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


#include "NumberWrapper.hh"

NumberWrapper::NumberWrapper () : m_num (0), m_del (false), m_size (0) {
}

NumberWrapper::~NumberWrapper () {
	free ();
}

size_t
NumberWrapper::size () const {
	return m_size;
}


bool
NumberWrapper::isNull () const {
	return m_num == 0;
}


std::string
NumberWrapper::toString () {
	return (this->*to_string_func_ptr) ();
}


void
NumberWrapper::free () {
	if (m_del && m_num) {
		(this->*free_func_ptr) ();
	}

	//(this->*free_func_ptr) ();
	m_size = 0;
	m_num = 0;
}

