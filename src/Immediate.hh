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
@file Immediate.hh
@brief Read-only implementation of INumberReadableWritable for immediate values.
*/

#ifndef JAF__IMMEDIATE_HH
#define JAF__IMMEDIATE_HH

#include "INumberReadableWritable.hh"
#include <iostream>

/**
@class Immediate
@brief Read-only implementation of INumberReadableWritable for immediate values.
*/
template<typename T>
class Immediate : public INumberReadableWritable<T> {
	T *m_num;
	bool m_deletable;

public:
	/** */
	Immediate () {
		m_num = new T ();
		m_deletable = true;
	}

	/** */
	Immediate (const Immediate<T> &src) {
		//if (src.m_deletable) {
			m_num = new T ();
			*m_num = *(src.m_num);
			m_deletable = true;
		/*
		}
		else {
			m_num = src.m_num;
			m_deletable = false;
		}
		*/
	}

	/** */
	Immediate (T &r, bool cp=false) {
		if (cp) {
			m_num = new T ();
			*m_num = r;
			m_deletable = true;
		}
		else {
			m_num = &r;
			m_deletable = false;
		}
	}

	/** */
	Immediate (const T &r) {
		m_num = new T ();
		*m_num = r;
		m_deletable = true;
	}

	/** */
	virtual ~Immediate () {
		if (m_deletable) {
			delete m_num;
		}
	}

private:
	void reinitialize (T &r) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
	}

	void reinitialize (const T &r) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
	}

public:
	/** @brief Implicit cast to stored value. */
	virtual operator const T& () const {
		return *m_num;
	}

	/** @brief Get the stored value. */
	virtual const T& getValue () const {
		return *m_num;
	}

private:
	virtual unsigned short getSegment () const {
		std::cerr << "Debug: class Immediate has no segment" << std::endl;
		return 0;
	}

	virtual unsigned short getOffset () const {
		std::cerr << "Debug: class Immediate has no offset" << std::endl;
		return 0;
	}

	virtual const INumberReadableWritable<T>& operator++ () {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	virtual const T operator++ (int) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *m_num;
	}

	virtual const INumberReadableWritable<T>& operator-- () {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	virtual const T operator-- (int) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *m_num;
	}

	virtual INumberReadableWritable<T>& operator= (const T &right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	virtual INumberReadableWritable<T>& operator= (const INumberReadableWritable<T> &right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	virtual INumberReadableWritable<T>& operator= (const Immediate<T> &right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	virtual INumberReadableWritable<T>& operator+= (const T& right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	virtual INumberReadableWritable<T>& operator-= (const T& right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	virtual INumberReadableWritable<T>& operator*= (const T& right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	virtual INumberReadableWritable<T>& operator/= (const T& right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	virtual INumberReadableWritable<T>& operator%= (const T& right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	virtual INumberReadableWritable<T>& operator^= (const T& right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	virtual INumberReadableWritable<T>& operator&= (const T& right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	virtual INumberReadableWritable<T>& operator|= (const T& right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	virtual INumberReadableWritable<T>& operator>>= (const T& right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	virtual INumberReadableWritable<T>& operator<<= (const T& right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

}; //end class Immediate

#endif //JAF__IMMEDIATE_HH

