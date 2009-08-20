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
	template<typename TDest, typename TSrc>
	void op_adc (TDest &dest, TSrc &src);

	/** */
	template<typename TDest, typename TSrc>
	void op_add (TDest &dest, TSrc &src);

	/** */
	template<typename TDest, typename TSrc>
	void op_and (TDest &dest, TSrc &src);

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
	template<typename TDest>
	void op_dec (TDest &dest);

	/** */
	void op_div (const unsigned char &src);

	/** */
	void op_div (const unsigned short &src);

	/** */
	void op_idiv (const unsigned char &src);

	/** */
	void op_idiv (const unsigned short &src);

	/** */
	void op_imul (const unsigned char &src);

	/** */
	void op_imul (const unsigned short &src);

	/** */
	template<typename TDest>
	void op_inc (TDest &dest);

	/** */
	void op_mul (const unsigned char &src);

	/** */
	void op_mul (const unsigned short &src);

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
	TDest result = dest - src;
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

//FIXME - fix flags
template<typename TDest>
void
ArithmeticLogicUnit::op_inc (TDest &dest) {
	++dest;
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
	TDest result = dest & src;
	m_eunit->set_reg_flags_cf (false);
	m_eunit->set_reg_flags_of (false);
}

//FIXME - fix flags
template<typename TDest, typename TSrc>
void
ArithmeticLogicUnit::op_xchg (TDest &dest, TSrc &src) {
	TDest tmp = dest;
	dest = src;
	src = tmp;
}

//FIXME - fix flags
template<typename TDest, typename TSrc>
void
ArithmeticLogicUnit::op_xor (TDest &dest, TSrc &src) {
	dest ^= src;
}

#endif //ARITHMETIC_LOGIC_UNIT_HH

