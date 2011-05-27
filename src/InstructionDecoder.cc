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


#include "InstructionDecoder.hh"

#include "CpuComponents.hh"
#include "ExecutionUnit.hh"
#include "BusInterfaceUnit.hh"

#include "Defines.hh"
#include "Instruction.hh"
#include "OperandList.hh"
#include "NumberWrapper.hh"
#include "InstructionTable.hh"

#include "MemoryAddress.hh"
#include "Register.hh"
#include "Immediate.hh"

#include <vector>
//#include <utility>
//#include <cstdio>


class InstructionDecoderPrivate {
public:
	CpuComponents *m_cpu;
	ExecutionUnit *m_eunit;
	BusInterfaceUnit *m_biu;
	Instruction *m_inst;

	Jaf::ModRM m_modrm;

	std::ostringstream m_disasm;
	std::ostringstream m_dis_src;
	std::ostringstream m_dis_dest;

	sigc::signal<void,
	             const std::string&,
	             const std::string&,
	             const std::string&,
	             const std::string&> m_signal_next_instruction;
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
	p->m_inst = &cpu.getInstruction ();
}

void
InstructionDecoder::reset () {
}

void
InstructionDecoder::getInstruction () {
	decodeInstruction ();
}

void
InstructionDecoder::nextInstruction () {
	if (!p->m_inst->isNull ()) {
		p->m_inst->execute ();
		p->m_cpu->incInstCounter ();
	}

	p->m_disasm.str ("");
	disSrc ().str ("");
	disDest ().str ("");
	p->m_inst->reset ();
	p->m_disasm.clear ();

	if (p->m_cpu->getHalt ()) {
		return;
	}

	p->m_inst->disassembly ().setSegmentOffset (p->m_biu->getSegRegCS (), p->m_biu->getRegIP ());
	p->m_inst->addBytes (p->m_biu->getInstructionBytes<quint8> ());

	decodeInstruction ();

	p->m_signal_next_instruction.emit (p->m_inst->disassembly ().getSegmentOffset (),
	                                   p->m_inst->disassembly ().getMachineCode (),
	                                   p->m_inst->disassembly ().getAssembly (),
	                                   p->m_inst->disassembly ().getAddressingMode ());
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
	p->m_inst->setItem (InstructionTable::getOneByteOpcodeInstruction (p->m_inst->getByte (0)));

	//decode modrm if instruction has it
	if (p->m_inst->getItem ().has_modrm) {
		p->m_inst->addBytes (p->m_biu->getInstructionBytes<quint8> ());

		//check secondary table
		size_t grp = p->m_inst->getItem ().group;
		if (grp <= InstructionTable::GROUP_6) {
			Jaf::ModRM modrm;
			modrm.byte = p->m_inst->getByte (1);
			p->m_inst->setItem (InstructionTable::getOneByteOpcodeInstructionExtension (grp, modrm.reg));
		}
	}

	p->m_inst->decode ();

	//get the mnemonic for disassembly
	p->m_disasm << p->m_inst->getItem ().mnemonic;
	p->m_disasm << ((!disDest ().str ().empty () || !disSrc ().str ().empty ()) ? " " : "");

	//get src and dest for disassembly
	p->m_disasm << disDest ().str ();
	p->m_disasm << ((!disDest ().str ().empty () && !disSrc ().str ().empty ()) ? "," : "");
	p->m_disasm << disSrc ().str ();

	//output disassembly
	p->m_inst->disassembly ().setMachineCode (p->m_inst->getBytes ());
	p->m_inst->disassembly ().setAssembly (p->m_disasm.str ());
}

void
InstructionDecoder::decodeNotImplemented () {
	std::cerr << "decodeNotImplemented (" << std::hex << (quint32)p->m_inst->getByte (0);
	std::cerr << "): this addressing mode is not implemented or doesn't exist" << std::endl;
}

void
InstructionDecoder::decodeNone () {
	p->m_inst->disassembly ().setAddressingMode ("None");
	p->m_inst->setAddrMode (0);
}

