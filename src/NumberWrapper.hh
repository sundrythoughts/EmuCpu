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
@file NumberWrapper.hh
@brief Wrap an INumberReadableWritable reference or pointer with automatic or manual memory management.
*/

#ifndef EMUCPU__NUMBER_WRAPPER_HH
#define EMUCPU__NUMBER_WRAPPER_HH

#include "INumberReadableWritable.hh"
#include <stdexcept>
#include <sstream>
#include <string>
#include <iomanip>
#include <iostream>

#include "Types.hh"


/**
@class NumberWrapper
@brief Wrap an INumberReadableWritable reference or pointer with automatic or manual memory management.
*/
class NumberWrapper {
	void *m_num;
	bool m_del;
	size_t m_size;
	void (NumberWrapper::*free_func_ptr) ();
	std::string (NumberWrapper::*to_string_func_ptr) ();

public:
	/** */
	NumberWrapper ();

	/** */
	~NumberWrapper ();

	/**
	@brief Wrap a reference or value type of INumberReadableWritable
	@param del If true, then delete the value that is referenced.
	*/
	template<typename T>
	void init (INumberReadableWritable<T> &n, bool del = false);

	/**
	@brief Wrap a pointer type of INumberReadableWritable
	@param del If true, then delete the value that is pointed to.
	*/
	template<typename T>
	void init (INumberReadableWritable<T> *n, bool del = false);

	/** @brief Get the size of the wrapped type */
	size_t size () const;

	/**
	@brief Is this value null (uninitialized) or not.
	@return true if uninitialized, false if initialized.
	*/
	bool isNull () const;

	/** @brief Convert the value to a string */
	std::string toString ();

	/** @brief Cast the wrapped value to INumberReadableWritable<T>& and throw an exception if the sizeof(T) != size (). */
	template<typename T>
	INumberReadableWritable<T>& get () throw(std::logic_error);

	/** @brief Release the resources associated with the value and set it back to null. */
	void free ();

private:
	template<typename T>
	void freeFunc ();

	template<typename T>
	std::string toStringFunc ();

}; //end class NumberWrapper


template<typename T>
void
NumberWrapper::init (INumberReadableWritable<T> &n, bool del) {
	m_num = &n;
	m_del = del;
	m_size = sizeof(T);
	free_func_ptr = &NumberWrapper::freeFunc<T>;
	to_string_func_ptr = &NumberWrapper::toStringFunc<T>;
}


/**
@brief Wrap a pointer type of INumberReadableWritable
@param del If true, then delete the value that is pointed to.
*/
template<typename T>
void
NumberWrapper::init (INumberReadableWritable<T> *n, bool del) {
	m_num = n;
	m_del = del;
	m_size = sizeof(T);
	free_func_ptr = &NumberWrapper::freeFunc<T>;
	to_string_func_ptr = &NumberWrapper::toStringFunc<T>;
}


template<typename T>
INumberReadableWritable<T>&
NumberWrapper::get () throw(std::logic_error) {
	if (sizeof(T) != size ()) {
		throw std::logic_error ("NumberWrapper::get<T> () => sizeof(T) != this->size ()");
	}

	return *(INumberReadableWritable<T> *)m_num;
}


template<typename T>
void
NumberWrapper::freeFunc () {
	delete (INumberReadableWritable<T>*)m_num;
}


template<typename T>
std::string
NumberWrapper::toStringFunc () {
	INumberReadableWritable<T> *tmp = (INumberReadableWritable<T>*)m_num;
	std::ostringstream oss;
	oss << std::setfill ('0') << std::setw (sizeof(T) << 1) << std::hex << (size_t)(*tmp);
	return oss.str ();
}

#endif //EMUCPU__NUMBER_WRAPPER_HH

