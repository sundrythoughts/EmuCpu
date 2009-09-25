#ifndef LOADER_HH
#define LOADER_HH

#include <vector>
#include <cstdio>
#include <iostream>

class Loader {
	enum Registers {
		REG_AX,
		REG_BX,
		REG_CX,
		REG_DX,
		REG_SP,
		REG_BP,
		REG_SI,
		REG_DI,
		REG_CS,
		REG_DS,
		REG_SS,
		REG_ES,
		REG_IP,
		REG_FLAGS,
		REG_TOTAL_SIZE
	};

	struct ModuleHeader {
		unsigned char segment_register;
		unsigned short module_offset;
		unsigned short module_size;
	};

	std::vector<unsigned short> m_regs;
	std::vector<unsigned char> m_memory;

public:
	Loader () : m_regs (14), m_memory (32768) {
	}

	void initialize () {
		unsigned int i;
		unsigned int sz;

		sz = m_regs.size ();
		for (i = 0; i < sz; ++i) {
			m_regs[i] = 0;
		}

		sz = m_memory.size ();
		for (i = 0; i < sz; ++i) {
			m_memory[i] = 0;
		}
	}

	bool load (const char *filename) {
		bool ret = true;
		std::FILE *f = std::fopen (filename, "rb");
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
				seg_reg = m_regs[REG_CS];
				break;
			case 1: //ds
				seg_reg = m_regs[REG_DS];
				break;
			case 2: //ss
				seg_reg = m_regs[REG_SS];
				break;
			case 3: //es
				seg_reg = m_regs[REG_ES];
				break;
			}

			unsigned int addr = physical_address (seg_reg, m_header_mask.module_offset);
			std::fread (&m_memory[addr], sizeof(unsigned char), m_header_mask.module_size, f);

			--n_modules;
		}

		fclose (f);

		return ret;
	}

	int checksum_memory () {
		int sum = 0;
		unsigned int i;

		for (i = 0; i < m_memory.size (); ++i) {
			sum += (m_memory[i] ^ i);
		}

		return sum;
	}

	int checksum_registers () {
		int sum = 0;
		unsigned int i;
		unsigned char *arr = (unsigned char*)m_regs.data ();

		for (i = 0; i < m_regs.size () * sizeof(unsigned short); ++i) {
			sum += (arr[i] ^ i);
		}

		return sum;
	}

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

private:
	unsigned int physical_address (unsigned int seg, unsigned int offset) {
		return (seg << 4) + offset;
	}
};

#endif //LOADER_HH

