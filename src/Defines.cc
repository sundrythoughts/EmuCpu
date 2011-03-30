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


#include "Defines.hh"

namespace Jaf {

const char8* reg_index_8_names[REG_COUNT_8] = {
	"al",
	"cl",
	"dl",
	"bl",
	"ah",
	"ch",
	"dh",
	"bh"
};

const char8* reg_index_16_names[REG_COUNT_16] = {
	"ax",
	"cx",
	"dx",
	"bx",
	"sp",
	"bp",
	"si",
	"di",
	"flags"
};

const char8* sreg_index_names[SREG_COUNT] = {
	"es",
	"cs",
	"ss",
	"ds"
};

const char8*
getSegRegIndexName (size_t reg_i) {
	if (reg_i >= SREG_COUNT) {
		return "";
	}

	return sreg_index_names[reg_i];
}

const char8*
getRegIndexName (size_t op_sz, size_t reg_i) {
	if (op_sz == OP_SIZE_8 && reg_i < REG_COUNT_8) {
		return reg_index_8_names[reg_i];
	}
	else if (op_sz == OP_SIZE_16 && reg_i < REG_COUNT_16) {
		return reg_index_16_names[reg_i];
	}
	else {
		return "";
	}
}

const char8*
getRegIndex8Name (size_t reg_i) {
	if (reg_i < REG_COUNT_8) {
		return reg_index_8_names[reg_i];
	}
	else {
		return "";
	}
}

const char8*
getRegIndex16Name (size_t reg_i) {
	if (reg_i < REG_COUNT_16) {
		return reg_index_16_names[reg_i];
	}
	else {
		return "";
	}
}

} //end namespace Jaf