quint16
InstructionDecoder::decodeRm0To7 (quint8 mrm, std::ostringstream &dis) {
	//FIXME - this should help to remove duplicate code in ModRM stuff

	Jaf::ModRM modrm;
	modrm.byte = mrm;
	quint16 mem;
	switch (modrm.rm) {
		case 0: { //[bx + si {+ d8}{+ d16}]
			dis << "[" << Jaf::getRegIndex16Name (Jaf::REG_BX);
			dis << "+" << Jaf::getRegIndex16Name (Jaf::REG_SI);
			mem = p->m_eunit->getRegBX () + p->m_eunit->getRegSI (); //zero displacement
		} break;

		case 1: { //[bx + di {+ d8}{+ d16}]
			dis << "[" << Jaf::getRegIndex16Name (Jaf::REG_BX);
			dis << "+" << Jaf::getRegIndex16Name (Jaf::REG_DI);
			mem = p->m_eunit->getRegBX () + p->m_eunit->getRegDI (); //zero displacement
		} break;

		case 2: { //[bp + si {+ d8}{+ d16}]
			dis << "[" << Jaf::getRegIndex16Name (Jaf::REG_BP);
			dis << "+" << Jaf::getRegIndex16Name (Jaf::REG_SI);
			mem = p->m_eunit->getRegBP () + p->m_eunit->getRegSI (); //zero displacement
		} break;

		case 3: { //[bp + di {+ d8}{+ d16}]
			dis << "[" << Jaf::getRegIndex16Name (Jaf::REG_BP);
			dis << "+" << Jaf::getRegIndex16Name (Jaf::REG_DI);
			mem = p->m_eunit->getRegBP () + p->m_eunit->getRegDI (); //zero displacement
		} break;

		case 4: { //[si {+ d8}{+ d16}]
			dis << "[" << Jaf::getRegIndex16Name (Jaf::REG_SI);
			mem = p->m_eunit->getRegSI (); //zero displacement
		} break;

		case 5: { //[di {+ d8}{+ d16}]
			dis << "[" << Jaf::getRegIndex16Name (Jaf::REG_DI);
			mem = p->m_eunit->getRegDI (); //zero displacement
		} break;

		case 6: { //[DIRECT ADDRESS] or [bp {+ d8}{+ d16}]
			dis << "[" << Jaf::getRegIndex16Name (Jaf::REG_BP);
			mem = p->m_eunit->getRegBP ();

			if (modrm.mod == 0) { //zero displacement SPECIAL CASE
				mem = p->m_biu->getInstructionBytes<quint16> ();
				p->m_inst->addBytes (mem);
				dis.str ("");
				dis << "[" << formatHexWord << (quint32)mem;
			}
		} break;

		case 7: { //[bx {+ d8}{+ d16}]
			dis << "[" << Jaf::getRegIndex16Name (Jaf::REG_BX);
			mem = p->m_eunit->getRegBX (); //zero displacement
		} break;
	}

	switch (modrm.mod) {
		case 0: {
			dis << "]";
		}break;
		case 1: { //sign extend next byte
			quint8 udis = p->m_biu->getInstructionBytes<quint8> ();
			p->m_inst->addBytes (udis);
			mem += (qint16)(qint8)udis;
			dis << "+" << formatHexByte << (quint32)udis << "]";
		} break;
		case 2: { //next two bytes
			quint16 udis = p->m_biu->getInstructionBytes<quint16> ();
			p->m_inst->addBytes (udis);
			mem += udis;
			dis << "+" << formatHexWord << (quint32)udis << "]";
		} break;
	}

	return mem;
}

