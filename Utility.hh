#ifndef UTILITY_HH
#define UTILITY_HH

#include <stdio.h>

class Utility {

public:
	template<typename T>
	static bool get_bit (const T &val, unsigned int n);

	template<typename T>
	static void set_bit (T &val, unsigned int n);

	template<typename T>
	static void clear_bit (T &val, unsigned int n);
};

template<typename T>
bool
Utility::get_bit (const T &val, unsigned int n) {
	T mask = 1;
	mask <<= n;
	T ret = val & mask;
	return ret == mask;
}

template<typename T>
void
Utility::set_bit (T &val, unsigned int n) {
	T mask = 1;
	mask <<= n;
	val |= mask;
}

template<typename T>
void
Utility::clear_bit (T &val, unsigned int n) {
	T mask = 1;
	mask <<= n;
	mask = ~mask;
	val &= mask;
}

#endif //UTILITY_HH

