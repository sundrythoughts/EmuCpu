/*
 * sim8086 -- Emulates an Intel 8086 processor
 * Copyright (C) 2009  Joseph Freeman (jfree143dev AT gmail DOT com)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


/**
@file ArithmeticLogicUnit.hh
@brief Does all the arithmetic and logical operations of the 8086.
*/

#ifndef JAF__ARITHMETIC_LOGIC_UNIT_HH
#define JAF__ARITHMETIC_LOGIC_UNIT_HH

//#include "CpuComponents.hh"

class CpuComponents;
class ArithmeticLogicUnitPrivate;

/**
@class ArithmeticLogicUnit
@brief Does all the arithmetic and logical operations of the 8086. It also updates flags after arithmetic operations.
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
	connectTo (CpuComponents &cpu);

	/**
	@brief FIXME - Update the auxilliary flag (AF) for an 8-bit operation.
	*/
	void updateFlagAF (unsigned char result8, unsigned short result16);

	/**
	@brief FIXME - Update the auxilliary flag (AF) for a 16-bit operation.
	*/
	void updateFlagAF (unsigned short result16, unsigned int result32);

	/**
	@brief Update the carry flag (CF) for an 8-bit addition operation.
	*/
	void updateFlagAddCF (unsigned char result8, unsigned short result16);

	/**
	@brief Update the carry flag (CF) for a 16-bit addition operation.
	*/
	void updateFlagAddCF (unsigned short result16, unsigned int result32);

	/**
	@brief Update the carry flag (CF) for an 8-bit subtraction operation.
	*/
	void updateFlagSubCF (unsigned char result8, short result16);

	/**
	@brief Update the carry flag (CF) for a 16-bit subtraction operation.
	*/
	void updateFlagSubCF (unsigned short result16, int result32);

	/**
	@brief Update the overflow flag (OF) for an 8-bit addition operation.
	*/
	void updateFlagAddOF (unsigned char orig_dest, unsigned char src, unsigned char dest);

	/**
	@brief Update the overflow flag (OF) for an 16-bit addition operation.
	*/
	void updateFlagAddOF (unsigned short orig_dest, unsigned short src, unsigned short dest);

	/**
	@brief Update the overflow flag (OF) for an 8-bit subtraction operation.
	*/
	void updateFlagSubOF (unsigned char orig_dest, unsigned char src, unsigned char dest);

	/**
	@brief Update the overflow flag (OF) for an 16-bit subtraction operation.
	*/
	void updateFlagSubOF (unsigned short orig_dest, unsigned short src, unsigned short dest);

	/**
	@brief Update the parity flag (PF) for an 8-bit operation.
	*/
	void updateFlagPF (unsigned char val);

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
	bool opDiv (unsigned char src);

	/**
	@brief Do a 16-bit div.
	*/
	bool opDiv (unsigned short src);

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
	void opRol (unsigned char dest, unsigned char cnt, unsigned char &ret);

	/**
	@brief Do a 16-bit rol.
	*/
	void opRol (unsigned short dest, unsigned char cnt, unsigned short &ret);

	/**
	@brief Do an 8-bit ror.
	*/
	void opRor (unsigned char dest, unsigned char cnt, unsigned char &ret);

	/**
	@brief Do a 16-bit ror.
	*/
	void opRor (unsigned short dest, unsigned char cnt, unsigned short &ret);

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
	void opSub (unsigned short dest, unsigned short src, unsigned short &ret);

	/**
	@brief Do an 8-bit test.
	*/
	void opTest (unsigned char dest, unsigned char src);

	/**
	@brief Do a 16-bit test
	*/
	void opTest (unsigned short dest, unsigned short src);

	/**
	@brief Do an 8-bit xor.
	*/
	void opXor (unsigned char dest, unsigned char src, unsigned char &ret);

	/**
	@brief Do a 16-bit xor.
	*/
	void opXor (unsigned short dest, unsigned short src, unsigned short &ret);

}; //end class ArithmeticLogicUnit

#endif //JAF__ARITHMETIC_LOGIC_UNIT_HH