void
InstructionDecoder::decodeRegRM () {
	union InstMask {
		quint8 byte;
		struct {
			uint w : 1;
			uint d : 1;
		};
	};

	p->m_inst->disassembly ().setAddressingMode ("RegRM");
	p->m_inst->setAddrMode (1);

	InstMask im;
	im.byte = p->m_inst->getByte (0);
	Jaf::ModRM modrm;
	modrm.byte = p->m_inst->getByte (1);

	p->m_inst->operands ().setOperandSize (im.w);

	if (im.byte == 0x8D) { //LEA is special because it's D bit is inverted
		im.d = 1;
	}
	else if (im.byte == 0xC4) { //LES is special because it's W and D bits are inverted
		im.w = 1;
		im.d = 1;
	}
	else if (im.byte == 0xC5) { //LDS is special because it's D bit is inverted
		im.d = 1;
	}

	if (modrm.mod == 3) {
		disDestIf (im.d) << Jaf::getRegIndexName (im.w, modrm.reg);
		disSrcIf (im.d) << Jaf::getRegIndexName (im.w, modrm.rm);

		if (im.w) { //16 bits
			instDestIf (im.d).init<quint16> (p->m_eunit->getReg16 (modrm.reg));
			instSrcIf (im.d).init<quint16> (p->m_eunit->getReg16 (modrm.rm));
		}
		else { //8 bits
			instDestIf (im.d).init<quint8> (p->m_eunit->getReg8 (modrm.reg));
			instSrcIf (im.d).init<quint8> (p->m_eunit->getReg8 (modrm.rm));
		}
	}
	else {
		disDestIf (im.d) << Jaf::getRegIndexName (im.w, modrm.reg);

		quint16 mem;
		mem = decodeRm0To7 (modrm.byte, disSrcIf (im.d));

		if (im.w) { //16 bits
			instDestIf (im.d).init<quint16> (p->m_eunit->getReg16 (modrm.reg));
			instSrcIf (im.d).init<quint16> (p->m_biu->getMemoryAddress<quint16> (p->m_biu->getSegRegDS (), mem), true);
		}
		else { //8 bits
			instDestIf (im.d).init<quint8> (p->m_eunit->getReg8 (modrm.reg));
			instSrcIf (im.d).init<quint8> (p->m_biu->getMemoryAddress<quint8> (p->m_biu->getSegRegDS (), mem), true);
		}
	}
}

void
InstructionDecoder::decodeAccImm () {
	union InstMask {
		quint8 byte;
		struct {
			uint w : 1;
		};
	};

	p->m_inst->disassembly ().setAddressingMode ("AccImm");
	p->m_inst->setAddrMode (2);

	InstMask im;
	im.byte = p->m_inst->getByte (0);

	p->m_inst->operands ().setOperandSize (im.w);

	disDest () << Jaf::getRegIndexName (im.w, Jaf::REG_AX);

	if (im.w) { //16 bits
		instDest ().init<quint16> (p->m_eunit->getRegAX ());

		const quint16 imm = p->m_biu->getInstructionBytes<quint16> ();
		p->m_inst->addBytes (imm);

		disSrc () << formatHexWord << (quint32)imm;

		instSrc ().init<quint16> (new Immediate<quint16> (imm), true);
	}
	else { //8 bits
		instDest ().init<quint8> (p->m_eunit->getRegAL ());

		const quint8 imm = p->m_biu->getInstructionBytes<quint8> ();
		p->m_inst->addBytes (imm);

		disSrc () << formatHexByte << (quint32)imm;

		instSrc ().init<quint8> (new Immediate<quint8> (imm), true);
	}
}

void
InstructionDecoder::decodeSegment () {
	union InstMask {
		quint8 byte;
		struct {
			uint _padding : 3;
			uint sreg : 2;
		};
	};

	p->m_inst->disassembly ().setAddressingMode ("Segment");
	p->m_inst->setAddrMode (3);

	InstMask im;
	im.byte = p->m_inst->getByte (0);

	p->m_inst->operands ().setOperandSize (Jaf::OP_SIZE_16);

	disDest () << Jaf::getSegRegIndexName (im.sreg);

	instDest ().init<quint16> (p->m_biu->getSegReg (im.sreg));
}

