#ifndef NUMBER_HH
#define NUMBER_HH

#include <sigc++/sigc++.h>
#include <iostream>

template<typename T>
class Number : public sigc::trackable {
	T *m_num;
	sigc::signal<void, const T&> m_signal_value_changed;

public:
	Number (T &r) {
		
		m_num = &r;
	}

	const T& get_value () const {
		return *m_num;
	}

	sigc::signal<void, const T&>& signal_value_changed () {
		return m_signal_value_changed;
	}

	/* Operator Usage

	All unary operators          <---->   member
	= ( ) [ ] –> –>*             <---->   must be member
	+= –= /= *= ^=               <---->   member
	&= |= %= >>= <<=
	All other binary operators   <---->   non-member

	end Operator Usage */

/*
	operator T () const {
		return T (*m_num);
	}
*/

	const T operator+ () {
		return T (*m_num);
	}

	const T operator- () {
		return T (-(*m_num));
	}

	const T operator~ () {
		return T (~(*m_num));
	}

	const T operator! () {
		return T (!(*m_num));
	}

	const Number<T>& operator++ () {
		++(*m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	const T operator++ (int) {
		T prev = (*m_num)++;
		m_signal_value_changed.emit (*m_num);
		return prev;
	}

	const Number<T>& operator-- () {
		--(*m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	const T operator-- (int) {
		T prev = (*m_num)--;
		m_signal_value_changed.emit (*m_num);
		return prev;
	}

	Number<T>& operator= (Number<T> &rhs) {
		if (this != &rhs) {
			*m_num = *(rhs.m_num);
			m_signal_value_changed.emit (*m_num);
		}
		return *this;
	}

	template<typename Tp>
	Number<T>& operator= (Number<Tp> &rhs) {
		*m_num = rhs.get_value ();
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	Number<T>& operator= (const T &rhs) {
		*m_num = rhs;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	Number<T>& operator+= (const Number<T>& right) {
		*m_num += *(right.m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	template<typename Tp>
	Number<T>& operator+= (const Number<Tp>& right) {
		*m_num += right.get_value ();
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	Number<T>& operator+= (const T& right) {
		*m_num += right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	Number<T>& operator-= (const Number<T>& right) {
		*m_num -= *(right.m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	template<typename Tp>
	Number<T>& operator-= (const Number<Tp>& right) {
		*m_num -= right.get_value ();
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	Number<T>& operator-= (const T& right) {
		*m_num -= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	Number<T>& operator*= (const Number<T>& right) {
		*m_num *= *(right.m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	template<typename Tp>
	Number<T>& operator*= (const Number<Tp>& right) {
		*m_num *= right.get_value ();
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	Number<T>& operator*= (const T& right) {
		*m_num *= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	Number<T>& operator/= (const Number<T>& right) {
		*m_num /= *(right.m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	template<typename Tp>
	Number<T>& operator/= (const Number<Tp>& right) {
		*m_num /= right.get_value ();
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	Number<T>& operator/= (const T& right) {
		*m_num /= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	Number<T>& operator%= (const Number<T>& right) {
		*m_num %= *(right.m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	template<typename Tp>
	Number<T>& operator%= (const Number<Tp>& right) {
		*m_num %= right.get_value ();
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	Number<T>& operator%= (const T& right) {
		*m_num %= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	Number<T>& operator^= (const Number<T>& right) {
		*m_num ^= *(right.m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	template<typename Tp>
	Number<T>& operator^= (const Number<Tp>& right) {
		*m_num ^= right.get_value ();
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	Number<T>& operator^= (const T& right) {
		*m_num ^= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	Number<T>& operator&= (const Number<T>& right) {
		*m_num &= *(right.m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	template<typename Tp>
	Number<T>& operator&= (const Number<Tp>& right) {
		*m_num &= right.get_value ();
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	Number<T>& operator&= (const T& right) {
		*m_num &= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	Number<T>& operator|= (const Number<T>& right) {
		*m_num |= *(right.m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	template<typename Tp>
	Number<T>& operator|= (const Number<Tp>& right) {
		*m_num |= right.get_value ();
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	Number<T>& operator|= (const T& right) {
		*m_num |= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	Number<T>& operator>>= (const Number<T>& right) {
		*m_num >>= *(right.m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	template<typename Tp>
	Number<T>& operator>>= (const Number<Tp>& right) {
		*m_num >>= right.get_value ();
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	Number<T>& operator>>= (const T& right) {
		*m_num >>= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	Number<T>& operator<<= (const Number<T>& right) {
		*m_num <<= *(right.m_num);
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	template<typename Tp>
	Number<T>& operator<<= (const Number<Tp>& right) {
		*m_num <<= right.get_value ();
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	Number<T>& operator<<= (const T& right) {
		*m_num <<= right;
		m_signal_value_changed.emit (*m_num);
		return *this;
	}

	friend T operator+ (const Number<T>& left, const Number<T>& right) {
		return T (*(left.m_num) + *(right.m_num));
	}

	template<typename Tp>
	friend T operator+ (const Number<T>& left, const Number<Tp>& right) {
		return T (*(left.m_num) + right.get_value ());
	}

	friend T operator+ (const Number<T>& left, const T& right) {
		return T (*(left.m_num) + right);
	}

	friend T operator- (const Number<T>& left, const Number<T>& right) {
		return T (*(left.m_num) - *(right.m_num));
	}

	template<typename Tp>
	friend T operator- (const Number<T>& left, const Number<Tp>& right) {
		return T (*(left.m_num) - right.get_value ());
	}

	friend T operator- (const Number<T>& left, const T& right) {
		return T (*(left.m_num) - right);
	}

	friend T operator* (const Number<T>& left, const Number<T>& right) {
		return T (*(left.m_num) * *(right.m_num));
	}

	template<typename Tp>
	friend T operator* (const Number<T>& left, const Number<Tp>& right) {
		return T (*(left.m_num) * right.get_value ());
	}

	friend T operator* (const Number<T>& left, const T& right) {
		return T (*(left.m_num) * right);
	}

	friend T operator/ (const Number<T>& left, const Number<T>& right) {
		return T (*(left.m_num) / *(right.m_num));
	}

	template<typename Tp>
	friend T operator/ (const Number<T>& left, const Number<Tp>& right) {
		return T (*(left.m_num) / right.get_value ());
	}

	friend T operator/ (const Number<T>& left, const T& right) {
		return T (*(left.m_num) / right);
	}

	friend T operator% (const Number<T>& left, const Number<T>& right) {
		return T (*(left.m_num) % *(right.m_num));
	}

	template<typename Tp>
	friend T operator% (const Number<T>& left, const Number<Tp>& right) {
		return T (*(left.m_num) % right.get_value ());
	}

	friend T operator% (const Number<T>& left, const T& right) {
		return T (*(left.m_num) % right);
	}

	friend T operator^ (const Number<T>& left, const Number<T>& right) {
		return T (*(left.m_num) ^ *(right.m_num));
	}

	template<typename Tp>
	friend T operator^ (const Number<T>& left, const Number<Tp>& right) {
		return T (*(left.m_num) ^ right.get_value ());
	}

	friend T operator^ (const Number<T>& left, const T& right) {
		return T (*(left.m_num) ^ right);
	}

	friend T operator& (const Number<T>& left, const Number<T>& right) {
		return T (*(left.m_num) & *(right.m_num));
	}

	template<typename Tp>
	friend T operator& (const Number<T>& left, const Number<Tp>& right) {
		return T (*(left.m_num) & right.get_value ());
	}

	friend T operator& (const Number<T>& left, const T& right) {
		return T (*(left.m_num) & right);
	}

	friend T operator| (const Number<T>& left, const Number<T>& right) {
		return T (*(left.m_num) | *(right.m_num));
	}

	template<typename Tp>
	friend T operator| (const Number<T>& left, const Number<Tp>& right) {
		return T (*(left.m_num) | right.get_value ());
	}

	friend T operator| (const Number<T>& left, const T& right) {
		return T (*(left.m_num) | right);
	}

	friend T operator<< (const Number<T>& left, const Number<T>& right) {
		return T (*(left.m_num) << *(right.m_num));
	}

	template<typename Tp>
	friend T operator<< (const Number<T>& left, const Number<Tp>& right) {
		return T (*(left.m_num) << right.get_value ());
	}

	friend T operator<< (const Number<T>& left, const T& right) {
		return T (*(left.m_num) << right);
	}

	friend T operator>> (const Number<T>& left, const Number<T>& right) {
		return T (*(left.m_num) >> *(right.m_num));
	}

	template<typename Tp>
	friend T operator>> (const Number<T>& left, const Number<Tp>& right) {
		return T (*(left.m_num) >> right.get_value ());
	}

	friend T operator>> (const Number<T>& left, const T& right) {
		return T (*(left.m_num) >> right);
	}

	// Conditional operators return true/false:
	friend bool operator== (const Number<T>& left, const Number<T>& right) {
		return *(left.m_num) == *(right.m_num);
	}

	template<typename Tp>
	friend bool operator== (const Number<T>& left, const Number<Tp>& right) {
		return *(left.m_num) == right.get_value ();
	}

	friend bool operator== (const Number<T>& left, const T& right) {
		return *(left.m_num) == right;
	}

	friend bool operator== (const T& left, const Number<T>& right) {
		return left == *(right.m_num);
	}

	friend bool operator!= (const Number<T>& left, const Number<T>& right) {
		return *(left.m_num) != *(right.m_num);
	}

	template<typename Tp>
	friend bool operator!= (const Number<T>& left, const Number<Tp>& right) {
		return *(left.m_num) != right.get_value ();
	}

#if 0
	template<typename Tp>
	friend bool operator!= (const Number<Tp>& left, const Number<T>& right) {
		return left.get_value () != *(right.m_num);
	}
#endif

	friend bool operator!= (const Number<T>& left, const T& right) {
		return *(left.m_num) != right;
	}

	friend bool operator!= (const T& left, const Number<T>& right) {
		return left != *(right.m_num);
	}

	friend bool operator< (const Number<T>& left, const Number<T>& right) {
		return *(left.m_num) < *(right.m_num);
	}

	template<typename Tp>
	friend bool operator< (const Number<T>& left, const Number<Tp>& right) {
		return *(left.m_num) < right.get_value ();
	}

	friend bool operator< (const Number<T>& left, const T& right) {
		return *(left.m_num) < right;
	}

	friend bool operator> (const Number<T>& left, const Number<T>& right) {
		return *(left.m_num) > *(right.m_num);
	}

	template<typename Tp>
	friend bool operator> (const Number<T>& left, const Number<Tp>& right) {
		return *(left.m_num) > right.get_value ();
	}

	friend bool operator> (const Number<T>& left, const T& right) {
		return *(left.m_num) > right;
	}

	friend bool operator<= (const Number<T>& left, const Number<T>& right) {
		return *(left.m_num) <= *(right.m_num);
	}

	template<typename Tp>
	friend bool operator<= (const Number<T>& left, const Number<Tp>& right) {
		return *(left.m_num) <= right.get_value ();
	}

	friend bool operator<= (const Number<T>& left, const T& right) {
		return *(left.m_num) <= right;
	}

	friend bool operator>= (const Number<T>& left, const Number<T>& right) {
		return *(left.m_num) >= *(right.m_num);
	}

	template<typename Tp>
	friend bool operator>= (const Number<T>& left, const Number<Tp>& right) {
		return *(left.m_num) >= right.get_value ();
	}

	friend bool operator>= (const Number<T>& left, const T& right) {
		return *(left.m_num) >= right;
	}

	friend bool operator&& (const Number<T>& left, const Number<T>& right) {
		return *(left.m_num) && *(right.m_num);
	}

	template<typename Tp>
	friend bool operator&& (const Number<T>& left, const Number<Tp>& right) {
		return *(left.m_num) && right.get_value ();
	}

	friend bool operator&& (const Number<T>& left, const T& right) {
		return *(left.m_num) && right;
	}

	friend bool operator|| (const Number<T>& left, const Number<T>& right) {
		return *(left.m_num) || *(right.m_num);
	}

	template<typename Tp>
	friend bool operator|| (const Number<T>& left, const Number<Tp>& right) {
		return *(left.m_num) || right.get_value ();
	}

	friend bool operator|| (const Number<T>& left, const T& right) {
		return *(left.m_num) || right;
	}
};

#endif //NUMBER_HH

