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
	T m_num;

public:
	/** */
	MemoryAddress (Memory *mem, unsigned short seg, unsigned short offset) : m_memory (mem) {
		m_phys_addr = seg << 4;
		m_phys_addr += offset;
	}

	/** */
	virtual operator const T& () {
		read (m_num);
		return m_num;
	}

	/** */
	virtual const T& getValue () {
		read (m_num);
		return m_num;
	}

	/** */
	virtual const INumberReadableWritable<T>& operator++ () {
		read (m_num);
		write (++m_num);
		return *this;
	}

	/** */
	virtual const T operator++ (int) {
		read (m_num);
		T tmp = m_num;
		write (++m_num);
		return tmp;
	}

	/** */
	virtual const INumberReadableWritable<T>& operator-- () {
		read (m_num);
		write (--m_num);
		return *this;
	}

	/** */
	virtual const T operator-- (int) {
		read (m_num);
		T tmp = m_num;
		write (--m_num);
		return tmp;
	}

	/** */
	virtual INumberReadableWritable<T>& operator= (const T &rhs) {
		m_num = rhs;
		write (m_num);

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator+= (const T& right) {
		read (m_num);
		m_num += right;
		write (m_num);

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator-= (const T& right) {
		read (m_num);
		m_num -= right;
		write (m_num);

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator*= (const T& right) {
		read (m_num);
		m_num *= right;
		write (m_num);

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator/= (const T& right) {
		read (m_num);
		m_num /= right;
		write (m_num);

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator%= (const T& right) {
		read (m_num);
		m_num %= right;
		write (m_num);

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator^= (const T& right) {
		read (m_num);
		m_num ^= right;
		write (m_num);

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator&= (const T& right) {
		read (m_num);
		m_num &= right;
		write (m_num);

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator|= (const T& right) {
		read (m_num);
		m_num |= right;
		write (m_num);

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator>>= (const T& right) {
		read (m_num);
		m_num >>= right;
		write (m_num);

		return *this;
	}

	/** */
	virtual INumberReadableWritable<T>& operator<<= (const T& right) {
		read (m_num);
		m_num <<= right;
		write (m_num);

		return *this;
	}

private:
	/**
	@brief Read T bytes of data from addr into dest.
	@param seg The memory segment to use.
	@param offset The offset of the memory segment.
	@param dest The destination of the data that is read.
	@return true if successful, false if unsuccessful.
	*/
	bool read (T &dest) {
		return m_memory->read (m_phys_addr, dest);
	}

#if 0
	/** */
	bool read (Number<T> &dest) {
		return m_memory->read (m_phys_addr, dest);
	}
#endif

	/**
	@brief Write T bytes of data into addr from src.
	@param seg The memory segment to use.
	@param offset The offset of the memory segment.
	@param src The data that is written.
	@return true if successful, false if unsuccessful.
	*/
	bool write (const T &src) {
		return m_memory->write (m_phys_addr, src);
	}

#if 0
	/** */
	bool write (const Number<T> &src) {
		return m_memory->write (m_phys_addr, src);
	}
#endif
};

#endif //MEMORY_ADDRESS_HH