void
InstructionDecoder::decodeAcc () {
	p->m_inst->disassembly ().setAddressingMode ("Acc");
	p->m_inst->setAddrMode (4);
}

void
InstructionDecoder::decodeReg () {
	union InstMask {
		quint8 byte;
		struct {
			uint reg : 3;
		};
	};

	p->m_inst->disassembly ().setAddressingMode ("Reg");
	p->m_inst->setAddrMode (5);

	InstMask im;
	im.byte = p->m_inst->getByte (0);

	p->m_inst->operands ().setOperandSize (Jaf::OP_SIZE_16);

	disDest () << Jaf::getRegIndex16Name (im.reg);

	instDest ().init<quint16> (p->m_eunit->getReg16 (im.reg));
}

void
InstructionDecoder::decodeShort () {
	p->m_inst->disassembly ().setAddressingMode ("Short");
	p->m_inst->setAddrMode (6);

	const qint8 imm = p->m_biu->getInstructionBytes<qint8> ();
	p->m_inst->addBytes ((quint8)imm);

	disDest () << formatHexWord << (quint32)(p->m_biu->getRegIP () + imm);

	p->m_inst->operands ().setOperandSize (Jaf::OP_SIZE_8);

	instDest ().init<qint8> (new Immediate<qint8> (imm), true);
}

void
InstructionDecoder::decodeSegRM () {
	union InstMask {
		quint8 byte;
		struct {
			uint _padding : 1;
			uint d : 1;
		};
	};

	p->m_inst->disassembly ().setAddressingMode ("SegRM");
	p->m_inst->setAddrMode (7);

	InstMask im;
	im.byte = p->m_inst->getByte (0);
	Jaf::ModRM modrm;
	modrm.byte = p->m_inst->getByte (1);

	p->m_inst->operands ().setOperandSize (Jaf::OP_SIZE_16);

	if (modrm.mod == 3) {
		disDestIf (im.d) << Jaf::getSegRegIndexName (modrm.reg & 3);
		disSrcIf (im.d) << Jaf::getRegIndex16Name (modrm.rm);

		if (im.d) { //reg is dest
			instDest ().init<quint16> (p->m_biu->getSegReg (modrm.reg & 3));
			instSrc ().init<quint16> (p->m_eunit->getReg16 (modrm.rm));
		}
		else { //reg is src
			instSrc ().init<quint16> (p->m_biu->getSegReg (modrm.reg & 3));
			instDest ().init<quint16> (p->m_eunit->getReg16 (modrm.rm));
		}
	}
	else {
		disDestIf (im.d) << Jaf::getSegRegIndexName (modrm.reg & 3);

		quint16 mem;
		mem = decodeRm0To7 (modrm.byte, disSrcIf (im.d));

		if (im.d) { //reg is dest
			instDest ().init<quint16> (p->m_biu->getSegReg (modrm.reg & 3));
			instSrc ().init<quint16> (p->m_biu->getMemoryAddress<quint16> (p->m_biu->getSegRegDS (), mem), true);
		}
		else { //reg is src
			instSrc ().init<quint16> (p->m_biu->getSegReg (modrm.reg & 3));
			instDest ().init<quint16> (p->m_biu->getMemoryAddress<quint16> (p->m_biu->getSegRegDS (), mem), true);
		}
	}
}

void
InstructionDecoder::decodeAccReg () {
	union InstMask {
		quint8 byte;
		struct {
			uint reg : 3;
		};
	};

	p->m_inst->disassembly ().setAddressingMode ("AccReg");
	p->m_inst->setAddrMode (8);

	InstMask im;
	im.byte = p->m_inst->getByte (0);

	p->m_inst->operands ().setOperandSize (Jaf::OP_SIZE_16);

	disDest () << Jaf::getRegIndex16Name (Jaf::REG_AX);
	instDest ().init<quint16> (p->m_eunit->getRegAX ());

	disSrc () << Jaf::getRegIndex16Name (im.reg);
	instSrc ().init<quint16> (p->m_eunit->getReg16 (im.reg));
}

