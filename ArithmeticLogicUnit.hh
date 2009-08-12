#ifndef ARITHMETIC_LOGIC_UNIT_HH
#define ARITHMETIC_LOGIC_UNIT_HH

#include "ExecutionUnit.hh"

class ArithmeticLogicUnit {
	ExecutionUnit *m_eunit;

public:
	/** */
	ArithmeticLogicUnit () {
	}

	/** */
	ArithmeticLogicUnit (const ArithmeticLogicUnit &src) {
	}

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
	void op_adc (TDest &dest, TSrc &src, TDest &result);

	/** */
	template<typename TDest, typename TSrc>
	void op_add (TDest &dest, TSrc &src, TDest &result);

	/** */
	template<typename TDest, typename TSrc>
	void op_and (TDest &dest, TSrc &src, TDest &result);

	/** */
	template<typename TDest, typename TSrc>
	void op_adc (TDest &dest, TSrc &src, TDest &result);

	/** */
	void op_cbw ();

	/** */
	void op_cmc ();

	/** */
	template<typename TDest, typename TSrc>
	void op_cmp (TDest &dest, TSrc &src, TDest &result);

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
	void op_dec (TDest &dest, TDest &result);

	/** */
	template<typename TSrc>
	void op_div (TSrc &src);

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
	void op_or (TDest &dest, TSrc &src, TDest &result);

	/** */
	template<typename TDest, typename TCount>
	void op_rcl (TDest &dest, TCount &cnt, TDest &result);

	/** */
	template<typename TDest, typename TCount>
	void op_rcr (TDest &dest, TCount &cnt, TDest &result);

	/** */
	template<typename TDest, typename TCount>
	void op_rol (TDest &dest, TCount &cnt, TDest &result);

	/** */
	template<typename TDest, typename TCount>
	void op_ror (TDest &dest, TCount &cnt, TDest &result);

	/** */
	template<typename TDest, typename TCount>
	void op_sal (TDest &dest, TCount &cnt, TDest &result);

	/** */
	template<typename TDest, typename TCount>
	void op_sar (TDest &dest, TCount &cnt, TDest &result);

	/** */
	template<typename TDest, typename TSrc>
	void op_sbb (TDest &dest, TSrc &src, TDest &result);

#if 0
	/** FIXME */
	template<typename TDest>
	void op_or (TDest &dest);
#endif

	/** */
	template<typename TDest, typename TCount>
	void op_shl (TDest &dest, TCount &cnt, TDest &result);

	/** */
	template<typename TDest, typename TCount>
	void op_shr (TDest &dest, TCount &cnt, TDest &result);

	/** */
	template<typename TDest, typename TSrc>
	void op_sub (TDest &dest, TSrc &src, TDest &result);

	/** */
	template<typename TDest, typename TSrc>
	void op_test (TDest &dest, TSrc &src, TDest &result);

	/** */
	template<typename TDest, typename TSrc>
	void op_xchg (TDest &dest, TSrc &src);
};

#endif //ARITHMETIC_LOGIC_UNIT_HH

