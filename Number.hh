#ifndef NUMBER_HH
#define NUMBER_HH

#include <sigc++/sigc++.h>
#include <iostream>

template<typename T>
class Number : public sigc::trackable {
	T m_num;
	sigc::signal<void, const T&> m_signal_value_changed;

public:
	Number () {
		//std::cout << "Number ()" << std::endl;
	}

	Number (const Number<T> &src) : sigc::trackable () {
		//std::cout << "Number (const Number<T> &src)" << std::endl;
		m_num = src.m_num;
	}

#if 0
	Number (T &r) {
		std::cout << "Number (T &r)" << std::endl;
		m_num = r;
	}
#endif

	Number (const T &r) {
		//std::cout << "Number (const T &r)" << std::endl;
		m_num = r;
	}

	~Number () {
		//std::cout << "~Number ()" << std::endl;
	}

	operator const T& () const {
		//std::cout << "operator const T& () const" << std::endl;
		return m_num;
	}

	const T& get_value () const {
		return m_num;
	}

	sigc::signal<void, const T&>& signal_value_changed () {
		return m_signal_value_changed;
	}

	const Number<T>& operator++ () {
		//std::cout << "const Number<T>& operator++ ()" << std::endl;
		++m_num;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

	const T operator++ (int) {
		//std::cout << "const T operator++ (int)" << std::endl;
		T prev = m_num++;
		m_signal_value_changed.emit (m_num);
		return prev;
	}

	const Number<T>& operator-- () {
		//std::cout << "const Number<T>& operator-- ()" << std::endl;
		--m_num;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

	const T operator-- (int) {
		//std::cout << "const T operator-- (int)" << std::endl;
		T prev = m_num--;
		m_signal_value_changed.emit (m_num);
		return prev;
	}

	Number<T>& operator= (const Number<T> &rhs) {
		//std::cout << "Number<T>& operator= (const Number<T> &rhs)" << std::endl;

		m_num = rhs.m_num;

		m_signal_value_changed.emit (m_num);

		return *this;
	}

	Number<T>& operator= (const T &rhs) {
		//std::cout << "Number<T>& operator= (const T &rhs)" << std::endl;

		m_num = rhs;

		m_signal_value_changed.emit (m_num);

		return *this;
	}

	Number<T>& operator+= (const Number<T>& right) {
		m_num += right.m_num;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

	Number<T>& operator+= (const T& right) {
		m_num += right;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

	Number<T>& operator-= (const Number<T>& right) {
		m_num -= right.m_num;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

	Number<T>& operator-= (const T& right) {
		m_num -= right;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

	Number<T>& operator*= (const Number<T>& right) {
		m_num *= right.m_num;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

	Number<T>& operator*= (const T& right) {
		m_num *= right;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

	Number<T>& operator/= (const Number<T>& right) {
		m_num /= right.m_num;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

	Number<T>& operator/= (const T& right) {
		m_num /= right;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

	Number<T>& operator%= (const Number<T>& right) {
		m_num %= right.m_num;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

	Number<T>& operator%= (const T& right) {
		m_num %= right;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

	Number<T>& operator^= (const Number<T>& right) {
		m_num ^= right.m_num;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

	Number<T>& operator^= (const T& right) {
		m_num ^= right;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

	Number<T>& operator&= (const Number<T>& right) {
		m_num &= right.m_num;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

	Number<T>& operator&= (const T& right) {
		m_num &= right;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

	Number<T>& operator|= (const Number<T>& right) {
		m_num |= right.m_num;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

	Number<T>& operator|= (const T& right) {
		m_num |= right;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

	Number<T>& operator>>= (const Number<T>& right) {
		m_num >>= right.m_num;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

	Number<T>& operator>>= (const T& right) {
		m_num >>= right;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

	Number<T>& operator<<= (const Number<T>& right) {
		m_num <<= right.m_num;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

	Number<T>& operator<<= (const T& right) {
		m_num <<= right;
		m_signal_value_changed.emit (m_num);
		return *this;
	}

#if 0
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

	friend T operator+ (const T& left, const Number<T>& right) {
		return T (left + *(right.m_num));
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

	friend T operator- (const T& left, const Number<T>& right) {
		return T (left - *(right.m_num));
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

	friend T operator* (const T& left, const Number<T>& right) {
		return T (left * *(right.m_num));
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

	friend T operator/ (const T& left, const Number<T>& right) {
		return T (left / *(right.m_num));
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

	friend T operator% (const T& left, const Number<T>& right) {
		return T (left % *(right.m_num));
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

	friend T operator^ (const T& left, const Number<T>& right) {
		return T (left ^ *(right.m_num));
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

	friend T operator& (const T& left, const Number<T>& right) {
		return T (left & *(right.m_num));
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

	friend T operator| (const T& left, const Number<T>& right) {
		return T (left | *(right.m_num));
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

	friend T operator<< (const T& left, const Number<T>& right) {
		return T (left << *(right.m_num));
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

	friend T operator>> (const T& left, const Number<T>& right) {
		return T (left >> *(right.m_num));
	}

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

	friend bool operator< (const T& left, const Number<T>& right) {
		return left < *(right.m_num);
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

	friend bool operator> (const T& left, const Number<T>& right) {
		return left > *(right.m_num);
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

	friend bool operator<= (const T& left, const Number<T>& right) {
		return left <= *(right.m_num);
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

	friend bool operator>= (const T& left, const Number<T>& right) {
		return left >= *(right.m_num);
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

	friend bool operator&& (const T& left, const Number<T>& right) {
		return left && *(right.m_num);
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

	friend bool operator|| (const T& left, const Number<T>& right) {
		return left || *(right.m_num);
	}
#endif
};

#endif //NUMBER_HH