void
InstructionDecoder::decodeAccMem () {
	union InstMask {
		quint8 byte;
		struct {
			uint w : 1;
			uint d : 1;
		};
	};

	p->m_inst->disassembly ().setAddressingMode ("AccMem");
	p->m_inst->setAddrMode (9);

	InstMask im;
	im.byte = p->m_inst->getByte (0);

	quint16 mem = p->m_biu->getInstructionBytes<quint16> ();
	p->m_inst->addBytes (mem);

	p->m_inst->operands ().setOperandSize (im.w);

	disDestIf (!im.d) << Jaf::getRegIndexName (im.w, Jaf::REG_AX);
	disSrcIf (!im.d) << "[" << formatHexWord << (quint32)mem << "]";

	if (im.w) { //16 bits
		instDestIf (im.d).init<quint16> (p->m_biu->getMemoryAddress<quint16> (p->m_biu->getSegRegDS (), mem), true);
		instSrcIf (im.d).init<quint16> (p->m_eunit->getRegAX ());
	}
	else { //8 bits
		instDestIf (im.d).init<quint8> (p->m_biu->getMemoryAddress<quint8> (p->m_biu->getSegRegDS (), mem), true);
		instSrcIf (im.d).init<quint8> (p->m_eunit->getRegAL ());
	}
}

void
InstructionDecoder::decodeRegImm () {
	union InstMask {
		quint8 byte;
		struct {
			uint reg : 3;
			uint w : 1;
		};
	};

	p->m_inst->disassembly ().setAddressingMode ("RegImm");
	p->m_inst->setAddrMode (10);

	InstMask im;
	im.byte = p->m_inst->getByte (0);

	disDest () << Jaf::getRegIndexName (im.w, im.reg);

	p->m_inst->operands ().setOperandSize (im.w);

	if (im.w) { //16 bits
		instDest ().init<quint16> (p->m_eunit->getReg16 (im.reg));

		const quint16 imm = p->m_biu->getInstructionBytes<quint16> ();
		p->m_inst->addBytes (imm);

		disSrc () << formatHexWord << (quint32)imm;

		instSrc ().init<quint16> (new Immediate<quint16> (imm), true);
	}
	else { //8 bits
		instDest ().init<quint8> (p->m_eunit->getReg8 (im.reg));

		const quint8 imm = p->m_biu->getInstructionBytes<quint8> ();
		p->m_inst->addBytes (imm);

		disSrc () << formatHexByte << (quint32)imm;

		instSrc ().init<quint8> (new Immediate<quint8> (imm), true);
	}
}

void
InstructionDecoder::decodeIntra () {
	p->m_inst->disassembly ().setAddressingMode ("Intra");
	p->m_inst->setAddrMode (11);

	const qint16 imm = p->m_biu->getInstructionBytes<qint16> ();
	p->m_inst->addBytes (imm);

	disDest () << formatHexWord << (quint32)(p->m_biu->getRegIP () + imm);

	p->m_inst->operands ().setOperandSize (Jaf::OP_SIZE_16);

	instDest ().init<qint16> (new Immediate<qint16> (imm), true);
}

void
InstructionDecoder::decodeInter () {
	p->m_inst->disassembly ().setAddressingMode ("Inter");
	p->m_inst->setAddrMode (12);

	const quint16 off = p->m_biu->getInstructionBytes<quint16> ();
	p->m_inst->addBytes (off);
	const quint16 seg = p->m_biu->getInstructionBytes<quint16> ();
	p->m_inst->addBytes (seg);

	disDest () << formatHexWord << seg;
	disDest () << ":";
	disDest () << formatHexWord << off;

	p->m_inst->operands ().setOperandSize (Jaf::OP_SIZE_16);

	instDest ().init<quint16> (p->m_biu->getMemoryAddress<quint16> (seg, off), true);
}

