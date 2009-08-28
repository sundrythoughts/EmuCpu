#include "InstructionDecoder.hh"

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
}

void
InstructionDecoder::next_instruction () {
}

void
InstructionDecoder::decode_instruction () {
}

