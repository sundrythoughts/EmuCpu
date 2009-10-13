#ifndef JAF__MEMORY_HH
#define JAF__MEMORY_HH

#include <sigc++/sigc++.h>
#include "INumberReadableWritable.hh"
#include <vector>

/**
*/
class Memory {
	std::vector<unsigned char> m_memory;
	sigc::signal<void, int, unsigned char> m_signal_value_changed;
	sigc::signal<void, size_t> m_signal_resized;
	sigc::signal<void, const unsigned char*, size_t> m_signal_reloaded;

public:
	/** */
	Memory () {
	}

	/** */
	void resize (size_t sz, bool clr=false) {
		if (clr) {
			m_memory.clear ();
		}

		m_memory.resize (sz, 0);

		m_signal_resized (m_memory.size ());
	}

	/** */
	unsigned char operator[] (size_t index) const {
		return m_memory[index];
	}

	/** */
	size_t size () const {
		return m_memory.size ();
	}

	/** */
	unsigned char* data () {
		return m_memory.data ();
	}

	/** */
	sigc::signal<void, int, unsigned char>& signalValueChanged () {
		return m_signal_value_changed;
	}

	/** */
	sigc::signal<void, size_t>& signalResized () {
		return m_signal_resized;
	}

	/** */
	sigc::signal<void, const unsigned char*, size_t> signalReloaded () {
		return m_signal_reloaded;
	}

	/** */
	void emitValueChangedForAll () const {
		for (size_t i = 0; i < m_memory.size (); ++i) {
			m_signal_value_changed.emit (i, m_memory[i]);
		}
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

	for (size_t i = addr; i < addr + sizeof(T); ++i) {
		m_signal_value_changed.emit (i, m_memory[i]);
	}

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

	for (size_t i = addr; i < addr + sizeof(T); ++i) {
		m_signal_value_changed.emit (i, m_memory[i]);
	}

	return true;
}

#endif //JAF__MEMORY_HH

