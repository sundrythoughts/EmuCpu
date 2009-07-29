#ifndef OPERAND_HH
#define OPERAND_HH

#include <glib-object.h>
#include <vector>

class Operand {

public:
	enum OperandType {
		REG,
		MEM,
		IMM,
		NONE
	};

private:
	OperandType _op_type;
	GValue *_value;

public:
	Operand () {
		_op_type = NONE;
		_value = (GValue*)g_malloc0 (sizeof(GValue)); //FIXME - has no mem checks
	}

	Operand (OperandType t, GValue *v) {
		_op_type = t;
		_value = v;
		
	}

	~Operand () { //FIXME - has no mem checks
		g_value_unset (_value);
		g_free (_value);
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

#endif //OPERAND_HH
