#ifndef ARITHMETIC_LOGIC_UNIT_HH
#define ARITHMETIC_LOGIC_UNIT_HH

#include "ExecutionUnit.hh"
#include "Utility.hh"
#include "Number.hh"
#include <iostream>

/**
*/
class ArithmeticLogicUnit {
	ExecutionUnit *m_eunit;

public:
	/** */
	ArithmeticLogicUnit () {
	}

	/** */
	ArithmeticLogicUnit (const ArithmeticLogicUnit &src);

	/** */
	~ArithmeticLogicUnit () {
	}

	/** */
	void connect_to (ExecutionUnit &eu);

	/** */
	void op_aaa ();

	/** */
	void op_aad ();

	/** */
	void op_aam ();

	/** */
	void op_aas ();

	/** */
	template<typename TDest, typename TSrc>
	void op_adc (TDest &dest, TSrc &src);

	/** */
	template<typename TDest, typename TSrc>
	void op_add (TDest &dest, TSrc &src);

	/** */
	template<typename TDest, typename TSrc>
	void op_and (TDest &dest, TSrc &src);

	/** */
	void op_cbw ();

	/** */
	void op_cmc ();

	/** */
	template<typename TDest, typename TSrc>
	void op_cmp (TDest &dest, TSrc &src);

#if 0
	/** FIXME */
	template<typename TDest, typename TSrc>
	void cmps (TDest &dest, TSrc &src, TDest &result);
#endif

	/** */
	void op_cwd ();

	/** */
	void op_daa ();

	/** */
	void op_das ();

	/** */
	template<typename TDest>
	void op_dec (TDest &dest);

#if 0
	/** */
	template<typename TSrc>
	void op_div (TSrc &src);

	void
	op_div (Number<unsigned char> &src);

	void
	op_div (Number<unsigned short> &src);
#endif

	/** */
	template<typename TSrc>
	void op_idiv (TSrc &src);

	/** */
	template<typename TSrc>
	void op_imul (TSrc &src);

	/** */
	template<typename TDest>
	void op_inc (TDest &dest);

	/** */
	template<typename TSrc>
	void op_mul (TSrc &src);

	/** */
	template<typename TDest>
	void op_neg (TDest &dest);

	/** */
	template<typename TDest, typename TSrc>
	void op_or (TDest &dest, TSrc &src);

	/** */
	template<typename TDest, typename TCount>
	void op_rcl (TDest &dest, const TCount &cnt);

	/** */
	template<typename TDest, typename TCount>
	void op_rcl (Number<TDest> &dest, const TCount &cnt);

	/** */
	template<typename TDest, typename TCount>
	void op_rcr (TDest &dest, const TCount &cnt);

	/** */
	template<typename TDest, typename TCount>
	void op_rcr (Number<TDest> &dest, const TCount &cnt);

	/** */
	template<typename TDest, typename TCount>
	void op_rol (TDest &dest, const TCount &cnt);

	/** */
	template<typename TDest, typename TCount>
	void op_rol (Number<TDest> &dest, const TCount &cnt);

	/** */
	template<typename TDest, typename TCount>
	void op_ror (TDest &dest, const TCount &cnt);

	/** */
	template<typename TDest, typename TCount>
	void op_ror (Number<TDest> &dest, const TCount &cnt);

	/** */
	template<typename TDest, typename TCount>
	void op_sal (TDest &dest, const TCount &cnt);

	/** */
	template<typename TDest, typename TCount>
	void op_sal (Number<TDest> &dest, const TCount &cnt);

	/** */
	template<typename TDest, typename TCount>
	void op_sar (TDest &dest, const TCount &cnt);

	/** */
	template<typename TDest, typename TCount>
	void op_sar (Number<TDest> &dest, const TCount &cnt);

	/** */
	template<typename TDest, typename TSrc>
	void op_sbb (TDest &dest, TSrc &src);

#if 0
	/** FIXME */
	template<typename TDest>
	void op_or (TDest &dest);
#endif

	/** */
	template<typename TDest, typename TCount>
	void op_shl (TDest &dest, const TCount &cnt);

	/** */
	template<typename TDest, typename TCount>
	void op_shl (Number<TDest> &dest, const TCount &cnt);

	/** */
	template<typename TDest, typename TCount>
	void op_shr (TDest &dest, const TCount &cnt);

	/** */
	template<typename TDest, typename TCount>
	void op_shr (Number<TDest> &dest, const TCount &cnt);

