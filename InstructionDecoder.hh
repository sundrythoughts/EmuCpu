#ifndef INSTRUCTION_DECODER_HH
#define INSTRUCTION_DECODER_HH

#include "Operand.hh"

class InstructionDecoder {

public:
	/**
	*/
	virtual void get_instruction () = 0;

	/**
	*/
	virtual void next_instruction () = 0;

protected:
	/**
	*/
	virtual void decode_instruction () = 0;
};

#endif //INSTRUCTION_DECODER_HH
