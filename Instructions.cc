#include "Instructions.hh"

const Instruction one_byte_opcode_instruction_map[255] = {
	{ "add", 2, {"Eb", "Gb", 0} },
	{ "add", 2, {"Ev", "Gv", 0} },
	{ "add", 2, {"Gb", "Eb", 0} },
	{ "add", 2, {"Gv", "Ev", 0} },
	{ "add", 2, {"AL", "Ib", 0} },
	{ "add", 2, {"rAX", "Iz", 0} }
};
