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
@file Register.hh
@brief Implementation of INumberReadableWritable for register values.
*/

#ifndef JAF__REGISTER_HH
#define JAF__REGISTER_HH

#include "INumberReadableWritable.hh"
#include <sigc++/sigc++.h>

#include <iostream>

/**
@class Register
@brief Implementation of INumberReadableWritable for register values.
*/
template<typename T>
class Register : public sigc::trackable, public INumberReadableWritable<T> {
	T *m_num;
	bool m_deletable;
	sigc::signal<void, T> m_signal_value_changed;
	sigc::signal<void> m_signal_emit_signal_value_changed;

public:
	/** */
	Register () : sigc::trackable () {
		m_num = new T ();
		m_deletable = true;

		m_signal_value_changed.emit (*m_num);
		m_signal_emit_signal_value_changed.emit ();
	}

	/** */
	Register (const Register<T> &src) : sigc::trackable () {
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

		m_signal_value_changed.emit (*m_num);
		m_signal_emit_signal_value_changed.emit ();
	}

	/** */
	Register (T &r, bool cp=false) : sigc::trackable () {
		if (cp) {
			m_num = new T ();
			*m_num = r;
			m_deletable = true;
		}
		else {
			m_num = &r;
			m_deletable = false;
		}

		m_signal_value_changed.emit (*m_num);
		m_signal_emit_signal_value_changed.emit ();
	}

	/** */
	Register (const T &r) : sigc::trackable () {
		m_num = new T ();
		*m_num = r;
		m_deletable = true;

		m_signal_value_changed.emit (*m_num);
		m_signal_emit_signal_value_changed.emit ();
	}

	/** */
	virtual ~Register () {
		if (m_deletable) {
			delete m_num;
		}
	}

	/** */
	void reinitialize (T &r) {
		if (m_deletable) {
			delete m_num;
			m_deletable = false;
		}

		m_num = &r;
	}

	/** */
	void reinitialize (const T &r) {
		if (!m_deletable) {
			m_num = new T ();
			m_deletable = true;
		}

		*m_num = r;
	}

	/** @brief Signal activated when Register value is changed */
	sigc::signal<void, T>& signalValueChanged () {
		return m_signal_value_changed;
	}

	/** @brief Signal activated when Register value is changed */
	sigc::signal<void>& signalEmitSignalValueChanged () {
		return m_signal_emit_signal_value_changed;
	}

	/** */
	void emitSignalValueChanged () {
		m_signal_value_changed.emit (*m_num);
	}

	/** @brief Implicit cast to stored value */
	virtual operator const T& () const {
		return *m_num;
	}

	/** @brief Get the stored value */
	virtual const T& getValue () const {
		return *m_num;
	}

	/** */
	virtual const INumberReadableWritable<T>& operator++ () {
		++(*m_num);
		m_signal_value_changed.emit (*m_num);
		m_signal_emit_signal_value_changed.emit ();
		return *this;
	}

	/** */
	virtual const T operator++ (int) {
		T prev = (*m_num)++;
		m_signal_value_changed.emit (*m_num);
		m_signal_emit_signal_value_changed.emit ();
		return prev;
	}

	/** */
	virtual const INumberReadableWritable<T>& operator-- () {
		--(*m_num);
		m_signal_value_changed.emit (*m_num);
		m_signal_emit_signal_value_changed.emit ();
		return *this;
	}

	/** */
	virtual const T operator-- (int) {
		T prev = (*m_num)--;
		m_signal_value_changed.emit (*m_num);
		m_signal_emit_signal_value_changed.emit ();
		return prev;
	}

	/** */
	virtual INumberReadableWritable<T>& operator= (const T &right) {
		*m_num = right;

		m_signal_value_changed.emit (*m_num);
		m_signal_emit_signal_value_changed.emit ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator= (const INumberReadableWritable<T> &right) {
		*m_num = right.getValue ();

		m_signal_value_changed.emit (*m_num);
		m_signal_emit_signal_value_changed.emit ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator= (const Register<T> &right) {
		*m_num = right.getValue ();

		m_signal_value_changed.emit (*m_num);
		m_signal_emit_signal_value_changed.emit ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator+= (const T& right) {
		*m_num += right;
		m_signal_value_changed.emit (*m_num);
		m_signal_emit_signal_value_changed.emit ();
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator-= (const T& right) {
		*m_num -= right;
		m_signal_value_changed.emit (*m_num);
		m_signal_emit_signal_value_changed.emit ();
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator*= (const T& right) {
		*m_num *= right;
		m_signal_value_changed.emit (*m_num);
		m_signal_emit_signal_value_changed.emit ();
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator/= (const T& right) {
		*m_num /= right;
		m_signal_value_changed.emit (*m_num);
		m_signal_emit_signal_value_changed.emit ();
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator%= (const T& right) {
		*m_num %= right;
		m_signal_value_changed.emit (*m_num);
		m_signal_emit_signal_value_changed.emit ();
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator^= (const T& right) {
		*m_num ^= right;
		m_signal_value_changed.emit (*m_num);
		m_signal_emit_signal_value_changed.emit ();
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator&= (const T& right) {
		*m_num &= right;
		m_signal_value_changed.emit (*m_num);
		m_signal_emit_signal_value_changed.emit ();
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator|= (const T& right) {
		*m_num |= right;
		m_signal_value_changed.emit (*m_num);
		m_signal_emit_signal_value_changed.emit ();
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator>>= (const T& right) {
		*m_num >>= right;
		m_signal_value_changed.emit (*m_num);
		m_signal_emit_signal_value_changed.emit ();
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator<<= (const T& right) {
		*m_num <<= right;
		m_signal_value_changed.emit (*m_num);
		m_signal_emit_signal_value_changed.emit ();
		return *this;
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

}; //end class Register

#endif //JAF__REGISTER_HH

