#ifndef MEMORY_HH
#define MEMORY_HH

#include "INumberReadableWritable.hh"
#include <vector>

/**
*/
class Memory {
	std::vector<unsigned char> m_memory;

public:
	/** */
	Memory (size_t n_bytes) : m_memory (n_bytes) {
	}

	/** */
	size_t getMemorySize () const {
		return m_memory.size ();
	}

	/**
	@brief Read T bytes of data from addr into dest.
	@param addr The address in memory.
	@param dest The destination of the data that is read.
	@return true if successful, false if unsuccessful.
	*/
	template<typename T>
	bool read (size_t addr, T &dest) const;

	/** */
	template<typename T>
	bool read (size_t addr, INumberReadableWritable<T> &dest) const;

	/**
	@brief Write T bytes of data into addr from src.
	@param addr The address in memory.
	@param src The data that is written.
	@return true if successful, false if unsuccessful.
	*/
	template<typename T>
	bool write (size_t addr, const T &src);

	/** */
	template<typename T>
	bool write (size_t addr, const INumberReadableWritable<T> &src);

	/** */
	void printMemoryDump (size_t start, size_t end);
};

template<typename T>
bool
Memory::read (size_t addr, T &dest) const {
	if (!(addr + sizeof(T) - 1 < m_memory.size ())) {
		return false;
	}

	dest = *((T*)&m_memory[addr]);	

	return true;
}

template<typename T>
bool
Memory::read (size_t addr, INumberReadableWritable<T> &dest) const {
	if (!(addr + sizeof(T) - 1 < m_memory.size ())) {
		return false;
	}

	dest = *((T*)&m_memory[addr]);	

	return true;
}

template<typename T>
bool
Memory::write (size_t addr, const T &src) {
	if (!(addr + sizeof(T) - 1 < m_memory.size ())) {
		return false;
	}

	T *tmp = (T*)&m_memory[addr];
	*tmp = src;

	return true;
}

template<typename T>
bool
Memory::write (size_t addr, const INumberReadableWritable<T> &src) {
	if (!(addr + sizeof(T) - 1 < m_memory.size ())) {
		return false;
	}

	T *tmp = (T*)&m_memory[addr];
	*tmp = src;

	return true;
}

#endif //MEMORY_HH

