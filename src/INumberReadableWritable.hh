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
@file INumberReadableWritable.hh
@brief Interface for Immediate, Register, and MemoryAddress.
*/

#ifndef EMUCPU__I_NUMBER_READABLE_WRITABLE_HH
#define EMUCPU__I_NUMBER_READABLE_WRITABLE_HH

#include <QtGlobal>

/**
@class INumberReadableWritable
@brief Interface for Immediate, Register, and MemoryAddress.
*/
template<typename T>
class INumberReadableWritable {

public:
	/** */
	virtual ~INumberReadableWritable () {
	}

	/** @brief Implicit cast to stored value */
	virtual operator const T& () const = 0;

	/** @brief Get the stored value */
	virtual const T& getValue () const = 0;

	/** @brief Get the segment. */
	virtual quint16 getSegment () const = 0;

	/** @brief Get the offset. */
	virtual quint16 getOffset () const = 0;

	/** */
	virtual const INumberReadableWritable<T>& operator++ () = 0;

	/** */
	virtual const T operator++ (qint32) = 0;

	/** */
	virtual const INumberReadableWritable<T>& operator-- () = 0;

	/** */
	virtual const T operator-- (qint32) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator= (const T &right) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator= (const INumberReadableWritable<T> &right) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator+= (const T& right) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator-= (const T& right) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator*= (const T& right) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator/= (const T& right) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator%= (const T& right) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator^= (const T& right) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator&= (const T& right) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator|= (const T& right) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator>>= (const T& right) = 0;

	/** */
	virtual INumberReadableWritable<T>& operator<<= (const T& right) = 0;

}; //end class INumberReadableWritable

#endif //EMUCPU__I_NUMBER_READABLE_WRITABLE_HH

