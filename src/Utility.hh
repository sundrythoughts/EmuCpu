/**
@file Utility.hh
@brief Various utility functions.
*/

#ifndef JAF__UTILITY_HH
#define JAF__UTILITY_HH

/**
@class Utility
@brief Various utility functions.
*/
class Utility {

public:
	/**
	@brief Get a bit
	@param n The bit index to get where 0 is the LSB.
	*/
	template<typename T>
	static bool get_bit (const T &val, unsigned int n);

	/**
	@brief Set a bit
	@param n The bit index to clear where 0 is the LSB.
	@param b The new value of bit n.
	*/
	template<typename T>
	static void set_bit (T &val, unsigned int n, bool b);

	/**
	@brief Set a bit
	@param n The bit index to set where 0 is the LSB.
	*/
	template<typename T>
	static void set_bit (T &val, unsigned int n);

	/**
	@brief Clear a bit
	@param n The bit index to clear where 0 is the LSB.
	*/
	template<typename T>
	static void clear_bit (T &val, unsigned int n);
}; //end class Utility

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
Utility::set_bit (T &val, unsigned int n, bool b) {
	if (b) {
		Utility::set_bit (val, n);
	}
	else {
		Utility::clear_bit (val, n);
	}
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

#endif //JAF__UTILITY_HH

