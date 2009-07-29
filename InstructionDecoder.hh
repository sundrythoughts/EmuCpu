#ifndef INSTRUCTION_DECODER_HH
#define INSTRUCTION_DECODER_HH

#include "Operand.hh"
#include <string>
#include <vector>

class InstructionDecoder {
	std::vector<unsigned char> _memory;

public:
	/**
	*/
	virtual std::string disassemble (void *ip) = 0;

	/**
	*/
	virtual std::vector<Operand>& decode_operands (void *) = 0;
};

#endif //INSTRUCTION_DECODER_HH
