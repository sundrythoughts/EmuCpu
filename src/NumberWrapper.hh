#ifndef JAF__NUMBER_WRAPPER_HH
#define JAF__NUMBER_WRAPPER_HH

#include "INumberReadableWritable.hh"
#include <stdexcept>
#include <iostream>

class NumberWrapper {
	void *m_num;
	bool m_del;
	size_t m_size;
	unsigned int *m_ref_count;
	void (NumberWrapper::*free_func_ptr) ();

public:
	NumberWrapper () : m_num (0), m_del (false), m_size (0), m_ref_count (0) {
		m_ref_count = new unsigned int (1);
	}

	NumberWrapper (const NumberWrapper &src) {
		m_num = src.m_num;
		m_del = src.m_del;
		m_size = src.m_size;
		m_ref_count = src.m_ref_count;
		++(*m_ref_count);
		free_func_ptr = src.free_func_ptr;
	}

	~NumberWrapper () {
		if (m_del && *m_ref_count == 1) {
			free ();
			delete m_ref_count;
		}
		else {
			--(*m_ref_count);
		}
	}

	template<typename T>
	void init (INumberReadableWritable<T> &n, bool del = false) {
		m_num = &n;
		m_del = del;
		m_size = sizeof(T);
		free_func_ptr = &NumberWrapper::freeFunc< INumberReadableWritable<T> >;
	}

	template<typename T>
	void init (INumberReadableWritable<T> *n, bool del = false) {
		m_num = n;
		m_del = del;
		m_size = sizeof(T);
		free_func_ptr = &NumberWrapper::freeFunc< INumberReadableWritable<T> >;
	}

	size_t size () const {
		return m_size;
	}

	bool isNull () const {
		return m_num == 0;
	}

	template<typename T>
	INumberReadableWritable<T>& get () throw(std::logic_error) {
		if (sizeof(T) != size ()) {
			throw std::logic_error ("NumberWrapper::get<T> () => sizeof(T) != this->size ()");
		}

		return *(INumberReadableWritable<T> *)m_num;
	}

	void free () {
		(this->*free_func_ptr) ();
		m_size = 0;
	}

private:
	template<typename T>
	void freeFunc () {
		delete (INumberReadableWritable<T>*)m_num;
	}
};

#endif //JAF__NUMBER_WRAPPER_HH

