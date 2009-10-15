#ifndef JAF__INSTRUCTION_TABLE_HH
#define JAF__INSTRUCTION_TABLE_HH

#include "NumberWrapper.hh"
#include <vector>
#include "INumberReadableWritable.hh"
#include "ExecutionUnit.hh"
#include "InstructionDecoder.hh"

class InstructionTable;
class InstructionDecoder;

class InstructionTableItem {
public:
	const char *mnemonic;
	bool has_modrm;
	unsigned int operand_count;
	const char *operand_codes[3];
	unsigned int group;

	void (InstructionDecoder::*decode_func) ();

	void (ExecutionUnit::*execute_func) (std::vector<NumberWrapper> &ops);

	void decode (InstructionDecoder *id) const {
		(id->*decode_func) ();
	}

	void execute (ExecutionUnit *eu, std::vector<NumberWrapper> &ops) const {
		(eu->*execute_func) (ops);
	}
}; //end class InstructionTableItem

class InstructionTable {
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

	static const InstructionTableItem one_byte_opcode_instruction_map[256];
	static const InstructionTableItem one_byte_opcode_instruction_extension_map[11][8];
}; //end class InstructionTable

#endif //JAF__INSTRUCTION_TABLE_HH

