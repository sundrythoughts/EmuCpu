#include "InstructionTable.hh"
#include "ExecutionUnit.hh"
#include "BusInterfaceUnit.hh"
#include "InstructionDecoder.hh"
#include "MemoryAddress.hh"
#include "Register.hh"
#include "Immediate.hh"
#include <iostream>
#include <cstdio>

using namespace std;

class InstructionDecoderPrivate {
public:
	Cpu *m_cpu;
	ExecutionUnit *m_eunit;
	BusInterfaceUnit *m_biu;
};

InstructionDecoder::InstructionDecoder () {
	p = new InstructionDecoderPrivate ();
}

InstructionDecoder::~InstructionDecoder () {
	delete p;
}

void
InstructionDecoder::connectTo (Cpu &cpu) {
	p->m_cpu = &cpu;
	p->m_eunit = &cpu.getExecutionUnit ();
	p->m_biu = &cpu.getBusInterfaceUnit ();
}

void
InstructionDecoder::getInstruction () {
	m_disassembly = "";
	decodeInstruction ();
}

void
InstructionDecoder::nextInstruction () {
	//FIXME
	m_operands.clear ();

	m_instruction_bytes.clear ();
	m_instruction_bytes.push_back (p->m_biu->getInstructionBytes<unsigned char> ());

	decodeInstruction ();
}

const std::string&
InstructionDecoder::getDisassembly () const {
	return m_disassembly;
}

void
InstructionDecoder::decodeInstruction () {
	m_inst_ptr = &m_instruction_bytes[0];
	const InstructionTableItem *inst = &InstructionTable::one_byte_opcode_instruction_map[*m_inst_ptr];
	cout << inst->mnemonic << " ";

	++m_inst_ptr;
	if (inst->has_modrm) {
		m_modrm.modrm = *m_inst_ptr;
		++m_inst_ptr;
	}

	inst->decode (this);
	
	//FIXME - not all execute pointers are implemented yet
	inst->execute (p->m_eunit, m_operands);
}

void
InstructionDecoder::decodeNone () {
	//cout << "decodeNone ()" << endl;
	cout << endl;
}

void
InstructionDecoder::decodeRegRM () {
	cout << "decodeRegRM ()" << endl;
}

void
InstructionDecoder::decodeAccImm () {
	union InstMask {
		unsigned char byte;
		struct {
			unsigned int w : 1;
		};
	};

	InstMask im;
	im.byte = m_instruction_bytes[0];

	//cout << im.w << endl;

	cout << "ax,";

	m_operands.resize (m_operands.size () + 1);
	m_operands.back ().init<unsigned short> (p->m_eunit->getRegAX ());

	unsigned char *bytes;
	if (im.w) { //16 bits
		const unsigned short imm = p->m_biu->getInstructionBytes<unsigned short> ();
		bytes = (unsigned char*)&imm;
		for (size_t i = 0; i < sizeof(imm); ++i) {
			m_instruction_bytes.push_back (bytes[i]);
		}

		cout << (unsigned int)imm << endl;

		m_operands.resize (m_operands.size () + 1);
		m_operands.back ().init<unsigned short> (new Immediate<unsigned short> (imm), true);

		//FIXME - debugging
		//std::cout << m_operands.back ().get<unsigned short> () << std::endl;

	}
	else { //8 bits
		const unsigned char imm = p->m_biu->getInstructionBytes<unsigned char> ();
		bytes = (unsigned char*)imm;
		for (size_t i = 0; i < sizeof(imm); ++i) {
			m_instruction_bytes.push_back (bytes[i]);
		}

		cout << (unsigned int)imm << endl;

		m_operands.resize (m_operands.size () + 1);
		m_operands.back ().init<unsigned short> (new Immediate<unsigned short> ((unsigned short)imm), true);
	}
}

void
InstructionDecoder::decodeSegment () {
	cout << "decodeSegment ()" << endl;
}

void
InstructionDecoder::decodeAcc () {
	cout << "decodeAcc ()" << endl;
}

void
InstructionDecoder::decodeReg () {
	//cout << "decodeReg ()" << endl;
	union InstMask {
		unsigned char byte;
		struct {
			unsigned int reg : 3;
		};
	};

	InstMask im;
	im.byte = m_instruction_bytes[0];

	cout << Jaf::reg_index_16_names[im.reg] << endl;
	m_operands.resize (m_operands.size () + 1);
	m_operands.back ().init<unsigned short> (p->m_eunit->getReg16 (im.reg));
}

