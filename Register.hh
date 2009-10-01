#ifndef REGISTER_HH
#define REGISTER_HH

#include <sigc++/sigc++.h>
#include "INumberReadableWritable.hh"
#include <iostream>

template<typename T>
class Register : public sigc::trackable, public INumberReadableWritable<T> {
	T *m_num;
	bool m_deletable;
	sigc::signal<void, T> m_signal_value_changed;

public:
	/** */
	Register () : sigc::trackable () {
		m_num = new T ();
		m_deletable = true;

		m_signal_value_changed.emit (*m_num);
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
	}

	/** */
	Register (T &r) : sigc::trackable () {
		m_num = &r;
		m_deletable = false;

		m_signal_value_changed.emit (*m_num);
	}

	/** */
	Register (const T &r) : sigc::trackable () {
		m_num = new T ();
		*m_num = r;
		m_deletable = true;

		m_signal_value_changed.emit (*m_num);
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

	void connectToSignalValueChanged (const sigc::slot<void, T> &slot) {
		m_signal_value_changed.connect (slot);

		m_signal_value_changed.emit (*m_num);
	}

	/** */
	virtual operator const T& () const {
		return *m_num;
	}

	/** */
	virtual const T& getValue () const {
		return *m_num;
	}

	/** */
	virtual const INumberReadableWritable<T>& operator++ () {
		++(*m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	virtual const T operator++ (int) {
		T prev = (*m_num)++;
		m_signal_value_changed.emit (*m_num);
		return prev;
	}

	/** */
	virtual const INumberReadableWritable<T>& operator-- () {
		--(*m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	virtual const T operator-- (int) {
		T prev = (*m_num)--;
		m_signal_value_changed.emit (*m_num);
		return prev;
	}

#if 0 //FIXME - probably not needed
	INumberWritable<T>& operator= (T &rhs) {
		//std::cout << "INumberWritable<T>& operator= (T &rhs)" << std::endl;

		*m_num = rhs;

		m_signal_value_changed.emit (*m_num);

		return *this;
	}
#endif

	/** */
	virtual INumberReadableWritable<T>& operator= (const T &right) {
		std::cout << "here" << std::endl;
		*m_num = right;

		m_signal_value_changed.emit (*m_num);

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator= (const INumberReadableWritable<T> &right) {
		std::cout << "here" << std::endl;
		*m_num = right.getValue ();

		m_signal_value_changed.emit (*m_num);

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator+= (const T& right) {
		*m_num += right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator-= (const T& right) {
		*m_num -= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator*= (const T& right) {
		*m_num *= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator/= (const T& right) {
		*m_num /= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator%= (const T& right) {
		*m_num %= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator^= (const T& right) {
		*m_num ^= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator&= (const T& right) {
		*m_num &= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator|= (const T& right) {
		*m_num |= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator>>= (const T& right) {
		*m_num >>= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator<<= (const T& right) {
		*m_num <<= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}
};

#endif //REGISTER_HH

