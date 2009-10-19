#include "InstructionDecoder.hh"

#include "CpuComponents.hh"
#include "ExecutionUnit.hh"
#include "BusInterfaceUnit.hh"

#include "Defines.hh"
#include "OperandList.hh"
#include "NumberWrapper.hh"
#include "InstructionDisassembly.hh"
#include "InstructionTable.hh"

#include "MemoryAddress.hh"
#include "Register.hh"
#include "Immediate.hh"

#include <vector>
//#include <utility>
//#include <cstdio>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class InstructionDecoderPrivate {
public:
	CpuComponents *m_cpu;
	ExecutionUnit *m_eunit;
	BusInterfaceUnit *m_biu;

	std::vector<unsigned char> m_instruction_bytes;
	unsigned char *m_inst_ptr;

	Jaf::ModRM m_modrm;

	OperandList m_operands;
	InstructionDisassembly m_disassembly;
	std::ostringstream m_disasm;

	sigc::signal<void, const std::string&, const std::string&, const std::string&, const std::string&> m_signal_next_instruction;
};

InstructionDecoder::InstructionDecoder () {
	p = new InstructionDecoderPrivate ();
}

InstructionDecoder::~InstructionDecoder () {
	delete p;
}

void
InstructionDecoder::connectTo (CpuComponents &cpu) {
	p->m_cpu = &cpu;
	p->m_eunit = &cpu.getExecutionUnit ();
	p->m_biu = &cpu.getBusInterfaceUnit ();
}

void
InstructionDecoder::getInstruction () {
	decodeInstruction ();
}

void
InstructionDecoder::nextInstruction () {
	if (!p->m_instruction_bytes.empty ()) {
		InstructionTable::one_byte_opcode_instruction_map[p->m_instruction_bytes[0]].execute (p->m_eunit, p->m_operands);
	}

	p->m_disasm.str ("");
	p->m_operands.reset ();
	p->m_disasm.clear ();
	p->m_instruction_bytes.clear ();

	if (p->m_cpu->getHalt ()) {
		return;
	}

	p->m_disassembly.setSegmentOffset (p->m_biu->getSegRegCS (), p->m_biu->getRegIP ());
	p->m_instruction_bytes.push_back (p->m_biu->getInstructionBytes<unsigned char> ());

	decodeInstruction ();

	p->m_signal_next_instruction.emit (p->m_disassembly.getSegmentOffset (),
	                                   p->m_disassembly.getMachineCode (),
	                                   p->m_disassembly.getAssembly (),
	                                   p->m_disassembly.getAddressingMode ());

	//cout << p->m_disassembly.toString () << endl;
}

sigc::signal<void, const std::string&,
                   const std::string&,
                   const std::string&,
                   const std::string&>&
InstructionDecoder::signalNextInstruction ()
{
	return p->m_signal_next_instruction;
}

void
InstructionDecoder::decodeInstruction () {
	p->m_inst_ptr = &p->m_instruction_bytes[0];
	const InstructionTableItem *inst = &InstructionTable::one_byte_opcode_instruction_map[*p->m_inst_ptr];

	p->m_disasm << inst->mnemonic << " ";

	++p->m_inst_ptr;
	if (inst->has_modrm) {
		p->m_modrm.modrm = *p->m_inst_ptr;
		++p->m_inst_ptr;
	}

	inst->decode (this);

	p->m_disassembly.setMachineCode (p->m_instruction_bytes);
	p->m_disassembly.setAssembly (p->m_disasm.str ());
}

void
InstructionDecoder::decodeNotImplemented () {
	std::cerr << "decodeNotImplemented (): this addressing mode is not implemented or doesn't exist" << std::endl;
}

void
InstructionDecoder::decodeNone () {
	p->m_disassembly.setAddressingMode ("None");
}

void
InstructionDecoder::decodeRegRM () {
	p->m_disassembly.setAddressingMode ("RegRM");
}

