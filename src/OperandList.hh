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
	OperandList ();

	~OperandList ();

	bool operandSize () const;

	void setOperandSize (bool s);

	NumberWrapper& src ();

	NumberWrapper& dest ();

	void reset ();
};

#endif //JAF__OPERAND_LIST_HH

