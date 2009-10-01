#include "InstructionDecoder.hh"
#include "ExecutionUnit.hh"
#include "BusInterfaceUnit.hh"
#include "Memory.hh"

int main (int argc, char **argv) {
	Memory mem (1048576);
	BusInterfaceUnit biu;
	biu.connect_to (mem);
	ExecutionUnit eu;
	eu.connect_to (biu);
	InstructionDecoder id;
	id.connect_to (eu);
	id.connect_to (biu);

	id.m_instruction_bytes.push_back (0x8C);
	id.m_instruction_bytes.push_back (0xC3);
//	id.m_instruction_bytes.push_back (0x00);

	id.get_instruction ();
}

