/*
 * emucpu -- Emulates processors
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
@file Loader.hh
@brief Load an obj file into memory.
*/

#ifndef EMUCPU__LOADER_HH
#define EMUCPU__LOADER_HH

#include <string>

#include "Types.hh"

class CpuComponents;
class LoaderPrivate;

/**
@class Loader
@brief Load an obj file into memory.
*/
class Loader {
	enum Registers {
		m_AX,
		m_BX,
		m_CX,
		m_DX,
		m_SP,
		m_BP,
		m_SI,
		m_DI,
		m_CS,
		m_DS,
		m_SS,
		m_ES,
		m_IP,
		m_FLAGS,
		m_TOTAL_SIZE
	};

	struct ModuleHeader {
		uint8 segment_register;
		uint16 module_offset;
		uint16 module_size;
	};

	LoaderPrivate *p;

	uint32 physicalAddress (uint32 seg, uint32 offset);

public:
	/** */
	Loader ();

	/** */
	~Loader ();

	/** @brief Create a connection to the CpuComponents. */
	void connectTo (CpuComponents &cpu);

	/**
	@brief Load a file into memory.
	@param filename The file to load.
	@brief If true, then clear the memory before loading.
	@return true if successful, false if unsuccessful.
	*/
	bool loadFile (std::string filename, bool clear = false);

	/** @brief Return the checksum of the memory. */
	int32 checksumMemory ();

	/** @brief Return the checksum of the registers. */
	int32 checksumRegisters ();

}; //end class Loader

#endif //EMUCPU__LOADER_HH