void
InstructionDecoder::decodeAccImm () {
	union InstMask {
		unsigned char byte;
		struct {
			unsigned int w : 1;
		};
	};

	p->m_disassembly.setAddressingMode ("AccImm");

	InstMask im;
	im.byte = p->m_instruction_bytes[0];

	p->m_operands.setOperandSize (im.w);

	unsigned char *bytes;
	if (im.w) { //16 bits
		p->m_disasm << "ax";

		p->m_operands.dest ().init<unsigned short> (p->m_eunit->getRegAX ());

		const unsigned short imm = p->m_biu->getInstructionBytes<unsigned short> ();
		bytes = (unsigned char*)&imm;
		for (size_t i = 0; i < sizeof(imm); ++i) {
			p->m_instruction_bytes.push_back (bytes[i]);
		}

		p->m_disasm << ", " << std::setfill ('0') << std::setw (sizeof(imm) << 1) << std::hex << (unsigned int)imm;

		p->m_operands.src ().init<unsigned short> (new Immediate<unsigned short> (imm), true);
	}
	else { //8 bits
		p->m_disasm << "al";

		p->m_operands.dest ().init<unsigned char> (p->m_eunit->getRegAL ());

		const unsigned char imm = p->m_biu->getInstructionBytes<unsigned char> ();
		bytes = (unsigned char*)&imm;
		for (size_t i = 0; i < sizeof(unsigned char); ++i) {
			p->m_instruction_bytes.push_back (bytes[i]);
		}

		p->m_disasm << ", " << std::setfill ('0') << std::setw (sizeof(imm) << 1) << std::hex << (unsigned int)imm;

		p->m_operands.src ().init<unsigned char> (new Immediate<unsigned char> (imm), true);
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
	union InstMask {
		unsigned char byte;
		struct {
			unsigned int reg : 3;
		};
	};

	p->m_disassembly.setAddressingMode ("Reg");

	InstMask im;
	im.byte = p->m_instruction_bytes[0];

	p->m_operands.setOperandSize (Jaf::OP_SIZE_16);

	p->m_disasm << Jaf::reg_index_16_names[im.reg];

	p->m_operands.dest ().init<unsigned short> (p->m_eunit->getReg16 (im.reg));
}

void
InstructionDecoder::decodeShort () {
	p->m_disassembly.setAddressingMode ("Short");

	const char imm = p->m_biu->getInstructionBytes<char> ();
	p->m_instruction_bytes.push_back ((unsigned char)imm);

	p->m_disasm << ", " << std::setfill ('0') << std::setw (sizeof(imm) << 1) << std::hex << (unsigned int)imm;

	p->m_operands.setOperandSize (Jaf::OP_SIZE_8);

	p->m_operands.dest ().init<char> (new Immediate<char> (imm), true);
}

void
InstructionDecoder::decodeSegRM () {
	cout << "decodeSegRM ()" << endl;

}

void
InstructionDecoder::decodeAccReg () {
	union InstMask {
		unsigned char byte;
		struct {
			unsigned int reg : 3;
		};
	};

	p->m_disassembly.setAddressingMode ("AccReg");

	InstMask im;
	im.byte = p->m_instruction_bytes[0];

	p->m_operands.setOperandSize (Jaf::OP_SIZE_16);

	p->m_disasm << Jaf::reg_index_16_names[Jaf::REG_AX] << ", ";
	p->m_operands.dest ().init<unsigned short> (p->m_eunit->getRegAX ());

	p->m_disasm << Jaf::reg_index_16_names[im.reg];
	p->m_operands.src ().init<unsigned short> (p->m_eunit->getReg16 (im.reg));
}

void
InstructionDecoder::decodeAccMem () {
	union InstMask {
		unsigned char byte;
		struct {
			unsigned int w : 1;
			unsigned int d : 1;
		};
	};

	p->m_disassembly.setAddressingMode ("AccMem");

	InstMask im;
	im.byte = p->m_instruction_bytes[0];

	const unsigned short mem = p->m_biu->getInstructionBytes<unsigned short> ();
	unsigned char *bytes;
	bytes = (unsigned char*)&mem;
	for (size_t i = 0; i < sizeof(mem); ++i) {
		p->m_instruction_bytes.push_back (bytes[i]);
	}

	p->m_operands.setOperandSize (im.w);

	if (im.w) { //16 bits
		if (!im.d == 0) {
			p->m_disasm << "[" << std::setfill ('0') << std::setw (sizeof(mem) << 1) << std::hex << (unsigned int)mem << "], ax";
			p->m_operands.dest ().init<unsigned short> (p->m_biu->getMemoryAddress<unsigned short> (p->m_biu->getSegRegDS (), mem), true);
			p->m_operands.src ().init<unsigned short> (p->m_eunit->getRegAX ());
		}
		else {
			p->m_disasm << "ax, [" << std::setfill ('0') << std::setw (sizeof(mem) << 1) << std::hex << (unsigned int)mem << "]";
			p->m_operands.dest ().init<unsigned short> (p->m_eunit->getRegAX ());
			p->m_operands.src ().init<unsigned short> (p->m_biu->getMemoryAddress<unsigned short> (p->m_biu->getSegRegDS (), mem), true);
		}
	}
	else { //8 bits
		if (!im.d == 0) {
			p->m_disasm << "[" << std::setfill ('0') << std::setw (sizeof(mem) << 1) << std::hex << (unsigned int)mem << "], al";
			p->m_operands.dest ().init<unsigned char> (p->m_biu->getMemoryAddress<unsigned char> (p->m_biu->getSegRegDS (), mem), true);
			p->m_operands.src ().init<unsigned char> (p->m_eunit->getRegAL ());
		}
		else {
			p->m_disasm << "al, [" << std::setfill ('0') << std::setw (sizeof(mem) << 1) << std::hex << (unsigned int)mem << "]";
			p->m_operands.dest ().init<unsigned char> (p->m_eunit->getRegAL ());
			p->m_operands.src ().init<unsigned char> (p->m_biu->getMemoryAddress<unsigned char> (p->m_biu->getSegRegDS (), mem), true);
		}
	}
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

	p->m_disassembly.setAddressingMode ("RegImm");

	InstMask im;
	im.byte = p->m_instruction_bytes[0];

	p->m_disasm << Jaf::reg_index_16_names[im.reg] << ", ";

	p->m_operands.setOperandSize (im.w);

	unsigned char *bytes;
	if (im.w) { //16 bits
		p->m_operands.dest ().init<unsigned short> (p->m_eunit->getReg16 (im.reg));

		const unsigned short imm = p->m_biu->getInstructionBytes<unsigned short> ();
		bytes = (unsigned char*)&imm;
		for (size_t i = 0; i < sizeof(imm); ++i) {
			p->m_instruction_bytes.push_back (bytes[i]);
		}

		p->m_disasm << std::setfill ('0') << std::setw (sizeof(imm) << 1) << std::hex << (unsigned int)imm;

		p->m_operands.src ().init<unsigned short> (new Immediate<unsigned short> (imm), true);
	}
	else { //8 bits
		p->m_operands.dest ().init<unsigned char> (p->m_eunit->getReg8 (im.reg));

		const unsigned char imm = p->m_biu->getInstructionBytes<unsigned char> ();
		bytes = (unsigned char*)&imm;
		for (size_t i = 0; i < sizeof(imm); ++i) {
			p->m_instruction_bytes.push_back (bytes[i]);
		}

		p->m_disasm << std::setfill ('0') << std::setw (sizeof(imm) << 1) << std::hex << (unsigned int)imm;

		p->m_operands.src ().init<unsigned char> (new Immediate<unsigned char> (imm), true);
	}
}

void
InstructionDecoder::decodeIntra () {
	p->m_disassembly.setAddressingMode ("Intra");

	unsigned char *bytes;
	const short imm = p->m_biu->getInstructionBytes<short> ();
	bytes = (unsigned char*)&imm;
	for (size_t i = 0; i < sizeof(imm); ++i) {
		p->m_instruction_bytes.push_back (bytes[i]);
	}

	p->m_disasm << std::setfill ('0') << std::setw (sizeof(imm) << 1) << std::hex << (unsigned int)imm;

	p->m_operands.setOperandSize (Jaf::OP_SIZE_16);

	p->m_operands.dest ().init<short> (new Immediate<short> (imm), true);
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