void
InstructionDecoder::decodeXferInd () {
	union InstMask {
		quint8 byte;
	};

	p->m_inst->disassembly ().setAddressingMode ("XferInd");
	p->m_inst->setAddrMode (13);

	InstMask im;
	im.byte = p->m_inst->getByte (0);
	Jaf::ModRM modrm;
	modrm.byte = p->m_inst->getByte (1);

	p->m_inst->operands ().setOperandSize (Jaf::OP_SIZE_16);

	if (modrm.mod == 3) {
		disDest () << Jaf::getRegIndex16Name (modrm.rm);

		instDest ().init<quint16> (p->m_eunit->getReg16 (modrm.rm));
	}
	else {

		quint16 mem;
		mem = decodeRm0To7 (modrm.byte, disDest ());

		quint16 segment = p->m_biu->getMemoryData<quint16> (p->m_biu->getSegRegDS (), mem);
		quint16 offset = p->m_biu->getMemoryData<quint16> (p->m_biu->getSegRegDS (), mem + 2);
		instDest ().init<quint16> (p->m_biu->getMemoryAddress<quint16> (segment, offset), true);
	}
}

void
InstructionDecoder::decodeRMImm () {
	union InstMask {
		quint8 byte;
		struct {
			uint w : 1;
		};
	};

	p->m_inst->disassembly ().setAddressingMode ("RMImm");
	p->m_inst->setAddrMode (15);

	InstMask im;
	im.byte = p->m_inst->getByte (0);
	Jaf::ModRM modrm;
	modrm.byte = p->m_inst->getByte (1);

	p->m_inst->operands ().setOperandSize (im.w);

	if (modrm.mod == 3) {
		disDest () << Jaf::getRegIndexName (im.w, modrm.rm);

		if (im.w) { //16 bits
			instDest ().init<quint16> (p->m_eunit->getReg16 (modrm.rm));
		}
		else { //8 bits
			instDest ().init<quint8> (p->m_eunit->getReg8 (modrm.rm));
		}
	}
	else {
		quint16 mem;
		mem = decodeRm0To7 (modrm.byte, disDest ());

		if (im.w) { //16 bits
			instDest ().init<quint16> (p->m_biu->getMemoryAddress<quint16> (p->m_biu->getSegRegDS (), mem), true);
		}
		else { //8 bits
			instDest ().init<quint8> (p->m_biu->getMemoryAddress<quint8> (p->m_biu->getSegRegDS (), mem), true);
		}
	}

	if (im.byte == 0x83) {
		qint8 immc = p->m_biu->getInstructionBytes<qint8> ();
		p->m_inst->addBytes ((quint8)immc);
		const quint16 imms = (qint16)immc;
		instSrc ().init<quint16> (new Immediate<quint16> (imms), true);
		disSrc () << formatHexWord << (quint16)imms;
	}
	else if (im.w) { //16 bits
		const quint16 imm = p->m_biu->getInstructionBytes<quint16> ();
		p->m_inst->addBytes (imm);
		instSrc ().init<quint16> (new Immediate<quint16> (imm), true);
		disSrc () << formatHexWord << (quint32)imm;
	}
	else { // 8 bits
		const quint8 imm = p->m_biu->getInstructionBytes<quint8> ();
		p->m_inst->addBytes (imm);
		instSrc ().init<quint8> (new Immediate<quint8> (imm), true);
		disSrc () << formatHexByte << (quint32)imm;
	}
}

void
InstructionDecoder::decodeAccPort () {
	union InstMask {
		quint8 byte;
		struct {
			uint w : 1;
			uint d : 1;
		};
	};

	p->m_inst->disassembly ().setAddressingMode ("AccPort");
	p->m_inst->setAddrMode (16);

	InstMask im;
	im.byte = p->m_inst->getByte (0);

	p->m_inst->operands ().setOperandSize (im.w);

	disDestIf (!im.d) << Jaf::getRegIndexName (im.w, Jaf::REG_AX);

	const quint8 imm = p->m_biu->getInstructionBytes<quint8> ();
	p->m_inst->addBytes (imm);

	disSrcIf (!im.d) << formatHexByte << (quint32)imm;

	instSrcIf (!im.d).init<quint16> (new Immediate<quint16> (imm), true);

	if (im.w) { //16 bits
		instDestIf (!im.d).init<quint16> (p->m_eunit->getRegAX ());
	}
	else { //8 bits
		instDestIf (!im.d).init<quint8> (p->m_eunit->getRegAL ());
	}
}

