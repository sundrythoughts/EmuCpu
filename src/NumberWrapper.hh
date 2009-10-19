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
	NumberWrapper () : m_num (0), m_del (false), m_size (0) {//, m_ref_count (0) {
		//std::cout << "NumberWrapper ()" << std::endl;
		//m_ref_count = new unsigned int (1);
	}

#if 0
	/** */
	NumberWrapper (const NumberWrapper &src) {
		std::cout << "NumberWrapper (copy)" << std::endl;
		m_num = src.m_num;
		m_del = src.m_del;
		m_size = src.m_size;
		m_ref_count = src.m_ref_count;
		++(*m_ref_count);
		free_func_ptr = src.free_func_ptr;
		to_string_func_ptr = src.to_string_func_ptr;
	}
#endif

	/** */
	~NumberWrapper () {
		free ();
		/*
		std::cout << "~NumberWrapper() => " << m_ref_count << ": " << *m_ref_count << std::endl;
		if (m_del && *m_ref_count == 1) {
			free ();
			delete m_ref_count;
		}
		else if (*m_ref_count == 1) {
			delete m_ref_count;
		}
		else {
			--(*m_ref_count);
		}
		*/
	}

	/**
	@brief Wrap a reference or value type of INumberReadableWritable
	@param del If true, then delete the value that is referenced.
	*/
	template<typename T>
	void init (INumberReadableWritable<T> &n, bool del = false) {
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
	void init (INumberReadableWritable<T> *n, bool del = false) {
		//std::cout << "init ()" << std::endl;
		m_num = n;
		m_del = del;
		m_size = sizeof(T);
		free_func_ptr = &NumberWrapper::freeFunc<T>;
		to_string_func_ptr = &NumberWrapper::toStringFunc<T>;
	}

	/** Get the size of the wrapped type */
	size_t size () const {
		return m_size;
	}

	/**
	@return true if uninitialized, false if initialized.
	*/
	bool isNull () const {
		return m_num == 0;
	}

	/** Convert the value to a string */
	std::string toString () {
		return (this->*to_string_func_ptr) ();
	}

	/** Cast the wrapped value to INumberReadableWritable<T>& and throw an exception if the sizeof(T) != size (). */
	template<typename T>
	INumberReadableWritable<T>& get () throw(std::logic_error) {
		if (sizeof(T) != size ()) {
			throw std::logic_error ("NumberWrapper::get<T> () => sizeof(T) != this->size ()");
		}

		return *(INumberReadableWritable<T> *)m_num;
	}

	void free () {
		if (!m_del || !m_num) {
			return;
		}

		(this->*free_func_ptr) ();
		m_size = 0;
		m_num = 0;
	}

private:

	template<typename T>
	void freeFunc () {
		delete (INumberReadableWritable<T>*)m_num;
	}

	template<typename T>
	std::string toStringFunc () {
		INumberReadableWritable<T> *tmp = (INumberReadableWritable<T>*)m_num;
		std::ostringstream oss;
		oss << std::setfill ('0') << std::setw (sizeof(T) << 1) << std::hex << (size_t)(*tmp);
		return oss.str ();
	}
}; //end class NumberWrapper

#endif //JAF__NUMBER_WRAPPER_HH

