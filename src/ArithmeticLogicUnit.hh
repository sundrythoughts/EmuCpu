/**
@file ArithmeticLogicUnit.hh
@brief Does all the arithmetic and logical operations of the 8086.
*/

#ifndef JAF__ARITHMETIC_LOGIC_UNIT_HH
#define JAF__ARITHMETIC_LOGIC_UNIT_HH

#include "Cpu.hh"
#include "Utility.hh"
#include "Register.hh"
#include <iostream>

class Cpu;
class ArithmeticLogicUnitPrivate;

/**
@class ArithmeticLogicUnit
@brief Does all the arithmetic and logical operations of the 8086. It also updates certain flags like ZF and CF.
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

	/** Create a connection to the Cpu */
	void
	connectTo (Cpu &cpu);

	//FIXME
	/**
	@brief Update the auxilliary flag (AF) for an 8-bit operation.
	*/
	void updateFlagAF (unsigned char result8, unsigned short result16);

	//FIXME
	/**
	@brief Update the auxilliary flag (AF) for a 16-bit operation.
	*/
	void updateFlagAF (unsigned short result16, unsigned int result32);

	/**
	@brief Update the carry flag (CF) for an 8-bit operation.
	*/
	void updateFlagCF (unsigned char result8, unsigned short result16);

	/**
	@brief Update the carry flag (CF) for a 16-bit operation.
	*/
	void updateFlagCF (unsigned short result16, unsigned int result32);

	/**
	@brief Update the overflow flag (OF).
	*/
	void updateFlagOF (bool msb_before, bool msb_after);

	/**
	@brief Update the parity flag (PF) for an 8-bit operation.
	*/
	void updateFlagPF (unsigned char val);

	/**
	@brief Update the parity flag (PF) for a 16-bit operation.
	*/
	void updateFlagPF (unsigned short val);

	/**
	@brief Update the sign flag (SF) for an 8-bit operation.
	*/
	void updateFlagSF (unsigned char val);

	/**
	@brief Update the sign flag (SF) for a 16-bit operation.
	*/
	void updateFlagSF (unsigned short val);

	/**
	@brief Update the zero flag (ZF) for an 8-bit operation.
	*/
	void updateFlagZF (unsigned char val);

	/**
	@brief Update the zero flag (ZF) for a 16-bit operation.
	*/
	void updateFlagZF (unsigned short val);

	/**
	@brief Do an 8-bit add with a carry.
	*/
	void opAdc (unsigned char dest, unsigned char src, unsigned char &ret);

	/**
	@brief Do a 16-bit add with a carry.
	*/
	void opAdc (unsigned short dest, unsigned short src, unsigned short &ret);

	/**
	@brief Do an 8-bit add.
	*/
	void opAdd (unsigned char dest, unsigned char src, unsigned char &ret);

	/**
	@brief Do a 16-bit add.
	*/
	void opAdd (unsigned short dest, unsigned short src, unsigned short &ret);

	/**
	@brief Do an 8-bit and.
	*/
	void opAnd (unsigned char dest, unsigned char src, unsigned char &ret);

	/**
	@brief Do a 16-bit and.
	*/
	void opAnd (unsigned short dest, unsigned short src, unsigned short &ret);

	/** */
	void opCmc ();

	/**
	@brief Do an 8-bit cmp.
	*/
	void opCmp (unsigned char dest, unsigned char src);

	/**
	@brief Do a 16-bit cmp.
	*/
	void opCmp (unsigned short dest, unsigned short src);

#if 0
	/** FIXME */
	template<typename TDest, typename TSrc>
	void cmps (TDest &dest, TSrc &src, TDest &result);
