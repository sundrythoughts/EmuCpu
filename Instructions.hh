#ifndef INSTRUCTIONS_HH
#define INSTRUCTIONS_HH

#include <vector>
#include "Value.hh"

namespace Jaf {

class Instruction {
public:
	const char *mnemonic;
	int operand_count;
	const char *operand_codes[3];
	unsigned int group;
	void (*execute_func) (Machine &mach, std::vector<Value> *ops);

	void execute (std::vector<Value> *ops) {
		execute_func (ops);
	}
};//end class Value

class Instructions {
public:
	static const Instruction one_byte_opcode_instruction_map[255];

	static void
	inst_00_add_Eb_Gb (std::vector<Value> *ops);

	static void
	inst_01_add_Ev_Gv (std::vector<Value> *ops);

	static void
	inst_02_add_Gb_Eb (std::vector<Value> *ops);

	static void
	inst_03_add_Gv_Ev (std::vector<Value> *ops);

	static void
	inst_04_add_AL_Ib (std::vector<Value> *ops);

	static void
	inst_05_add_rAX_Iz (std::vector<Value> *ops);
};//end class Instructions

} //end namespace Jaf

#endif //INSTRUCTIONS_HH

