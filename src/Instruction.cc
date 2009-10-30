#include "Instruction.hh"

Instruction::Instruction () : m_decoder (0), m_eunit (0), m_inst_item (0) {
}

void
Instruction::connectTo (InstructionDecoder &dec) {
	m_decoder = &dec;
}

void
Instruction::connectTo (ExecutionUnit &eu) {
	m_eunit = &eu;
}

OperandList&
Instruction::operands () {
	return m_operands;
}

void
Instruction::decode () {
	m_inst_item->decode (*m_decoder);
}

void
Instruction::execute () {
	m_inst_item->execute (*m_eunit, m_operands);
}

void
Instruction::setItem (const InstructionTableItem &item) {
	m_inst_item = &item;
}

const InstructionTableItem&
Instruction::getItem () {
	return *m_inst_item;
}

void
Instruction::reset () {
	m_operands.reset ();
	m_inst_item = 0;
	m_inst_bytes.clear ();
}

const std::vector<unsigned char>&
Instruction::getBytes () const {
	return m_inst_bytes;
}

