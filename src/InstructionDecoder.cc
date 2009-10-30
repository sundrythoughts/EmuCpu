#include "InstructionDecoder.hh"

#include "CpuComponents.hh"
#include "ExecutionUnit.hh"
#include "BusInterfaceUnit.hh"

#include "Defines.hh"
#include "Instruction.hh"
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


class InstructionDecoderPrivate {
public:
	CpuComponents *m_cpu;
	ExecutionUnit *m_eunit;
	BusInterfaceUnit *m_biu;

	Jaf::ModRM m_modrm;

	Instruction m_inst;

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

	p->m_inst.connectTo (*this);
	p->m_inst.connectTo (*p->m_eunit);
}

void
InstructionDecoder::getInstruction () {
	decodeInstruction ();
}

void
InstructionDecoder::nextInstruction () {
	if (!p->m_inst.getBytes ().empty ()) {
		p->m_inst.execute ();
	}

	p->m_disasm.str ("");
	p->m_inst.reset ();
	p->m_disasm.clear ();

	if (p->m_cpu->getHalt ()) {
		return;
	}

	p->m_disassembly.setSegmentOffset (p->m_biu->getSegRegCS (), p->m_biu->getRegIP ());
	p->m_inst.addBytes (p->m_biu->getInstructionBytes<unsigned char> ());

	decodeInstruction ();

	p->m_signal_next_instruction.emit (p->m_disassembly.getSegmentOffset (),
	                                   p->m_disassembly.getMachineCode (),
	                                   p->m_disassembly.getAssembly (),
	                                   p->m_disassembly.getAddressingMode ());
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
	p->m_inst.setItem (InstructionTable::one_byte_opcode_instruction_map[p->m_inst.getBytes ()[0]]);

	//decode modrm if instruction has it
	if (p->m_inst.getItem ().has_modrm) {
		p->m_inst.addBytes (p->m_biu->getInstructionBytes<unsigned char> ());

		//check secondary table
		size_t grp = p->m_inst.getItem ().group;
		if (grp <= InstructionTable::GROUP_6) {
			Jaf::ModRM modrm;
			modrm.byte = p->m_inst.getBytes ()[1];
			p->m_inst.setItem (InstructionTable::one_byte_opcode_instruction_extension_map[grp][modrm.reg]);
		}
	}

	//get the mnemonic for disassembly
	p->m_disasm << p->m_inst.getItem ().mnemonic << " ";

	p->m_inst.decode ();

	//output disassembly
	p->m_disassembly.setMachineCode (p->m_inst.getBytes ());
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
	union InstMask {
		unsigned char byte;
		struct {
			unsigned int w : 1;
			unsigned int d : 1;
		};
	};

	p->m_disassembly.setAddressingMode ("RegRM");

	InstMask im;
	im.byte = p->m_inst.getBytes ()[0];
	Jaf::ModRM modrm;
	modrm.byte = p->m_inst.getBytes ()[1];

	p->m_inst.operands ().setOperandSize (im.w);

	switch (modrm.mod) {
	case 0: //
		std::cout << "decodeRegRM (): mod == 0 is not yet implemented." << std::endl;
		break;
	case 1:
		std::cout << "decodeRegRM (): mod == 1 is not yet implemented." << std::endl;
		break;
	case 2: //Sign extende byte mode
		std::cout << "decodeRegRM (): mod == 2 is not yet implemented." << std::endl;
		break;
	case 3: //Register mode
		if (im.w) { //16 bits
			if (im.d) { //reg is dest
				p->m_inst.operands ().dest ().init<unsigned short> (p->m_eunit->getReg16 (modrm.reg));
				p->m_inst.operands ().src ().init<unsigned short> (p->m_eunit->getReg16 (modrm.rm));

				p->m_disasm << Jaf::reg_index_16_names[modrm.reg];
				p->m_disasm << ", ";
				p->m_disasm << Jaf::reg_index_16_names[modrm.rm];
			}
			else { //reg is src
				p->m_inst.operands ().src ().init<unsigned short> (p->m_eunit->getReg16 (modrm.reg));
				p->m_inst.operands ().dest ().init<unsigned short> (p->m_eunit->getReg16 (modrm.rm));

				p->m_disasm << Jaf::reg_index_16_names[modrm.rm];
				p->m_disasm << ", ";
				p->m_disasm << Jaf::reg_index_16_names[modrm.reg];
			}
		}
		else { //8 bits
			if (im.d) { //reg is dest
				p->m_inst.operands ().dest ().init<unsigned char> (p->m_eunit->getReg8 (modrm.reg));
				p->m_inst.operands ().src ().init<unsigned char> (p->m_eunit->getReg8 (modrm.rm));

				p->m_disasm << Jaf::reg_index_8_names[modrm.reg];
				p->m_disasm << ", ";
				p->m_disasm << Jaf::reg_index_8_names[modrm.rm];
			}
			else { //reg is src
				p->m_inst.operands ().src ().init<unsigned char> (p->m_eunit->getReg8 (modrm.reg));
				p->m_inst.operands ().dest ().init<unsigned char> (p->m_eunit->getReg8 (modrm.rm));

				p->m_disasm << Jaf::reg_index_8_names[modrm.rm];
				p->m_disasm << ", ";
				p->m_disasm << Jaf::reg_index_8_names[modrm.reg];
			}
		}

		break;
	}
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
	im.byte = p->m_inst.getBytes ()[0];

	p->m_inst.operands ().setOperandSize (im.w);

	if (im.w) { //16 bits
		p->m_disasm << "ax";

		p->m_inst.operands ().dest ().init<unsigned short> (p->m_eunit->getRegAX ());

		const unsigned short imm = p->m_biu->getInstructionBytes<unsigned short> ();
		p->m_inst.addBytes (imm);

		p->m_disasm << ", " << std::setfill ('0') << std::setw (sizeof(imm) << 1) << std::hex << (unsigned int)imm;

		p->m_inst.operands ().src ().init<unsigned short> (new Immediate<unsigned short> (imm), true);
	}
	else { //8 bits
		p->m_disasm << "al";

		p->m_inst.operands ().dest ().init<unsigned char> (p->m_eunit->getRegAL ());

		const unsigned char imm = p->m_biu->getInstructionBytes<unsigned char> ();
		p->m_inst.addBytes (imm);

		p->m_disasm << ", " << std::setfill ('0') << std::setw (sizeof(imm) << 1) << std::hex << (unsigned int)imm;

		p->m_inst.operands ().src ().init<unsigned char> (new Immediate<unsigned char> (imm), true);
	}
}

