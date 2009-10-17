/**
@file Loader.hh
@brief Load an obj file into memory.
*/

#ifndef JAF__LOADER_HH
#define JAF__LOADER_HH

#include <vector>
#include <cstdio>
#include <iostream>
#include <string>

#include "Cpu.hh"
#include "Defines.hh"

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
		unsigned char segment_register;
		unsigned short module_offset;
		unsigned short module_size;
	};

	LoaderPrivate *p;

	unsigned int physicalAddress (unsigned int seg, unsigned int offset);

public:
	/** */
	Loader ();

	/** */
	~Loader ();

	/** Create a connection to the Cpu */
	void connectTo (Cpu &cpu);

	/**
	@brief Load a file into memory
	@param filename The file to load.
	@brief If true, then clear the memory before loading.
	@return true if successful, false if unsuccessful
	*/
	bool loadFile (std::string filename, bool clear = false);

	/** Return the checksum of the memory */
	int checksumMemory ();

	/** Return the checksum of the registers */
	int checksumRegisters ();

#if 0
	void print_registers () {
		for (unsigned int i = 0; i < m_regs.size (); ++i) {
			std::printf ("%x ", m_regs[i]);
		}
		std::cout << std::endl;
	}

	void print_memory () {
		for (unsigned int i = 0; i < m_memory.size (); ++i) {
			if (m_memory[i] != 0) {
				std::printf ("%x ", m_memory[i]);
			}
		}
		printf ("\n");
	}

	void print_byte_array (void *arr, unsigned int szof, unsigned int len) {
		unsigned char *cptr = (unsigned char*)arr;
		for (unsigned int i = 0; i < szof * len; ++i) {
			printf ("%x ", (unsigned int)cptr[i]);
		}
		printf ("\n");
	}
#endif

}; //end class Loader

#endif //JAF__LOADER_HH

