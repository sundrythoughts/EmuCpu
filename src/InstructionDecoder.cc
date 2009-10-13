#include "InstructionDecoder.hh"
#include <iostream>
#include <cstdio>

using namespace std;

void
InstructionDecoder::connectTo (ExecutionUnit &eu) {
	m_eunit = &eu;
}

void
InstructionDecoder::connectTo (BusInterfaceUnit &biu) {
	m_biu = &biu;
}

void
InstructionDecoder::get_instruction () {
	m_disassembly = "";
	decode_instruction ();
}

void
InstructionDecoder::next_instruction () {
	//FIXME
}

const std::string&
InstructionDecoder::get_disassembly () const {
	return m_disassembly;
}

void
InstructionDecoder::decode_instruction () {
	m_inst_ptr = &m_instruction_bytes[0];
	const Instruction *inst = &Instructions::one_byte_opcode_instruction_map[*m_inst_ptr];
	cout << inst->mnemonic << " ";

	++m_inst_ptr;
	if (inst->has_modrm) {
		m_modrm.modrm = *m_inst_ptr;
		++m_inst_ptr;
	}

	unsigned int op_count = inst->operand_count;
	for (unsigned int i = 0; i < op_count; ++i) {
		(this->*(*m_decode_map.find (inst->operand_codes[i])).second) ();

		if (i < op_count - 1 ) {
			cout << ", ";
			m_disassembly += ", ";
		}
	}

	cout << endl;
}

void
InstructionDecoder::decode_operand_AH () {
	cout << "ah";
	m_disassembly += "ah"; 
}

void
InstructionDecoder::decode_operand_AL () {
	cout << "al";
	m_disassembly += "al";
}

void
InstructionDecoder::decode_operand_BH () {
	cout << "bh";
	m_disassembly += "bh";
}

void
InstructionDecoder::decode_operand_BL () {
	cout << "bl";
	m_disassembly += "bl";
}

void
InstructionDecoder::decode_operand_CH () {
	cout << "ch";
	m_disassembly += "ch";
}

void
InstructionDecoder::decode_operand_CL () {
	cout << "cl";
	m_disassembly += "cl";
}

void
InstructionDecoder::decode_operand_DH () {
	cout << "dh";
	m_disassembly += "dh";
}

void
InstructionDecoder::decode_operand_DL () {
	cout << "dl";
	m_disassembly += "dl";
}

void
InstructionDecoder::decode_operand_Ap () {
	//FIXME
}

void
InstructionDecoder::decode_operand_AX () {
	cout << "ax";
	m_disassembly += "ax";
}

void
InstructionDecoder::decode_operand_BP () {
	cout << "bp";
	m_disassembly += "bp";
}

void
InstructionDecoder::decode_operand_BX () {
	cout << "bx";
	m_disassembly += "bx";
}

void
InstructionDecoder::decode_operand_CX () {
	cout << "cx";
	m_disassembly += "cx";
}

void
InstructionDecoder::decode_operand_DI () {
	cout << "di";
	m_disassembly += "di";
}

void
InstructionDecoder::decode_operand_DX () {
	cout << "dx";
	m_disassembly += "dx";
}

void
InstructionDecoder::decode_operand_Eb () {
	//FIXME
	switch (m_modrm.mod) {
	case 0: // DISP = 0, disp-low and disp-high are absent
		break;
	case 1: // DISP = disp-low sign-extended to 16-bits, disp-high is absent
		break;
	case 2: // DISP = disp-high: disp-low
		break;
	case 3: // r/m is treated as a "reg" field
		cout << Jaf::reg_index_8_names[m_modrm.rm];
		m_disassembly += Jaf::reg_index_8_names[m_modrm.rm];
		break;
	//default - FIXME
	}
}

void
InstructionDecoder::decode_operand_Ev () {
	//FIXME
	switch (m_modrm.mod) {
	case 0: // DISP = 0, disp-low and disp-high are absent
		break;
	case 1: // DISP = disp-low sign-extended to 16-bits, disp-high is absent
		break;
	case 2: // DISP = disp-high: disp-low
		break;
	case 3: // r/m is treated as a "reg" field
		cout << Jaf::reg_index_16_names[m_modrm.rm];
		m_disassembly += Jaf::reg_index_16_names[m_modrm.rm];
		break;
	//default - FIXME
	}
}

void
InstructionDecoder::decode_operand_Ew () {
	//FIXME
	switch (m_modrm.mod) {
	case 0: // DISP = 0, disp-low and disp-high are absent
		break;
	case 1: // DISP = disp-low sign-extended to 16-bits, disp-high is absent
		break;
	case 2: // DISP = disp-high: disp-low
		break;
	case 3: // r/m is treated as a "reg" field
		cout << Jaf::reg_index_16_names[m_modrm.rm];
		m_disassembly += Jaf::reg_index_16_names[m_modrm.rm];
		break;
	//default - FIXME
	}
}

void
InstructionDecoder::decode_operand_Fv () {
	//FIXME
}

