#ifndef INSTRUCTION_DECODER_8086_HH
#define INSTRUCTION_DECODER_8086_HH

#include "InstructionDecoder.hh"
#include "Operand.hh"
#include <vector>
#include <string>
#include <iostream>

class InstructionDecoder8086 : public InstructionDecoder {
	static unsigned char memory[];
	unsigned char *ip;

public:
	InstructionDecoder8086 () {
		ip = memory;
	}

	/**
	*/
	virtual std::string disassemble () {
		/*
		switch (*ip) {
			case 0x83:
				return inst_83_add_rAX_Iz ();
			default:
				return "Error: no such instruction";
		}
		*/
	}

	/**
	*/
	virtual std::vector<Operand>& decode_operands () {
		switch (*ip) {
			case 0x83:
				return inst_83_add_rAX_Iz ();
			default:
				return "Error: no such instruction";
		}
	}

private:

	std::vector<Operand>* inst_83_add_rAX_Iz () {
		
	}
};

#endif //INSTRUCTION_DECODER_8086_HH
