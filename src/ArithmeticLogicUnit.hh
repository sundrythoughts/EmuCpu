/*
 * emucpu -- Emulates processors
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

#ifndef EMUCPU__ARITHMETIC_LOGIC_UNIT_HH
#define EMUCPU__ARITHMETIC_LOGIC_UNIT_HH

#include "Types.hh"

class CpuComponents;
class ArithmeticLogicUnitPrivate;

/**
@class ArithmeticLogicUnit
@brief Does all the arithmetic and logical operations of the 8086.
       It also updates flags after arithmetic operations.
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
	@brief FIXME - Update the auxilliary flag (AF) for an 8-bit addition operation.
	*/
	void updateFlagAddAF (uint8 result8);

	/**
	@brief FIXME - Update the auxilliary flag (AF) for an 8-bit subtraction operation.
	*/
	void updateFlagSubAF (int8 result8);

	/**
	@brief Update the carry flag (CF) for an 8-bit addition operation.
	*/
	void updateFlagAddCF (uint8 result8, uint16 result16);

	/**
	@brief Update the carry flag (CF) for a 16-bit addition operation.
	*/
	void updateFlagAddCF (uint16 result16, uint32 result32);

	/**
	@brief Update the carry flag (CF) for an 8-bit subtraction operation.
	*/
	void updateFlagSubCF (uint8 result8, int16 result16);

	/**
	@brief Update the carry flag (CF) for a 16-bit subtraction operation.
	*/
	void updateFlagSubCF (uint16 result16, int32 result32);

	/**
	@brief Update the overflow flag (OF) for an 8-bit addition operation.
	*/
	void updateFlagAddOF (uint8 orig_dest, uint8 src, uint8 dest);

	/**
	@brief Update the overflow flag (OF) for an 16-bit addition operation.
	*/
	void updateFlagAddOF (uint16 orig_dest, uint16 src, uint16 dest);

	/**
	@brief Update the overflow flag (OF) for an 8-bit subtraction operation.
	*/
	void updateFlagSubOF (uint8 orig_dest, uint8 src, uint8 dest);

	/**
	@brief Update the overflow flag (OF) for an 16-bit subtraction operation.
	*/
	void updateFlagSubOF (uint16 orig_dest, uint16 src, uint16 dest);

	/**
	@brief Update the parity flag (PF) for an 8-bit operation.
	*/
	void updateFlagPF (uint8 val);

	/**
	@brief Update the sign flag (SF) for an 8-bit operation.
	*/
	void updateFlagSF (uint8 val);

	/**
	@brief Update the sign flag (SF) for a 16-bit operation.
	*/
	void updateFlagSF (uint16 val);

	/**
	@brief Update the zero flag (ZF) for an 8-bit operation.
	*/
	void updateFlagZF (uint8 val);

	/**
	@brief Update the zero flag (ZF) for a 16-bit operation.
	*/
	void updateFlagZF (uint16 val);

	/**
	@brief Do an 8-bit add with a carry.
	*/
	void opAdc (uint8 dest, uint8 src, uint8 &ret);

	/**
	@brief Do a 16-bit add with a carry.
	*/
	void opAdc (uint16 dest, uint16 src, uint16 &ret);

	/**
	@brief Do an 8-bit add.
	*/
	void opAdd (uint8 dest, uint8 src, uint8 &ret);

	/**
	@brief Do a 16-bit add.
	*/
	void opAdd (uint16 dest, uint16 src, uint16 &ret);

	/**
	@brief Do an 8-bit and.
	*/
	void opAnd (uint8 dest, uint8 src, uint8 &ret);

	/**
	@brief Do a 16-bit and.
	*/
	void opAnd (uint16 dest, uint16 src, uint16 &ret);

	/** */
	void opCmc ();

	/**
	@brief Do an 8-bit cmp.
	*/
	void opCmp (uint8 dest, uint8 src);

	/**
	@brief Do a 16-bit cmp.
	*/
	void opCmp (uint16 dest, uint16 src);

	/**
	@brief Do an 8-bit dec.
	*/
	void opDec (uint8 src, uint8 &ret);

	/**
	@brief Do a 16-bit dec.
	*/
	void opDec (uint16 src, uint16 &ret);

	/**
	@brief Do an 8-bit div.
	*/
	bool opDiv (uint8 src);

	/**
	@brief Do a 16-bit div.
	*/
	bool opDiv (uint16 src);

	/**
	@brief Do an 8-bit idiv.
	*/
	void opIdiv (uint8 src);

	/**
	@brief Do a 16-bit idiv.
	*/
	void opIdiv (uint16 src);

	/**
	@brief Do an 8-bit imul.
	*/
	void opImul (uint8 src);

	/**
	@brief Do a 16-bit imul.
	*/
	void opImul (uint16 src);

	/**
	@brief Do an 8-bit inc.
	*/
	void opInc (uint8 src, uint8 &ret);

	/**
	@brief Do a 16-bit inc.
	*/
	void opInc (uint16 src, uint16 &ret);

	/**
	@brief Do an 8-bit mul.
	*/
	void opMul (uint8 src);

	/**
	@brief Do a 16-bit mul.
	*/
	void opMul (uint16 src);

	/**
	@brief Do an 8-bit neg.
	*/
	void opNeg (uint8 dest, uint8 &ret);

	/**
	@brief Do a 16-bit neg.
	*/
	void opNeg (uint16 dest, uint16 &ret);

	/**
	@brief Do an 8-bit or.
	*/
	void opOr (uint8 dest, uint8 src, uint8 &ret);

	/**
	@brief Do a 16-bit or.
	*/
	void opOr (uint16 dest, uint16 src, uint16 &ret);

	/**
	@brief Do an 8-bit rcl.
	*/
	void opRcl (uint8 dest, uint32 cnt, uint8 &ret);

	/**
	@brief Do a 16-bit rcl.
	*/
	void opRcl (uint16 dest, uint32 cnt, uint16 &ret);

	/**
	@brief Do an 8-bit rcr.
	*/
	void opRcr (uint8 dest, uint32 cnt, uint8 &ret);

	/**
	@brief Do a 16-bit rcr.
	*/
	void opRcr (uint16 dest, uint32 cnt, uint16 &ret);

	/**
	@brief Do an 8-bit rol.
	*/
	void opRol (uint8 dest, uint8 cnt, uint8 &ret);

	/**
	@brief Do a 16-bit rol.
	*/
	void opRol (uint16 dest, uint8 cnt, uint16 &ret);

	/**
	@brief Do an 8-bit ror.
	*/
	void opRor (uint8 dest, uint8 cnt, uint8 &ret);

	/**
	@brief Do a 16-bit ror.
	*/
	void opRor (uint16 dest, uint8 cnt, uint16 &ret);

	/**
	@brief Do an 8-bit sal.
	*/
	void opSal (uint8 dest, uint32 cnt, uint8 &ret);

	/**
	@brief Do a 16-bit sal.
	*/
	void opSal (uint16 dest, uint32 cnt, uint16 &ret);

	/**
	@brief Do an 8-bit sar.
	*/
	void opSar (uint8 dest, uint32 cnt, uint8 &ret);

	/**
	@brief Do a 16-bit sar.
	*/
	void opSar (uint16 dest, uint32 cnt, uint16 &ret);

	/**
	@brief Do an 8-bit sbb.
	*/
	void opSbb (uint8 dest, uint8 src, uint8 &ret);

	/**
	@brief Do a 16-bit sbb.
	*/
	void opSbb (uint16 dest, uint16 src, uint16 &ret);

	/**
	@brief Do an 8-bit shl.
	*/
	void opShl (uint8 dest, uint32 cnt, uint8 &ret);

	/**
	@brief Do a 16-bit shl.
	*/
	void opShl (uint16 dest, uint32 cnt, uint16 &ret);

	/**
	@brief Do an 8-bit shr.
	*/
	void opShr (uint8 dest, uint32 cnt, uint8 &ret);

	/**
	@brief Do a 16-bit shr.
	*/
	void opShr (uint16 dest, uint32 cnt, uint16 &ret);

	/**
	@brief Do an 8-bit sub.
	*/
	void opSub (uint8 dest, uint8 src, uint8 &ret);

	/**
	@brief Do a 16-bit sub.
	*/
	void opSub (uint16 dest, uint16 src, uint16 &ret);

	/**
	@brief Do an 8-bit test.
	*/
	void opTest (uint8 dest, uint8 src);

	/**
	@brief Do a 16-bit test
	*/
	void opTest (uint16 dest, uint16 src);

	/**
	@brief Do an 8-bit xor.
	*/
	void opXor (uint8 dest, uint8 src, uint8 &ret);

	/**
	@brief Do a 16-bit xor.
	*/
	void opXor (uint16 dest, uint16 src, uint16 &ret);

}; //end class ArithmeticLogicUnit

#endif //EMUCPU__ARITHMETIC_LOGIC_UNIT_HH

