#ifndef JAF__OPERAND_HH
#define JAF__OPERAND_HH

#include "Defines.hh"
#include <vector>

class Operand {
	size_t m_op_size;
	std::vector<Value> m_op_vec;


public:
	Operand () :  {
		m_op_size = Jaf::OP_SIZE_NONE;
	}

	~Operand () {
		
	}

	OperandType get_operand_type () const {
		return _op_type;
	}

	GValue* get_value () const {
		return _value;
	}

	
};

class OperandVector : public std::vector<Operand*> {

public:
	void add_operand (Operand::OperandType t, GValue *v) {
		push_back (new Operand (t, v));
	}

	~OperandVector () {
		size_t i;
		for (i = 0; i < size (); ++i) {
			delete (*this)[i];
		}
	}
};

#endif //JAF__OPERAND_HH

