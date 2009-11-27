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
@file INumberReadableWritable.hh
@brief Interface for Immediate, Register, and MemoryAddress.
*/

#ifndef JAF__I_NUMBER_READABLE_WRITABLE_HH
#define JAF__I_NUMBER_READABLE_WRITABLE_HH


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

	/** Implicit cast to stored value */
	virtual operator const T& () const = 0;

	/** Get the stored value */
	virtual const T& getValue () const = 0;

	/** Get the segment. */
	virtual unsigned short getSegment () const = 0;

	/** Get the offset. */
	virtual unsigned short getOffset () const = 0;

	/** */
	virtual const INumberReadableWritable<T>& operator++ () = 0;

	/** */
	virtual const T operator++ (int) = 0;

	/** */
	virtual const INumberReadableWritable<T>& operator-- () = 0;

	/** */
	virtual const T operator-- (int) = 0;

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

#endif //JAF__I_NUMBER_READABLE_WRITABLE_HH

