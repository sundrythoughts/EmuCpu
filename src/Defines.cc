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

} //end namespace Jaf