void
InstructionDecoder::decodeSegment () {
	std::cout << "decodeSegment ()" << std::endl;
}

void
InstructionDecoder::decodeAcc () {
	p->m_disassembly.setAddressingMode ("Acc");
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
	im.byte = p->m_inst.getBytes ()[0];

	p->m_inst.operands ().setOperandSize (Jaf::OP_SIZE_16);

	p->m_disasm << Jaf::reg_index_16_names[im.reg];

	p->m_inst.operands ().dest ().init<unsigned short> (p->m_eunit->getReg16 (im.reg));
}

void
InstructionDecoder::decodeShort () {
	p->m_disassembly.setAddressingMode ("Short");

	const char imm = p->m_biu->getInstructionBytes<char> ();
	p->m_inst.addBytes ((unsigned char)imm);

	p->m_disasm << ", " << std::setfill ('0') << std::setw (sizeof(imm) << 1) << std::hex << (unsigned int)(p->m_biu->getRegIP () + imm);

	p->m_inst.operands ().setOperandSize (Jaf::OP_SIZE_8);

	p->m_inst.operands ().dest ().init<char> (new Immediate<char> (imm), true);
}

void
InstructionDecoder::decodeSegRM () {
	std::cout << "decodeSegRM ()" << std::endl;

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
	im.byte = p->m_inst.getBytes ()[0];

	p->m_inst.operands ().setOperandSize (Jaf::OP_SIZE_16);

	p->m_disasm << Jaf::reg_index_16_names[Jaf::REG_AX] << ", ";
	p->m_inst.operands ().dest ().init<unsigned short> (p->m_eunit->getRegAX ());

	p->m_disasm << Jaf::reg_index_16_names[im.reg];
	p->m_inst.operands ().src ().init<unsigned short> (p->m_eunit->getReg16 (im.reg));
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
	im.byte = p->m_inst.getBytes ()[0];

	const unsigned short mem = p->m_biu->getInstructionBytes<unsigned short> ();
	p->m_inst.addBytes (mem);

	p->m_inst.operands ().setOperandSize (im.w);

	if (im.w) { //16 bits
		if (!im.d == 0) {
			p->m_disasm << "[" << std::setfill ('0') << std::setw (sizeof(mem) << 1) << std::hex << (unsigned int)mem << "], ax";
			p->m_inst.operands ().dest ().init<unsigned short> (p->m_biu->getMemoryAddress<unsigned short> (p->m_biu->getSegRegDS (), mem), true);
			p->m_inst.operands ().src ().init<unsigned short> (p->m_eunit->getRegAX ());
		}
		else {
			p->m_disasm << "ax, [" << std::setfill ('0') << std::setw (sizeof(mem) << 1) << std::hex << (unsigned int)mem << "]";
			p->m_inst.operands ().dest ().init<unsigned short> (p->m_eunit->getRegAX ());
			p->m_inst.operands ().src ().init<unsigned short> (p->m_biu->getMemoryAddress<unsigned short> (p->m_biu->getSegRegDS (), mem), true);
		}
	}
	else { //8 bits
		if (!im.d == 0) {
			p->m_disasm << "[" << std::setfill ('0') << std::setw (sizeof(mem) << 1) << std::hex << (unsigned int)mem << "], al";
			p->m_inst.operands ().dest ().init<unsigned char> (p->m_biu->getMemoryAddress<unsigned char> (p->m_biu->getSegRegDS (), mem), true);
			p->m_inst.operands ().src ().init<unsigned char> (p->m_eunit->getRegAL ());
		}
		else {
			p->m_disasm << "al, [" << std::setfill ('0') << std::setw (sizeof(mem) << 1) << std::hex << (unsigned int)mem << "]";
			p->m_inst.operands ().dest ().init<unsigned char> (p->m_eunit->getRegAL ());
			p->m_inst.operands ().src ().init<unsigned char> (p->m_biu->getMemoryAddress<unsigned char> (p->m_biu->getSegRegDS (), mem), true);
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
	im.byte = p->m_inst.getBytes ()[0];

	p->m_disasm << Jaf::reg_index_16_names[im.reg] << ", ";

	p->m_inst.operands ().setOperandSize (im.w);

	//unsigned char *bytes;
	if (im.w) { //16 bits
		p->m_inst.operands ().dest ().init<unsigned short> (p->m_eunit->getReg16 (im.reg));

		const unsigned short imm = p->m_biu->getInstructionBytes<unsigned short> ();
		p->m_inst.addBytes (imm);

		p->m_disasm << std::setfill ('0') << std::setw (sizeof(imm) << 1) << std::hex << (unsigned int)imm;

		p->m_inst.operands ().src ().init<unsigned short> (new Immediate<unsigned short> (imm), true);
	}
	else { //8 bits
		p->m_inst.operands ().dest ().init<unsigned char> (p->m_eunit->getReg8 (im.reg));

		const unsigned char imm = p->m_biu->getInstructionBytes<unsigned char> ();
		p->m_inst.addBytes (imm);

		p->m_disasm << std::setfill ('0') << std::setw (sizeof(imm) << 1) << std::hex << (unsigned int)imm;

		p->m_inst.operands ().src ().init<unsigned char> (new Immediate<unsigned char> (imm), true);
	}
}

void
InstructionDecoder::decodeIntra () {
	p->m_disassembly.setAddressingMode ("Intra");

	const short imm = p->m_biu->getInstructionBytes<short> ();
	p->m_inst.addBytes (imm);

	p->m_disasm << std::setfill ('0') << std::setw (sizeof(imm) << 1) << std::hex << (unsigned int)(p->m_biu->getRegIP () + imm);

	p->m_inst.operands ().setOperandSize (Jaf::OP_SIZE_16);

	p->m_inst.operands ().dest ().init<short> (new Immediate<short> (imm), true);
}

void
InstructionDecoder::decodeInter () {
	std::cout << "decodeInter ()" << std::endl;
}

void
InstructionDecoder::decodeXferInd () {
	std::cout << "decodeXferInd ()" << std::endl;
}

void
InstructionDecoder::decodeRMImm () {
	std::cout << "decodeRMImm ()" << std::endl;
}

void
InstructionDecoder::decodeAccPort () {
	std::cout << "decodeAccPort ()" << std::endl;
}

void
InstructionDecoder::decodeRM () {
	std::cout << "decodeRM ()" << std::endl;
}

void
InstructionDecoder::decodeFlags () {
	p->m_disassembly.setAddressingMode ("Flags");
}

void
InstructionDecoder::decodeRetPop () {
	std::cout << "decodeRetPop ()" << std::endl;
}

void
InstructionDecoder::decodeType3 () {
	std::cout << "decodeType3 ()" << std::endl;
}

void
InstructionDecoder::decodeEscNum () {
	std::cout << "decodeEscNum ()" << std::endl;
}

void
InstructionDecoder::decodeAccVPort () {
	std::cout << "decodeAccVPort ()" << std::endl;
}

void
InstructionDecoder::decodeAccBase () {
	std::cout << "decodeAccBase ()" << std::endl;
}

void
InstructionDecoder::decodeIntNum () {
	std::cout << "decodeIntNum ()" << std::endl;
}

void
InstructionDecoder::decodeString () {
	std::cout << "decodeString ()" << std::endl;
}

