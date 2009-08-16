#ifndef NUMBER_HH
#define NUMBER_HH

#include <sigc++/sigc++.h>
#include <iostream>

/**
*/
template<typename T>
class Number : public sigc::trackable {
	T *m_num;
	bool m_deletable;
	sigc::signal<void, const T&> m_signal_value_changed;

public:
	/** */
	Number () {
		//std::cout << "Number ()" << std::endl;
		m_num = new T ();
		m_deletable = true;

		m_signal_value_changed.emit (*m_num);
	}

	/** */
	Number (const Number<T> &src) : sigc::trackable () {
		//std::cout << "Number (const Number<T> &src)" << std::endl;
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
	Number (T &r) {
		//std::cout << "Number (T &r)" << std::endl;
		//std::cout << "Number (" << r << ")" << std::endl;
		m_num = &r;
		m_deletable = false;

		m_signal_value_changed.emit (*m_num);
	}

	/** */
	Number (const T &r) {
		//std::cout << "Number (const T &r)" << std::endl;
		m_num = new T ();
		*m_num = r;
		m_deletable = true;

		m_signal_value_changed.emit (*m_num);
	}

	/** */
	~Number () {
		//std::cout << "~Number ()" << std::endl;
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
	operator const T& () const {
		//std::cout << "operator const T& () const" << std::endl;
		return *m_num;
	}

	/** */
	const T& get_value () const {
		return *m_num;
	}

	/** */
	sigc::signal<void, const T&>& signal_value_changed () {
		return m_signal_value_changed;
	}

	/** */
	const Number<T>& operator++ () {
		//std::cout << "const Number<T>& operator++ ()" << std::endl;
		++(*m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	const T operator++ (int) {
		//std::cout << "const T operator++ (int)" << std::endl;
		T prev = (*m_num)++;
		m_signal_value_changed.emit (*m_num);
		return prev;
	}

	/** */
	const Number<T>& operator-- () {
		//std::cout << "const Number<T>& operator-- ()" << std::endl;
		--(*m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	const T operator-- (int) {
		//std::cout << "const T operator-- (int)" << std::endl;
		T prev = (*m_num)--;
		m_signal_value_changed.emit (*m_num);
		return prev;
	}

	/** */
	Number<T>& operator= (const Number<T> &rhs) {
		//std::cout << "Number<T>& operator= (const Number<T> &rhs)" << std::endl;

		*m_num = *(rhs.m_num);

		m_signal_value_changed.emit (*m_num);

		return *this;
	}

#if 0 //FIXME - probably not needed
	Number<T>& operator= (T &rhs) {
		std::cout << "Number<T>& operator= (T &rhs)" << std::endl;

		*m_num = rhs;

		m_signal_value_changed.emit (*m_num);

		return *this;
	}
#endif

	/** */
	Number<T>& operator= (const T &rhs) {
		//std::cout << "Number<T>& operator= (const T &rhs)" << std::endl;

		*m_num = rhs;

		m_signal_value_changed.emit (*m_num);

		return *this;
	}

	/** */
	Number<T>& operator+= (const Number<T>& right) {
		*m_num += *(right.m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	Number<T>& operator+= (const T& right) {
		*m_num += right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	Number<T>& operator-= (const Number<T>& right) {
		*m_num -= *(right.m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	Number<T>& operator-= (const T& right) {
		*m_num -= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	Number<T>& operator*= (const Number<T>& right) {
		*m_num *= *(right.m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	Number<T>& operator*= (const T& right) {
		*m_num *= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	Number<T>& operator/= (const Number<T>& right) {
		*m_num /= *(right.m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	Number<T>& operator/= (const T& right) {
		*m_num /= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	Number<T>& operator%= (const Number<T>& right) {
		*m_num %= *(right.m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	Number<T>& operator%= (const T& right) {
		*m_num %= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	Number<T>& operator^= (const Number<T>& right) {
		*m_num ^= *(right.m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	Number<T>& operator^= (const T& right) {
		*m_num ^= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	Number<T>& operator&= (const Number<T>& right) {
		*m_num &= *(right.m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	Number<T>& operator&= (const T& right) {
		*m_num &= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	Number<T>& operator|= (const Number<T>& right) {
		*m_num |= *(right.m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	Number<T>& operator|= (const T& right) {
		*m_num |= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	Number<T>& operator>>= (const Number<T>& right) {
		*m_num >>= *(right.m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	Number<T>& operator>>= (const T& right) {
		*m_num >>= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	Number<T>& operator<<= (const Number<T>& right) {
		*m_num <<= *(right.m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	/** */
	Number<T>& operator<<= (const T& right) {
		*m_num <<= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}
};

#endif //NUMBER_HH

