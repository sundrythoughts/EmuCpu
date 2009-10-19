#ifndef JAF__OPERAND_LIST_HH
#define JAF__OPERAND_LIST_HH

//#include "InstructionTable.hh"
#include "NumberWrapper.hh"
#include <string>
#include <vector>

class OperandList {
	//InstructionTableItem *m_inst;
	//std::vector m_machine_code;
	bool m_op_size;
	//std::vector<NumberWrapper> m_ops;
	NumberWrapper m_ops[2];

public:
	OperandList () {
		//m_ops.resize (2);
	}

	~OperandList () {
		//m_ops.clear ();
	}

	bool operandSize () const {
		return m_op_size;
	}

	void setOperandSize (bool s) {
		m_op_size = s;
	}

	NumberWrapper& src () {
		return m_ops[1];
	}

	NumberWrapper& dest () {
		return m_ops[0];
	}

	void reset () {
		//m_ops.clear ();
		//m_ops.resize (2);
		m_ops[0].free ();
		m_ops[1].free ();
	}
};

#endif //JAF__OPERAND_LIST_HH

