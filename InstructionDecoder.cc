#include "InstructionDecoder.hh"
#include <iostream>
#include <cstdio>

using namespace std;

void
InstructionDecoder::connect_to (ExecutionUnit &eu) {
	m_eunit = &eu;
}

void
InstructionDecoder::connect_to (BusInterfaceUnit &biu) {
	m_biu = &biu;
}

void
InstructionDecoder::get_instruction () {
	decode_instruction ();
}

void
InstructionDecoder::next_instruction () {
	//FIXME
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
		}
	}

	cout << endl;
}

void
InstructionDecoder::decode_operand_AH () {
	cout << "ah";
}

void
InstructionDecoder::decode_operand_AL () {
	cout << "al";
}

void
InstructionDecoder::decode_operand_BH () {
	cout << "bh";
}

void
InstructionDecoder::decode_operand_BL () {
	cout << "bl";
}

void
InstructionDecoder::decode_operand_CH () {
	cout << "ch";
}

void
InstructionDecoder::decode_operand_CL () {
	cout << "cl";
}

void
InstructionDecoder::decode_operand_DH () {
	cout << "dh";
}

void
InstructionDecoder::decode_operand_DL () {
	cout << "dl";
}

void
InstructionDecoder::decode_operand_Ap () {
	//FIXME
}

void
InstructionDecoder::decode_operand_AX () {
	cout << "ax";
}

void
InstructionDecoder::decode_operand_BP () {
	cout << "bp";
}

void
InstructionDecoder::decode_operand_BX () {
	cout << "bx";
}

void
InstructionDecoder::decode_operand_CX () {
	cout << "cx";
}

void
InstructionDecoder::decode_operand_DI () {
	cout << "di";
}

void
InstructionDecoder::decode_operand_DX () {
	cout << "dx";
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
		cout << reg_index_8_names[m_modrm.rm];
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
		cout << reg_index_16_names[m_modrm.rm];
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
		cout << reg_index_16_names[m_modrm.rm];
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
	case REG_AL:
		cout << "al";
		break;
	case REG_CL:
		cout << "cl";
		break;
	case REG_DL:
		cout << "dl";
		break;
	case REG_BL:
		cout << "bl";
		break;
	case REG_AH:
		cout << "ah";
		break;
	case REG_CH:
		cout << "ch";
		break;
	case REG_DH:
		cout << "dh";
		break;
	case REG_BH:
		cout << "bh";
		break;
	//default - FIXME
	}
}

void
InstructionDecoder::decode_operand_Gv () {
	switch (m_modrm.reg) {
	case REG_AX:
		cout << "ax";
		break;
	case REG_CX:
		cout << "cx";
		break;
	case REG_DX:
		cout << "dx";
		break;
	case REG_BX:
		cout << "bx";
		break;
	case REG_SP:
		cout << "sp";
		break;
	case REG_BP:
		cout << "bp";
		break;
	case REG_SI:
		cout << "si";
		break;
	case REG_DI:
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
	case SREG_ES:
		cout << "es";
		break;
	case SREG_CS:
		cout << "cs";
		break;
	case SREG_SS:
		cout << "ss";
		break;
	case SREG_DS:
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

