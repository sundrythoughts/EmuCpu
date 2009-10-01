#ifndef IMMEDIATE_HH
#define IMMEDIATE_HH

#include "INumberReadableWritable.hh"
#include <iostream>

template<typename T>
class Immediate : public INumberReadableWritable<T> {
	T *m_num;
	bool m_deletable;

public:
	/** */
	Immediate () {
		m_num = new T ();
		m_deletable = true;
	}

	/** */
	Immediate (const Immediate<T> &src) {
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
	}

	/** */
	Immediate (T &r) {
		m_num = &r;
		m_deletable = false;
	}

	/** */
	Immediate (const T &r) {
		m_num = new T ();
		*m_num = r;
		m_deletable = true;
	}

	/** */
	virtual ~Immediate () {
		if (m_deletable) {
			delete m_num;
		}
	}

private:
	/** */
	void reinitialize (T &r) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
	}

	/** */
	void reinitialize (const T &r) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
	}

public:
	/** */
	virtual operator const T& () const {
		return *m_num;
	}

	/** */
	virtual const T& getValue () const {
		return *m_num;
	}

private:
	/** */
	virtual const INumberReadableWritable<T>& operator++ () {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	/** */
	virtual const T operator++ (int) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *m_num;
	}

	/** */
	virtual const INumberReadableWritable<T>& operator-- () {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	/** */
	virtual const T operator-- (int) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *m_num;
	}

	/** */
	virtual INumberReadableWritable<T>& operator= (const T &right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator= (const INumberReadableWritable<T> &right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator+= (const T& right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator-= (const T& right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator*= (const T& right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator/= (const T& right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator%= (const T& right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator^= (const T& right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator&= (const T& right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator|= (const T& right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator>>= (const T& right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator<<= (const T& right) {
		std::cerr << "Debug: class Immediate is read-only" << std::endl;
		return *this;
	}
};

#endif //IMMEDIATE_HH