void
InstructionDecoder::decodeShort () {
	//cout << "decodeShort ()" << endl;

	char imm = p->m_biu->getInstructionBytes<char> ();
	m_instruction_bytes.push_back ((unsigned char)imm);

	cout << (int)imm << endl;

	m_operands.resize (m_operands.size () + 1);
	m_operands.back ().init<char> (new Immediate<char> (imm), true);
}

void
InstructionDecoder::decodeSegRM () {
	cout << "decodeSegRM ()" << endl;

}

void
InstructionDecoder::decodeAccReg () {
	//cout << "decodeAccReg ()" << endl;

	union InstMask {
		unsigned char byte;
		struct {
			unsigned int reg : 3;
		};
	};

	InstMask im;
	im.byte = m_instruction_bytes[0];

	cout << Jaf::reg_index_16_names[Jaf::REG_AX] << ",";
	m_operands.resize (m_operands.size () + 1);
	m_operands.back ().init<unsigned short> (p->m_eunit->getRegAX ());

	cout << Jaf::reg_index_16_names[im.reg] << endl;
	m_operands.resize (m_operands.size () + 1);
	m_operands.back ().init<unsigned short> (p->m_eunit->getReg16 (im.reg));
}

void
InstructionDecoder::decodeAccMem () {
	cout << "decodeAccMem ()" << endl;

}

void
InstructionDecoder::decodeRegImm () {
	union InstMask {
		unsigned char byte;
		struct {
			unsigned int reg : 3;
			unsigned int w : 1;
		};
	};

	//cout << "decodeRegImm ()" << endl;

	InstMask im;
	im.byte = m_instruction_bytes[0];

	//cout << im.w << endl;

	cout << Jaf::reg_index_16_names[im.reg] << ",";

	unsigned char *bytes;
	if (im.w) { //16 bits
		m_operands.resize (m_operands.size () + 1);
		m_operands.back ().init<unsigned short> (p->m_eunit->getReg16 (im.reg));

		const unsigned short imm = p->m_biu->getInstructionBytes<unsigned short> ();
		bytes = (unsigned char*)&imm;
		for (size_t i = 0; i < sizeof(imm); ++i) {
			m_instruction_bytes.push_back (bytes[i]);
		}

		cout << (unsigned int)imm << endl;

		m_operands.resize (m_operands.size () + 1);
		m_operands.back ().init<unsigned short> (new Immediate<unsigned short> (imm), true);
	}
	else { //8 bits
		m_operands.resize (m_operands.size () + 1);
		m_operands.back ().init<unsigned char> (p->m_eunit->getReg8 (im.reg));

		const unsigned char imm = p->m_biu->getInstructionBytes<unsigned char> ();
		bytes = (unsigned char*)imm;
		for (size_t i = 0; i < sizeof(imm); ++i) {
			m_instruction_bytes.push_back (bytes[i]);
		}

		cout << (unsigned int)imm << endl;

		m_operands.resize (m_operands.size () + 1);
		m_operands.back ().init<unsigned char> (new Immediate<unsigned char> (imm), true);
	}
}

void
InstructionDecoder::decodeIntra () {
	cout << "decodeIntra ()" << endl;

}

void
InstructionDecoder::decodeInter () {
	cout << "decodeInter ()" << endl;

}

void
InstructionDecoder::decodeXferInd () {
	cout << "decodeXferInd ()" << endl;

}

void
InstructionDecoder::decodeRMImm () {
	cout << "decodeRMImm ()" << endl;

}

void
InstructionDecoder::decodeAccPort () {
	cout << "decodeAccPort ()" << endl;

}

void
InstructionDecoder::decodeRM () {
	cout << "decodeRM ()" << endl;

}

void
InstructionDecoder::decodeFlags () {
	cout << "decodeFlags ()" << endl;

}

void
InstructionDecoder::decodeRetPop () {
	cout << "decodeRetPop ()" << endl;

}

void
InstructionDecoder::decodeType3 () {
	cout << "decodeType3 ()" << endl;

}

void
InstructionDecoder::decodeEscNum () {
	cout << "decodeEscNum ()" << endl;

}

void
InstructionDecoder::decodeAccVPort () {
	cout << "decodeAccVPort ()" << endl;

}

void
InstructionDecoder::decodeAccBase () {
	cout << "decodeAccBase ()" << endl;

}

void
InstructionDecoder::decodeIntNum () {
	cout << "decodeIntNum ()" << endl;

}

void
InstructionDecoder::decodeString () {
	cout << "decodeString ()" << endl;

}


