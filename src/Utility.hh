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
@file Utility.hh
@brief Various utility functions.
*/

#ifndef JAF__UTILITY_HH
#define JAF__UTILITY_HH

/**
@class Utility
@brief Various utility functions.
*/
class Utility {

public:
	/**
	@brief Get a bit
	@param n The bit index to get where 0 is the LSB.
	*/
	template<typename T>
	static bool get_bit (const T &val, unsigned int n);

	/**
	@brief Set a bit
	@param n The bit index to clear where 0 is the LSB.
	@param b The new value of bit n.
	*/
	template<typename T>
	static void set_bit (T &val, unsigned int n, bool b);

	/**
	@brief Set a bit
	@param n The bit index to set where 0 is the LSB.
	*/
	template<typename T>
	static void set_bit (T &val, unsigned int n);

	/**
	@brief Clear a bit
	@param n The bit index to clear where 0 is the LSB.
	*/
	template<typename T>
	static void clear_bit (T &val, unsigned int n);
}; //end class Utility

template<typename T>
bool
Utility::get_bit (const T &val, unsigned int n) {
	T mask = 1;
	mask <<= n;
	T ret = val & mask;
	return ret == mask;
}

template<typename T>
void
Utility::set_bit (T &val, unsigned int n, bool b) {
	if (b) {
		Utility::set_bit (val, n);
	}
	else {
		Utility::clear_bit (val, n);
	}
}

template<typename T>
void
Utility::set_bit (T &val, unsigned int n) {
	T mask = 1;
	mask <<= n;
	val |= mask;
}

template<typename T>
void
Utility::clear_bit (T &val, unsigned int n) {
	T mask = 1;
	mask <<= n;
	mask = ~mask;
	val &= mask;
}

#endif //JAF__UTILITY_HH

