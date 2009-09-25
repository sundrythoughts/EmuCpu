#ifndef INSTRUCTION_DECODER_HH
#define INSTRUCTION_DECODER_HH

//#include "Operand.hh"
#include "ExecutionUnit.hh"
#include "BusInterfaceUnit.hh"
#include "Instructions.hh"
#include "Defines.hh"
#include <vector>
#include <map>
#include <string>
#include <utility>

class InstructionDecoder {
	ExecutionUnit *m_eunit;
	BusInterfaceUnit *m_biu;

public:
	std::vector<unsigned char> m_instruction_bytes;

private:
	unsigned char *m_inst_ptr;
	ModRM m_modrm;

	typedef void (InstructionDecoder::*DecodeFunc) ();
	std::map<std::string, DecodeFunc> m_decode_map;

public:

	InstructionDecoder () {
		insert_decode_pair ("AH", &InstructionDecoder::decode_operand_AH);
		insert_decode_pair ("AL", &InstructionDecoder::decode_operand_AL);
		insert_decode_pair ("BH", &InstructionDecoder::decode_operand_BH);
		insert_decode_pair ("BL", &InstructionDecoder::decode_operand_BL);
		insert_decode_pair ("CH", &InstructionDecoder::decode_operand_CH);
		insert_decode_pair ("CL", &InstructionDecoder::decode_operand_CL);
		insert_decode_pair ("DH", &InstructionDecoder::decode_operand_DH);
		insert_decode_pair ("DL", &InstructionDecoder::decode_operand_DL);
		insert_decode_pair ("Ap", &InstructionDecoder::decode_operand_Ap);
		insert_decode_pair ("AX", &InstructionDecoder::decode_operand_AX);
		insert_decode_pair ("BP", &InstructionDecoder::decode_operand_BP);
		insert_decode_pair ("BX", &InstructionDecoder::decode_operand_BX);
		insert_decode_pair ("CX", &InstructionDecoder::decode_operand_CX);
		insert_decode_pair ("DI", &InstructionDecoder::decode_operand_DI);
		insert_decode_pair ("DX", &InstructionDecoder::decode_operand_DX);
		insert_decode_pair ("Eb", &InstructionDecoder::decode_operand_Eb);
		insert_decode_pair ("Ev", &InstructionDecoder::decode_operand_Ev);
		insert_decode_pair ("Ew", &InstructionDecoder::decode_operand_Ew);
		insert_decode_pair ("Fv", &InstructionDecoder::decode_operand_Fv);
		insert_decode_pair ("Gb", &InstructionDecoder::decode_operand_Gb);
		insert_decode_pair ("Gv", &InstructionDecoder::decode_operand_Gv);
		insert_decode_pair ("Ib", &InstructionDecoder::decode_operand_Ib);
		insert_decode_pair ("Iv", &InstructionDecoder::decode_operand_Iv);
		insert_decode_pair ("Iw", &InstructionDecoder::decode_operand_Iw);
		insert_decode_pair ("Jb", &InstructionDecoder::decode_operand_Jb);
		insert_decode_pair ("Jv", &InstructionDecoder::decode_operand_Jb);
		insert_decode_pair ("Mp", &InstructionDecoder::decode_operand_Mp);
		insert_decode_pair ("SI", &InstructionDecoder::decode_operand_SI);
		insert_decode_pair ("Sw", &InstructionDecoder::decode_operand_Sw);
		insert_decode_pair ("Xb", &InstructionDecoder::decode_operand_Xb);
		insert_decode_pair ("Xv", &InstructionDecoder::decode_operand_Xv);
		insert_decode_pair ("Yb", &InstructionDecoder::decode_operand_Yb);
		insert_decode_pair ("Yv", &InstructionDecoder::decode_operand_Yv);

//		(this->*(*m_decode_map.find ("AH")).second) ();
	}

	/**
	*/
	void connect_to (ExecutionUnit &eu);

	/**
	*/
	void connect_to (BusInterfaceUnit &biu);

	/**
	*/
	void get_instruction ();

	/**
	*/
	void next_instruction ();

protected:
	void insert_decode_pair (const char *s, DecodeFunc f) {
		m_decode_map.insert (std::pair<std::string, DecodeFunc> (s, f));
	}

	/**
	*/
	void decode_instruction ();

	void decode_operand_AH ();
	void decode_operand_AL ();
	void decode_operand_BH ();
	void decode_operand_BL ();
	void decode_operand_CH ();
	void decode_operand_CL ();
	void decode_operand_DH ();
	void decode_operand_DL ();
	void decode_operand_Ap ();
	void decode_operand_AX ();
	void decode_operand_BP ();
	void decode_operand_BX ();
	void decode_operand_CX ();
	void decode_operand_DI ();
	void decode_operand_DX ();
	void decode_operand_Eb ();
	void decode_operand_Ev ();
	void decode_operand_Ew ();
	void decode_operand_Fv ();
	void decode_operand_Gb ();
	void decode_operand_Gv ();
	void decode_operand_Ib ();
	void decode_operand_Iv ();
	void decode_operand_Iw ();
	void decode_operand_Jb ();
	void decode_operand_Jv ();
	void decode_operand_Mp ();
	void decode_operand_SI ();
	void decode_operand_Sw ();
	void decode_operand_Xb ();
	void decode_operand_Xv ();
	void decode_operand_Yb ();
	void decode_operand_Yv ();
};

#endif //INSTRUCTION_DECODER_HH

