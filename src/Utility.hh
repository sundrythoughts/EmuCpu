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
@file Utility.hh
@brief Various utility functions.
*/

#ifndef EMUCPU__UTILITY_HH
#define EMUCPU__UTILITY_HH

#include "Types.hh"

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
	static bool getBit (const T &val, uint32 n);

	/**
	@brief Get the LSB
	*/
	template<typename T>
	static bool getLsb (const T &val);

	/**
	@brief Get the LSB
	*/
	template<typename T>
	static bool getMsb (const T &val);

	/**
	@brief Set a bit
	@param n The bit index to clear where 0 is the LSB.
	@param b The new value of bit n.
	*/
	template<typename T>
	static void setBit (T &val, uint32 n, bool b);

	/**
	@brief Set a bit
	@param n The bit index to set where 0 is the LSB.
	*/
	template<typename T>
	static void setBit (T &val, uint32 n);

	/**
	@brief Clear a bit
	@param n The bit index to clear where 0 is the LSB.
	*/
	template<typename T>
	static void clearBit (T &val, uint32 n);

}; //end class Utility

template<typename T>
bool
Utility::getBit (const T &val, uint32 n) {
	T mask = 1;
	mask <<= n;
	T ret = val & mask;
	return ret == mask;
}

template<typename T>
bool
Utility::getLsb (const T &val) {
	return getBit (val, 0);
}

template<typename T>
bool
Utility::getMsb (const T &val) {
	return getBit (val, (sizeof(T) << 3) - 1);
}

template<typename T>
void
Utility::setBit (T &val, uint32 n, bool b) {
	if (b) {
		Utility::setBit (val, n);
	}
	else {
		Utility::clearBit (val, n);
	}
}

template<typename T>
void
Utility::setBit (T &val, uint32 n) {
	T mask = 1;
	mask <<= n;
	val |= mask;
}

template<typename T>
void
Utility::clearBit (T &val, uint32 n) {
	T mask = 1;
	mask <<= n;
	mask = ~mask;
	val &= mask;
}

#endif //EMUCPU__UTILITY_HH