	/** */
	template<typename TDest, typename TSrc>
	void op_sub (TDest &dest, TSrc &src);

	/** */
	template<typename TDest, typename TSrc>
	void op_test (TDest &dest, TSrc &src);

	/** */
	template<typename TDest, typename TSrc>
	void op_xchg (TDest &dest, TSrc &src);

#if 0
	/** */
	template<typename TDest, typename TSrc>
	void op_xchg (Number<TDest> &dest, TSrc &src);
#endif

	/** */
	template<typename TDest, typename TSrc>
	void op_xor (TDest &dest, TSrc &src);
};

//FIXME - fix flags
template<typename TDest, typename TSrc>
void
ArithmeticLogicUnit::op_adc (TDest &dest, TSrc &src) {
	bool cf = m_eunit->get_reg_flags_cf ();

	dest += src;
	if (cf) {
		dest += 1;
	}
}

//FIXME - fix flags
template<typename TDest, typename TSrc>
void
ArithmeticLogicUnit::op_add (TDest &dest, TSrc &src) {
	dest += src;
}

//FIXME - fix flags
template<typename TDest, typename TSrc>
void
ArithmeticLogicUnit::op_and (TDest &dest, TSrc &src) {
	dest &= src;
	m_eunit->set_reg_flags_cf (false);
	m_eunit->set_reg_flags_of (false);
}

//FIXME - fix flags
template<typename TDest, typename TSrc>
void
ArithmeticLogicUnit::op_cmp (TDest &dest, TSrc &src) {
}

#if 0
//FIXME - fix flags
template<typename TDest, typename TSrc>
void
ArithmeticLogicUnit::cmps (TDest &dest, TSrc &src, TDest &result) {
}
#endif

//FIXME - fix flags
template<typename TDest>
void
ArithmeticLogicUnit::op_dec (TDest &dest) {
	--dest;
}

#if 0
//FIXME - make overloaded instead of templated - fix flags
template<typename TSrc>
void
ArithmeticLogicUnit::op_div (TSrc &src) {
}

void
ArithmeticLogicUnit::op_div (Number<unsigned char> &src) {
	Number<unsigned short> &ax = m_eunit->get_reg_ax ();
	Number<unsigned char> &al = m_eunit->get_reg_al ();
	Number<unsigned char> &ah = m_eunit->get_reg_ah ();

	Number<unsigned char> tmp = src;
	if (tmp / ax > 0xFF) {
		//FIXME - interrupt 0
	}
	else {
		al = tmp / ax;
		ah = tmp % ax;
	}
}

void
ArithmeticLogicUnit::op_div (Number<unsigned short> &src) {
	Number<unsigned short> &ax = m_eunit->get_reg_ax ();
	Number<unsigned short> &dx = m_eunit->get_reg_ax ();
	unsigned int dx_ax = dx;
	dx_ax <<= 16;
	dx_ax += ax;

	Number<unsigned short> tmp = src;

	if (tmp / dx_ax > 0xFFFF) {
		//FIXME - interrupt 0
	}
	else {
		ax = tmp / dx_ax;
		dx = tmp % dx_ax;
	}
}
#endif

//FIXME - make overloaded instead of templated - fix flags
template<typename TSrc>
void
ArithmeticLogicUnit::op_idiv (TSrc &src) {
}

//FIXME - make overloaded instead of templated - fix flags
template<typename TSrc>
void
ArithmeticLogicUnit::op_imul (TSrc &src) {
}

//FIXME - fix flags
template<typename TDest>
void
ArithmeticLogicUnit::op_inc (TDest &dest) {
	++dest;
}

//FIXME - make overloaded instead of templated - fix flags
template<typename TSrc>
void
ArithmeticLogicUnit::op_mul (TSrc &src) {
}

//FIXME - fix flags
template<typename TDest>
void
ArithmeticLogicUnit::op_neg (TDest &dest) {
	if (dest == 0) {
		m_eunit->set_reg_flags_cf (false);
	}
	else {
		m_eunit->set_reg_flags_cf (true);
	}

	dest = -dest;
}

//FIXME - fix flags
template<typename TDest, typename TSrc>
void
ArithmeticLogicUnit::op_or (TDest &dest, TSrc &src) {
	dest |= src;
	m_eunit->set_reg_flags_cf (false);
	m_eunit->set_reg_flags_of (false);
}

