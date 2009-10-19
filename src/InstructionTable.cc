#include "InstructionTable.hh"

const InstructionTableItem InstructionTable::one_byte_opcode_instruction_map[256] = {
	/* 0x */
	{"add", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"add", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"add", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"add", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"add", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execADD},
	{"add", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execADD},
	{"push es", false, GROUP_NONE, &InstructionDecoder::decodeSegment, &ExecutionUnit::execNotImplemented},
	{"pop es", false, GROUP_NONE, &InstructionDecoder::decodeSegment, &ExecutionUnit::execNotImplemented},
	{"or", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"or", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"or", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"or", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"or", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execOR},
	{"or", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execOR},
	{"push cs", false, GROUP_NONE, &InstructionDecoder::decodeSegment, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED},

	/* 1x */
	{"adc", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"adc", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"adc", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"adc", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"adc", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execNotImplemented},
	{"adc", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execNotImplemented},
	{"push ss", false, GROUP_NONE, &InstructionDecoder::decodeSegment, &ExecutionUnit::execNotImplemented},
	{"pop ss", false, GROUP_NONE, &InstructionDecoder::decodeSegment, &ExecutionUnit::execNotImplemented},
	{"sbb", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"sbb", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"sbb", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"sbb", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"sbb", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execNotImplemented},
	{"sbb", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execNotImplemented},
	{"push ds", false, GROUP_NONE, &InstructionDecoder::decodeSegment, &ExecutionUnit::execNotImplemented},
	{"pop ds", false, GROUP_NONE, &InstructionDecoder::decodeSegment, &ExecutionUnit::execNotImplemented},

	/* 2x */
	{"and", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"and", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"and", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"and", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"and", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execAND},
	{"and", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execAND},
	{0, false, GROUP_RESERVED},
	{"daa", false, GROUP_NONE, &InstructionDecoder::decodeAcc, &ExecutionUnit::execNotImplemented},
	{"sub", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"sub", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"sub", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"sub", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"sub", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execSUB},
	{"sub", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execSUB},
	{0, false, GROUP_RESERVED},
	{"das", false, GROUP_NONE, &InstructionDecoder::decodeAcc, &ExecutionUnit::execNotImplemented},
	
	/* 3x */
	{"xor", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"xor", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"xor", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"xor", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"xor", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execNotImplemented},
	{"xor", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED},
	{"aaa", false, GROUP_NONE, &InstructionDecoder::decodeAcc, &ExecutionUnit::execNotImplemented},
	{"cmp", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"cmp", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"cmp", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"cmp", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"cmp", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execNotImplemented},
	{"cmp", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED},
	{"aas", false, GROUP_NONE, &InstructionDecoder::decodeAcc, &ExecutionUnit::execNotImplemented},

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
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execNotImplemented},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execNotImplemented},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execNotImplemented},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execNotImplemented},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execNotImplemented},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execNotImplemented},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execNotImplemented},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execNotImplemented},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execNotImplemented},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execNotImplemented},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execNotImplemented},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execNotImplemented},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execNotImplemented},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execNotImplemented},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execNotImplemented},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execNotImplemented},

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
	{"jo", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execNotImplemented},
	{"jno", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execNotImplemented},
	{"jb/jnae/jc", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execNotImplemented},
	{"jnb/jae/jnc", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execNotImplemented},
	{"jz/je", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJE},
	{"jnz/jne", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJNE},
	{"jbe/jna", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execNotImplemented},
	{"jnbe/ja", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execNotImplemented},
	{"js", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execNotImplemented},
	{"jns", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execNotImplemented},
	{"jp/jpe", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execNotImplemented},
	{"jnp/jpo", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execNotImplemented},
	{"jl/jnge", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execNotImplemented},
	{"jnl/jge", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execNotImplemented},
	{"jle/jng", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execNotImplemented},
	{"jnle/jg", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execNotImplemented},

	/* 8x */
	{0, false, GROUP_1},
	{0, false, GROUP_1},
	{0, false, GROUP_1},
	{0, false, GROUP_1},
	{"test", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"test", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"xchg", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"xchg", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeSegRM, &ExecutionUnit::execNotImplemented},
	{"lea", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeSegRM, &ExecutionUnit::execNotImplemented},
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
	{"cbw", false, GROUP_NONE, &InstructionDecoder::decodeAcc, &ExecutionUnit::execNotImplemented},
	{"cwd", false, GROUP_NONE, &InstructionDecoder::decodeAcc, &ExecutionUnit::execNotImplemented},
	{"call", false, GROUP_NONE, &InstructionDecoder::decodeInter, &ExecutionUnit::execNotImplemented},
	{"wait", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"pushf", false, GROUP_NONE, &InstructionDecoder::decodeFlags, &ExecutionUnit::execNotImplemented},
	{"popf", false, GROUP_NONE, &InstructionDecoder::decodeFlags, &ExecutionUnit::execNotImplemented},
	{"sahf", false, GROUP_NONE, &InstructionDecoder::decodeFlags, &ExecutionUnit::execNotImplemented},
	{"lahf", false, GROUP_NONE, &InstructionDecoder::decodeFlags, &ExecutionUnit::execNotImplemented},

	/* Ax */
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeAccMem, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeAccMem, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeAccMem, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeAccMem, &ExecutionUnit::execMOV},
	{"movsb", false, GROUP_NONE, &InstructionDecoder::decodeString, &ExecutionUnit::execNotImplemented},
	{"movsw", false, GROUP_NONE, &InstructionDecoder::decodeString, &ExecutionUnit::execNotImplemented},
	{"cmpsw", false, GROUP_NONE, &InstructionDecoder::decodeString, &ExecutionUnit::execNotImplemented},
	{"cmpsw", false, GROUP_NONE, &InstructionDecoder::decodeString, &ExecutionUnit::execNotImplemented},
	{"test", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execNotImplemented},
	{"test", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execNotImplemented},
	{"stosb", false, GROUP_NONE, &InstructionDecoder::decodeString, &ExecutionUnit::execNotImplemented},
	{"stosw", false, GROUP_NONE, &InstructionDecoder::decodeString, &ExecutionUnit::execNotImplemented},
	{"lodsb", false, GROUP_NONE, &InstructionDecoder::decodeString, &ExecutionUnit::execNotImplemented},
	{"lodsw", false, GROUP_NONE, &InstructionDecoder::decodeString, &ExecutionUnit::execNotImplemented},
	{"scasb", false, GROUP_NONE, &InstructionDecoder::decodeString, &ExecutionUnit::execNotImplemented},
	{"scasw", false, GROUP_NONE, &InstructionDecoder::decodeString, &ExecutionUnit::execNotImplemented},

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
	{"ret", false, GROUP_NONE, &InstructionDecoder::decodeRetPop, &ExecutionUnit::execNotImplemented},
	{"ret", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"les", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"lds", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execNotImplemented},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED},
	{0, false, GROUP_RESERVED},
	{"ret", false, GROUP_NONE, &InstructionDecoder::decodeRetPop, &ExecutionUnit::execNotImplemented},
	{"ret", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"int 3", false, GROUP_NONE, &InstructionDecoder::decodeType3, &ExecutionUnit::execNotImplemented},
	{"int", false, GROUP_NONE, &InstructionDecoder::decodeIntNum, &ExecutionUnit::execNotImplemented},
	{"into", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"iret", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},

	/* Dx */
	{0, true, GROUP_2},
	{0, true, GROUP_2},
	{0, true, GROUP_2},
	{0, true, GROUP_2},
	{"aam", false, GROUP_NONE, &InstructionDecoder::decodeAccBase, &ExecutionUnit::execNotImplemented},
	{"aad", false, GROUP_NONE, &InstructionDecoder::decodeAccBase, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED},
	{"xlat", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"esc 0", false, GROUP_NONE, &InstructionDecoder::decodeEscNum, &ExecutionUnit::execNotImplemented},
	{"esc 1", false, GROUP_NONE, &InstructionDecoder::decodeEscNum, &ExecutionUnit::execNotImplemented},
	{"esc 2", false, GROUP_NONE, &InstructionDecoder::decodeEscNum, &ExecutionUnit::execNotImplemented},
	{"esc 3", false, GROUP_NONE, &InstructionDecoder::decodeEscNum, &ExecutionUnit::execNotImplemented},
	{"esc 4", false, GROUP_NONE, &InstructionDecoder::decodeEscNum, &ExecutionUnit::execNotImplemented},
	{"esc 5", false, GROUP_NONE, &InstructionDecoder::decodeEscNum, &ExecutionUnit::execNotImplemented},
	{"esc 6", false, GROUP_NONE, &InstructionDecoder::decodeEscNum, &ExecutionUnit::execNotImplemented},
	{"esc 7", false, GROUP_NONE, &InstructionDecoder::decodeEscNum, &ExecutionUnit::execNotImplemented},

	/* Ex */
	{"loopne/loopnz", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execNotImplemented},
	{"loope/loopz", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execNotImplemented},
	{"loop", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execNotImplemented},
	{"jcxz", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execNotImplemented},
	{"in", false, GROUP_NONE, &InstructionDecoder::decodeAccPort, &ExecutionUnit::execNotImplemented},
	{"in", false, GROUP_NONE, &InstructionDecoder::decodeAccPort, &ExecutionUnit::execNotImplemented},
	{"out", false, GROUP_NONE, &InstructionDecoder::decodeAccPort, &ExecutionUnit::execNotImplemented},
	{"out", false, GROUP_NONE, &InstructionDecoder::decodeAccPort, &ExecutionUnit::execNotImplemented},
	{"call", false, GROUP_NONE, &InstructionDecoder::decodeIntra, &ExecutionUnit::execNotImplemented},
	{"jmp", false, GROUP_NONE, &InstructionDecoder::decodeIntra,  &ExecutionUnit::execJMP},
	{"jmp", false, GROUP_NONE, &InstructionDecoder::decodeInter, &ExecutionUnit::execNotImplemented},
	{"jmp", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJMP},
	{"in", false, GROUP_NONE, &InstructionDecoder::decodeAccVPort, &ExecutionUnit::execNotImplemented},
	{"in", false, GROUP_NONE, &InstructionDecoder::decodeAccVPort, &ExecutionUnit::execNotImplemented},
	{"out", false, GROUP_NONE, &InstructionDecoder::decodeAccVPort, &ExecutionUnit::execNotImplemented},
	{"out", false, GROUP_NONE, &InstructionDecoder::decodeAccVPort, &ExecutionUnit::execNotImplemented},

	/* Fx */
	{"lock", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED},
	{"repne", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"rep/repe", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"hlt", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execHLT},
	{"cmc", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_3},
	{0, false, GROUP_3},
	{"clc", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"stc", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"cli", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"sti", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"cld", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"std", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
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

