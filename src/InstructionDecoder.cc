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
	std::ostringstream m_dis_src;
	std::ostringstream m_dis_dest;

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
	p->m_dis_src.str ("");
	p->m_dis_dest.str ("");
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

	//get src and dest for disassembly
	p->m_disasm << p->m_dis_dest.str () << ((!p->m_dis_src.str ().empty ()) ? ", " : "") << p->m_dis_src.str ();

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
InstructionDecoder::decodeRm0To7 () {
	//FIXME - this should help to remove duplicate code in ModRM stuff
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

	if (modrm.mod == 3) {
		((im.d) ? p->m_dis_dest : p->m_dis_src) << Jaf::getRegIndexName (im.w, modrm.reg);
		((im.d) ? p->m_dis_src : p->m_dis_dest) << Jaf::getRegIndexName (im.w, modrm.rm);


		//FIXME - make sure this works before deleting the previous version
		if (im.w) { //16 bits
			((im.d) ? p->m_inst.operands ().dest () : p->m_inst.operands ().src ()).init<unsigned short> (p->m_eunit->getReg16 (modrm.reg));
			((im.d) ? p->m_inst.operands ().src () : p->m_inst.operands ().dest ()).init<unsigned short> (p->m_eunit->getReg16 (modrm.rm));
		}
		else { //8 bits
			((im.d) ? p->m_inst.operands ().dest () : p->m_inst.operands ().src ()).init<unsigned char> (p->m_eunit->getReg8 (modrm.reg));
			((im.d) ? p->m_inst.operands ().src () : p->m_inst.operands ().dest ()).init<unsigned char> (p->m_eunit->getReg8 (modrm.rm));
		}
	}
	else {
		((im.d) ? p->m_dis_dest : p->m_dis_src) << Jaf::getRegIndexName (im.w, modrm.reg);

		unsigned short mem;
		switch (modrm.rm) {
			case 0: { //[bx + si {+ d8}{+ d16}]
				((im.d) ? p->m_dis_src : p->m_dis_dest) << "[" << Jaf::getRegIndex16Name (Jaf::REG_BX) << " + " << Jaf::getRegIndex16Name (Jaf::REG_SI);
				mem = p->m_eunit->getRegBX () + p->m_eunit->getRegSI (); //zero displacement
			} break;

			case 1: { //[bx + di {+ d8}{+ d16}]
				((im.d) ? p->m_dis_src : p->m_dis_dest) << "[" << Jaf::getRegIndex16Name (Jaf::REG_BX) << " + " << Jaf::getRegIndex16Name (Jaf::REG_DI);
				mem = p->m_eunit->getRegBX () + p->m_eunit->getRegDI (); //zero displacement
			} break;

			case 2: { //[bp + si {+ d8}{+ d16}]
				((im.d) ? p->m_dis_src : p->m_dis_dest) << "[" << Jaf::getRegIndex16Name (Jaf::REG_BP) << " + " << Jaf::getRegIndex16Name (Jaf::REG_SI);
				mem = p->m_eunit->getRegBP () + p->m_eunit->getRegSI (); //zero displacement
			} break;

			case 3: { //[bp + di {+ d8}{+ d16}]
				((im.d) ? p->m_dis_src : p->m_dis_dest) << "[" << Jaf::getRegIndex16Name (Jaf::REG_BP) << " + " << Jaf::getRegIndex16Name (Jaf::REG_DI);
				mem = p->m_eunit->getRegBP () + p->m_eunit->getRegDI (); //zero displacement
			} break;

			case 4: { //[si {+ d8}{+ d16}]
				((im.d) ? p->m_dis_src : p->m_dis_dest) << "[" << Jaf::getRegIndex16Name (Jaf::REG_SI);
				mem = p->m_eunit->getRegSI (); //zero displacement
			} break;

			case 5: { //[di {+ d8}{+ d16}]
				((im.d) ? p->m_dis_src : p->m_dis_dest) << "[" << Jaf::getRegIndex16Name (Jaf::REG_DI);
				mem = p->m_eunit->getRegDI (); //zero displacement
			} break;

			case 6: { //[DIRECT ADDRESS] or [bp {+ d8}{+ d16}]
				((im.d) ? p->m_dis_src : p->m_dis_dest) << "[" << Jaf::getRegIndex16Name (Jaf::REG_BP);
				mem = p->m_eunit->getRegBP ();

				if (modrm.mod == 0) { //zero displacement SPECIAL CASE
					mem = p->m_biu->getInstructionBytes<unsigned short> ();
					p->m_inst.addBytes (mem);
					((im.d) ? p->m_dis_src : p->m_dis_dest).str ("");
					((im.d) ? p->m_dis_src : p->m_dis_dest) << "[" << (unsigned int)mem << "]";
				}
			} break;

			case 7: { //[bx {+ d8}{+ d16}]
				((im.d) ? p->m_dis_src : p->m_dis_dest) << "[" << Jaf::getRegIndex16Name (Jaf::REG_BX);
				mem = p->m_eunit->getRegBX (); //zero displacement
			} break;
		}

		switch (modrm.mod) {
			case 1: { //sign extend next byte
				unsigned char udis = p->m_biu->getInstructionBytes<unsigned char> ();
				p->m_inst.addBytes (udis);
				mem += (short)udis;
				((im.d) ? p->m_dis_src : p->m_dis_dest) << " + " << (unsigned int)udis << "]";
			} break;
			case 2: { //next two bytes
				unsigned short udis = p->m_biu->getInstructionBytes<unsigned short> ();
				p->m_inst.addBytes (udis);
				mem += udis;
				((im.d) ? p->m_dis_src : p->m_dis_dest) << " + " << (unsigned int)udis << "]";
			} break;
		}


		//FIXME - make sure this works before deleting the previous version
		if (im.w) { //16 bits
			((im.d) ? p->m_inst.operands ().dest () : p->m_inst.operands ().src ()).init<unsigned short> (p->m_eunit->getReg16 (modrm.reg));
			((im.d) ? p->m_inst.operands ().src () : p->m_inst.operands ().dest ()).init<unsigned short> (p->m_biu->getMemoryAddress<unsigned short> (p->m_biu->getSegRegDS (), mem), true);
		}
		else { //8 bits
			((im.d) ? p->m_inst.operands ().dest () : p->m_inst.operands ().src ()).init<unsigned char> (p->m_eunit->getReg8 (modrm.reg));
			((im.d) ? p->m_inst.operands ().src () : p->m_inst.operands ().dest ()).init<unsigned char> (p->m_biu->getMemoryAddress<unsigned char> (p->m_biu->getSegRegDS (), mem), true);
		}
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

	p->m_dis_dest << Jaf::getRegIndexName (im.w, Jaf::REG_AX);

	if (im.w) { //16 bits
		p->m_inst.operands ().dest ().init<unsigned short> (p->m_eunit->getRegAX ());

		const unsigned short imm = p->m_biu->getInstructionBytes<unsigned short> ();
		p->m_inst.addBytes (imm);

		p->m_dis_src << std::setfill ('0') << std::setw (sizeof(imm) << 1) << std::hex << (unsigned int)imm;

		p->m_inst.operands ().src ().init<unsigned short> (new Immediate<unsigned short> (imm), true);
	}
	else { //8 bits
		p->m_inst.operands ().dest ().init<unsigned char> (p->m_eunit->getRegAL ());

		const unsigned char imm = p->m_biu->getInstructionBytes<unsigned char> ();
		p->m_inst.addBytes (imm);

		p->m_dis_src << std::setfill ('0') << std::setw (sizeof(imm) << 1) << std::hex << (unsigned int)imm;

		p->m_inst.operands ().src ().init<unsigned char> (new Immediate<unsigned char> (imm), true);
	}
}

void
InstructionDecoder::decodeSegment () {
	union InstMask {
		unsigned char byte;
		struct {
			unsigned int _padding : 3;
			unsigned int sreg : 2;
		};
	};

	p->m_disassembly.setAddressingMode ("Segment");

	InstMask im;
	im.byte = p->m_inst.getBytes ()[0];

	p->m_inst.operands ().setOperandSize (Jaf::OP_SIZE_16);

	p->m_dis_dest << Jaf::getSegRegIndexName (im.sreg);

	p->m_inst.operands ().dest ().init<unsigned short> (p->m_biu->getSegReg (im.sreg));
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

	p->m_dis_dest << Jaf::getRegIndex16Name (im.reg);

	p->m_inst.operands ().dest ().init<unsigned short> (p->m_eunit->getReg16 (im.reg));
}

void
InstructionDecoder::decodeShort () {
	p->m_disassembly.setAddressingMode ("Short");

	const char imm = p->m_biu->getInstructionBytes<char> ();
	p->m_inst.addBytes ((unsigned char)imm);

	p->m_dis_dest << std::setfill ('0') << std::setw (sizeof(imm) << 1) << std::hex << (unsigned int)(p->m_biu->getRegIP () + imm);

	p->m_inst.operands ().setOperandSize (Jaf::OP_SIZE_8);

	p->m_inst.operands ().dest ().init<char> (new Immediate<char> (imm), true);
}

void
InstructionDecoder::decodeSegRM () {
	//std::cout << "decodeSegRM ()" << std::endl;

	union InstMask {
		unsigned char byte;
		struct {
			unsigned int _padding : 1;
			unsigned int d : 1;
		};
	};

	p->m_disassembly.setAddressingMode ("SegRM");

	InstMask im;
	im.byte = p->m_inst.getBytes ()[0];
	Jaf::ModRM modrm;
	modrm.byte = p->m_inst.getBytes ()[1];

	p->m_inst.operands ().setOperandSize (Jaf::OP_SIZE_16);

	if (modrm.mod == 3) {
		((im.d) ? p->m_dis_dest : p->m_dis_src) << Jaf::getSegRegIndexName (modrm.reg & 3);
		((im.d) ? p->m_dis_src : p->m_dis_dest) << Jaf::getRegIndex16Name (modrm.rm);

		if (im.d) { //reg is dest
			p->m_inst.operands ().dest ().init<unsigned short> (p->m_biu->getSegReg (modrm.reg & 3));
			p->m_inst.operands ().src ().init<unsigned short> (p->m_eunit->getReg16 (modrm.rm));
		}
		else { //reg is src
			p->m_inst.operands ().src ().init<unsigned short> (p->m_biu->getSegReg (modrm.reg & 3));
			p->m_inst.operands ().dest ().init<unsigned short> (p->m_eunit->getReg16 (modrm.rm));
		}
	}
	else {
		((im.d) ? p->m_dis_dest : p->m_dis_src) << Jaf::getSegRegIndexName (modrm.reg & 3);

		unsigned short mem;
		switch (modrm.rm) {
			case 0: { //[bx + si {+ d8}{+ d16}]
				((im.d) ? p->m_dis_src : p->m_dis_dest) << "[" << Jaf::getRegIndex16Name (Jaf::REG_BX) << " + " << Jaf::getRegIndex16Name (Jaf::REG_SI);
				mem = p->m_eunit->getRegBX () + p->m_eunit->getRegSI (); //zero displacement
			} break;

			case 1: { //[bx + di {+ d8}{+ d16}]
				((im.d) ? p->m_dis_src : p->m_dis_dest) << "[" << Jaf::getRegIndex16Name (Jaf::REG_BX) << " + " << Jaf::getRegIndex16Name (Jaf::REG_DI);
				mem = p->m_eunit->getRegBX () + p->m_eunit->getRegDI (); //zero displacement
			} break;

			case 2: { //[bp + si {+ d8}{+ d16}]
				((im.d) ? p->m_dis_src : p->m_dis_dest) << "[" << Jaf::getRegIndex16Name (Jaf::REG_BP) << " + " << Jaf::getRegIndex16Name (Jaf::REG_SI);
				mem = p->m_eunit->getRegBP () + p->m_eunit->getRegSI (); //zero displacement
			} break;

			case 3: { //[bp + di {+ d8}{+ d16}]
				((im.d) ? p->m_dis_src : p->m_dis_dest) << "[" << Jaf::getRegIndex16Name (Jaf::REG_BP) << " + " << Jaf::getRegIndex16Name (Jaf::REG_DI);
				mem = p->m_eunit->getRegBP () + p->m_eunit->getRegDI (); //zero displacement
			} break;

			case 4: { //[si {+ d8}{+ d16}]
				((im.d) ? p->m_dis_src : p->m_dis_dest) << "[" << Jaf::getRegIndex16Name (Jaf::REG_SI);
				mem = p->m_eunit->getRegSI (); //zero displacement
			} break;

			case 5: { //[di {+ d8}{+ d16}]
				((im.d) ? p->m_dis_src : p->m_dis_dest) << "[" << Jaf::getRegIndex16Name (Jaf::REG_DI);
				mem = p->m_eunit->getRegDI (); //zero displacement
			} break;

			case 6: { //[DIRECT ADDRESS] or [bp {+ d8}{+ d16}]
				((im.d) ? p->m_dis_src : p->m_dis_dest) << "[" << Jaf::getRegIndex16Name (Jaf::REG_BP);
				mem = p->m_eunit->getRegBP ();

				if (modrm.mod == 0) { //zero displacement SPECIAL CASE
					mem = p->m_biu->getInstructionBytes<unsigned short> ();
					p->m_inst.addBytes (mem);
					((im.d) ? p->m_dis_src : p->m_dis_dest).str ("");
					((im.d) ? p->m_dis_src : p->m_dis_dest) << "[" << (unsigned int)mem << "]";
				}
			} break;

			case 7: { //[bx {+ d8}{+ d16}]
				((im.d) ? p->m_dis_src : p->m_dis_dest) << "[" << Jaf::getRegIndex16Name (Jaf::REG_BX);
				mem = p->m_eunit->getRegBX (); //zero displacement
			} break;
		}

		switch (modrm.mod) {
			case 1: { //sign extend next byte
				unsigned char udis = p->m_biu->getInstructionBytes<unsigned char> ();
				p->m_inst.addBytes (udis);
				mem += (short)udis;
				((im.d) ? p->m_dis_src : p->m_dis_dest) << " + " << (unsigned int)udis << "]";
			} break;

			case 2: { //next two bytes
				unsigned short udis = p->m_biu->getInstructionBytes<unsigned short> ();
				p->m_inst.addBytes (udis);
				mem += udis;
				((im.d) ? p->m_dis_src : p->m_dis_dest) << " + " << (unsigned int)udis << "]";
			} break;
		}

		if (im.d) { //reg is dest
			p->m_inst.operands ().dest ().init<unsigned short> (p->m_biu->getSegReg (modrm.reg & 3));
			p->m_inst.operands ().src ().init<unsigned short> (p->m_biu->getMemoryAddress<unsigned short> (p->m_biu->getSegRegDS (), mem), true);
		}
		else { //reg is src
			p->m_inst.operands ().src ().init<unsigned short> (p->m_biu->getSegReg (modrm.reg & 3));
			p->m_inst.operands ().dest ().init<unsigned short> (p->m_biu->getMemoryAddress<unsigned short> (p->m_biu->getSegRegDS (), mem), true);
		}
	}
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

	p->m_dis_dest << Jaf::getRegIndex16Name (Jaf::REG_AX);
	p->m_inst.operands ().dest ().init<unsigned short> (p->m_eunit->getRegAX ());

	p->m_dis_src << Jaf::getRegIndex16Name (im.reg);
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

	unsigned short mem = p->m_biu->getInstructionBytes<unsigned short> ();
	p->m_inst.addBytes (mem);

	p->m_inst.operands ().setOperandSize (im.w);

	((!im.d) ? p->m_dis_dest : p->m_dis_src) << Jaf::getRegIndexName (im.w, Jaf::REG_AX);
	((!im.d) ? p->m_dis_src : p->m_dis_dest) << "[" << std::setfill ('0') << std::setw (sizeof(mem) << 1) << std::hex << (unsigned int)mem << "]";

	//FIXME - make sure this works before deleting the previous version
	if (im.w) { //16 bits
		((im.d) ? p->m_inst.operands ().dest () : p->m_inst.operands ().src ()).init<unsigned short> (p->m_biu->getMemoryAddress<unsigned short> (p->m_biu->getSegRegDS (), mem), true);
		((im.d) ? p->m_inst.operands ().src () : p->m_inst.operands ().dest ()).init<unsigned short> (p->m_eunit->getRegAX ());
	}
	else { //8 bits
		((im.d) ? p->m_inst.operands ().dest () : p->m_inst.operands ().src ()).init<unsigned char> (p->m_biu->getMemoryAddress<unsigned char> (p->m_biu->getSegRegDS (), mem), true);
		((im.d) ? p->m_inst.operands ().src () : p->m_inst.operands ().dest ()).init<unsigned char> (p->m_eunit->getRegAL ());
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

	p->m_dis_dest << Jaf::getRegIndex16Name (im.reg);

	p->m_inst.operands ().setOperandSize (im.w);

	if (im.w) { //16 bits
		p->m_inst.operands ().dest ().init<unsigned short> (p->m_eunit->getReg16 (im.reg));

		const unsigned short imm = p->m_biu->getInstructionBytes<unsigned short> ();
		p->m_inst.addBytes (imm);

		p->m_dis_src << std::setfill ('0') << std::setw (sizeof(imm) << 1) << std::hex << (unsigned int)imm;

		p->m_inst.operands ().src ().init<unsigned short> (new Immediate<unsigned short> (imm), true);
	}
	else { //8 bits
		p->m_inst.operands ().dest ().init<unsigned char> (p->m_eunit->getReg8 (im.reg));

		const unsigned char imm = p->m_biu->getInstructionBytes<unsigned char> ();
		p->m_inst.addBytes (imm);

		p->m_dis_src << std::setfill ('0') << std::setw (sizeof(imm) << 1) << std::hex << (unsigned int)imm;

		p->m_inst.operands ().src ().init<unsigned char> (new Immediate<unsigned char> (imm), true);
	}
}

void
InstructionDecoder::decodeIntra () {
	p->m_disassembly.setAddressingMode ("Intra");

	const short imm = p->m_biu->getInstructionBytes<short> ();
	p->m_inst.addBytes (imm);

	p->m_dis_dest << std::setfill ('0') << std::setw (sizeof(imm) << 1) << std::hex << (unsigned int)(p->m_biu->getRegIP () + imm);

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
	union InstMask {
		unsigned char byte;
		struct {
			unsigned int w : 1;
		};
	};

	p->m_disassembly.setAddressingMode ("RMImm");

	InstMask im;
	im.byte = p->m_inst.getBytes ()[0];
	Jaf::ModRM modrm;
	modrm.byte = p->m_inst.getBytes ()[1];

	p->m_inst.operands ().setOperandSize (im.w);

	if (modrm.mod == 3) {
		p->m_dis_dest << Jaf::getRegIndexName (im.w, modrm.rm);

		if (im.w) { //16 bits
			p->m_inst.operands ().dest ().init<unsigned short> (p->m_eunit->getReg16 (modrm.rm));
		}
		else { //8 bits
			p->m_inst.operands ().dest ().init<unsigned char> (p->m_eunit->getReg8 (modrm.rm));
		}
	}
	else {
		unsigned short mem;
		switch (modrm.rm) {
			case 0: { //[bx + si {+ d8}{+ d16}]
				p->m_dis_dest << "[" << Jaf::getRegIndex16Name (Jaf::REG_BX) << " + " << Jaf::getRegIndex16Name (Jaf::REG_SI);
				mem = p->m_eunit->getRegBX () + p->m_eunit->getRegSI (); //zero displacement
			} break;

			case 1: { //[bx + di {+ d8}{+ d16}]
				p->m_dis_dest << "[" << Jaf::getRegIndex16Name (Jaf::REG_BX) << " + " << Jaf::getRegIndex16Name (Jaf::REG_DI);
				mem = p->m_eunit->getRegBX () + p->m_eunit->getRegDI (); //zero displacement
			} break;

			case 2: { //[bp + si {+ d8}{+ d16}]
				p->m_dis_dest << "[" << Jaf::getRegIndex16Name (Jaf::REG_BP) << " + " << Jaf::getRegIndex16Name (Jaf::REG_SI);
				mem = p->m_eunit->getRegBP () + p->m_eunit->getRegSI (); //zero displacement
			} break;

			case 3: { //[bp + di {+ d8}{+ d16}]
				p->m_dis_dest << "[" << Jaf::getRegIndex16Name (Jaf::REG_BP) << " + " << Jaf::getRegIndex16Name (Jaf::REG_DI);
				mem = p->m_eunit->getRegBP () + p->m_eunit->getRegDI (); //zero displacement
			} break;

			case 4: { //[si {+ d8}{+ d16}]
				p->m_dis_dest << "[" << Jaf::getRegIndex16Name (Jaf::REG_SI);
				mem = p->m_eunit->getRegSI (); //zero displacement
			} break;

			case 5: { //[di {+ d8}{+ d16}]
				p->m_dis_dest << "[" << Jaf::getRegIndex16Name (Jaf::REG_DI);
				mem = p->m_eunit->getRegDI (); //zero displacement
			} break;

			case 6: { //[DIRECT ADDRESS] or [bp {+ d8}{+ d16}]
				p->m_dis_dest << "[" << Jaf::getRegIndex16Name (Jaf::REG_BP);
				mem = p->m_eunit->getRegBP ();

				if (modrm.mod == 0) { //zero displacement SPECIAL CASE
					mem = p->m_biu->getInstructionBytes<unsigned short> ();
					p->m_inst.addBytes (mem);
					p->m_dis_dest.str ("");
					p->m_dis_dest << "[" << (unsigned int)mem;
				}
			} break;

			case 7: { //[bx {+ d8}{+ d16}]
				p->m_dis_dest << "[" << Jaf::getRegIndex16Name (Jaf::REG_BX);
				mem = p->m_eunit->getRegBX (); //zero displacement
			} break;
		}

		switch (modrm.mod) {
			case 0: {
				p->m_dis_dest << "]";
			} break;
			case 1: { //sign extend next byte
				unsigned char udis = p->m_biu->getInstructionBytes<unsigned char> ();
				p->m_inst.addBytes (udis);
				mem += (short)udis;
				p->m_dis_dest << " + " << (unsigned int)udis << "]";
			} break;
			case 2: { //next two bytes
				unsigned short udis = p->m_biu->getInstructionBytes<unsigned short> ();
				p->m_inst.addBytes (udis);
				mem += udis;
				p->m_dis_dest << " + " << (unsigned int)udis << "]";
			} break;
		}

		if (im.w) { //16 bits
			p->m_inst.operands ().dest ().init<unsigned short> (p->m_biu->getMemoryAddress<unsigned short> (p->m_biu->getSegRegDS (), mem), true);
		}
		else { //8 bits
			p->m_inst.operands ().dest ().init<unsigned char> (p->m_biu->getMemoryAddress<unsigned char> (p->m_biu->getSegRegDS (), mem), true);
		}
	}

	if (im.byte == 0x83) {
		char immc = p->m_biu->getInstructionBytes<char> ();
		p->m_inst.addBytes ((unsigned char)immc);
		const unsigned short imms = (short)immc;
		p->m_inst.operands ().src ().init<unsigned short> (new Immediate<unsigned short> (imms), true);
		p->m_dis_src << std::setfill ('0') << std::setw (sizeof(imms) << 1) << std::hex << (unsigned short)imms;
	}
	else if (im.w) { //16 bits
		const unsigned short imm = p->m_biu->getInstructionBytes<unsigned short> ();
		p->m_inst.addBytes (imm);
		p->m_inst.operands ().src ().init<unsigned short> (new Immediate<unsigned short> (imm), true);
		p->m_dis_src << std::setfill ('0') << std::setw (sizeof(imm) << 1) << std::hex << (unsigned int)imm;
	}
	else { // 8 bits
		const unsigned char imm = p->m_biu->getInstructionBytes<unsigned char> ();
		p->m_inst.addBytes (imm);
		p->m_inst.operands ().src ().init<unsigned char> (new Immediate<unsigned char> (imm), true);
		p->m_dis_src << std::setfill ('0') << std::setw (sizeof(imm) << 1) << std::hex << (unsigned int)imm;
	}
}

void
InstructionDecoder::decodeAccPort () {
	std::cout << "decodeAccPort ()" << std::endl;
}

void
InstructionDecoder::decodeRM () {
	union InstMask {
		unsigned char byte;
		struct {
			unsigned int w : 1;
			unsigned int v : 1;
		};
	};

	p->m_disassembly.setAddressingMode ("RM");

	InstMask im;
	im.byte = p->m_inst.getBytes ()[0];
	Jaf::ModRM modrm;
	modrm.byte = p->m_inst.getBytes ()[1];

	p->m_inst.operands ().setOperandSize (im.w);

	if (modrm.mod == 3) {
		p->m_dis_dest << Jaf::getRegIndexName (im.w, modrm.rm);

		if (im.w) { //16 bits
			p->m_inst.operands ().dest ().init<unsigned short> (p->m_eunit->getReg16 (modrm.rm));
		}
		else { //8 bits
			p->m_inst.operands ().dest ().init<unsigned char> (p->m_eunit->getReg8 (modrm.rm));
		}
	}
	else {
		unsigned short mem;
		switch (modrm.rm) {
			case 0: { //[bx + si {+ d8}{+ d16}]
				p->m_dis_dest << "[" << Jaf::getRegIndex16Name (Jaf::REG_BX) << " + " << Jaf::getRegIndex16Name (Jaf::REG_SI);
				mem = p->m_eunit->getRegBX () + p->m_eunit->getRegSI (); //zero displacement
			} break;

			case 1: { //[bx + di {+ d8}{+ d16}]
				p->m_dis_dest << "[" << Jaf::getRegIndex16Name (Jaf::REG_BX) << " + " << Jaf::getRegIndex16Name (Jaf::REG_DI);
				mem = p->m_eunit->getRegBX () + p->m_eunit->getRegDI (); //zero displacement
			} break;

			case 2: { //[bp + si {+ d8}{+ d16}]
				p->m_dis_dest << "[" << Jaf::getRegIndex16Name (Jaf::REG_BP) << " + " << Jaf::getRegIndex16Name (Jaf::REG_SI);
				mem = p->m_eunit->getRegBP () + p->m_eunit->getRegSI (); //zero displacement
			} break;

			case 3: { //[bp + di {+ d8}{+ d16}]
				p->m_dis_dest << "[" << Jaf::getRegIndex16Name (Jaf::REG_BP) << " + " << Jaf::getRegIndex16Name (Jaf::REG_DI);
				mem = p->m_eunit->getRegBP () + p->m_eunit->getRegDI (); //zero displacement
			} break;

			case 4: { //[si {+ d8}{+ d16}]
				p->m_dis_dest << "[" << Jaf::getRegIndex16Name (Jaf::REG_SI);
				mem = p->m_eunit->getRegSI (); //zero displacement
			} break;

			case 5: { //[di {+ d8}{+ d16}]
				p->m_dis_dest << "[" << Jaf::getRegIndex16Name (Jaf::REG_DI);
				mem = p->m_eunit->getRegDI (); //zero displacement
			} break;

			case 6: { //[DIRECT ADDRESS] or [bp {+ d8}{+ d16}]
				p->m_dis_dest << "[" << Jaf::getRegIndex16Name (Jaf::REG_BP);
				mem = p->m_eunit->getRegBP ();

				if (modrm.mod == 0) { //zero displacement SPECIAL CASE
					mem = p->m_biu->getInstructionBytes<unsigned short> ();
					p->m_inst.addBytes (mem);
					p->m_dis_dest.str ("");
					p->m_dis_dest << "[" << (unsigned int)mem;
				}
			} break;

			case 7: { //[bx {+ d8}{+ d16}]
				p->m_dis_dest << "[" << Jaf::getRegIndex16Name (Jaf::REG_BX);
				mem = p->m_eunit->getRegBX (); //zero displacement
			} break;
		}

		switch (modrm.mod) {
			case 0: {
				p->m_dis_dest << "]";
			} break;
			case 1: { //sign extend next byte
				unsigned char udis = p->m_biu->getInstructionBytes<unsigned char> ();
				p->m_inst.addBytes (udis);
				mem += (short)udis;
				p->m_dis_dest << " + " << (unsigned int)udis << "]";
			} break;
			case 2: { //next two bytes
				unsigned short udis = p->m_biu->getInstructionBytes<unsigned short> ();
				p->m_inst.addBytes (udis);
				mem += udis;
				p->m_dis_dest << " + " << (unsigned int)udis << "]";
			} break;
		}

		if (im.w) { //16 bits
			p->m_inst.operands ().dest ().init<unsigned short> (p->m_biu->getMemoryAddress<unsigned short> (p->m_biu->getSegRegDS (), mem), true);
		}
		else { //8 bits
			p->m_inst.operands ().dest ().init<unsigned char> (p->m_biu->getMemoryAddress<unsigned char> (p->m_biu->getSegRegDS (), mem), true);
		}
	}

	if (im.byte >= 0xD0 && im.byte <= 0xD3) {
		if (im.v) { //16 bits
			p->m_inst.operands ().src ().init<unsigned char> (new Immediate<unsigned char> (p->m_eunit->getRegCL ()), true);
			p->m_dis_src << "cl";
		}
		else { // 8 bits
			p->m_inst.operands ().src ().init<unsigned char> (new Immediate<unsigned char> (1), true);
			p->m_dis_src << "1";
		}
	}
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
	union InstMask {
		unsigned char byte;
		struct {
			unsigned int w : 1;
		};
	};

	p->m_disassembly.setAddressingMode ("String");

	InstMask im;
	im.byte = p->m_inst.getBytes ()[0];

	p->m_inst.operands ().setOperandSize (im.w);

	if (im.w) { //16 bits
		p->m_inst.operands ().dest ().init<short> (p->m_biu->getMemoryAddress<short> (p->m_biu->getSegRegDS (), p->m_eunit->getRegDI ()), true);
		p->m_inst.operands ().src ().init<short> (p->m_biu->getMemoryAddress<short> (p->m_biu->getSegRegDS (), p->m_eunit->getRegSI ()), true);
	}
	else { //8 bits
		p->m_inst.operands ().dest ().init<unsigned char> (p->m_biu->getMemoryAddress<unsigned char> (p->m_biu->getSegRegDS (), p->m_eunit->getRegDI ()), true);
		p->m_inst.operands ().src ().init<unsigned char> (p->m_biu->getMemoryAddress<unsigned char> (p->m_biu->getSegRegDS (), p->m_eunit->getRegSI ()), true);
	}
}