//FIXME - fix flags
template<typename TDest, typename TCount>
void
ArithmeticLogicUnit::op_rcl (TDest &dest, const TCount &cnt) {
	TCount tmp_cnt = cnt;
	bool tmp_cf;
	while (tmp_cnt != 0) {
		tmp_cf = m_eunit->get_reg_flags_cf ();
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, (sizeof(TDest) << 3) - 1)); //msb
		dest <<= 1;
		dest += tmp_cf;
		tmp_cnt -= 1;
	}

	if (tmp_cnt == 1) {
		//of = msb(dest) ^ cf
		m_eunit->set_reg_flags_of (Utility::get_bit (dest, (sizeof(TDest) << 3) - 1) ^ m_eunit->get_reg_flags_cf ());
	}
}

//FIXME - fix flags
template<typename TDest, typename TCount>
void
ArithmeticLogicUnit::op_rcl (Number<TDest> &dest, const TCount &cnt) {
	TCount tmp_cnt = cnt;
	bool tmp_cf;
	while (tmp_cnt != 0) {
		tmp_cf = m_eunit->get_reg_flags_cf ();
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, (sizeof(TDest) << 3) - 1)); //msb
		dest <<= 1;
		dest += tmp_cf;
		tmp_cnt -= 1;
	}

	if (tmp_cnt == 1) {
		//of = lsb(dest) ^ cf
		m_eunit->set_reg_flags_of (Utility::get_bit (dest, (sizeof(TDest) << 3) - 1) ^ m_eunit->get_reg_flags_cf ());
	}
}

//FIXME - fix flags
template<typename TDest, typename TCount>
void
ArithmeticLogicUnit::op_rcr (TDest &dest, const TCount &cnt) {
	TCount tmp_cnt = cnt;
	bool tmp_cf;
	while (tmp_cnt != 0) {
		tmp_cf = m_eunit->get_reg_flags_cf ();
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, 0)); //msb
		dest >>= 1;
		Utility::set_bit (dest, (sizeof(TDest) << 3) - 1, tmp_cf);
		tmp_cnt -= 1;
	}

	if (tmp_cnt == 1) {
		//of = lsb(dest) ^ cf
		m_eunit->set_reg_flags_of (Utility::get_bit (dest, 0) ^ m_eunit->get_reg_flags_cf ());
	}
}

//FIXME - fix flags
template<typename TDest, typename TCount>
void
ArithmeticLogicUnit::op_rcr (Number<TDest> &dest, const TCount &cnt) {
	TCount tmp_cnt = cnt;
	bool tmp_cf;
	while (tmp_cnt != 0) {
		tmp_cf = m_eunit->get_reg_flags_cf ();
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, 0)); //msb
		dest >>= 1;
		Utility::set_bit (dest, (sizeof(TDest) << 3) - 1, tmp_cf);
		tmp_cnt -= 1;
	}

	if (tmp_cnt == 1) {
		//of = lsb(dest) ^ cf
		m_eunit->set_reg_flags_of (Utility::get_bit (dest, 0) ^ m_eunit->get_reg_flags_cf ());
	}
}

//FIXME - fix flags
template<typename TDest, typename TCount>
void
ArithmeticLogicUnit::op_rol (TDest &dest, const TCount &cnt) {
	TCount tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, (sizeof(TDest) << 3) - 1));
		dest <<= 1;
		dest += m_eunit->get_reg_flags_cf ();
		tmp_cnt -= 1;
	}
}

//FIXME - fix flags
template<typename TDest, typename TCount>
void
ArithmeticLogicUnit::op_rol (Number<TDest> &dest, const TCount &cnt) {
	TCount tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, (sizeof(TDest) << 3) - 1));
		dest <<= 1;
		dest += m_eunit->get_reg_flags_cf ();
		tmp_cnt -= 1;
	}
}

//FIXME - fix flags
template<typename TDest, typename TCount>
void
ArithmeticLogicUnit::op_ror (TDest &dest, const TCount &cnt) {
	TCount tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, 0));
		dest >>= 1;
		Utility::set_bit (dest, (sizeof(TDest) << 3) - 1, m_eunit->get_reg_flags_cf ());
		tmp_cnt -= 1;
	}
}

//FIXME - fix flags
template<typename TDest, typename TCount>
void
ArithmeticLogicUnit::op_ror (Number<TDest> &dest, const TCount &cnt) {
	TCount tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, 0));
		dest >>= 1;
		Utility::set_bit (dest, (sizeof(TDest) << 3) - 1, m_eunit->get_reg_flags_cf ());
		tmp_cnt -= 1;
	}
}

