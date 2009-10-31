#include "Defines.hh"

namespace Jaf {

const char* reg_index_8_names[REG_COUNT_8] = {
	"al",
	"cl",
	"dl",
	"bl",
	"ah",
	"ch",
	"dh",
	"bh"
};

const char* reg_index_16_names[REG_COUNT_16] = {
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

const char* sreg_index_names[SREG_COUNT] = {
	"es",
	"cs",
	"ss",
	"ds"
};

const char*
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

const char*
getRegIndex8Name (size_t reg_i) {
	if (reg_i < REG_COUNT_8) {
		return reg_index_8_names[reg_i];
	}
	else {
		return "";
	}
}

const char*
getRegIndex16Name (size_t reg_i) {
	if (reg_i < REG_COUNT_16) {
		return reg_index_16_names[reg_i];
	}
	else {
		return "";
	}
}

} //end namespace Jaf
