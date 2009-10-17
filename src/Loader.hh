#ifndef JAF__LOADER_HH
#define JAF__LOADER_HH

#include <vector>
#include <cstdio>
#include <iostream>
#include <string>

#include "Cpu.hh"
#include "Defines.hh"

//class ExecutionUnit;

class LoaderPrivate;

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

public:
	Loader ();

	~Loader ();

	void connectTo (Cpu &cpu);

	bool loadFile (std::string filename, bool clear = false);

	int checksumMemory ();

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

private:
	unsigned int physicalAddress (unsigned int seg, unsigned int offset);
};

#endif //JAF__LOADER_HH

