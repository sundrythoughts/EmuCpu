#include "ArithmeticLogicUnit.hh"

void
ArithmeticLogicUnit::connect_to (ExecutionUnit &eu) {
	m_eunit = &eu;
}

//FIXME - fix flags
void
ArithmeticLogicUnit::op_aaa () {
	unsigned char &al = m_eunit->get_reg_al ();
	unsigned char &ah = m_eunit->get_reg_ah ();
	bool af = m_eunit->get_reg_flags_af ();

	if ((al & 0x0F) > 9 || af) {
		al += 6;
		ah += 1;
		m_eunit->set_reg_flags_af (true);
		m_eunit->set_reg_flags_cf (true);
	}
	else {
		m_eunit->set_reg_flags_af (false);
		m_eunit->set_reg_flags_cf (false);
	}
	al &= 0x0F;
}

//FIXME - fix flags
void
ArithmeticLogicUnit::op_aad () {
	unsigned char &al = m_eunit->get_reg_al ();
	unsigned char &ah = m_eunit->get_reg_ah ();

	al = ah * 0x0A + al;
	ah = 0;
}

//FIXME - fix flags
void
ArithmeticLogicUnit::op_aam () {
	unsigned char &al = m_eunit->get_reg_al ();
	unsigned char &ah = m_eunit->get_reg_ah ();

	ah = al / 0x0A;
	al %= 0x0A;
}

//FIXME - fix flags
void
ArithmeticLogicUnit::op_aas () {
	unsigned char &al = m_eunit->get_reg_al ();
	unsigned char &ah = m_eunit->get_reg_ah ();
	bool af = m_eunit->get_reg_flags_af ();

	if ((al & 0x0F) > 9 || af) {
		al -= 6;
		ah -= 1;
		m_eunit->set_reg_flags_af (true);
		m_eunit->set_reg_flags_cf (true);
	}
	else {
		m_eunit->set_reg_flags_af (false);
		m_eunit->set_reg_flags_cf (false);
	}
	al &= 0x0F;
}

//FIXME - fix flags
void
ArithmeticLogicUnit::op_cbw () {
	unsigned char &al = m_eunit->get_reg_al ();
	unsigned char &ah = m_eunit->get_reg_ah ();

	if (al < 0x80) {
		ah = 0;
	}
	else {
		ah = 0xFF;
	}
}

void
ArithmeticLogicUnit::op_cmc () {
	bool cf = m_eunit->get_reg_flags_cf ();

	if (!cf) {
		m_eunit->set_reg_flags_cf (true);
	}
	else {
		m_eunit->set_reg_flags_cf (false);
	}
}

void
ArithmeticLogicUnit::op_cwd () {
	unsigned short &ax = m_eunit->get_reg_ax ();
	unsigned short &dx = m_eunit->get_reg_dx ();

	if (ax < 0x8000) {
		dx = 0;
	}
	else {
		dx = 0xFFFF;
	}
}

//FIXME - fix flags
void
ArithmeticLogicUnit::op_daa () {
}

//FIXME - fix flags
void
ArithmeticLogicUnit::op_das () {
}

