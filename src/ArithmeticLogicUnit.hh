#ifndef ARITHMETIC_LOGIC_UNIT_HH
#define ARITHMETIC_LOGIC_UNIT_HH

#include "ExecutionUnit.hh"
#include "Utility.hh"
#include "Register.hh"
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
	void
	connect_to (ExecutionUnit &eu);

	/** FIXME */
	void update_flag_af_8 (unsigned char result8, unsigned short result16);

	/** FIXME */
	void update_flag_af_16 (unsigned short result16, unsigned int result32);

	/** */
	void update_flag_cf_8 (unsigned char result8, unsigned short result16);

	/** */
	void update_flag_cf_16 (unsigned short result16, unsigned int result32);

	/** */
	void update_flag_of_8 (bool msb_before, bool msb_after);

	/** */
	void update_flag_of_16 (bool msb_before, bool msb_after);

	/** */
	void update_flag_pf_8 (unsigned char val);

	/** */
	void update_flag_pf_16 (unsigned short val);

	/** */
	void update_flag_sf_8 (unsigned char val);

	/** */
	void update_flag_sf_16 (unsigned short val);

	/** */
	void update_flag_zf_8 (unsigned char val);

	/** */
	void update_flag_zf_16 (unsigned short val);

	/** */
	void op_adc_8 (unsigned char dest, unsigned char src, unsigned char &ret);

	/** */
	void op_adc_16 (unsigned short dest, unsigned short src, unsigned short &ret);

	/** */
	void op_add_8 (unsigned char dest, unsigned char src, unsigned char &ret);

	/** */
	void op_add_16 (unsigned short dest, unsigned short src, unsigned short &ret);

	/** */
	void op_and_8 (unsigned char dest, unsigned char src, unsigned char &ret);

	/** */
	void op_and_16 (unsigned short dest, unsigned short src, unsigned short &ret);

	/** */
	void op_cmc ();

	/** */
	void op_cmp_8 (unsigned char dest, unsigned char src);

	/** */
	void op_cmp_16 (unsigned short dest, unsigned short src);

#if 0
	/** FIXME */
	template<typename TDest, typename TSrc>
	void cmps (TDest &dest, TSrc &src, TDest &result);
#endif

	/** */
	void op_dec_8 (unsigned char src, unsigned char &ret);

	/** */
	void op_dec_16 (unsigned short src, unsigned short &ret);

	/** */
	void op_div_8 (unsigned char src);

	/** */
	void op_div_16 (unsigned short src);

	/** */
	void op_idiv_8 (unsigned char src);

	/** */
	void op_idiv_16 (unsigned short src);

	/** */
	void op_imul_8 (unsigned char src);

	/** */
	void op_imul_16 (unsigned short src);

	/** */
	void op_inc_8 (unsigned char src, unsigned char &ret);

	/** */
	void op_inc_16 (unsigned short src, unsigned short &ret);

	/** */
	void op_mul_8 (unsigned char src);

	/** */
	void op_mul_16 (unsigned short src);

	/** */
	void op_neg_8 (unsigned char dest, unsigned char &ret);

	/** */
	void op_neg_16 (unsigned short dest, unsigned short &ret);

	/** */
	void op_or_8 (unsigned char dest, unsigned char src, unsigned char &ret);

	/** */
	void op_or_16 (unsigned short dest, unsigned short src, unsigned short &ret);

	/** */
	void op_rcl_8 (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/** */
	void op_rcl_16 (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/** */
	void op_rcr_8 (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/** */
	void op_rcr_16 (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/** */
	void op_rol_8 (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/** */
	void op_rol_16 (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/** */
	void op_ror_8 (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/** */
	void op_ror_16 (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/** */
	void op_sal_8 (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/** */
	void op_sal_16 (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/** */
	void op_sar_8 (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/** */
	void op_sar_16 (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/** */
	void op_sbb_8 (unsigned char dest, unsigned char src, unsigned char &ret);

	/** */
	void op_sbb_16 (unsigned short dest, unsigned short src, unsigned short &ret);

	/** */
	void op_shl_8 (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/** */
	void op_shl_16 (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/** */
	void op_shr_8 (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/** */
	void op_shr_16 (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/** */
	void op_sub_8 (unsigned char dest, unsigned char src, unsigned char &ret);

	/** */
	void op_sub_16 (unsigned short dest, unsigned char src, unsigned short &ret);

	/** */
	void op_test_8 (unsigned char dest, unsigned char src);

	/** */
	void op_test_16 (unsigned short dest, unsigned char src);

	/** */
	template<typename TDest, typename TSrc>
	void
	op_xchg (TDest &dest, TSrc &src);

	/** */
	void op_xor_8 (unsigned char dest, unsigned char src, unsigned char &ret);

	/** */
	void op_xor_16 (unsigned short dest, unsigned short src, unsigned short &ret);
};

#if 0
//FIXME - fix flags
template<typename TDest, typename TSrc>
void
ArithmeticLogicUnit::cmps (TDest &dest, TSrc &src, TDest &result) {
}
#endif

//FIXME - fix flags
template<typename TDest, typename TSrc>
void
ArithmeticLogicUnit::op_xchg (TDest &dest, TSrc &src) {
	TDest tmp = dest;
	dest = src;
	src = tmp;
}

#endif //ARITHMETIC_LOGIC_UNIT_HH