void
InstructionDecoder::decodeRM () {
	union InstMask {
		quint8 byte;
		struct {
			uint w : 1;
			uint v : 1;
		};
	};

	p->m_inst->disassembly ().setAddressingMode ("RM");
	p->m_inst->setAddrMode (17);

	InstMask im;
	im.byte = p->m_inst->getByte (0);
	Jaf::ModRM modrm;
	modrm.byte = p->m_inst->getByte (1);

	p->m_inst->operands ().setOperandSize (im.w);

	if (modrm.mod == 3) {
		disDest () << Jaf::getRegIndexName (im.w, modrm.rm);

		if (im.w) { //16 bits
			instDest ().init<quint16> (p->m_eunit->getReg16 (modrm.rm));
		}
		else { //8 bits
			instDest ().init<quint8> (p->m_eunit->getReg8 (modrm.rm));
		}
	}
	else {
		quint16 mem;
		mem = decodeRm0To7 (modrm.byte, disDest ());

		if (im.w) { //16 bits
			instDest ().init<quint16> (p->m_biu->getMemoryAddress<quint16> (p->m_biu->getSegRegDS (), mem), true);
		}
		else { //8 bits
			instDest ().init<quint8> (p->m_biu->getMemoryAddress<quint8> (p->m_biu->getSegRegDS (), mem), true);
		}
	}

	if (im.byte >= 0xD0 && im.byte <= 0xD3) {
		if (im.v) { //16 bits
			instSrc ().init<quint8> (new Immediate<quint8> (p->m_eunit->getRegCL ()), true);
			disSrc () << "cl";
		}
		else { // 8 bits
			instSrc ().init<quint8> (new Immediate<quint8> (1), true);
			disSrc () << "1";
		}
	}
}

void
InstructionDecoder::decodeFlags () {
	p->m_inst->disassembly ().setAddressingMode ("Flags");
	p->m_inst->setAddrMode (18);
}

void
InstructionDecoder::decodeRetPop () {
	p->m_inst->disassembly ().setAddressingMode ("RetPop");
	p->m_inst->setAddrMode (19);

	p->m_inst->operands ().setOperandSize (Jaf::OP_SIZE_16);

	const quint16 imm = p->m_biu->getInstructionBytes<quint16> ();
	p->m_inst->addBytes (imm);
	instSrc ().init<quint16> (new Immediate<quint16> (imm), true);
	disSrc () << formatHexWord << imm;
}

void
InstructionDecoder::decodeType3 () {
	union InstMask {
		quint8 byte;
	};

	p->m_inst->disassembly ().setAddressingMode ("Type3");
	p->m_inst->setAddrMode (21);

	InstMask im;
	im.byte = p->m_inst->getByte (0);

	p->m_inst->operands ().setOperandSize (Jaf::OP_SIZE_8);

	instSrc ().init<quint8> (new Immediate<quint8> (3), true);
}

void
InstructionDecoder::decodeEscNum () {
	std::cout << "decodeEscNum ()" << std::endl;
	p->m_inst->setAddrMode (22);
}