void
InstructionDecoder::decode_operand_Gb () {
	switch (m_modrm.reg) {
	case Jaf::REG_AL:
		cout << "al";
		break;
	case Jaf::REG_CL:
		cout << "cl";
		break;
	case Jaf::REG_DL:
		cout << "dl";
		break;
	case Jaf::REG_BL:
		cout << "bl";
		break;
	case Jaf::REG_AH:
		cout << "ah";
		break;
	case Jaf::REG_CH:
		cout << "ch";
		break;
	case Jaf::REG_DH:
		cout << "dh";
		break;
	case Jaf::REG_BH:
		cout << "bh";
		break;
	//default - FIXME
	}
}

void
InstructionDecoder::decode_operand_Gv () {
	switch (m_modrm.reg) {
	case Jaf::REG_AX:
		cout << "ax";
		break;
	case Jaf::REG_CX:
		cout << "cx";
		break;
	case Jaf::REG_DX:
		cout << "dx";
		break;
	case Jaf::REG_BX:
		cout << "bx";
		break;
	case Jaf::REG_SP:
		cout << "sp";
		break;
	case Jaf::REG_BP:
		cout << "bp";
		break;
	case Jaf::REG_SI:
		cout << "si";
		break;
	case Jaf::REG_DI:
		cout << "di";
		break;
	//default - FIXME
	}
}

void
InstructionDecoder::decode_operand_Ib () {
	unsigned char *imm = (unsigned char*)m_inst_ptr;
	printf ("%x", *imm);
	++m_inst_ptr;
}

void
InstructionDecoder::decode_operand_Iv () {
	unsigned short *imm = (unsigned short*)m_inst_ptr;
	printf ("%x", *imm);
	m_inst_ptr += sizeof(unsigned short);
}

void
InstructionDecoder::decode_operand_Iw () {
	unsigned short *imm = (unsigned short*)m_inst_ptr;
	printf ("%x", *imm);
	m_inst_ptr += sizeof(unsigned short);
}

void
InstructionDecoder::decode_operand_Jb () {
	unsigned char *imm = (unsigned char*)m_inst_ptr;
	printf ("%x", *imm);
	++m_inst_ptr;
}

void
InstructionDecoder::decode_operand_Jv () {
	unsigned short *imm = (unsigned short*)m_inst_ptr;
	printf ("%x", *imm);
	m_inst_ptr += sizeof(unsigned short);
}

void
InstructionDecoder::decode_operand_Mp () {
	//FIXME
}

void
InstructionDecoder::decode_operand_SI () {
	cout << "si";
}

void
InstructionDecoder::decode_operand_Sw () {
	switch (m_modrm.reg) {
	case Jaf::SREG_ES:
		cout << "es";
		break;
	case Jaf::SREG_CS:
		cout << "cs";
		break;
	case Jaf::SREG_SS:
		cout << "ss";
		break;
	case Jaf::SREG_DS:
		cout << "ds";
		break;
	//default - FIXME
	}
}

void
InstructionDecoder::decode_operand_Xb () {
	//FIXME
}

void
InstructionDecoder::decode_operand_Xv () {
	//FIXME
}

void
InstructionDecoder::decode_operand_Yb () {
	//FIXME
}

void
InstructionDecoder::decode_operand_Yv () {
	//FIXME
}

std::vector<Value>*
InstructionDecoder::decodeNone () {
}

std::vector<Value>*
InstructionDecoder::decodeRegRM () {
}

std::vector<Value>*
InstructionDecoder::decodeAccImm () {
}

std::vector<Value>*
InstructionDecoder::decodeSegment () {
}

std::vector<Value>*
InstructionDecoder::decodeAcc () {
}

std::vector<Value>*
InstructionDecoder::decodeReg () {
}

std::vector<Value>*
InstructionDecoder::decodeShort () {
}

std::vector<Value>*
InstructionDecoder::decodeSegRM () {
}

std::vector<Value>*
InstructionDecoder::decodeAccReg () {
}

std::vector<Value>*
InstructionDecoder::decodeAccMem () {
}

std::vector<Value>*
InstructionDecoder::decodeRegImm () {
}

std::vector<Value>*
InstructionDecoder::decodeIntra () {
}

std::vector<Value>*
InstructionDecoder::decodeInter () {
}

std::vector<Value>*
InstructionDecoder::decodeXferInd () {
}

std::vector<Value>*
InstructionDecoder::decodeRMImm () {
}

std::vector<Value>*
InstructionDecoder::decodeAccPort () {
}

std::vector<Value>*
InstructionDecoder::decodeRM () {
}

std::vector<Value>*
InstructionDecoder::decodeFlags () {
}

std::vector<Value>*
InstructionDecoder::decodeRetPop () {
}

std::vector<Value>*
InstructionDecoder::decodeType3 () {
}

std::vector<Value>*
InstructionDecoder::decodeEscNum () {
}

std::vector<Value>*
InstructionDecoder::decodeAccVPort () {
}

std::vector<Value>*
InstructionDecoder::decodeAccBase () {
}

std::vector<Value>*
InstructionDecoder::decodeIntNum () {
}

std::vector<Value>*
InstructionDecoder::decodeString () {
}


