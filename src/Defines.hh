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

/**
@file Defines.hh
@brief Definitions and declarations for global data.
*/


#ifndef SIM8086__DEFINES_HH
#define SIM8086__DEFINES_HH

#include <cstddef>
#include "Types.hh"

/** @namespace Jaf */
namespace Jaf {

/** @brief Addressing modes. */
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

/** @brief Operand size. */
enum OperandSize {
	OP_SIZE_8 = 0,
	OP_SIZE_16,
	OP_SIZE_NONE
};

/** @brief Register indexes for 8-bit registers. */
enum RegisterIndex8 {
	REG_AL = 0,
	REG_CL,
	REG_DL,
	REG_BL,
	REG_AH,
	REG_CH,
	REG_DH,
	REG_BH,
	REG_COUNT_8 //number of indexes
};

/** @brief Register indexes for 16-bit registers. */
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
	REG_COUNT_16 //number of indexes
};

/**
@brief Get a register name.
@param op_sz The OperandSize of register.
@param reg_i The register index listed in RegisterIndex8 or RegisterIndex16.
*/
const char8* getRegIndexName (size_t op_sz, size_t reg_i);

/**
@brief Get a register name for an 8-bit register.
@param reg_i The register index listed in RegisterIndex8.
*/
const char8* getRegIndex8Name (size_t reg_i);

/**
@brief Get a register name for an 16-bit register.
@param reg_i The register index listed in RegisterIndex16.
*/
const char8* getRegIndex16Name (size_t reg_i);

/** @brief Register indexes of segment registers. */
enum SegmentRegisterIndex {
	SREG_ES = 0,
	SREG_CS,
	SREG_SS,
	SREG_DS,
	SREG_COUNT
};

/**
@brief Get a segment register name.
@param reg_i The segment register index listed in SegmentRegisterIndex.
*/
const char8* getSegRegIndexName (size_t reg_i);

/** @brief ModRM */
union ModRM {
	uint8 byte;
	struct {
		uint32 rm : 3;
		uint32 reg : 3;
		uint32 mod : 2;
	};
};

/** @brief Scale, index, and base */
union ScaleIndexBase {
	uint8 byte;
	struct {
		uint32 base : 3;
		uint32 index : 3;
		uint32 scale : 2;
	} v;
};

} //end namespace Jaf

#endif //SIM8086__DEFINES_HH