void
InstructionDecoder::decodeAccVPort () {
	union InstMask {
		quint8 byte;
		struct {
			uint w : 1;
			uint d : 1;
		};
	};

	p->m_inst->disassembly ().setAddressingMode ("AccVPort");
	p->m_inst->setAddrMode (24);

	InstMask im;
	im.byte = p->m_inst->getByte (0);

	p->m_inst->operands ().setOperandSize (im.w);

	disDestIf (!im.d) << Jaf::getRegIndexName (im.w, Jaf::REG_AX);

	disSrcIf (!im.d) << Jaf::getRegIndex16Name (Jaf::REG_DX);

	instSrcIf (!im.d).init<quint16> (p->m_eunit->getRegDX ());

	if (im.w) { //16 bits
		instDestIf (!im.d).init<quint16> (p->m_eunit->getRegAX ());
	}
	else { //8 bits
		instDestIf (!im.d).init<quint8> (p->m_eunit->getRegAL ());
	}
}

void
InstructionDecoder::decodeAccBase () {
	std::cout << "decodeAccBase ()" << std::endl;
	p->m_inst->setAddrMode (25);
}

void
InstructionDecoder::decodeIntNum () {
	union InstMask {
		quint8 byte;
	};

	p->m_inst->disassembly ().setAddressingMode ("IntNum");
	p->m_inst->setAddrMode (26);

	InstMask im;
	im.byte = p->m_inst->getByte (0);

	p->m_inst->operands ().setOperandSize (Jaf::OP_SIZE_8);

	const quint8 imm = p->m_biu->getInstructionBytes<quint8> ();
	p->m_inst->addBytes (imm);

	disSrc () << formatHexByte << (quint32)imm;

	instSrc ().init<quint8> (new Immediate<quint8> (imm), true);
}

void
InstructionDecoder::decodeString () {
	union InstMask {
		quint8 byte;
		struct {
			uint w : 1;
		};
	};

	p->m_inst->disassembly ().setAddressingMode ("String");
	p->m_inst->setAddrMode (27);

	InstMask im;
	im.byte = p->m_inst->getByte (0);

	p->m_inst->operands ().setOperandSize (im.w);

	if (im.w) { //16 bits
		instDest ().init<qint16> (p->m_biu->getMemoryAddress<qint16> (p->m_biu->getSegRegDS (), p->m_eunit->getRegDI ()), true);
		instSrc ().init<qint16> (p->m_biu->getMemoryAddress<qint16> (p->m_biu->getSegRegDS (), p->m_eunit->getRegSI ()), true);
	}
	else { //8 bits
		instDest ().init<quint8> (p->m_biu->getMemoryAddress<quint8> (p->m_biu->getSegRegDS (), p->m_eunit->getRegDI ()), true);
		instSrc ().init<quint8> (p->m_biu->getMemoryAddress<quint8> (p->m_biu->getSegRegDS (), p->m_eunit->getRegSI ()), true);
	}
}

NumberWrapper&
InstructionDecoder::instSrc () {
	return p->m_inst->operands ().src ();
}

NumberWrapper&
InstructionDecoder::instDest () {
	return p->m_inst->operands ().dest ();
}

NumberWrapper&
InstructionDecoder::instSrcIf (bool b) {
	return (b ? p->m_inst->operands ().src () : p->m_inst->operands ().dest ());
}

NumberWrapper&
InstructionDecoder::instDestIf (bool b) {
	return (b ? p->m_inst->operands ().dest () : p->m_inst->operands ().src ());
}

std::ostringstream&
InstructionDecoder::disSrc () {
	return p->m_dis_src;
}

std::ostringstream&
InstructionDecoder::disDest () {
	return p->m_dis_dest;
}

std::ostringstream&
InstructionDecoder::disSrcIf (bool b) {
	return (b ? p->m_dis_src : p->m_dis_dest);
}

std::ostringstream&
InstructionDecoder::disDestIf (bool b) {
	return (b ? p->m_dis_dest : p->m_dis_src);
}

std::ostream&
InstructionDecoder::formatHexByte (std::ostream& os) {
	os << std::setfill ('0') << std::setw (sizeof(quint8) << 1) << std::hex;
	return os;
}

std::ostream&
InstructionDecoder::formatHexWord (std::ostream& os) {
	os << std::setfill ('0') << std::setw (sizeof(quint16) << 1) << std::hex;
	return os;
}