//FIXME - fix flags
template<typename TDest, typename TCount>
void
ArithmeticLogicUnit::op_sal (TDest &dest, const TCount &cnt) {
	TCount tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, (sizeof(TDest) << 3) - 1));
		dest <<= 1;
		tmp_cnt -= 1;
	}
}

//FIXME - fix flags
template<typename TDest, typename TCount>
void
ArithmeticLogicUnit::op_sal (Number<TDest> &dest, const TCount &cnt) {
	TCount tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, (sizeof(TDest) << 3) - 1));
		dest <<= 1;
		tmp_cnt -= 1;
	}
}

//FIXME - fix flags
template<typename TDest, typename TCount>
void
ArithmeticLogicUnit::op_sar (TDest &dest, const TCount &cnt) {
	TCount tmp_cnt = cnt;
	bool tmp_msb = Utility::get_bit (dest, (sizeof(TDest) << 3) - 1);
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, 0));
		dest >>= 1;
		Utility::set_bit (dest, (sizeof(TDest) << 3) - 1, tmp_msb);
		tmp_cnt -= 1;
	}
}

//FIXME - fix flags
template<typename TDest, typename TCount>
void
ArithmeticLogicUnit::op_sar (Number<TDest> &dest, const TCount &cnt) {
	TCount tmp_cnt = cnt;
	bool tmp_msb = Utility::get_bit (dest, (sizeof(TDest) << 3) - 1);
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, 0));
		dest >>= 1;
		Utility::set_bit (dest, (sizeof(TDest) << 3) - 1, tmp_msb);
		tmp_cnt -= 1;
	}
}

//FIXME - fix flags
template<typename TDest, typename TSrc>
void
ArithmeticLogicUnit::op_sbb (TDest &dest, TSrc &src) {
	bool cf = m_eunit->get_reg_flags_cf ();

	dest -= src;
	if (cf) {
		dest -= 1;
	}
}

#if 0
//FIXME - fix flags
template<typename TDest>
void
ArithmeticLogicUnit::op_or (TDest &dest) {
}
#endif

//FIXME - fix flags
template<typename TDest, typename TCount>
void
ArithmeticLogicUnit::op_shl (TDest &dest, const TCount &cnt) {
	TCount tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, (sizeof(TDest) << 3) - 1));
		dest <<= 1;
		tmp_cnt -= 1;
	}
}

//FIXME - fix flags
template<typename TDest, typename TCount>
void
ArithmeticLogicUnit::op_shl (Number<TDest> &dest, const TCount &cnt) {
	TCount tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, (sizeof(TDest) << 3) - 1));
		dest <<= 1;
		tmp_cnt -= 1;
	}
}

//FIXME - fix flags
template<typename TDest, typename TCount>
void
ArithmeticLogicUnit::op_shr (TDest &dest, const TCount &cnt) {
	TCount tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, 0));
		dest >>= 1;
		tmp_cnt -= 1;
	}
}

//FIXME - fix flags
template<typename TDest, typename TCount>
void
ArithmeticLogicUnit::op_shr (Number<TDest> &dest, const TCount &cnt) {
	TCount tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		m_eunit->set_reg_flags_cf (Utility::get_bit (dest, 0));
		dest >>= 1;
		tmp_cnt -= 1;
	}
}

//FIXME - fix flags
template<typename TDest, typename TSrc>
void
ArithmeticLogicUnit::op_sub (TDest &dest, TSrc &src) {
	dest -= src;
}

//FIXME - fix flags
template<typename TDest, typename TSrc>
void
ArithmeticLogicUnit::op_test (TDest &dest, TSrc &src) {
}

//FIXME - fix flags
template<typename TDest, typename TSrc>
void
ArithmeticLogicUnit::op_xchg (TDest &dest, TSrc &src) {
	TDest tmp = dest;
	dest = src;
	src = tmp;
}

#if 0
//FIXME - fix flags
template<typename TDest, typename TSrc>
void
ArithmeticLogicUnit::op_xchg (Number<TDest> &dest, TSrc &src) {
	Number<TDest> tmp;
	tmp = dest;
	dest = src;
	src = tmp;
}
#endif

//FIXME - fix flags
template<typename TDest, typename TSrc>
void
ArithmeticLogicUnit::op_xor (TDest &dest, TSrc &src) {
	dest ^= src;
}

#endif //ARITHMETIC_LOGIC_UNIT_HH

