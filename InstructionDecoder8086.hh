#ifndef INSTRUCTION_DECODER_8086_HH
#define INSTRUCTION_DECODER_8086_HH

#include "InstructionDecoder.hh"
#include <vector>

class InstructionDecoder8086 : public InstructionDecoder {
	/**
	*/
	std::vector<unsigned char> m_inst_code;

public:
	/**
	*/
	virtual void get_instruction () {
	}

	/**
	*/
	virtual void next_instruction () {
	}

protected:
	/**
	*/
	virtual void decode_instruction () {
	}
};

#endif //INSTRUCTION_DECODER_8086_HH

