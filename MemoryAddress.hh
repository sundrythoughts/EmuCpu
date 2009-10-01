#ifndef MEMORY_ADDRESS_HH
#define MEMORY_ADDRESS_HH

#include "Memory.hh"
#include "INumberReadableWritable.hh"

/**
*/
template<typename T>
class MemoryAddress : public INumberReadableWritable<T> {
	Memory *m_memory;
	unsigned int m_phys_addr;
	mutable T m_num;

public:
	/** */
	MemoryAddress (Memory *mem, unsigned short seg, unsigned short offset) : m_memory (mem) {
		m_phys_addr = seg << 4;
		m_phys_addr += offset;
	}

	/** */
	virtual operator const T& () const {
		read ();
		return m_num;
	}

	/** */
	virtual const T& getValue () const {
		read ();
		return m_num;
	}

	/** */
	virtual const INumberReadableWritable<T>& operator++ () {
		read ();
		++m_num;
		write ();
		return *this;
	}

	/** */
	virtual const T operator++ (int) {
		read ();
		T tmp = m_num;
		++m_num;
		write ();
		return tmp;
	}

	/** */
	virtual const INumberReadableWritable<T>& operator-- () {
		read ();
		--m_num;
		write ();
		return *this;
	}

	/** */
	virtual const T operator-- (int) {
		read ();
		T tmp = m_num;
		--m_num;
		write ();
		return tmp;
	}

	/** */
	virtual INumberReadableWritable<T>& operator= (const T &right) {
		m_num = right;
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator= (const INumberReadableWritable<T> &right) {
		m_num = right.getValue ();
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator+= (const T& right) {
		read ();
		m_num += right;
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator-= (const T& right) {
		read ();
		m_num -= right;
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator*= (const T& right) {
		read ();
		m_num *= right;
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator/= (const T& right) {
		read ();
		m_num /= right;
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator%= (const T& right) {
		read ();
		m_num %= right;
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator^= (const T& right) {
		read ();
		m_num ^= right;
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator&= (const T& right) {
		read ();
		m_num &= right;
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator|= (const T& right) {
		read ();
		m_num |= right;
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator>>= (const T& right) {
		read ();
		m_num >>= right;
		write ();

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator<<= (const T& right) {
		read ();
		m_num <<= right;
		write ();

		return *this;
	}

private:
	bool read () const {
		return m_memory->read (m_phys_addr, m_num);
	}

	bool write () const {
		return m_memory->write (m_phys_addr, m_num);
	}
};

#endif //MEMORY_ADDRESS_HH

