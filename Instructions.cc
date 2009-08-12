#include "Instructions.hh"

namespace Jaf {

void
Instructions::inst_00_add_Eb_Gb (Machine &mach, std::vector<Value> *ops) {
}

void
Instructions::inst_01_add_Ev_Gv (std::vector<Value> *ops) {
}

void
Instructions::inst_02_add_Gb_Eb (std::vector<Value> *ops) {
}

void
Instructions::inst_03_add_Gv_Ev (std::vector<Value> *ops) {
}

void
Instructions::inst_04_add_AL_Ib (Machine &mach, std::vector<Value> *ops) {
/*
	Cpu cpu = mach.get_cpu ();
	unsigned char b;
	if (!(*ops)[1].get_value (b)) {
		throw new BigProblemException ();
	}
	cpu.set_reg_al (cpu.get_reg_al () + b);
*/
}

void
Instructions::inst_05_add_rAX_Iz (std::vector<Value> *ops) {
}

const Instruction Instructions::one_byte_opcode_instruction_map[255] = {
	{ "add", 2, {"Eb", "Gb", 0}, &Instructions::inst_00_add_Eb_Gb},
	{ "add", 2, {"Ev", "Gv", 0}, &Instructions::inst_01_add_Ev_Gv},
	{ "add", 2, {"Gb", "Eb", 0}, &Instructions::inst_02_add_Gb_Eb },
	{ "add", 2, {"Gv", "Ev", 0}, &Instructions::inst_03_add_Gv_Ev },
	{ "add", 2, {"AL", "Ib", 0}, &Instructions::inst_04_add_AL_Ib },
	{ "add", 2, {"rAX", "Iz", 0}, &Instructions::inst_05_add_rAX_Iz }
};

}//end namespace Jaf


//***OPERATION PSEUDOCODE****
//get opcode from memory
//decode the opcode by getting the element from opcode array
//decode each operand and store the values Operation[[{Value<int>(0), 0x7} {pointer to opcode instruction map element}]]
//store Operation in the Queue (if 8086 has pipelining???)
//Operation->instruction->execute (maching, Operation->operands)

