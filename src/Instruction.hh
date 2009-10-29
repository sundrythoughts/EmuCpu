#ifndef JAF__INSTRUCTION_HH
#define JAF__INSTRUCTION_HH

#include "InstructionDecoder.hh"
#include "ExecutionUnit.hh"
#include "OperandList.hh"
#include "InstructionTable.hh"

class Instruction {
	InstructionDecoder *m_decoder;
	ExecutionUnit *m_eunit;
	OperandList m_operands;
	const InstructionTableItem *m_inst_item;

public:
	Instruction () : m_decoder (0), m_eunit (0), m_inst_item (0) {
	}

	void connectTo (InstructionDecoder &dec) {
		m_decoder = &dec;
	}

	void connectTo (ExecutionUnit &eu) {
		m_eunit = &eu;
	}

	OperandList& operands () {
		return m_operands;
	}

	void decode () {
		m_inst_item->decode (*m_decoder);
	}

	void execute () {
		m_inst_item->execute (*m_eunit, m_operands);
	}

	void setInstructionTableItem (const InstructionTableItem *item) {
		m_inst_item = 0;
	}

	void reset () {
		m_operands.reset ();
		m_inst_item = 0;
	}
};

#endif //JAF__INSTRUCTION_HH

