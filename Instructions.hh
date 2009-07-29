#ifndef J_INSTRUCTIONS_HH
#define J_INSTRUCTIONS_HH

#include <vector>

typedef void (*InstructionFunc) (

typedef struct {
	const char *mnemonic;
	int n_operands;
	const char *operands[3];
} Instruction;

extern const Instruction one_byte_opcode_instruction_map[255];

#endif //J_INSTRUCTIONS_HH
