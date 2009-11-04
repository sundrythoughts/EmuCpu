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

const InstructionTableItem InstructionTable::one_byte_opcode_instruction_map[256] = {
	/* 0x */
	{"add", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execADD},
	{"add", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execADD},
	{"add", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execADD},
	{"add", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execADD},
	{"add", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execADD},
	{"add", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execADD},
	{"push es", false, GROUP_NONE, &InstructionDecoder::decodeSegment, &ExecutionUnit::execNotImplemented},
	{"pop es", false, GROUP_NONE, &InstructionDecoder::decodeSegment, &ExecutionUnit::execNotImplemented},
	{"or", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execOR},
	{"or", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execOR},
	{"or", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execOR},
	{"or", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execOR},
	{"or", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execOR},
	{"or", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execOR},
	{"push cs", false, GROUP_NONE, &InstructionDecoder::decodeSegment, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},

	/* 1x */
	{"adc", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execADC},
	{"adc", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execADC},
	{"adc", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execADC},
	{"adc", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execADC},
	{"adc", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execADC},
	{"adc", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execADC},
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
	{"and", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execAND},
	{"and", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execAND},
	{"and", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execAND},
	{"and", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execAND},
	{"and", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execAND},
	{"and", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execAND},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{"daa", false, GROUP_NONE, &InstructionDecoder::decodeAcc, &ExecutionUnit::execNotImplemented},
	{"sub", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execSUB},
	{"sub", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execSUB},
	{"sub", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execSUB},
	{"sub", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execSUB},
	{"sub", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execSUB},
	{"sub", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execSUB},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{"das", false, GROUP_NONE, &InstructionDecoder::decodeAcc, &ExecutionUnit::execNotImplemented},

	/* 3x */
	{"xor", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execXOR},
	{"xor", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execXOR},
	{"xor", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execXOR},
	{"xor", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execXOR},
	{"xor", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execXOR},
	{"xor", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execXOR},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{"aaa", false, GROUP_NONE, &InstructionDecoder::decodeAcc, &ExecutionUnit::execNotImplemented},
	{"cmp", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execCMP},
	{"cmp", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execCMP},
	{"cmp", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execCMP},
	{"cmp", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execCMP},
	{"cmp", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execCMP},
	{"cmp", false, GROUP_NONE, &InstructionDecoder::decodeAccImm, &ExecutionUnit::execCMP},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
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
	{0, true, GROUP_0, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, true, GROUP_0, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, true, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, true, GROUP_1, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{"test", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"test", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"xchg", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execXCHG},
	{"xchg", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execXCHG},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execMOV},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execMOV},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execMOV},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execMOV},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeSegRM, &ExecutionUnit::execMOV},
	{"lea", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
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
	{"call", false, GROUP_NONE, &InstructionDecoder::decodeInter, &ExecutionUnit::execNotImplemented},
	{"wait", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"pushf", false, GROUP_NONE, &InstructionDecoder::decodeFlags, &ExecutionUnit::execNotImplemented},
	{"popf", false, GROUP_NONE, &InstructionDecoder::decodeFlags, &ExecutionUnit::execNotImplemented},
	{"sahf", false, GROUP_NONE, &InstructionDecoder::decodeFlags, &ExecutionUnit::execSAHF},
	{"lahf", false, GROUP_NONE, &InstructionDecoder::decodeFlags, &ExecutionUnit::execLAHF},

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
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{"ret", false, GROUP_NONE, &InstructionDecoder::decodeRetPop, &ExecutionUnit::execNotImplemented},
	{"ret", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"les", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"lds", true, GROUP_NONE, &InstructionDecoder::decodeRegRM, &ExecutionUnit::execNotImplemented},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execMOV},
	{"mov", true, GROUP_NONE, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execMOV},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{"ret", false, GROUP_NONE, &InstructionDecoder::decodeRetPop, &ExecutionUnit::execNotImplemented},
	{"ret", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"int 3", false, GROUP_NONE, &InstructionDecoder::decodeType3, &ExecutionUnit::execNotImplemented},
	{"int", false, GROUP_NONE, &InstructionDecoder::decodeIntNum, &ExecutionUnit::execNotImplemented},
	{"into", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"iret", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},

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
	{0, false, GROUP_RESERVED, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
	{"repne", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"rep/repe", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
	{"hlt", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execHLT},
	{"cmc", false, GROUP_NONE, &InstructionDecoder::decodeNone, &ExecutionUnit::execNotImplemented},
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
		{"sbb", true, GROUP_0, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execNotImplemented},
		{"and", true, GROUP_0, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execAND},
		{"sub", true, GROUP_0, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execSUB},
		{"xor", true, GROUP_0, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execXOR},
		{"cmp", true, GROUP_0, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execCMP}
	},//END GROUP 0

	{//GROUP 1
		{"add", true, GROUP_1, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execADD},
		{0, true, GROUP_1, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{"adc", true, GROUP_1, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execADC},
		{"sbb", true, GROUP_1, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execNotImplemented},
		{0, true, GROUP_1, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{"sub", true, GROUP_1, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execSUB},
		{0, true, GROUP_1, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{"cmp", true, GROUP_1, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execCMP}
	},//END GROUP 1

	{//GROUP 2
		{"pop", true, GROUP_2, &InstructionDecoder::decodeRM, &ExecutionUnit::execNotImplemented},
		{0, true, GROUP_2, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, true, GROUP_2, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, true, GROUP_2, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, true, GROUP_2, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, true, GROUP_2, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, true, GROUP_2, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, true, GROUP_2, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented}
	},//END GROUP 2

	{//GROUP 3
		{"rol", true, GROUP_3, &InstructionDecoder::decodeRM, &ExecutionUnit::execROL},
		{"ror", true, GROUP_3, &InstructionDecoder::decodeRM, &ExecutionUnit::execROR},
		{"rcl", true, GROUP_3, &InstructionDecoder::decodeRM, &ExecutionUnit::execRCL},
		{"rcr", true, GROUP_3, &InstructionDecoder::decodeRM, &ExecutionUnit::execRCR},
		{"shl/sal", true, GROUP_3, &InstructionDecoder::decodeRM, &ExecutionUnit::execNotImplemented},
		{"shr", true, GROUP_3, &InstructionDecoder::decodeRM, &ExecutionUnit::execNotImplemented},
		{0, true, GROUP_3, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{"sar", true, GROUP_3, &InstructionDecoder::decodeRM, &ExecutionUnit::execNotImplemented}
	},//END GROUP 3

	{//GROUP 4
		{"test", true, GROUP_4, &InstructionDecoder::decodeRMImm, &ExecutionUnit::execNotImplemented},
		{0, true, GROUP_4, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{"not", true, GROUP_4, &InstructionDecoder::decodeRM, &ExecutionUnit::execNotImplemented},
		{"neg", true, GROUP_4, &InstructionDecoder::decodeRM, &ExecutionUnit::execNotImplemented},
		{"mul", true, GROUP_4, &InstructionDecoder::decodeRM, &ExecutionUnit::execNotImplemented},
		{"imul", true, GROUP_4, &InstructionDecoder::decodeRM, &ExecutionUnit::execNotImplemented},
		{"div", true, GROUP_4, &InstructionDecoder::decodeRM, &ExecutionUnit::execNotImplemented},
		{"idiv", true, GROUP_4, &InstructionDecoder::decodeRM, &ExecutionUnit::execNotImplemented}
	},//END GROUP 4

	{//GROUP 5
		{"inc", true, GROUP_5, &InstructionDecoder::decodeRM, &ExecutionUnit::execINC},
		{"dec", true, GROUP_5, &InstructionDecoder::decodeRM, &ExecutionUnit::execDEC},
		{0, true, GROUP_5, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, true, GROUP_5, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, true, GROUP_5, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, true, GROUP_5, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, true, GROUP_5, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented},
		{0, true, GROUP_5, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented}
	},//END GROUP 5

	{//GROUP 6
		{"inc", true, GROUP_6, &InstructionDecoder::decodeRM, &ExecutionUnit::execINC},
		{"dec", true, GROUP_6, &InstructionDecoder::decodeRM, &ExecutionUnit::execDEC},
		{"call", true, GROUP_6, &InstructionDecoder::decodeXferInd, &ExecutionUnit::execNotImplemented},
		{"call", true, GROUP_6, &InstructionDecoder::decodeXferInd, &ExecutionUnit::execNotImplemented},
		{"jmp", true, GROUP_6, &InstructionDecoder::decodeXferInd, &ExecutionUnit::execNotImplemented},
		{"jmp", true, GROUP_6, &InstructionDecoder::decodeXferInd, &ExecutionUnit::execNotImplemented},
		{"push", true, GROUP_6, &InstructionDecoder::decodeRM, &ExecutionUnit::execNotImplemented},
		{0, true, GROUP_6, &InstructionDecoder::decodeNotImplemented, &ExecutionUnit::execNotImplemented}
	}//END GROUP 6
};

//***OPERATION PSEUDOCODE****
//get opcode from memory
//decode the opcode by getting the element from opcode array
//decode each operand and store the values Operation[[{Value<int>(0), 0x7} {pointer to opcode instruction map element}]]
//store Operation in the Queue (if 8086 has pipelining???)
//Operation->instruction->execute (maching, Operation->operands)

