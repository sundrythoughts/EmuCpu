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
@file MemoryAddress.hh
@brief Implementation of INumberReadableWritable for memory addresses.
*/

#ifndef EMUCPU__MEMORY_ADDRESS_HH
#define EMUCPU__MEMORY_ADDRESS_HH

#include "INumberReadableWritable.hh"
#include "Memory.hh"

#include <QtGlobal>

/**
@class MemoryAddress
@brief Implementation of INumberReadableWritable for memory addresses.
*/
template<typename T>
class MemoryAddress : public INumberReadableWritable<T> {
	Memory *m_memory;
	size_t m_phys_addr;
	quint16 m_seg;
	quint16 m_offset;
	mutable T m_num;

public:
	/** */
	MemoryAddress (Memory *mem, quint16 seg, quint16 offset) : m_memory (mem) {
		m_seg = seg;
		m_offset = offset;
		m_phys_addr = seg << 4;
		m_phys_addr += offset;
	}

	/** @brief Implicit cast to stored value. */
	virtual operator const T& () const {
		read ();
		return m_num;
	}

	/** @brief Get the stored value. */
	virtual const T& getValue () const {
		read ();
		return m_num;
	}

	/** @brief Get segment. */
	virtual quint16 getSegment () const {
		return m_seg;
	}

	/** @brief Get offset. */
	virtual quint16 getOffset () const {
		return m_offset;
	}

	/** */
	virtual const INumberReadableWritable<T>& operator++ () {
		read ();
		++m_num;
		write ();
		return *this;
	}

	/** */
	virtual const T operator++ (qint32) {
		read ();
		T tmp = m_num;
		++m_num;
		write ();
		return tmp;
	}

	/** */
	virtual const INumberReadableWritable<T>& operator-- () {
		read ();
		--m_num;
		write ();
		return *this;
	}

	/** */
	virtual const T operator-- (qint32) {
		read ();
		T tmp = m_num;
		--m_num;
		write ();
		return tmp;
	}

	/** */
	virtual INumberReadableWritable<T>& operator= (const T &right) {
		m_num = right;
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator= (const INumberReadableWritable<T> &right) {
		m_num = right.getValue ();
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator= (const MemoryAddress<T> &right) {
		m_num = right.getValue ();
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator+= (const T& right) {
		read ();
		m_num += right;
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator-= (const T& right) {
		read ();
		m_num -= right;
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator*= (const T& right) {
		read ();
		m_num *= right;
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator/= (const T& right) {
		read ();
		m_num /= right;
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator%= (const T& right) {
		read ();
		m_num %= right;
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator^= (const T& right) {
		read ();
		m_num ^= right;
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator&= (const T& right) {
		read ();
		m_num &= right;
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator|= (const T& right) {
		read ();
		m_num |= right;
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator>>= (const T& right) {
		read ();
		m_num >>= right;
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator<<= (const T& right) {
		read ();
		m_num <<= right;
		write ();

		return *this;
	}

private:
	bool read () const {
		return m_memory->read (m_phys_addr, m_num);
	}

	bool write () const {
		return m_memory->write (m_phys_addr, m_num);
	}
}; //end class MemoryAddress

#endif //EMUCPU__MEMORY_ADDRESS_HH

