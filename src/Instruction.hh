/**
@file Instruction.hh
@brief Stores the information and function pointers for decoding and executing instructions.
*/

#ifndef JAF__INSTRUCTION_HH
#define JAF__INSTRUCTION_HH

#include "InstructionDecoder.hh"
#include "ExecutionUnit.hh"
#include "OperandList.hh"
#include "InstructionTable.hh"

#include <vector>

/**
@class Instruction
@brief Store the information and function pointers for decoding and executing instructions.
*/
class Instruction {
	InstructionDecoder *m_decoder;
	ExecutionUnit *m_eunit;
	OperandList m_operands;
	const InstructionTableItem *m_inst_item;
	std::vector<unsigned char> m_inst_bytes;

public:
	/** */
	Instruction ();

	/** */
	void connectTo (InstructionDecoder &dec);

	/** */
	void connectTo (ExecutionUnit &eu);

	/** */
	OperandList& operands ();

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
	const std::vector<unsigned char>& getBytes () const;

	/** */
	template<typename T>
	void addBytes (const T &val);

}; //end class Instruction

template<typename T>
void
Instruction::addBytes (const T &val) {
	unsigned char *b = (unsigned char*)&val;
	for (size_t i = 0; i < sizeof(T); ++i) {
		m_inst_bytes.push_back (*b);
		++b;
	}
}

#endif //JAF__INSTRUCTION_HH

