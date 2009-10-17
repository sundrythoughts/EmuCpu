#include "InstructionTable.hh"

const InstructionTableItem InstructionTable::one_byte_opcode_instruction_map[256] = {
	/* 0x */
	{"add", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"add", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"add", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"add", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"add", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execADD},
	{"add", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execADD},
	{"push es", false, GROUP_NONE, &InstructionDecoder::decodeSegment},
	{"pop es", false, GROUP_NONE, &InstructionDecoder::decodeSegment},
	{"or", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"or", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"or", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"or", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"or", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execOR},
	{"or", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execOR},
	{"push cs", false, GROUP_NONE, &InstructionDecoder::decodeSegment},
	{0, false, GROUP_RESERVED},

	/* 1x */
	{"adc", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"adc", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"adc", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"adc", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"adc", false, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{"adc", false, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{"push ss", false, GROUP_NONE, &InstructionDecoder::decodeSegment},
	{"pop ss", false, GROUP_NONE, &InstructionDecoder::decodeSegment},
	{"sbb", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"sbb", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"sbb", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"sbb", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"sbb", false, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{"sbb", false, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{"push ds", false, GROUP_NONE, &InstructionDecoder::decodeSegment},
	{"pop ds", false, GROUP_NONE, &InstructionDecoder::decodeSegment},

	/* 2x */
	{"and", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"and", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"and", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"and", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"and", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execAND},
	{"and", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execAND},
	{0, false, GROUP_RESERVED},
	{"daa", false, GROUP_NONE, &InstructionDecoder::decodeAcc},
	{"sub", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"sub", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"sub", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"sub", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"sub", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execSUB},
	{"sub", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execSUB},
	{0, false, GROUP_RESERVED},
	{"das", false, GROUP_NONE, &InstructionDecoder::decodeAcc},
	
	/* 3x */
	{"xor", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"xor", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"xor", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"xor", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"xor", false, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{"xor", false, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{0, false, GROUP_RESERVED},
	{"aaa", false, GROUP_NONE, &InstructionDecoder::decodeAcc},
	{"cmp", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"cmp", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"cmp", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"cmp", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"cmp", false, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{"cmp", false, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{0, false, GROUP_RESERVED},
	{"aas", false, GROUP_NONE, &InstructionDecoder::decodeAcc},

	/* 4x */
	{"inc", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execINC},
	{"inc", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execINC},
	{"inc", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execINC},
	{"inc", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execINC},
	{"inc", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execINC},
	{"inc", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execINC},
	{"inc", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execINC},
	{"inc", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execINC},
	{"dec", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execDEC},
	{"dec", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execDEC},
	{"dec", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execDEC},
	{"dec", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execDEC},
	{"dec", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execDEC},
	{"dec", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execDEC},
	{"dec", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execDEC},
	{"dec", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execDEC},

	/* 5x */
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg},

	/* 6x */
	{0, false, GROUP_RESERVED},
	{0, false, GROUP_RESERVED},
	{0, false, GROUP_RESERVED},
	{0, false, GROUP_RESERVED},
	{0, false, GROUP_RESERVED},
	{0, false, GROUP_RESERVED},
	{0, false, GROUP_RESERVED},
	{0, false, GROUP_RESERVED},
	{0, false, GROUP_RESERVED},
	{0, false, GROUP_RESERVED},
	{0, false, GROUP_RESERVED},
	{0, false, GROUP_RESERVED},
	{0, false, GROUP_RESERVED},
	{0, false, GROUP_RESERVED},
	{0, false, GROUP_RESERVED},
	{0, false, GROUP_RESERVED},

	/* 7x */
	{"jo", false, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jno", false, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jb/jnae/jc", false, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jnb/jae/jnc", false, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jz/je", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJE},
	{"jnz/jne", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJNE},
	{"jbe/jna", false, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jnbe/ja", false, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"js", false, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jns", false, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jp/jpe", false, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jnp/jpo", false, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jl/jnge", false, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jnl/jge", false, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jle/jng", false, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jnle/jg", false, GROUP_NONE, &InstructionDecoder::decodeShort},

	/* 8x */
	{0, false, GROUP_1},
	{0, false, GROUP_1},
	{0, false, GROUP_1},
	{0, false, GROUP_1},
	{"test", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"test", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"xchg", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"xchg", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeSegRM},
	{"lea", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeSegRM},
	{"pop", true, GROUP_NONE},

	/* 9x */
	{"nop", false, GROUP_NONE, &InstructionDecoder::decodeAccReg, &ExecutionUnit::execNOP},
	{"xchg", false, GROUP_NONE, &InstructionDecoder::decodeAccReg, &ExecutionUnit::execXCHG},
	{"xchg", false, GROUP_NONE, &InstructionDecoder::decodeAccReg, &ExecutionUnit::execXCHG},
	{"xchg", false, GROUP_NONE, &InstructionDecoder::decodeAccReg, &ExecutionUnit::execXCHG},
	{"xchg", false, GROUP_NONE, &InstructionDecoder::decodeAccReg, &ExecutionUnit::execXCHG},
	{"xchg", false, GROUP_NONE, &InstructionDecoder::decodeAccReg, &ExecutionUnit::execXCHG},
	{"xchg", false, GROUP_NONE, &InstructionDecoder::decodeAccReg, &ExecutionUnit::execXCHG},
	{"xchg", false, GROUP_NONE, &InstructionDecoder::decodeAccReg, &ExecutionUnit::execXCHG},
	{"cbw", false, GROUP_NONE, &InstructionDecoder::decodeAcc},
	{"cwd", false, GROUP_NONE, &InstructionDecoder::decodeAcc},
	{"call", false, GROUP_NONE, &InstructionDecoder::decodeInter},
	{"wait", false, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"pushf", false, GROUP_NONE, &InstructionDecoder::decodeFlags},
	{"popf", false, GROUP_NONE, &InstructionDecoder::decodeFlags},
	{"sahf", false, GROUP_NONE, &InstructionDecoder::decodeFlags},
	{"lahf", false, GROUP_NONE, &InstructionDecoder::decodeFlags},

	/* Ax */
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeAccMem, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeAccMem, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeAccMem, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeAccMem, &ExecutionUnit::execMOV},
	{"movsb", false, GROUP_NONE, &InstructionDecoder::decodeString},
	{"movsw", false, GROUP_NONE, &InstructionDecoder::decodeString},
	{"cmpsw", false, GROUP_NONE, &InstructionDecoder::decodeString},
	{"cmpsw", false, GROUP_NONE, &InstructionDecoder::decodeString},
	{"test", false, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{"test", false, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{"stosb", false, GROUP_NONE, &InstructionDecoder::decodeString},
	{"stosw", false, GROUP_NONE, &InstructionDecoder::decodeString},
	{"lodsb", false, GROUP_NONE, &InstructionDecoder::decodeString},
	{"lodsw", false, GROUP_NONE, &InstructionDecoder::decodeString},
	{"scasb", false, GROUP_NONE, &InstructionDecoder::decodeString},
	{"scasw", false, GROUP_NONE, &InstructionDecoder::decodeString},

	/* Bx */
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeRegImm, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeRegImm, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeRegImm, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeRegImm, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeRegImm, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeRegImm, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeRegImm, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeRegImm, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeRegImm, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeRegImm, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeRegImm, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeRegImm, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeRegImm, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeRegImm, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeRegImm, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeRegImm, &ExecutionUnit::execMOV},

	/* Cx */
	{0, false, GROUP_RESERVED},
	{0, false, GROUP_RESERVED},
	{"ret", false, GROUP_NONE, &InstructionDecoder::decodeRetPop},
	{"ret", false, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"les", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"lds", true, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRMImm},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRMImm},
	{0, false, GROUP_RESERVED},
	{0, false, GROUP_RESERVED},
	{"ret", false, GROUP_NONE, &InstructionDecoder::decodeRetPop},
	{"ret", false, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"int 3", false, GROUP_NONE, &InstructionDecoder::decodeType3},
	{"int", false, GROUP_NONE, &InstructionDecoder::decodeIntNum},
	{"into", false, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"iret", false, GROUP_NONE, &InstructionDecoder::decodeNone},

	/* Dx */
	{0, true, GROUP_2},
	{0, true, GROUP_2},
	{0, true, GROUP_2},
	{0, true, GROUP_2},
	{"aam", false, GROUP_NONE, &InstructionDecoder::decodeAccBase},
	{"aad", false, GROUP_NONE, &InstructionDecoder::decodeAccBase},
	{0, false, GROUP_RESERVED},
	{"xlat", false, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"esc 0", false, GROUP_NONE, &InstructionDecoder::decodeEscNum},
	{"esc 1", false, GROUP_NONE, &InstructionDecoder::decodeEscNum},
	{"esc 2", false, GROUP_NONE, &InstructionDecoder::decodeEscNum},
	{"esc 3", false, GROUP_NONE, &InstructionDecoder::decodeEscNum},
	{"esc 4", false, GROUP_NONE, &InstructionDecoder::decodeEscNum},
	{"esc 5", false, GROUP_NONE, &InstructionDecoder::decodeEscNum},
	{"esc 6", false, GROUP_NONE, &InstructionDecoder::decodeEscNum},
	{"esc 7", false, GROUP_NONE, &InstructionDecoder::decodeEscNum},

	/* Ex */
	{"loopne/loopnz", false, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"loope/loopz", false, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"loop", false, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jcxz", false, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"in", false, GROUP_NONE, &InstructionDecoder::decodeAccPort},
	{"in", false, GROUP_NONE, &InstructionDecoder::decodeAccPort},
	{"out", false, GROUP_NONE, &InstructionDecoder::decodeAccPort},
	{"out", false, GROUP_NONE, &InstructionDecoder::decodeAccPort},
	{"call", false, GROUP_NONE, &InstructionDecoder::decodeIntra},
	{"jmp", false, GROUP_NONE, &InstructionDecoder::decodeIntra,  &ExecutionUnit::execJMP},
	{"jmp", false, GROUP_NONE, &InstructionDecoder::decodeInter},
	{"jmp", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJMP},
	{"in", false, GROUP_NONE, &InstructionDecoder::decodeAccVPort},
	{"in", false, GROUP_NONE, &InstructionDecoder::decodeAccVPort},
	{"out", false, GROUP_NONE, &InstructionDecoder::decodeAccVPort},
	{"out", false, GROUP_NONE, &InstructionDecoder::decodeAccVPort},

	/* Fx */
	{"lock", false, GROUP_NONE, &InstructionDecoder::decodeNone},
	{0, false, GROUP_RESERVED},
	{"repne", false, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"rep/repe", false, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"hlt", false, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"cmc", false, GROUP_NONE, &InstructionDecoder::decodeNone},
	{0, false, GROUP_3},
	{0, false, GROUP_3},
	{"clc", false, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"stc", false, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"cli", false, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"sti", false, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"cld", false, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"std", false, GROUP_NONE, &InstructionDecoder::decodeNone},
	{0, false, GROUP_4},
	{0, false, GROUP_5}
};

const InstructionTableItem InstructionTable::one_byte_opcode_instruction_extension_map[11][8] = {
	{//GROUP 0
		{},
		{},
		{},
		{},
		{},
		{},
		{},
		{}
	},//END GROUP 0

	{//GROUP 1
		{"add",},
		{"or",},
		{"adc",},
		{"sbb",},
		{"and",},
		{"sub",},
		{"xor",},
		{"cmp",}
	},//END GROUP 1

	{//GROUP 2
		{"rol",},
		{"ror",},
		{"rcl",},
		{"rcr",},
		{"shl/sal",},
		{"shr",},
		{},
		{"sar",}
	},//END GROUP 2

	{//GROUP 3
		{"test",},
		{},
		{"not",},
		{"neg",},
		{"mul",},
		{"imul",},
		{"div",},
		{"idiv",}
	},//END GROUP 3

	{//GROUP 4
		{"inc",},
		{"dec",},
		{},
		{},
		{},
		{},
		{},
		{}
	},//END GROUP 4

	{//GROUP 5
		{"inc",},
		{"dec",},
		{"call",},
		{"call",},
		{"jmp",},
		{"jmp",},
		{"push",},
		{}
	},//END GROUP 5

	{//GROUP 6
		{},
		{},
		{},
		{},
		{},
		{},
		{},
		{}
	},//END GROUP 6

	{//GROUP 7
		{},
		{},
		{},
		{},
		{},
		{},
		{},
		{}
	},//END GROUP 7

	{//GROUP 8
		{},
		{},
		{},
		{},
		{},
		{},
		{},
		{}
	},//END GROUP 8

	{//GROUP 9
		{},
		{},
		{},
		{},
		{},
		{},
		{},
		{}
	},//END GROUP 9

	{//GROUP 10
		{},
		{},
		{},
		{},
		{},
		{},
		{},
		{}
	}//END GROUP 10
};

//***OPERATION PSEUDOCODE****
//get opcode from memory
//decode the opcode by getting the element from opcode array
//decode each operand and store the values Operation[[{Value<int>(0), 0x7} {pointer to opcode instruction map element}]]
//store Operation in the Queue (if 8086 has pipelining???)
//Operation->instruction->execute (maching, Operation->operands)

