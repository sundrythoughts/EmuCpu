#ifndef DEFINES_HH
#define DEFINES_HH

namespace Jaf {

enum OperandSize {
	OP_SIZE_8 = 0,
	OP_SIZE_16
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

extern const char* reg_index_8_names[REG_COUNT_8];

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

extern const char* reg_index_16_names[REG_COUNT_16];

enum SegmentRegisterIndex {
	SREG_ES = 0,
	SREG_CS,
	SREG_SS,
	SREG_DS,
	SREG_COUNT
};

extern const char* sreg_index_names[SREG_COUNT];

union ModRM {
	unsigned char modrm;
	struct {
		unsigned int rm : 3;
		unsigned int reg : 3;
		unsigned int mod : 2;
	};
};

union ScaleIndexBase {
	unsigned char sib;
	struct {
		unsigned int base : 3;
		unsigned int index : 3;
		unsigned int scale : 2;
	} v;
};

} //end namespace Jaf

#endif //DEFINES_HH

