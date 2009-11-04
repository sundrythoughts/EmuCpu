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


#ifndef JAF__DEFINES_HH
#define JAF__DEFINES_HH

#include <cstddef>

namespace Jaf {

enum AddressMode {
	ADDR_MODE_NONE = 0,
	ADDR_MODE_REG_RM,
	ADDR_MODE_ACC_IMM,
	ADDR_MODE_SEGMENT,
	ADDR_MODE_ACC,
	ADDR_MODE_REG,
	ADDR_MODE_SHORT,
	ADDR_MODE_SEG_RM,
	ADDR_MODE_ACC_REG,
	ADDR_MODE_ACC_MEM,
	ADDR_MODE_REG_IMM,
	ADDR_MODE_INTRA,
	ADDR_MODE_INTER,
	ADDR_MODE_XFER_IND,
	ADDR_MODE_RM_IMM,
	ADDR_MODE_ACC_PORT,
	ADDR_MODE_RM,
	ADDR_MODE_FLAGS,
	ADDR_MODE_RET_POP,
	ADDR_MODE_TYPE3,
	ADDR_MODE_ESC_NUM,
	ADDR_MODE_ACC_VPORT,
	ADDR_MODE_ACC_BASE,
	ADDR_MODE_INT_NUM,
	ADDR_MODE_STRING
};

enum OperandSize {
	OP_SIZE_8 = 0,
	OP_SIZE_16,
	OP_SIZE_NONE
};

enum RegisterIndex8 {
	REG_AL = 0,
	REG_CL,
	REG_DL,
	REG_BL,
	REG_AH,
	REG_CH,
	REG_DH,
	REG_BH,
	REG_COUNT_8
};

enum RegisterIndex16 {
	REG_AX = 0,
	REG_CX,
	REG_DX,
	REG_BX,
	REG_SP,
	REG_BP,
	REG_SI,
	REG_DI,
	REG_FLAGS,
	REG_COUNT_16
};

const char* getRegIndexName (size_t op_sz, size_t reg_i);
const char* getRegIndex8Name (size_t reg_i);
const char* getRegIndex16Name (size_t reg_i);

enum SegmentRegisterIndex {
	SREG_ES = 0,
	SREG_CS,
	SREG_SS,
	SREG_DS,
	SREG_COUNT
};

extern const char* sreg_index_names[SREG_COUNT];

const char* getSegRegIndexName (size_t reg_i);

union ModRM {
	unsigned char byte;
	struct {
		unsigned int rm : 3;
		unsigned int reg : 3;
		unsigned int mod : 2;
	};
};

union ScaleIndexBase {
	unsigned char byte;
	struct {
		unsigned int base : 3;
		unsigned int index : 3;
		unsigned int scale : 2;
	} v;
};

} //end namespace Jaf

#endif //JAF__DEFINES_HH

