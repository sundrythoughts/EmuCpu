#ifndef JAF__ARITHMETIC_LOGIC_UNIT_HH
#define JAF__ARITHMETIC_LOGIC_UNIT_HH

#include "Cpu.hh"
#include "Utility.hh"
#include "Register.hh"
#include <iostream>

class Cpu;
class ArithmeticLogicUnitPrivate;

/**
*/
class ArithmeticLogicUnit {
	ArithmeticLogicUnitPrivate *p;

public:
	/** */
	ArithmeticLogicUnit ();

	/** */
	ArithmeticLogicUnit (const ArithmeticLogicUnit &src);

	/** */
	~ArithmeticLogicUnit ();

	/** */
	void
	connectTo (Cpu &cpu);

	/** FIXME */
	void updateFlagAF (unsigned char result8, unsigned short result16);

	/** FIXME */
	void updateFlagAF (unsigned short result16, unsigned int result32);

	/** */
	void updateFlagCF (unsigned char result8, unsigned short result16);

	/** */
	void updateFlagCF (unsigned short result16, unsigned int result32);

	/** */
	void updateFlagOF (bool msb_before, bool msb_after);

	/** */
	void updateFlagPF (unsigned char val);

	/** */
	void updateFlagPF (unsigned short val);

	/** */
	void updateFlagSF (unsigned char val);

	/** */
	void updateFlagSF (unsigned short val);

	/** */
	void updateFlagZF (unsigned char val);

	/** */
	void updateFlagZF (unsigned short val);

	/** */
	void opAdc (unsigned char dest, unsigned char src, unsigned char &ret);

	/** */
	void opAdc (unsigned short dest, unsigned short src, unsigned short &ret);

	/** */
	void opAdd (unsigned char dest, unsigned char src, unsigned char &ret);

	/** */
	void opAdd (unsigned short dest, unsigned short src, unsigned short &ret);

	/** */
	void opAnd (unsigned char dest, unsigned char src, unsigned char &ret);

	/** */
	void opAnd (unsigned short dest, unsigned short src, unsigned short &ret);

	/** */
	void opCmc ();

	/** */
	void opCmp (unsigned char dest, unsigned char src);

	/** */
	void opCmp (unsigned short dest, unsigned short src);

#if 0
	/** FIXME */
	template<typename TDest, typename TSrc>
	void cmps (TDest &dest, TSrc &src, TDest &result);
#endif

	/** */
	void opDec (unsigned char src, unsigned char &ret);

	/** */
	void opDec (unsigned short src, unsigned short &ret);

	/** */
	void opDiv (unsigned char src);

	/** */
	void opDiv (unsigned short src);

	/** */
	void opIdiv (unsigned char src);

	/** */
	void opIdiv (unsigned short src);

	/** */
	void opImul (unsigned char src);

	/** */
	void opImul (unsigned short src);

	/** */
	void opInc (unsigned char src, unsigned char &ret);

	/** */
	void opInc (unsigned short src, unsigned short &ret);

	/** */
	void opMul (unsigned char src);

	/** */
	void opMul (unsigned short src);

	/** */
	void opNeg (unsigned char dest, unsigned char &ret);

	/** */
	void opNeg (unsigned short dest, unsigned short &ret);

	/** */
	void opOr (unsigned char dest, unsigned char src, unsigned char &ret);

	/** */
	void opOr (unsigned short dest, unsigned short src, unsigned short &ret);

	/** */
	void opRcl (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/** */
	void opRcl (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/** */
	void opRcr (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/** */
	void opRcr (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/** */
	void opRol (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/** */
	void opRol (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/** */
	void opRor (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/** */
	void opRor (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/** */
	void opSal (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/** */
	void opSal (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/** */
	void opSar (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/** */
	void opSar (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/** */
	void opSbb (unsigned char dest, unsigned char src, unsigned char &ret);

	/** */
	void opSbb (unsigned short dest, unsigned short src, unsigned short &ret);

	/** */
	void opShl (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/** */
	void opShl (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/** */
	void opShr (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/** */
	void opShr (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/** */
	void opSub (unsigned char dest, unsigned char src, unsigned char &ret);

	/** */
	void opSub (unsigned short dest, unsigned char src, unsigned short &ret);

	/** */
	void opTest (unsigned char dest, unsigned char src);

	/** */
	void opTest (unsigned short dest, unsigned char src);

	/** */
	template<typename TDest, typename TSrc>
	void
	opXchg (TDest &dest, TSrc &src);

	/** */
	void opXor (unsigned char dest, unsigned char src, unsigned char &ret);

	/** */
	void opXor (unsigned short dest, unsigned short src, unsigned short &ret);
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
ArithmeticLogicUnit::opXchg (TDest &dest, TSrc &src) {
	TDest tmp = dest;
	dest = src;
	src = tmp;
}

#endif //JAF__ARITHMETIC_LOGIC_UNIT_HH

