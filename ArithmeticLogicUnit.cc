#include "ArithmeticLogicUnit.hh"
#include <iostream>

void
ArithmeticLogicUnit::connect_to (ExecutionUnit &eu) {
	m_eunit = &eu;
}

void
ArithmeticLogicUnit::op_adc_8 (unsigned char dest, unsigned char src, unsigned char &ret) {
	bool cf = m_eunit->get_reg_flags_cf ();

	unsigned short result = dest + src;
	if (cf) {
		result += 1;
	}

	ret = (unsigned char)result;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_adc_16 (unsigned short dest, unsigned short src, unsigned short &ret) {
	bool cf = m_eunit->get_reg_flags_cf ();

	unsigned int result = dest + src;
	if (cf) {
		result += 1;
	}

	ret = (unsigned short)result;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_add_8 (unsigned char dest, unsigned char src, unsigned char &ret) {
	unsigned short result = dest + src;

	ret = (unsigned char)result;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_add_16 (unsigned short dest, unsigned short src, unsigned short &ret) {
	unsigned int result = dest + src;

	ret = (unsigned short)result;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_and_8 (unsigned char dest, unsigned char src, unsigned char &ret) {
	unsigned short result = dest & src;
	m_eunit->set_reg_flags_cf (false);
	m_eunit->set_reg_flags_of (false);

	ret = (unsigned char)result;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_and_16 (unsigned short dest, unsigned short src, unsigned short &ret) {
	unsigned int result = dest & src;
	m_eunit->set_reg_flags_cf (false);
	m_eunit->set_reg_flags_of (false);

	ret = (unsigned short)result;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_cmc () {
	bool cf = m_eunit->get_reg_flags_cf ();
	m_eunit->set_reg_flags_cf (cf ^ 1);

}

void
ArithmeticLogicUnit::op_cmp_8 (unsigned char dest, unsigned char src) {
	unsigned short result = dest - src;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_cmp_16 (unsigned short dest, unsigned short src) {
	unsigned int result = dest - src;

	//FIXME - fix flags
}

#if 0
/** FIXME */
template<typename TDest, typename TSrc>
void cmps (TDest &dest, TSrc &src, TDest &result);
#endif

void
ArithmeticLogicUnit::op_dec_8 (unsigned char src, unsigned char &ret) {
	unsigned short result = --src;
	ret = (unsigned char)result;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_dec_16 (unsigned short src, unsigned short &ret) {
	unsigned int result = --src;
	ret = (unsigned short)result;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_div_8 (unsigned char src) {
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

void
ArithmeticLogicUnit::op_div_16 (unsigned short src) {
	Number<unsigned short> &ax = m_eunit->get_reg_ax ();
	Number<unsigned short> &dx = m_eunit->get_reg_dx ();
	unsigned int dx_ax = dx;
	dx_ax <<= 16;
	dx_ax += ax;

	if (src == 0) {
		//FIXME - interrupt 0
	}

	Number<unsigned short> tmp = dx_ax / src;
	if (tmp > (unsigned short)0xFFFF) {
		//FIXME - interrupt 0
	}
	else {
		ax = tmp;
		dx = dx_ax % src;
	}
}

void
ArithmeticLogicUnit::op_idiv_8 (unsigned char src) {
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

void
ArithmeticLogicUnit::op_idiv_16 (unsigned short src) {
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

void
ArithmeticLogicUnit::op_imul_8 (unsigned char src) {
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

void
ArithmeticLogicUnit::op_imul_16 (unsigned short src) {
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

void
ArithmeticLogicUnit::op_inc_8 (unsigned char src, unsigned char &ret) {
	unsigned short result = ++src;
	ret = (unsigned char)result;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_inc_16 (unsigned short src, unsigned short &ret) {
	unsigned int result = ++src;
	ret = (unsigned short)result;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_mul_8 (unsigned char src) {
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

void
ArithmeticLogicUnit::op_mul_16 (unsigned short src) {
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

void
ArithmeticLogicUnit::op_neg_8 (unsigned char dest, unsigned char &ret) {
	dest = ~dest;
	unsigned char r;
	op_add_8 (dest, 1, r);

	ret = (unsigned char)r;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_neg_16 (unsigned short dest, unsigned short &ret) {
	dest = ~dest;
	unsigned short r;
	op_add_16 (dest, 1, r);

	ret = (unsigned short)r;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_or_8 (unsigned char dest, unsigned char src, unsigned char &ret) {
	unsigned short result = dest | src;
	m_eunit->set_reg_flags_cf (false);
	m_eunit->set_reg_flags_of (false);

	ret = (unsigned char)result;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_or_16 (unsigned short dest, unsigned short src, unsigned short &ret) {
	unsigned int result = dest | src;
	m_eunit->set_reg_flags_cf (false);
	m_eunit->set_reg_flags_of (false);

	ret = (unsigned short)result;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_rcl_8 (unsigned char dest, unsigned int cnt, unsigned char &ret) {
	unsigned int tmp_cnt = cnt;
	bool tmp_cf;
	while (tmp_cnt != 0) {
		tmp_cf = m_eunit->get_reg_flags_cf ();
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, (sizeof(dest) << 3) - 1)); //msb
		dest <<= 1;
		dest += tmp_cf;
		tmp_cnt -= 1;
	}

	if (tmp_cnt == 1) {
		//of = msb(dest) ^ cf
		m_eunit->set_reg_flags_of (Utility::get_bit (dest, (sizeof(dest) << 3) - 1) ^ m_eunit->get_reg_flags_cf ());
	}

	ret = (unsigned char)dest;
}

void
ArithmeticLogicUnit::op_rcl_16 (unsigned short dest, unsigned int cnt, unsigned short &ret) {
	unsigned int tmp_cnt = cnt;
	bool tmp_cf;
	while (tmp_cnt != 0) {
		tmp_cf = m_eunit->get_reg_flags_cf ();
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, (sizeof(dest) << 3) - 1)); //msb
		dest <<= 1;
		dest += tmp_cf;
		tmp_cnt -= 1;
	}

	if (tmp_cnt == 1) {
		//of = msb(dest) ^ cf
		m_eunit->set_reg_flags_of (Utility::get_bit (dest, (sizeof(dest) << 3) - 1) ^ m_eunit->get_reg_flags_cf ());
	}

	ret = (unsigned short)dest;
}

void
ArithmeticLogicUnit::op_rcr_8 (unsigned char dest, unsigned int cnt, unsigned char &ret) {
	unsigned int tmp_cnt = cnt;
	bool tmp_cf;
	while (tmp_cnt != 0) {
		tmp_cf = m_eunit->get_reg_flags_cf ();
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, 0)); //msb
		dest >>= 1;
		Utility::set_bit (dest, (sizeof(dest) << 3) - 1, tmp_cf);
		tmp_cnt -= 1;
	}

	if (tmp_cnt == 1) {
		//of = lsb(dest) ^ cf
		m_eunit->set_reg_flags_of (Utility::get_bit (dest, 0) ^ m_eunit->get_reg_flags_cf ());
	}

	ret = (unsigned char)dest;
}

void
ArithmeticLogicUnit::op_rcr_16 (unsigned short dest, unsigned int cnt, unsigned short &ret) {
	unsigned int tmp_cnt = cnt;
	bool tmp_cf;
	while (tmp_cnt != 0) {
		tmp_cf = m_eunit->get_reg_flags_cf ();
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, 0)); //msb
		dest >>= 1;
		Utility::set_bit (dest, (sizeof(dest) << 3) - 1, tmp_cf);
		tmp_cnt -= 1;
	}

	if (tmp_cnt == 1) {
		//of = lsb(dest) ^ cf
		m_eunit->set_reg_flags_of (Utility::get_bit (dest, 0) ^ m_eunit->get_reg_flags_cf ());
	}

	ret = (unsigned short)dest;
}

void
ArithmeticLogicUnit::op_rol_8 (unsigned char dest, unsigned int cnt, unsigned char &ret) {
	unsigned int tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, (sizeof(dest) << 3) - 1));
		dest <<= 1;
		dest += m_eunit->get_reg_flags_cf ();
		tmp_cnt -= 1;
	}

	ret = (unsigned char)dest;
}

void
ArithmeticLogicUnit::op_rol_16 (unsigned short dest, unsigned int cnt, unsigned short &ret) {
	unsigned int tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, (sizeof(dest) << 3) - 1));
		dest <<= 1;
		dest += m_eunit->get_reg_flags_cf ();
		tmp_cnt -= 1;
	}

	ret = (unsigned short)dest;
}

void
ArithmeticLogicUnit::op_ror_8 (unsigned char dest, unsigned int cnt, unsigned char &ret) {
	unsigned int tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, 0));
		dest >>= 1;
		Utility::set_bit (dest, (sizeof(dest) << 3) - 1, m_eunit->get_reg_flags_cf ());
		tmp_cnt -= 1;
	}

	ret = (unsigned char)dest;
}

void
ArithmeticLogicUnit::op_ror_16 (unsigned short dest, unsigned int cnt, unsigned short &ret) {
	unsigned int tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, 0));
		dest >>= 1;
		Utility::set_bit (dest, (sizeof(dest) << 3) - 1, m_eunit->get_reg_flags_cf ());
		tmp_cnt -= 1;
	}

	ret = (unsigned short)dest;
}

void
ArithmeticLogicUnit::op_sal_8 (unsigned char dest, unsigned int cnt, unsigned char &ret) {
	unsigned int tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, (sizeof(dest) << 3) - 1));
		dest <<= 1;
		tmp_cnt -= 1;
	}

	ret = (unsigned char)dest;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_sal_16 (unsigned short dest, unsigned int cnt, unsigned short &ret) {
	unsigned int tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, (sizeof(dest) << 3) - 1));
		dest <<= 1;
		tmp_cnt -= 1;
	}

	ret = (unsigned short)dest;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_sar_8 (unsigned char dest, unsigned int cnt, unsigned char &ret) {
	unsigned int tmp_cnt = cnt;
	bool tmp_msb = Utility::get_bit (dest, (sizeof(dest) << 3) - 1);
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, 0));
		dest >>= 1;
		Utility::set_bit (dest, (sizeof(dest) << 3) - 1, tmp_msb);
		tmp_cnt -= 1;
	}

	ret = (unsigned char)dest;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_sar_16 (unsigned short dest, unsigned int cnt, unsigned short &ret) {
	unsigned int tmp_cnt = cnt;
	bool tmp_msb = Utility::get_bit (dest, (sizeof(dest) << 3) - 1);
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, 0));
		dest >>= 1;
		Utility::set_bit (dest, (sizeof(dest) << 3) - 1, tmp_msb);
		tmp_cnt -= 1;
	}

	ret = (unsigned short)dest;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_sbb_8 (unsigned char dest, unsigned char src, unsigned char &ret) {
	bool cf = m_eunit->get_reg_flags_cf ();

	unsigned short result = dest - src - cf;

	ret = (unsigned char)result;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_sbb_16 (unsigned short dest, unsigned short src, unsigned short &ret) {
	bool cf = m_eunit->get_reg_flags_cf ();

	unsigned int result = dest - src - cf;

	ret = (unsigned short)result;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_shl_8 (unsigned char dest, unsigned int cnt, unsigned char &ret) {
	unsigned int tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, (sizeof(dest) << 3) - 1));
		dest <<= 1;
		tmp_cnt -= 1;
	}

	ret = (unsigned char)dest;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_shl_16 (unsigned short dest, unsigned int cnt, unsigned short &ret) {
	unsigned int tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, (sizeof(dest) << 3) - 1));
		dest <<= 1;
		tmp_cnt -= 1;
	}

	ret = (unsigned short)dest;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_shr_8 (unsigned char dest, unsigned int cnt, unsigned char &ret) {
	unsigned int tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, 0));
		dest >>= 1;
		tmp_cnt -= 1;
	}

	ret = (unsigned char)dest;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_shr_16 (unsigned short dest, unsigned int cnt, unsigned short &ret) {
	unsigned int tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, 0));
		dest >>= 1;
		tmp_cnt -= 1;
	}

	ret = (unsigned short)dest;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_sub_8 (unsigned char dest, unsigned char src, unsigned char &ret) {
	unsigned short result = dest - src;
	ret = (unsigned char)result;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_sub_16 (unsigned short dest, unsigned char src, unsigned short &ret) {
	unsigned int result = dest - src;
	ret = (unsigned short)result;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_test_8 (unsigned char dest, unsigned char src) {
	unsigned short result = dest & src;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_test_16 (unsigned short dest, unsigned char src) {
	unsigned int result = dest & src;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_xor_8 (unsigned char dest, unsigned char src, unsigned char &ret) {
	unsigned short result = dest ^ src;
	m_eunit->set_reg_flags_cf (false);
	m_eunit->set_reg_flags_of (false);

	ret = (unsigned char)result;

	//FIXME - fix flags
}

void
ArithmeticLogicUnit::op_xor_16 (unsigned short dest, unsigned short src, unsigned short &ret) {
	unsigned int result = dest ^ src;
	m_eunit->set_reg_flags_cf (false);
	m_eunit->set_reg_flags_of (false);

	ret = (unsigned short)result;

	//FIXME - fix flags
}

