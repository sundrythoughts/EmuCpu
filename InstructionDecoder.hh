#ifndef INSTRUCTION_DECODER_HH
#define INSTRUCTION_DECODER_HH

#include "Operand.hh"
#include <vector>

class InstructionDecoder {
	ExecutionUnit *m_eunit;
	BusInterfaceUnit *m_biu;

	std::vector<unsigned char> m_instruction_bytes;

public:
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
	/**
	*/
	void decode_instruction ();
};

#endif //INSTRUCTION_DECODER_HH

