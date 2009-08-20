#ifndef MEMORY_ADDRESS_HH
#define MEMORY_ADDRESS_HH

#include "Memory.hh"
#include "Number.hh"

class MemoryAddress {
	Memory *m_memory;
	unsigned int m_phys_addr;

public:
	MemoryAddress (Memory *mem, unsigned short seg, unsigned short offset) : m_memory (mem) {
		m_phys_addr = seg << 4;
		m_phys_addr += offset;
	}

	/**
	@brief Read T bytes of data from addr into dest.
	@param seg The memory segment to use.
	@param offset The offset of the memory segment.
	@param dest The destination of the data that is read.
	@return true if successful, false if unsuccessful.
	*/
	template<typename T>
	bool read (T &dest);

	/** */
	template<typename T>
	bool read (Number<T> &dest);

	/**
	@brief Write T bytes of data into addr from src.
	@param seg The memory segment to use.
	@param offset The offset of the memory segment.
	@param src The data that is written.
	@return true if successful, false if unsuccessful.
	*/
	template<typename T>
	bool write (const T &src);

	/** */
	template<typename T>
	bool write (const Number<T> &src);
};

template<typename T>
bool
MemoryAddress::read (T &dest) {
	return m_memory->read (m_phys_addr, dest);
}

template<typename T>
bool
MemoryAddress::read (Number<T> &dest) {
	return m_memory->read (m_phys_addr, dest);
}

template<typename T>
bool
MemoryAddress::write (const T &src) {
	return m_memory->write (m_phys_addr, src);
}

template<typename T>
bool
MemoryAddress::write (const Number<T> &src) {
	return m_memory->write (m_phys_addr, src);
}

#endif //MEMORY_ADDRESS_HH

