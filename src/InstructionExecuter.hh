#ifndef JAF__INSTRUCTION_EXECUTER
#define JAF__INSTRUCTION_EXECUTER

#include "Cpu.hh"
#include "INumberReadableWritable.hh"
#include <iostream>

class InstructionExecuter {
public:
	template<typename T1, typename T2>
	static void execMOV (Cpu &cpu, INumberReadableWritable<T1> &op1, INumberReadableWritable<T2> &op2) {
		op1 = op2;
		std::cout << "execMOV (" << op1 << " , " << op2 << ")" << std::endl;
	}
};

#endif //JAF__INSTRUCTION_EXECUTER

