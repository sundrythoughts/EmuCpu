/**
@file NumberWrapper.hh
@brief Wrap an INumberReadableWritable reference or pointer.
*/

#ifndef JAF__NUMBER_WRAPPER_HH
#define JAF__NUMBER_WRAPPER_HH

#include "INumberReadableWritable.hh"
#include <stdexcept>
#include <sstream>
#include <string>
#include <iomanip>
#include <iostream>


/**
@class NumberWrapper
@brief Wrap an INumberReadableWritable reference or pointer.
*/
class NumberWrapper {
	void *m_num;
	bool m_del;
	size_t m_size;
	//unsigned int *m_ref_count;
	void (NumberWrapper::*free_func_ptr) ();
	std::string (NumberWrapper::*to_string_func_ptr) ();

public:
	/** */
	NumberWrapper ();

	/** */
	~NumberWrapper ();

	/**
	@brief Wrap a reference or value type of INumberReadableWritable
	@param del If true, then delete the value that is referenced.
	*/
	template<typename T>
	void init (INumberReadableWritable<T> &n, bool del = false);

	/**
	@brief Wrap a pointer type of INumberReadableWritable
	@param del If true, then delete the value that is pointed to.
	*/
	template<typename T>
	void init (INumberReadableWritable<T> *n, bool del = false);

	/** Get the size of the wrapped type */
	size_t size () const;

	/**
	@return true if uninitialized, false if initialized.
	*/
	bool isNull () const;

	/** Convert the value to a string */
	std::string toString ();

	/** Cast the wrapped value to INumberReadableWritable<T>& and throw an exception if the sizeof(T) != size (). */
	template<typename T>
	INumberReadableWritable<T>& get () throw(std::logic_error);

	void free ();

private:

	template<typename T>
	void freeFunc ();

	template<typename T>
	std::string toStringFunc ();

}; //end class NumberWrapper


template<typename T>
void
NumberWrapper::init (INumberReadableWritable<T> &n, bool del) {
	m_num = &n;
	m_del = del;
	m_size = sizeof(T);
	free_func_ptr = &NumberWrapper::freeFunc<T>;
	to_string_func_ptr = &NumberWrapper::toStringFunc<T>;
}


/**
@brief Wrap a pointer type of INumberReadableWritable
@param del If true, then delete the value that is pointed to.
*/
template<typename T>
void
NumberWrapper::init (INumberReadableWritable<T> *n, bool del) {
	//std::cout << "init ()" << std::endl;
	m_num = n;
	m_del = del;
	m_size = sizeof(T);
	free_func_ptr = &NumberWrapper::freeFunc<T>;
	to_string_func_ptr = &NumberWrapper::toStringFunc<T>;
}


template<typename T>
INumberReadableWritable<T>&
NumberWrapper::get () throw(std::logic_error) {
	if (sizeof(T) != size ()) {
		throw std::logic_error ("NumberWrapper::get<T> () => sizeof(T) != this->size ()");
	}

	return *(INumberReadableWritable<T> *)m_num;
}


template<typename T>
void
NumberWrapper::freeFunc () {
	delete (INumberReadableWritable<T>*)m_num;
}


template<typename T>
std::string
NumberWrapper::toStringFunc () {
	INumberReadableWritable<T> *tmp = (INumberReadableWritable<T>*)m_num;
	std::ostringstream oss;
	oss << std::setfill ('0') << std::setw (sizeof(T) << 1) << std::hex << (size_t)(*tmp);
	return oss.str ();
}

#endif //JAF__NUMBER_WRAPPER_HH

