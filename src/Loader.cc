#include "Loader.hh"

#include "CpuComponents.hh"
#include "Memory.hh"
#include "ExecutionUnit.hh"
#include "BusInterfaceUnit.hh"
#include "Defines.hh"

#include <vector>

class LoaderPrivate {
public:
	std::vector<unsigned short> m_regs;

	CpuComponents *m_cpu;
	Memory *m_memory;
	ExecutionUnit *m_eunit;
	BusInterfaceUnit *m_biu;
};

Loader::Loader () {
	p = new LoaderPrivate ();
	p->m_regs.resize (14, 0);
}

Loader::~Loader () {
	delete p;
}

void
Loader::connectTo (CpuComponents &cpu) {
	p->m_cpu = &cpu;
	p->m_memory = &cpu.getMemory ();
	p->m_eunit = &cpu.getExecutionUnit ();
	p->m_biu = &cpu.getBusInterfaceUnit ();
}

bool
Loader::loadFile (std::string filename, bool clear) {
	if (clear) {
		size_t i;
		size_t sz;

		for (i = 0; i < Jaf::REG_COUNT_16; ++i) {
			p->m_eunit->setReg16 (i, 0);
		}

		sz = p->m_regs.size ();
		for (i = 0; i < sz; ++i) {
			p->m_regs[i] = 0;
		}

		sz = p->m_memory->size ();
		for (i = 0; i < sz; ++i) {
			p->m_memory->write<unsigned char> (i, 0);
		}
	}

	bool ret = true;
	std::FILE *f = std::fopen (filename.c_str (), "rb");
	if (!f) {
		ret = false;
		return ret;
	}

	std::fread (&p->m_regs[0], sizeof(unsigned short), p->m_regs.size (), f);

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
			seg_reg = p->m_regs[m_CS];
			break;
		case 1: //ds
			seg_reg = p->m_regs[m_DS];
			break;
		case 2: //ss
			seg_reg = p->m_regs[m_SS];
			break;
		case 3: //es
			seg_reg = p->m_regs[m_ES];
			break;
		}

		unsigned int addr = physicalAddress (seg_reg, m_header_mask.module_offset);
		std::fread (&(p->m_memory->data ())[addr], sizeof(unsigned char), m_header_mask.module_size, f);

		--n_modules;
	}

	fclose (f);

	p->m_eunit->setReg16 (Jaf::REG_AX, p->m_regs[m_AX]);
	p->m_eunit->setReg16 (Jaf::REG_BX, p->m_regs[m_BX]);
	p->m_eunit->setReg16 (Jaf::REG_CX, p->m_regs[m_CX]);
	p->m_eunit->setReg16 (Jaf::REG_DX, p->m_regs[m_DX]);
	p->m_eunit->setReg16 (Jaf::REG_SP, p->m_regs[m_SP]);
	p->m_eunit->setReg16 (Jaf::REG_BP, p->m_regs[m_BP]);
	p->m_eunit->setReg16 (Jaf::REG_SI, p->m_regs[m_SI]);
	p->m_eunit->setReg16 (Jaf::REG_DI, p->m_regs[m_DI]);
	p->m_biu->setSegRegCS (p->m_regs[m_CS]);
	p->m_biu->setSegRegDS (p->m_regs[m_DS]);
	p->m_biu->setSegRegSS (p->m_regs[m_SS]);
	p->m_biu->setSegRegES (p->m_regs[m_ES]);
	p->m_biu->setRegIP (p->m_regs[m_IP]);
	p->m_eunit->setReg16 (Jaf::REG_FLAGS, p->m_regs[m_FLAGS]);

	p->m_memory->emitSignalReloaded ();

	return ret;
}

int
Loader::checksumMemory () {
	int sum = 0;
	unsigned int i;

	for (i = 0; i < p->m_memory->size (); ++i) {
		sum += (*(p->m_memory->data () + i) ^ i);
	}

	return sum;
}

int
Loader::checksumRegisters () {
	int sum = 0;
	unsigned int i;
	unsigned char *arr = (unsigned char*)p->m_regs.data ();

	for (i = 0; i < p->m_regs.size () * sizeof(unsigned short); ++i) {
		sum += (arr[i] ^ i);
	}

	return sum;
}

unsigned int
Loader::physicalAddress (unsigned int seg, unsigned int offset) {
	return (seg << 4) + offset;
}

