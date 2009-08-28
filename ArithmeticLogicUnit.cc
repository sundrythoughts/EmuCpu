#include "ArithmeticLogicUnit.hh"
#include <iostream>

void
ArithmeticLogicUnit::connect_to (ExecutionUnit &eu) {
	m_eunit = &eu;
}

//FIXME - fix flags
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

//FIXME - fix flags
void
ArithmeticLogicUnit::op_div (const unsigned char &src) {
	Number<unsigned short> ax = m_eunit->get_reg_ax ();
	Number<unsigned char> &al = m_eunit->get_reg_al ();
	Number<unsigned char> &ah = m_eunit->get_reg_ah ();

	if (src == 0) {
		//FIXME - interrupt 0
	}

	Number<unsigned char> tmp = ax / src;
	if (tmp > 0xFF) {
		//FIXME - interrupt 0
	}
	else {
		al = tmp;
		ah = ax % src;
	}
}

//FIXME - fix flags
void
ArithmeticLogicUnit::op_div (const unsigned short &src) {
	Number<unsigned short> &ax = m_eunit->get_reg_ax ();
	Number<unsigned short> &dx = m_eunit->get_reg_dx ();
	unsigned int dx_ax = dx;
	dx_ax <<= 16;
	dx_ax += ax;

	if (src == 0) {
		//FIXME - interrupt 0
	}

	Number<unsigned short> tmp = dx_ax / src;
	if (tmp > 0xFFFF) {
		//FIXME - interrupt 0
	}
	else {
		ax = tmp;
		dx = dx_ax % src;
	}
}

//FIXME - fix flags
void
ArithmeticLogicUnit::op_idiv (const unsigned char &src) {
	Number<unsigned short> ax = m_eunit->get_reg_ax ();
	Number<unsigned char> &al = m_eunit->get_reg_al ();
	Number<unsigned char> &ah = m_eunit->get_reg_ah ();

	if (src == 0) {
		//FIXME - interrupt 0
	}

	char tmp = (short)ax / (char)src;
	//if ((tmp > 0x7F) || (tmp < 0x80)) {
	//	//FIXME - interrupt 0
	//}
	//else {
		al = tmp;
		ah = (short)ax % (char)src;
	//}
}

//FIXME - fix flags
void
ArithmeticLogicUnit::op_idiv (const unsigned short &src) {
	Number<unsigned short> &ax = m_eunit->get_reg_ax ();
	Number<unsigned short> &dx = m_eunit->get_reg_dx ();
	unsigned int dx_ax = dx;
	dx_ax <<= 16;
	dx_ax += ax;

	if (src == 0) {
		//FIXME - interrupt 0
	}

	short tmp = (int)dx_ax / (short)src;
	//if ((tmp > 0x7FFF) || (tmp < 0x8000)) {
	//	//FIXME - interrupt 0
	//}
	//else {
		ax = tmp;
		dx = (int)dx_ax % (short)tmp;
	//}
}

//FIXME - fix flags
void
ArithmeticLogicUnit::op_imul (const unsigned char &src) {
	Number<unsigned short> &ax = m_eunit->get_reg_ax ();
	Number<unsigned char> &al = m_eunit->get_reg_al ();
	Number<unsigned char> &ah = m_eunit->get_reg_ah ();

	ax = (char)src * (char)al;
	unsigned char al_sign_ext = (Utility::get_bit (al, sizeof(unsigned char) - 1)) ? 0xFF : 0;

	if (ah == al_sign_ext) {
		m_eunit->set_reg_flags_cf (false);
	}
	else {
		m_eunit->set_reg_flags_cf (true);
		m_eunit->set_reg_flags_of (true);
	}
}

//FIXME - fix flags
void
ArithmeticLogicUnit::op_imul (const unsigned short &src) {
	Number<unsigned short> &ax = m_eunit->get_reg_ax ();
	Number<unsigned short> &dx = m_eunit->get_reg_dx ();
	unsigned int dx_ax = dx;
	dx_ax <<= 16;
	dx_ax += ax;
	unsigned short *dx_ax_ptr = (unsigned short*)&dx_ax;

	dx_ax = (short)src * (short)ax;
	m_eunit->set_reg_ax (dx_ax_ptr[0]);
	m_eunit->set_reg_dx (dx_ax_ptr[1]);
	unsigned short ax_sign_ext = (Utility::get_bit (ax, sizeof(unsigned short) - 1)) ? 0xFFFF : 0;

	if (dx == ax_sign_ext) {
		m_eunit->set_reg_flags_cf (false);
	}
	else {
		m_eunit->set_reg_flags_cf (true);
		m_eunit->set_reg_flags_of (true);
	}
}

//FIXME - fix flags
void
ArithmeticLogicUnit::op_mul (const unsigned char &src) {
	Number<unsigned short> &ax = m_eunit->get_reg_ax ();
	Number<unsigned char> &al = m_eunit->get_reg_al ();
	Number<unsigned char> &ah = m_eunit->get_reg_ah ();

	ax = src * al;

	if (ah == 0) {
		m_eunit->set_reg_flags_cf (false);
	}
	else {
		m_eunit->set_reg_flags_cf (true);
		m_eunit->set_reg_flags_of (true);
	}
}

//FIXME - fix flags
void
ArithmeticLogicUnit::op_mul (const unsigned short &src) {
	Number<unsigned short> &ax = m_eunit->get_reg_ax ();
	Number<unsigned short> &dx = m_eunit->get_reg_dx ();
	unsigned int dx_ax = dx;
	dx_ax <<= 16;
	dx_ax += ax;
	unsigned short *dx_ax_ptr = (unsigned short*)&dx_ax;

	dx_ax = src * ax;
	m_eunit->set_reg_ax (dx_ax_ptr[0]);
	m_eunit->set_reg_dx (dx_ax_ptr[1]);

	if (dx == 0) {
		m_eunit->set_reg_flags_cf (false);
	}
	else {
		m_eunit->set_reg_flags_cf (true);
		m_eunit->set_reg_flags_of (true);
	}
}

