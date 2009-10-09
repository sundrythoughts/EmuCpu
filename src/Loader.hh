#ifndef LOADER_HH
#define LOADER_HH

#include <vector>
#include <cstdio>
#include <iostream>
#include <string>

#include "Memory.hh"
#include "ExecutionUnit.hh"
#include "BusInterfaceUnit.hh"

#include "Defines.hh"

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

	std::vector<unsigned short> m_regs;

	Memory *m_memory;
	ExecutionUnit *m_eunit;
	BusInterfaceUnit *m_biu;

public:
	Loader () : m_regs (14) {
	}

	void connectTo (Memory &mem) {
		m_memory = &mem;
	}

	void connectTo (ExecutionUnit &eu) {
		m_eunit = &eu;
	}

	void connectTo (BusInterfaceUnit &biu) {
		m_biu = &biu;
	}

	bool loadFile (std::string filename, bool clear = false) {
		if (clear) {
			size_t i;
			size_t sz;

			for (i = 0; i < REG_COUNT_16; ++i) {
				m_eunit->setReg16 (i, 0);
			}

			sz = m_regs.size ();
			for (i = 0; i < sz; ++i) {
				m_regs[i] = 0;
			}

			sz = m_memory->size ();
			for (i = 0; i < sz; ++i) {
				m_memory->write<unsigned char> (i, 0);
			}
		}

		bool ret = true;
		std::FILE *f = std::fopen (filename.c_str (), "rb");
		if (!f) {
			ret = false;
			return ret;
		}

		std::fread (&m_regs[0], sizeof(unsigned short), m_regs.size (), f);

		unsigned char n_modules;
		std::fread (&n_modules, sizeof(unsigned char), 1, f);

		unsigned char m_header[5];
		ModuleHeader m_header_mask;

		while (n_modules) {
			std::fread (m_header, 5, 1, f);
			m_header_mask.segment_register = m_header[0];
			m_header_mask.module_offset = *((unsigned short*)&m_header[1]);
			m_header_mask.module_size = *((unsigned short*)&m_header[3]);

			unsigned short seg_reg;
			switch (m_header_mask.segment_register) {
			case 0: //cs
				seg_reg = m_regs[m_CS];
				break;
			case 1: //ds
				seg_reg = m_regs[m_DS];
				break;
			case 2: //ss
				seg_reg = m_regs[m_SS];
				break;
			case 3: //es
				seg_reg = m_regs[m_ES];
				break;
			}

			unsigned int addr = physicalAddress (seg_reg, m_header_mask.module_offset);
			std::fread (&(m_memory->data ())[addr], sizeof(unsigned char), m_header_mask.module_size, f);

			--n_modules;
		}

		fclose (f);

		m_eunit->setReg16 (REG_AX, m_regs[m_AX]);
		m_eunit->setReg16 (REG_BX, m_regs[m_BX]);
		m_eunit->setReg16 (REG_CX, m_regs[m_CX]);
		m_eunit->setReg16 (REG_DX, m_regs[m_DX]);
		m_eunit->setReg16 (REG_SP, m_regs[m_SP]);
		m_eunit->setReg16 (REG_BP, m_regs[m_BP]);
		m_eunit->setReg16 (REG_SI, m_regs[m_SI]);
		m_eunit->setReg16 (REG_DI, m_regs[m_DI]);
		m_biu->setSegRegCS (m_regs[m_CS]);
		m_biu->setSegRegDS (m_regs[m_DS]);
		m_biu->setSegRegSS (m_regs[m_SS]);
		m_biu->setSegRegES (m_regs[m_ES]);
		m_biu->setRegIP (m_regs[m_IP]);
		m_eunit->setReg16 (REG_FLAGS, m_regs[m_FLAGS]);

		m_memory->signalReloaded ().emit (m_memory->data (), m_memory->size ());

		return ret;
	}

	int checksumMemory () {
		int sum = 0;
		unsigned int i;

		for (i = 0; i < m_memory->size (); ++i) {
			sum += (*(m_memory->data () + i) ^ i);
		}

		return sum;
	}

	int checksumRegisters () {
		int sum = 0;
		unsigned int i;
		unsigned char *arr = (unsigned char*)m_regs.data ();

		for (i = 0; i < m_regs.size () * sizeof(unsigned short); ++i) {
			sum += (arr[i] ^ i);
		}

		return sum;
	}

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
	unsigned int physicalAddress (unsigned int seg, unsigned int offset) {
		return (seg << 4) + offset;
	}
};

#endif //LOADER_HH

