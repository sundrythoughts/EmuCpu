/*
 * sim8086 -- Emulates an Intel 8086 processor
 * Copyright (C) 2009  Joseph Freeman (jfree143dev AT gmail DOT com)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


/**
@file Memory.hh
@brief Manage the memory for the Cpu.
*/

#ifndef JAF__MEMORY_HH
#define JAF__MEMORY_HH

#include <sigc++/sigc++.h>
#include "INumberReadableWritable.hh"
#include <vector>


/**
@class Memory
@brief Manage the memory for the Cpu.
*/
class Memory {
	std::vector<unsigned char> m_memory;
	sigc::signal<void, int, unsigned char> m_signal_value_changed;
	sigc::signal<void, size_t> m_signal_resized;
	sigc::signal<void, const unsigned char*, size_t> m_signal_reloaded;

public:
	/** */
	Memory ();

	/** @brief Set the memory to its default state. */
	void reset ();

	/**
	@brief Resize the memory.
	@param sz The new size of the memory.
	@param clr If true, then clear all the memory before resize.
	*/
	void resize (size_t sz, bool clr=false);

	/**
	@brief Get a memory loaction at the given index.
	*/
	unsigned char operator[] (size_t index) const;

	/** @brief Get the size of the memory. */
	size_t size () const;

	/** @brief Get an unchecked pointer to the memory. */
	unsigned char* data ();

	/** @brief Signal activated when a memory location is changed. */
	sigc::signal<void, int, unsigned char>& signalValueChanged ();

	/** @brief Signal activated when memory is resized. */
	sigc::signal<void, size_t>& signalResized ();

	/** @brief Signal activated when memory is reloaded. */
	sigc::signal<void, const unsigned char*, size_t>& signalReloaded ();

	/** @brief Emit signalValueChanged () for each memory location. */
	void emitValueChangedForAll () const;

	/** */
	void emitSignalReloaded ();

	/**
	@brief Read T bytes of data from addr into dest.
	@param addr The address in memory.
	@param dest The destination of the data that is read.
	@return true if successful, false if unsuccessful.
	*/
	template<typename T>
	bool read (size_t addr, T &dest) const;

	/**
	@brief Read T bytes of data from addr into dest.
	@param addr The address in memory.
	@param dest The destination of the data that is read.
	@return true if successful, false if unsuccessful.
	*/
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

	/**
	@brief Write T bytes of data into addr from src.
	@param addr The address in memory.
	@param src The data that is written.
	@return true if successful, false if unsuccessful.
	*/
	template<typename T>
	bool write (size_t addr, const INumberReadableWritable<T> &src);

	/** @brief Print the memory to std::cout starting at index start and ending at index end. */
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

