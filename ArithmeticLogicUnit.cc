#include "ArithmeticLogicUnit.hh"

void
ArithmeticLogicUnit::connect_to (ExecutionUnit &eu) {
	m_eunit = &eu;
}

//FIXME - fix flags
void
ArithmeticLogicUnit::op_aaa () {
	Number<unsigned char> &al = m_eunit->get_reg_al ();
	Number<unsigned char> &ah = m_eunit->get_reg_ah ();
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
	Number<unsigned char> &al = m_eunit->get_reg_al ();
	Number<unsigned char> &ah = m_eunit->get_reg_ah ();

	al = ah * 0x0A + al;
	ah = 0;
}

//FIXME - fix flags
void
ArithmeticLogicUnit::op_aam () {
	Number<unsigned char> &al = m_eunit->get_reg_al ();
	Number<unsigned char> &ah = m_eunit->get_reg_ah ();

	ah = al / 0x0A;
	al %= 0x0A;
}

//FIXME - fix flags
void
ArithmeticLogicUnit::op_aas () {
	Number<unsigned char> &al = m_eunit->get_reg_al ();
	Number<unsigned char> &ah = m_eunit->get_reg_ah ();
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
	Number<unsigned char> &al = m_eunit->get_reg_al ();
	Number<unsigned char> &ah = m_eunit->get_reg_ah ();

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
	Number<unsigned short> &ax = m_eunit->get_reg_ax ();
	Number<unsigned short> &dx = m_eunit->get_reg_dx ();

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
	Number<unsigned char> &al = m_eunit->get_reg_al ();
	bool af = m_eunit->get_reg_flags_af ();
	bool cf = m_eunit->get_reg_flags_cf ();

	if ((al & 0x0F) > 9 || af) {
		al += 6;
		m_eunit->set_reg_flags_af (true);
	}
	if (al > 0x9F || cf) {
		al += 0x60;
		m_eunit->set_reg_flags_cf (true);
	}
}

//FIXME - fix flags
void
ArithmeticLogicUnit::op_das () {
	Number<unsigned char> &al = m_eunit->get_reg_al ();
	bool af = m_eunit->get_reg_flags_af ();
	bool cf = m_eunit->get_reg_flags_cf ();

	if ((al & 0x0F) > 9 || af) {
		al -= 6;
		m_eunit->set_reg_flags_af (true);
	}
	if (al > 0x9F || cf) {
		al -= 0x60;
		m_eunit->set_reg_flags_cf (true);
	}
}

