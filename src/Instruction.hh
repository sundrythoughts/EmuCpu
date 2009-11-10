/**
@file Instruction.hh
@brief Stores the information and function pointers for decoding and executing instructions.
*/

#ifndef JAF__INSTRUCTION_HH
#define JAF__INSTRUCTION_HH

#include "InstructionDisassembly.hh"
#include "InstructionTable.hh"
#include <vector>

class CpuComponents;
class InstructionPrivate;

/**
@class Instruction
@brief Store the information and function pointers for decoding and executing instructions.
*/
class Instruction {

	InstructionPrivate *p;

public:
	/** */
	Instruction ();

	/** */
	void connectTo (CpuComponents &cpu);

	/** */
	void connectTo (InstructionDecoder &dec);

	/** */
	void connectTo (ExecutionUnit &eu);

	/** */
	OperandList& operands ();

	/** */
	InstructionDisassembly& disassembly ();

	/** */
	void decode ();

	/** */
	void execute ();

	/** */
	void setItem (const InstructionTableItem &item);

	/** */
	const InstructionTableItem& getItem ();

	/** */
	void reset ();

	/** */
	bool isNull () const;

	/** */
	const std::vector<unsigned char>& getBytes () const;

	/** */
	std::vector<unsigned char>& getBytes ();

	/** */
	unsigned char getByte (size_t i) const;

	/** */
	template<typename T>
	void addBytes (const T &val);

}; //end class Instruction

template<typename T>
void
Instruction::addBytes (const T &val) {
	unsigned char *b = (unsigned char*)&val;
	for (size_t i = 0; i < sizeof(T); ++i) {
		getBytes ().push_back (*b);
		++b;
	}
}

#endif //JAF__INSTRUCTION_HH

