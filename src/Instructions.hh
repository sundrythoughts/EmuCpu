#ifndef INSTRUCTIONS_HH
#define INSTRUCTIONS_HH

#include <vector>
#include "INumberReadableWritable.hh"

class Instructions;

class Instruction {
public:
	const char *mnemonic;
	bool has_modrm;
	unsigned int operand_count;
	const char *operand_codes[3];
	unsigned int group;

	void (*decode_func) (std::vector<INumberReadableWritable*> *ops);
	void (*execute_func) (std::vector<INumberReadableWritable*> *ops);

	void decode (std::vector<INumberReadableWritable*> *ops) {
		decode_func (ops);
	}

	void execute (std::vector<INumberReadableWritable*> *ops) {
		execute_func (ops);
	}
};//end class Value

class Instructions {
public:
	enum {
		GROUP_NONE = 0,
		GROUP_1,
		GROUP_2,
		GROUP_3,
		GROUP_4,
		GROUP_5,
		GROUP_RESERVED
	} InstructionGroups;

	static const Instruction one_byte_opcode_instruction_map[256];
	static const Instruction one_byte_opcode_instruction_extension_map[11][8];
};//end class Instructions

#endif //INSTRUCTIONS_HH

