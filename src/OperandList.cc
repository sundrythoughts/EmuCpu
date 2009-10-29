#include "OperandList.hh"

OperandList::OperandList () {
	//m_ops.resize (2);
}


OperandList::~OperandList () {
	//m_ops.clear ();
}


bool
OperandList::operandSize () const {
	return m_op_size;
}


void
OperandList::setOperandSize (bool s) {
	m_op_size = s;
}


NumberWrapper&
OperandList::src () {
	return m_ops[1];
}

NumberWrapper&
OperandList::dest () {
	return m_ops[0];
}

void
OperandList::reset () {
	//m_ops.clear ();
	//m_ops.resize (2);
	m_ops[0].free ();
	m_ops[1].free ();
}

