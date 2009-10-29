#include "NumberWrapper.hh"

NumberWrapper::NumberWrapper () : m_num (0), m_del (false), m_size (0) {
}

NumberWrapper::~NumberWrapper () {
	free ();
}

size_t
NumberWrapper::size () const {
	return m_size;
}


bool
NumberWrapper::isNull () const {
	return m_num == 0;
}


std::string
NumberWrapper::toString () {
	return (this->*to_string_func_ptr) ();
}


void
NumberWrapper::free () {
	if (!m_del || !m_num) {
		return;
	}

	(this->*free_func_ptr) ();
	m_size = 0;
	m_num = 0;
}