#endif

	/**
	@brief Do an 8-bit dec.
	*/
	void opDec (unsigned char src, unsigned char &ret);

	/**
	@brief Do a 16-bit dec.
	*/
	void opDec (unsigned short src, unsigned short &ret);

	/**
	@brief Do an 8-bit div.
	*/
	void opDiv (unsigned char src);

	/**
	@brief Do a 16-bit div.
	*/
	void opDiv (unsigned short src);

	/**
	@brief Do an 8-bit idiv.
	*/
	void opIdiv (unsigned char src);

	/**
	@brief Do a 16-bit idiv.
	*/
	void opIdiv (unsigned short src);

	/**
	@brief Do an 8-bit imul.
	*/
	void opImul (unsigned char src);

	/**
	@brief Do a 16-bit imul.
	*/
	void opImul (unsigned short src);

	/**
	@brief Do an 8-bit inc.
	*/
	void opInc (unsigned char src, unsigned char &ret);

	/**
	@brief Do a 16-bit inc.
	*/
	void opInc (unsigned short src, unsigned short &ret);

	/**
	@brief Do an 8-bit mul.
	*/
	void opMul (unsigned char src);

	/**
	@brief Do a 16-bit mul.
	*/
	void opMul (unsigned short src);

	/**
	@brief Do an 8-bit neg.
	*/
	void opNeg (unsigned char dest, unsigned char &ret);

	/**
	@brief Do a 16-bit neg.
	*/
	void opNeg (unsigned short dest, unsigned short &ret);

	/**
	@brief Do an 8-bit or.
	*/
	void opOr (unsigned char dest, unsigned char src, unsigned char &ret);

	/**
	@brief Do a 16-bit or.
	*/
	void opOr (unsigned short dest, unsigned short src, unsigned short &ret);

	/**
	@brief Do an 8-bit rcl.
	*/
	void opRcl (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/**
	@brief Do a 16-bit rcl.
	*/
	void opRcl (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/**
	@brief Do an 8-bit rcr.
	*/
	void opRcr (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/**
	@brief Do a 16-bit rcr.
	*/
	void opRcr (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/**
	@brief Do an 8-bit rol.
	*/
	void opRol (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/**
	@brief Do a 16-bit rol.
	*/
	void opRol (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/**
	@brief Do an 8-bit ror.
	*/
	void opRor (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/**
	@brief Do a 16-bit ror.
	*/
	void opRor (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/**
	@brief Do an 8-bit sal.
	*/
	void opSal (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/**
	@brief Do a 16-bit sal.
	*/
	void opSal (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/**
	@brief Do an 8-bit sar.
	*/
	void opSar (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/**
	@brief Do a 16-bit sar.
	*/
	void opSar (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/**
	@brief Do an 8-bit sbb.
	*/
	void opSbb (unsigned char dest, unsigned char src, unsigned char &ret);

	/**
	@brief Do a 16-bit sbb.
	*/
	void opSbb (unsigned short dest, unsigned short src, unsigned short &ret);

	/**
	@brief Do an 8-bit shl.
	*/
	void opShl (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/**
	@brief Do a 16-bit shl.
	*/
	void opShl (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/**
	@brief Do an 8-bit shr.
	*/
	void opShr (unsigned char dest, unsigned int cnt, unsigned char &ret);

	/**
	@brief Do a 16-bit shr.
	*/
	void opShr (unsigned short dest, unsigned int cnt, unsigned short &ret);

	/**
	@brief Do an 8-bit sub.
	*/
	void opSub (unsigned char dest, unsigned char src, unsigned char &ret);

	/**
	@brief Do a 16-bit sub.
	*/
	void opSub (unsigned short dest, unsigned char src, unsigned short &ret);

	/**
	@brief Do an 8-bit test.
	*/
	void opTest (unsigned char dest, unsigned char src);

	/**
	@brief Do a 16-bit test
	*/
	void opTest (unsigned short dest, unsigned char src);

	/**
	@brief Do an 8-bit xor.
	*/
	void opXor (unsigned char dest, unsigned char src, unsigned char &ret);

	/**
	@brief Do a 16-bit xor.
	*/
	void opXor (unsigned short dest, unsigned short src, unsigned short &ret);
}; //end class ArithmeticLogicUnit

#if 0
//FIXME - fix flags
template<typename TDest, typename TSrc>
void
ArithmeticLogicUnit::cmps (TDest &dest, TSrc &src, TDest &result) {
}
#endif

#endif //JAF__ARITHMETIC_LOGIC_UNIT_HH

