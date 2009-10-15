#include "InstructionTable.hh"

const InstructionTableItem InstructionTable::one_byte_opcode_instruction_map[256] = {
	/* 00 */
	{"add", true, 2, {"Eb","Gb",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"add", true, 2, {"Ev","Gv",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"add", true, 2, {"Gb","Eb",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"add", true, 2, {"Gv","Ev",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"add", false, 2, {"AL","Ib",0}, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{"add", false, 2, {"AX","Iv",0}, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execADD},
	{"push es", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeSegment},
	{"pop es", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeSegment},
	{"or", true, 2, {"Eb","Gb",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"or", true, 2, {"Ev","Gv",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"or", true, 2, {"Gb","Eb",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"or", true, 2, {"Gv","Ev",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"or", false, 2, {"AL","Ib",0}, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{"or", false, 2, {"AX","Iv",0}, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{"push cs", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeSegment},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},

	/* 01 */
	{"adc", true, 2, {"Eb","Gb",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"adc", true, 2, {"Ev","Gv",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"adc", true, 2, {"Gb","Eb",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"adc", true, 2, {"Gv","Ev",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"adc", false, 2, {"AL","Ib",0}, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{"adc", false, 2, {"AX","Iv",0}, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{"push ss", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeSegment},
	{"pop ss", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeSegment},
	{"sbb", true, 2, {"Eb","Gb",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"sbb", true, 2, {"Ev","Gv",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"sbb", true, 2, {"Gb","Eb",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"sbb", true, 2, {"Gv","Ev",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"sbb", false, 2, {"AL","Ib",0}, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{"sbb", false, 2, {"AX","Iv",0}, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{"push ds", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeSegment},
	{"pop ds", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeSegment},

	/* 02 */
	{"and", true, 2, {"Eb","Gb",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"and", true, 2, {"Ev","Gv",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"and", true, 2, {"Gb","Eb",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"and", true, 2, {"Gv","Ev",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"and", false, 2, {"AL","Ib",0}, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{"and", false, 2, {"AX","Iv",0}, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{"daa", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeAcc},
	{"sub", true, 2, {"Eb","Gb",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"sub", true, 2, {"Ev","Gv",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"sub", true, 2, {"Gb","Eb",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"sub", true, 2, {"Gv","Ev",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"sub", false, 2, {"AL","Ib",0}, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{"sub", false, 2, {"AX","Iv",0}, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{"das", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeAcc},
	
	/* 03 */
	{"xor", true, 2, {"Eb","Gb",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"xor", true, 2, {"Ev","Gv",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"xor", true, 2, {"Gb","Eb",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"xor", true, 2, {"Gv","Ev",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"xor", false, 2, {"AL","Ib",0}, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{"xor", false, 2, {"AX","Iv",0}, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{"aaa", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeAcc},
	{"cmp", true, 2, {"Eb","Gb",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"cmp", true, 2, {"Ev","Gv",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"cmp", true, 2, {"Gb","Eb",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"cmp", true, 2, {"Gv","Ev",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"cmp", false, 2, {"AL","Ib",0}, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{"cmp", false, 2, {"AX","Iv",0}, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{"aas", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeAcc},

	/* 04 */
	{"inc", false, 1, {"AX",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"inc", false, 1, {"CX",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"inc", false, 1, {"DX",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"inc", false, 1, {"BX",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"inc", false, 1, {"SP",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"inc", false, 1, {"BP",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"inc", false, 1, {"SI",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"inc", false, 1, {"DI",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"dec", false, 1, {"AX",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"dec", false, 1, {"CX",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"dec", false, 1, {"DX",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"dec", false, 1, {"BX",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"dec", false, 1, {"SP",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"dec", false, 1, {"BP",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"dec", false, 1, {"SI",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"dec", false, 1, {"DI",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},

	/* 05 */
	{"push", false, 1, {"AX",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"push", false, 1, {"CX",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"push", false, 1, {"DX",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"push", false, 1, {"BX",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"push", false, 1, {"SP",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"push", false, 1, {"BP",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"push", false, 1, {"SI",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"push", false, 1, {"DI",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"pop", false, 1, {"AX",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"pop", false, 1, {"CX",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"pop", false, 1, {"DX",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"pop", false, 1, {"BX",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"pop", false, 1, {"SP",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"pop", false, 1, {"BP",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"pop", false, 1, {"SI",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},
	{"pop", false, 1, {"DI",0,0}, GROUP_NONE, &InstructionDecoder::decodeReg},

	/* 06 */
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},

	/* 07 */
	{"jo", false, 1, {"Jb",0,0}, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jno", false, 1, {"Jb",0,0}, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jb/jnae/jc", false, 1, {"Jb",0,0}, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jnb/jae/jnc", false, 1, {"Jb",0,0}, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jz/je", false, 1, {"Jb",0,0}, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jnz/jne", false, 1, {"Jb",0,0}, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jbe/jna", false, 1, {"Jb",0,0}, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jnbe/ja", false, 1, {"Jb",0,0}, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"js", false, 1, {"Jb",0,0}, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jns", false, 1, {"Jb",0,0}, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jp/jpe", false, 1, {"Jb",0,0}, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jnp/jpo", false, 1, {"Jb",0,0}, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jl/jnge", false, 1, {"Jb",0,0}, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jnl/jge", false, 1, {"Jb",0,0}, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jle/jng", false, 1, {"Jb",0,0}, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jnle/jg", false, 1, {"Jb",0,0}, GROUP_NONE, &InstructionDecoder::decodeShort},

	/* 08 */
	{0, false, 2, {"Eb","Ib",0}, GROUP_1},
	{0, false, 2, {"Ev","Iv",0}, GROUP_1},
	{0, false, 2, {"Ev","Ib",0}, GROUP_1},
	{0, false, 2, {"Eb","Ib",0}, GROUP_1},
	{"test", true, 2, {"Eb","Gb",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"test", true, 2, {"Ev","Gv",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"xchg", true, 2, {"Eb","Gb",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"xchg", true, 2, {"Ev","Gv",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"mov", true, 2, {"Eb","Gb",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"mov", true, 2, {"Ev","Gv",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"mov", true, 2, {"Gb","Eb",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"mov", true, 2, {"Gv","Ev",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"mov", true, 2, {"Ew","Sw",0}, GROUP_NONE, &InstructionDecoder::decodeSegRM},
	{"lea", true, 2, {"Gv","M",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"mov", true, 2, {"Sw","Ew",0}, GROUP_NONE, &InstructionDecoder::decodeSegRM},
	{"pop", true, 1, {"Ev",0,0}, GROUP_NONE},

	/* 09 */
	{"nop", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeAccReg},
	{"xchg", false, 1, {"CX",0,0}, GROUP_NONE, &InstructionDecoder::decodeAccReg},
	{"xchg", false, 1, {"DX",0,0}, GROUP_NONE, &InstructionDecoder::decodeAccReg},
	{"xchg", false, 1, {"BX",0,0}, GROUP_NONE, &InstructionDecoder::decodeAccReg, &ExecutionUnit::execXCHG},
	{"xchg", false, 1, {"SP",0,0}, GROUP_NONE, &InstructionDecoder::decodeAccReg},
	{"xchg", false, 1, {"BP",0,0}, GROUP_NONE, &InstructionDecoder::decodeAccReg},
	{"xchg", false, 1, {"SI",0,0}, GROUP_NONE, &InstructionDecoder::decodeAccReg},
	{"xchg", false, 1, {"DI",0,0}, GROUP_NONE, &InstructionDecoder::decodeAccReg},
	{"cbw", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeAcc},
	{"cwd", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeAcc},
	{"call", false, 1, {"Ap",0,0}, GROUP_NONE, &InstructionDecoder::decodeInter},
	{"wait", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"pushf", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeFlags},
	{"popf", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeFlags},
	{"sahf", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeFlags},
	{"lahf", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeFlags},

	/* 0A */
	{"mov", false, 2, {"AL","Ob",0}, GROUP_NONE, &InstructionDecoder::decodeAccMem},
	{"mov", false, 2, {"AX","Ov",0}, GROUP_NONE, &InstructionDecoder::decodeAccMem},
	{"mov", false, 2, {"Ob","AL",0}, GROUP_NONE, &InstructionDecoder::decodeAccMem},
	{"mov", false, 2, {"Ov","AX",0}, GROUP_NONE, &InstructionDecoder::decodeAccMem},
	{"movsb", false, 2, {"Xb","Yb",0}, GROUP_NONE, &InstructionDecoder::decodeString},
	{"movsw", false, 2, {"Xv","Yv",0}, GROUP_NONE, &InstructionDecoder::decodeString},
	{"cmpsw", false, 2, {"Xb","Yb",0}, GROUP_NONE, &InstructionDecoder::decodeString},
	{"cmpsw", false, 2, {"Xv","Yv",0}, GROUP_NONE, &InstructionDecoder::decodeString},
	{"test", false, 2, {"AL","Ib",0}, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{"test", false, 2, {"AX","Iv",0}, GROUP_NONE, &InstructionDecoder::decodeAccImm},
	{"stosb", false, 2, {"Yb","AL",0}, GROUP_NONE, &InstructionDecoder::decodeString},
	{"stosw", false, 2, {"Yv","AX",0}, GROUP_NONE, &InstructionDecoder::decodeString},
	{"lodsb", false, 2, {"AL","Xb",0}, GROUP_NONE, &InstructionDecoder::decodeString},
	{"lodsw", false, 2, {"AX","Xv",0}, GROUP_NONE, &InstructionDecoder::decodeString},
	{"scasb", false, 2, {"AL","Yb",0}, GROUP_NONE, &InstructionDecoder::decodeString},
	{"scasw", false, 2, {"AX","Yv",0}, GROUP_NONE, &InstructionDecoder::decodeString},

	/* 0B */
	{"mov", false, 2, {"AL","Ib",0}, GROUP_NONE, &InstructionDecoder::decodeRegImm},
	{"mov", false, 2, {"CL","Ib",0}, GROUP_NONE, &InstructionDecoder::decodeRegImm},
	{"mov", false, 2, {"DL","Ib",0}, GROUP_NONE, &InstructionDecoder::decodeRegImm},
	{"mov", false, 2, {"BL","Ib",0}, GROUP_NONE, &InstructionDecoder::decodeRegImm},
	{"mov", false, 2, {"AH","Ib",0}, GROUP_NONE, &InstructionDecoder::decodeRegImm},
	{"mov", false, 2, {"CH","Ib",0}, GROUP_NONE, &InstructionDecoder::decodeRegImm},
	{"mov", false, 2, {"DH","Ib",0}, GROUP_NONE, &InstructionDecoder::decodeRegImm},
	{"mov", false, 2, {"BH","Ib",0}, GROUP_NONE, &InstructionDecoder::decodeRegImm},
	{"mov", false, 2, {"AX","Iv",0}, GROUP_NONE, &InstructionDecoder::decodeRegImm, &ExecutionUnit::execMOV},
	{"mov", false, 2, {"CX","Iv",0}, GROUP_NONE, &InstructionDecoder::decodeRegImm},
	{"mov", false, 2, {"DX","Iv",0}, GROUP_NONE, &InstructionDecoder::decodeRegImm},
	{"mov", false, 2, {"BX","Iv",0}, GROUP_NONE, &InstructionDecoder::decodeRegImm},
	{"mov", false, 2, {"SP","Iv",0}, GROUP_NONE, &InstructionDecoder::decodeRegImm},
	{"mov", false, 2, {"BP","Iv",0}, GROUP_NONE, &InstructionDecoder::decodeRegImm},
	{"mov", false, 2, {"SI","Iv",0}, GROUP_NONE, &InstructionDecoder::decodeRegImm},
	{"mov", false, 2, {"DI","Iv",0}, GROUP_NONE, &InstructionDecoder::decodeRegImm},

	/* 0C */
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{"ret", false, 1, {"Iw",0,0}, GROUP_NONE, &InstructionDecoder::decodeRetPop},
	{"ret", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"les", true, 2, {"Gv","Mp",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"lds", true, 2, {"Gv","Mp",0}, GROUP_NONE, &InstructionDecoder::decodeRegRM},
	{"mov", true, 2, {"Eb","Ib",0}, GROUP_NONE, &InstructionDecoder::decodeRMImm},
	{"mov", true, 2, {"Ev","Iv",0}, GROUP_NONE, &InstructionDecoder::decodeRMImm},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{"ret", false, 1, {"Iw",0,0}, GROUP_NONE, &InstructionDecoder::decodeRetPop},
	{"ret", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"int 3", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeType3},
	{"int", false, 1, {"Ib",0,0}, GROUP_NONE, &InstructionDecoder::decodeIntNum},
	{"into", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"iret", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeNone},

	/* 0D */
	{0, true, 2, {"Eb",0,0}, GROUP_2},
	{0, true, 2, {"Ev",0,0}, GROUP_2},
	{0, true, 2, {"Eb","CL",0}, GROUP_2},
	{0, true, 2, {"Ev","CL",0}, GROUP_2},
	{"aam", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeAccBase},
	{"aad", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeAccBase},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{"xlat", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"esc 0", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeEscNum},
	{"esc 1", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeEscNum},
	{"esc 2", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeEscNum},
	{"esc 3", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeEscNum},
	{"esc 4", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeEscNum},
	{"esc 5", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeEscNum},
	{"esc 6", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeEscNum},
	{"esc 7", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeEscNum},

	/* 0E */
	{"loopne/loopnz", false, 1, {"Jb",0,0}, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"loope/loopz", false, 1, {"Jb",0,0}, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"loop", false, 1, {"Jb",0,0}, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"jcxz", false, 1, {"Jb",0,0}, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"in", false, 2, {"AL","Ib",0}, GROUP_NONE, &InstructionDecoder::decodeAccPort},
	{"in", false, 2, {"AX","Ib",0}, GROUP_NONE, &InstructionDecoder::decodeAccPort},
	{"out", false, 2, {"Ib","AL",0}, GROUP_NONE, &InstructionDecoder::decodeAccPort},
	{"out", false, 2, {"Ib","AX",0}, GROUP_NONE, &InstructionDecoder::decodeAccPort},
	{"call", false, 1, {"Jv",0,0}, GROUP_NONE, &InstructionDecoder::decodeIntra},
	{"jmp", false, 1, {"Jv",0,0}, GROUP_NONE, &InstructionDecoder::decodeIntra},
	{"jmp", false, 1, {"Ap",0,0}, GROUP_NONE, &InstructionDecoder::decodeInter},
	{"jmp", false, 1, {"Jb",0,0}, GROUP_NONE, &InstructionDecoder::decodeShort},
	{"in", false, 2, {"AL","DX",0}, GROUP_NONE, &InstructionDecoder::decodeAccVPort},
	{"in", false, 2, {"AX","DX",0}, GROUP_NONE, &InstructionDecoder::decodeAccVPort},
	{"out", false, 2, {"DX","AL",0}, GROUP_NONE, &InstructionDecoder::decodeAccVPort},
	{"out", false, 2, {"DX","AX",0}, GROUP_NONE, &InstructionDecoder::decodeAccVPort},

	/* 0F */
	{"lock", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeNone},
	{0, false, 0, {0,0,0}, GROUP_RESERVED},
	{"repne", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"rep/repe", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"hlt", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"cmc", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeNone},
	{0, false, 1, {"Eb",0,0}, GROUP_3},
	{0, false, 1, {"Ev",0,0}, GROUP_3},
	{"clc", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"stc", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"cli", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"sti", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"cld", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeNone},
	{"std", false, 0, {0,0,0}, GROUP_NONE, &InstructionDecoder::decodeNone},
	{0, false, 1, {"Eb",0,0}, GROUP_4},
	{0, false, 1, {"Ev",0,0}, GROUP_5}
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

