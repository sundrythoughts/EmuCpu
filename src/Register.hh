#ifndef JAF__REGISTER_HH
#define JAF__REGISTER_HH

#include <sigc++/sigc++.h>
#include "INumberReadableWritable.hh"
#include <iostream>

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

	/** */
	sigc::signal<void, T>& signalValueChanged () {
		return m_signal_value_changed;
	}

	/** */
	sigc::signal<void>& signalEmitSignalValueChanged () {
		return m_signal_emit_signal_value_changed;
	}

	void emitSignalValueChanged () {
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
		//std::cout << right << std::endl; //FIXME - debugging
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
};

#endif //JAF__REGISTER_HH

