/*
 * sim8086 -- Emulates an Intel 8086 processor
 * Copyright (C) 2009  Joseph Freeman (jfree143dev AT gmail DOT com)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "InstructionTable.hh"

const InstructionTableItem&
InstructionTable::getOneByteOpcodeInstruction (size_t i) {
	return one_byte_opcode_instruction_map[i];
}

const InstructionTableItem&
InstructionTable::getOneByteOpcodeInstructionExtension (size_t row, size_t col) {
	return one_byte_opcode_instruction_extension_map[row][col];
}

const InstructionTableItem InstructionTable::one_byte_opcode_instruction_map[256] = {
	/* 0x */
	{"add", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execADD},
	{"add", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execADD},
	{"add", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execADD},
	{"add", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execADD},
	{"add", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execADD},
	{"add", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execADD},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeSegment, &ExecutionUnit::execPUSH}, //push es
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeSegment, &ExecutionUnit::execPOP}, //pop es
	{"or", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execOR},
	{"or", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execOR},
	{"or", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execOR},
	{"or", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execOR},
	{"or", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execOR},
	{"or", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execOR},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeSegment, &ExecutionUnit::execPUSH}, //push cs
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},

	/* 1x */
	{"adc", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execADC},
	{"adc", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execADC},
	{"adc", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execADC},
	{"adc", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execADC},
	{"adc", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execADC},
	{"adc", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execADC},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeSegment, &ExecutionUnit::execPUSH}, //push ss
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeSegment, &ExecutionUnit::execPOP}, //pop ss
	{"sbb", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execSBB},
	{"sbb", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execSBB},
	{"sbb", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execSBB},
	{"sbb", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execSBB},
	{"sbb", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execSBB},
	{"sbb", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execSBB},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeSegment, &ExecutionUnit::execPUSH}, //push ds
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeSegment, &ExecutionUnit::execPOP}, //pop ds

	/* 2x */
	{"and", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execAND},
	{"and", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execAND},
	{"and", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execAND},
	{"and", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execAND},
	{"and", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execAND},
	{"and", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execAND},
	{"seg", false, GROUP_NONE, &InstructionDecoder::decodeSegment, &ExecutionUnit::execSEG},
	{"daa", false, GROUP_NONE, &InstructionDecoder::decodeAcc, &ExecutionUnit::execNotImplemented},
	{"sub", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execSUB},
	{"sub", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execSUB},
	{"sub", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execSUB},
	{"sub", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execSUB},
	{"sub", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execSUB},
	{"sub", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execSUB},
	{"seg", false, GROUP_NONE, &InstructionDecoder::decodeSegment, &ExecutionUnit::execSEG},
	{"das", false, GROUP_NONE, &InstructionDecoder::decodeAcc, &ExecutionUnit::execNotImplemented},

	/* 3x */
	{"xor", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execXOR},
	{"xor", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execXOR},
	{"xor", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execXOR},
	{"xor", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execXOR},
	{"xor", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execXOR},
	{"xor", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execXOR},
	{"seg", false, GROUP_NONE, &InstructionDecoder::decodeSegment, &ExecutionUnit::execSEG},
	{"aaa", false, GROUP_NONE, &InstructionDecoder::decodeAcc, &ExecutionUnit::execNotImplemented},
	{"cmp", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execCMP},
	{"cmp", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execCMP},
	{"cmp", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execCMP},
	{"cmp", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execCMP},
	{"cmp", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execCMP},
	{"cmp", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execCMP},
	{"seg", false, GROUP_NONE, &InstructionDecoder::decodeSegment, &ExecutionUnit::execSEG},
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
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execPUSH},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execPUSH},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execPUSH},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execPUSH},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execPUSH},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execPUSH},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execPUSH},
	{"push", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execPUSH},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execPOP},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execPOP},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execPOP},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execPOP},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execPOP},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execPOP},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execPOP},
	{"pop", false, GROUP_NONE, &InstructionDecoder::decodeReg, &ExecutionUnit::execPOP},

	/* 6x */
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},

	/* 7x */
	{"jo", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJO},
	{"jno", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJNO},
	{"jb/jnae/jc", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJNAE},
	{"jnb/jae/jnc", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJNB},
	{"jz/je", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJE},
	{"jnz/jne", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJNE},
	{"jbe/jna", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJNA},
	{"jnbe/ja", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJNBE},
	{"js", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJS},
	{"jns", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJNS},
	{"jp/jpe", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJPE},
	{"jnp/jpo", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJNP},
	{"jl/jnge", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJL},
	{"jnl/jge", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJGE},
	{"jle/jng", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJLE},
	{"jnle/jg", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJG},

	/* 8x */
	{0, true, GROUP_0, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, true, GROUP_0, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, true, GROUP_1, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{"test", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execTEST},
	{"test", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execTEST},
	{"xchg", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execXCHG},
	{"xchg", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execXCHG},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execMOV},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execMOV},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execMOV},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execMOV},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeSegRM, &ExecutionUnit::execMOV},
	{"lea", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execLEA}, //has an inverted D bit
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeSegRM, &ExecutionUnit::execMOV},
	{0, true, GROUP_2, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},

	/* 9x */
	{"nop", false, GROUP_NONE, &InstructionDecoder::decodeAccReg, &ExecutionUnit::execNOP},
	{"xchg", false, GROUP_NONE, &InstructionDecoder::decodeAccReg, &ExecutionUnit::execXCHG},
	{"xchg", false, GROUP_NONE, &InstructionDecoder::decodeAccReg, &ExecutionUnit::execXCHG},
	{"xchg", false, GROUP_NONE, &InstructionDecoder::decodeAccReg, &ExecutionUnit::execXCHG},
	{"xchg", false, GROUP_NONE, &InstructionDecoder::decodeAccReg, &ExecutionUnit::execXCHG},
	{"xchg", false, GROUP_NONE, &InstructionDecoder::decodeAccReg, &ExecutionUnit::execXCHG},
	{"xchg", false, GROUP_NONE, &InstructionDecoder::decodeAccReg, &ExecutionUnit::execXCHG},
	{"xchg", false, GROUP_NONE, &InstructionDecoder::decodeAccReg, &ExecutionUnit::execXCHG},
	{"cbw", false, GROUP_NONE, &InstructionDecoder::decodeAcc, &ExecutionUnit::execCBW},
	{"cwd", false, GROUP_NONE, &InstructionDecoder::decodeAcc, &ExecutionUnit::execCWD},
	{"call", false, GROUP_NONE, &InstructionDecoder::decodeInter, &ExecutionUnit::execCALLFAR},
	{"wait", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"pushf", false, GROUP_NONE, &InstructionDecoder::decodeFlags, &ExecutionUnit::execPUSHF},
	{"popf", false, GROUP_NONE, &InstructionDecoder::decodeFlags, &ExecutionUnit::execPOPF},
	{"sahf", false, GROUP_NONE, &InstructionDecoder::decodeFlags, &ExecutionUnit::execSAHF},
	{"lahf", false, GROUP_NONE, &InstructionDecoder::decodeFlags, &ExecutionUnit::execLAHF},

	/* Ax */
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeAccMem, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeAccMem, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeAccMem, &ExecutionUnit::execMOV},
	{"mov", false, GROUP_NONE, &InstructionDecoder::decodeAccMem, &ExecutionUnit::execMOV},
	{"movsb", false, GROUP_NONE, &InstructionDecoder::decodeString, &ExecutionUnit::execMOVS},
	{"movsw", false, GROUP_NONE, &InstructionDecoder::decodeString, &ExecutionUnit::execMOVS},
	{"cmpsb", false, GROUP_NONE, &InstructionDecoder::decodeString, &ExecutionUnit::execCMPS},
	{"cmpsw", false, GROUP_NONE, &InstructionDecoder::decodeString, &ExecutionUnit::execCMPS},
	{"test", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execTEST},
	{"test", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execTEST},
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
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{"ret", false, GROUP_NONE, &InstructionDecoder::decodeRetPop, &ExecutionUnit::execRET}, //near
	{"ret", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execRET}, //near
	{"les", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"lds", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execMOV},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execMOV},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{"ret", false, GROUP_NONE, &InstructionDecoder::decodeRetPop, &ExecutionUnit::execRETFAR}, //far
	{"ret", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execRETFAR}, //far
	{"int 3", false, GROUP_NONE, &InstructionDecoder::decodeType3, &ExecutionUnit::execNotImplemented},
	{"int", false, GROUP_NONE, &InstructionDecoder::decodeIntNum, &ExecutionUnit::execINT},
	{"into", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"iret", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execIRET},

	/* Dx */
	{0, true, GROUP_3, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, true, GROUP_3, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, true, GROUP_3, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, true, GROUP_3, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{"aam", false, GROUP_NONE, &InstructionDecoder::decodeAccBase, &ExecutionUnit::execNotImplemented},
	{"aad", false, GROUP_NONE, &InstructionDecoder::decodeAccBase, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
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
	{"loopne/loopnz", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execLOOPNE},
	{"loope/loopz", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execLOOPE},
	{"loop", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execLOOP},
	{"jcxz", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJCXZ},
	{"in", false, GROUP_NONE, &InstructionDecoder::decodeAccPort, &ExecutionUnit::execIN},
	{"in", false, GROUP_NONE, &InstructionDecoder::decodeAccPort, &ExecutionUnit::execIN},
	{"out", false, GROUP_NONE, &InstructionDecoder::decodeAccPort, &ExecutionUnit::execOUT},
	{"out", false, GROUP_NONE, &InstructionDecoder::decodeAccPort, &ExecutionUnit::execOUT},
	{"call", false, GROUP_NONE, &InstructionDecoder::decodeIntra, &ExecutionUnit::execCALL},
	{"jmp", false, GROUP_NONE, &InstructionDecoder::decodeIntra,  &ExecutionUnit::execJMPSHORT},
	{"jmp", false, GROUP_NONE, &InstructionDecoder::decodeInter, &ExecutionUnit::execJMPFAR},
	{"jmp", false, GROUP_NONE, &InstructionDecoder::decodeShort, &ExecutionUnit::execJMPSHORT},
	{"in", false, GROUP_NONE, &InstructionDecoder::decodeAccVPort, &ExecutionUnit::execIN},
	{"in", false, GROUP_NONE, &InstructionDecoder::decodeAccVPort, &ExecutionUnit::execIN},
	{"out", false, GROUP_NONE, &InstructionDecoder::decodeAccVPort, &ExecutionUnit::execOUT},
	{"out", false, GROUP_NONE, &InstructionDecoder::decodeAccVPort, &ExecutionUnit::execOUT},

	/* Fx */
	{"lock", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{"repne", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"rep/repe", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"hlt", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execHLT},
	{"cmc", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execCMC},
	{0, true, GROUP_4, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, true, GROUP_4, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{"clc", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execCLC},
	{"stc", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execSTC},
	{"cli", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execCLI},
	{"sti", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execSTI},
	{"cld", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execCLD},
	{"std", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execSTD},
	{0, true, GROUP_5, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, true, GROUP_6, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented}
};

const InstructionTableItem InstructionTable::one_byte_opcode_instruction_extension_map[7][8] = {
	{//GROUP 0
		{"add", true, GROUP_0, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execADD},
		{"or", true, GROUP_0, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execOR},
		{"adc", true, GROUP_0, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execADC},
		{"sbb", true, GROUP_0, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execSBB},
		{"and", true, GROUP_0, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execAND},
		{"sub", true, GROUP_0, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execSUB},
		{"xor", true, GROUP_0, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execXOR},
		{"cmp", true, GROUP_0, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execCMP}
	},//END GROUP 0

	{//GROUP 1
		{"add", true, GROUP_1, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execADD},
		{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{"adc", true, GROUP_1, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execADC},
		{"sbb", true, GROUP_1, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execSBB},
		{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{"sub", true, GROUP_1, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execSUB},
		{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{"cmp", true, GROUP_1, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execCMP}
	},//END GROUP 1

	{//GROUP 2
		{"pop", true, GROUP_2, &InstructionDecoder::decodeRM, &ExecutionUnit::execPOP},
		{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented}
	},//END GROUP 2

	{//GROUP 3
		{"rol", true, GROUP_3, &InstructionDecoder::decodeRM, &ExecutionUnit::execROL},
		{"ror", true, GROUP_3, &InstructionDecoder::decodeRM, &ExecutionUnit::execROR},
		{"rcl", true, GROUP_3, &InstructionDecoder::decodeRM, &ExecutionUnit::execRCL},
		{"rcr", true, GROUP_3, &InstructionDecoder::decodeRM, &ExecutionUnit::execRCR},
		{"shl/sal", true, GROUP_3, &InstructionDecoder::decodeRM, &ExecutionUnit::execSHL},
		{"shr", true, GROUP_3, &InstructionDecoder::decodeRM, &ExecutionUnit::execSHR},
		{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{"sar", true, GROUP_3, &InstructionDecoder::decodeRM, &ExecutionUnit::execSAR}
	},//END GROUP 3

	{//GROUP 4
		{"test", true, GROUP_4, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execTEST},
		{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{"not", true, GROUP_4, &InstructionDecoder::decodeRM, &ExecutionUnit::execNOT},
		{"neg", true, GROUP_4, &InstructionDecoder::decodeRM, &ExecutionUnit::execNEG},
		{"mul", true, GROUP_4, &InstructionDecoder::decodeRM, &ExecutionUnit::execMUL},
		{"imul", true, GROUP_4, &InstructionDecoder::decodeRM, &ExecutionUnit::execNotImplemented},
		{"div", true, GROUP_4, &InstructionDecoder::decodeRM, &ExecutionUnit::execDIV},
		{"idiv", true, GROUP_4, &InstructionDecoder::decodeRM, &ExecutionUnit::execNotImplemented}
	},//END GROUP 4

	{//GROUP 5
		{"inc", true, GROUP_5, &InstructionDecoder::decodeRM, &ExecutionUnit::execINC},
		{"dec", true, GROUP_5, &InstructionDecoder::decodeRM, &ExecutionUnit::execDEC},
		{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented}
	},//END GROUP 5

	{//GROUP 6
		{"inc", true, GROUP_6, &InstructionDecoder::decodeRM, &ExecutionUnit::execINC},
		{"dec", true, GROUP_6, &InstructionDecoder::decodeRM, &ExecutionUnit::execDEC},
		{"call", true, GROUP_6, &InstructionDecoder::decodeXferInd, &ExecutionUnit::execCALLFAR},
		{"call", true, GROUP_6, &InstructionDecoder::decodeXferInd, &ExecutionUnit::execCALLFAR},
		{"jmp", true, GROUP_6, &InstructionDecoder::decodeXferInd, &ExecutionUnit::execJMP},
		{"jmp", true, GROUP_6, &InstructionDecoder::decodeXferInd, &ExecutionUnit::execJMPFAR},
		{"push", true, GROUP_6, &InstructionDecoder::decodeRM, &ExecutionUnit::execPUSH},
		{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented}
	}//END GROUP 6
};

