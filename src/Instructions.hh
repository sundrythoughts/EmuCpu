#ifndef JAF__INSTRUCTIONS_HH
#define JAF__INSTRUCTIONS_HH

#include "Value.hh"
#include <vector>
#include "INumberReadableWritable.hh"
#include "ExecutionUnit.hh"
#include "InstructionDecoder.hh"

class Instructions;
class InstructionDecoder;

class Instruction {
public:
	const char *mnemonic;
	bool has_modrm;
	unsigned int operand_count;
	const char *operand_codes[3];
	unsigned int group;

	std::vector<Value>* (InstructionDecoder::*decode_func) ();

	void (ExecutionUnit::*execute_func) (std::vector<Value> *ops);

	std::vector<Value>* decode (InstructionDecoder *id) {
		return (id->*decode_func) ();
	}

	void execute (ExecutionUnit *eu, std::vector<Value> *ops) {
		(eu->*execute_func) (ops);
	}
}; //end class Value

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
}; //end class Instructions

#endif //JAF__INSTRUCTIONS_HH

