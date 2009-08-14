#ifndef MEMORY_HH
#define MEMORY_HH

#include <vector>

class Memory {
	std::vector<unsigned char> m_memory;

public:
	/** */
	Memory (unsigned int n_bytes) : m_memory (n_bytes) {
	}

	/** */
	unsigned int get_memory_size () const {
		return m_memory.size ();
	}

	/**
	@brief Read T bytes of data from addr into dest.
	@param addr The address in memory.
	@param dest The destination of the data that is read.
	@return true if successful, false if unsuccessful.
	*/
	template<typename T>
	bool read (unsigned int addr, T* &dest) const;

	/**
	@brief Write T bytes of data into addr from src.
	@param addr The address in memory.
	@param src The data that is written.
	@return true if successful, false if unsuccessful.
	*/
	template<typename T>
	bool write (unsigned int addr, const T &src);

	/** */
	void print_memory_dump (unsigned int start, unsigned int end);
};

template<typename T>
bool
Memory::read (unsigned int addr, T* &dest) const {
	if (!(addr + sizeof(T) - 1 < m_memory.size ())) {
		return false;
	}

	dest = (T*)&m_memory[addr];	

	return true;
}

template<typename T>
bool
Memory::write (unsigned int addr, const T &src) {
	if (!(addr + sizeof(T) - 1 < m_memory.size ())) {
		return false;
	}

	T *tmp = (T*)&m_memory[addr];
	*tmp = src;

	return true;
}

#endif //MEMORY_HH

