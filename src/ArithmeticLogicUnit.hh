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

#include <QtGlobal>

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
	void updateFlagAddAF (quint8 result8);

	/**
	@brief FIXME - Update the auxilliary flag (AF) for an 8-bit subtraction operation.
	*/
	void updateFlagSubAF (qint8 result8);

	/**
	@brief Update the carry flag (CF) for an 8-bit addition operation.
	*/
	void updateFlagAddCF (quint8 result8, quint16 result16);

	/**
	@brief Update the carry flag (CF) for a 16-bit addition operation.
	*/
	void updateFlagAddCF (quint16 result16, quint32 result32);

	/**
	@brief Update the carry flag (CF) for an 8-bit subtraction operation.
	*/
	void updateFlagSubCF (quint8 result8, qint16 result16);

	/**
	@brief Update the carry flag (CF) for a 16-bit subtraction operation.
	*/
	void updateFlagSubCF (quint16 result16, qint32 result32);

	/**
	@brief Update the overflow flag (OF) for an 8-bit addition operation.
	*/
	void updateFlagAddOF (quint8 orig_dest, quint8 src, quint8 dest);

	/**
	@brief Update the overflow flag (OF) for an 16-bit addition operation.
	*/
	void updateFlagAddOF (quint16 orig_dest, quint16 src, quint16 dest);

	/**
	@brief Update the overflow flag (OF) for an 8-bit subtraction operation.
	*/
	void updateFlagSubOF (quint8 orig_dest, quint8 src, quint8 dest);

	/**
	@brief Update the overflow flag (OF) for an 16-bit subtraction operation.
	*/
	void updateFlagSubOF (quint16 orig_dest, quint16 src, quint16 dest);

	/**
	@brief Update the parity flag (PF) for an 8-bit operation.
	*/
	void updateFlagPF (quint8 val);

	/**
	@brief Update the sign flag (SF) for an 8-bit operation.
	*/
	void updateFlagSF (quint8 val);

	/**
	@brief Update the sign flag (SF) for a 16-bit operation.
	*/
	void updateFlagSF (quint16 val);

	/**
	@brief Update the zero flag (ZF) for an 8-bit operation.
	*/
	void updateFlagZF (quint8 val);

	/**
	@brief Update the zero flag (ZF) for a 16-bit operation.
	*/
	void updateFlagZF (quint16 val);

	/**
	@brief Do an 8-bit add with a carry.
	*/
	void opAdc (quint8 dest, quint8 src, quint8 &ret);

	/**
	@brief Do a 16-bit add with a carry.
	*/
	void opAdc (quint16 dest, quint16 src, quint16 &ret);

	/**
	@brief Do an 8-bit add.
	*/
	void opAdd (quint8 dest, quint8 src, quint8 &ret);

	/**
	@brief Do a 16-bit add.
	*/
	void opAdd (quint16 dest, quint16 src, quint16 &ret);

	/**
	@brief Do an 8-bit and.
	*/
	void opAnd (quint8 dest, quint8 src, quint8 &ret);

	/**
	@brief Do a 16-bit and.
	*/
	void opAnd (quint16 dest, quint16 src, quint16 &ret);

	/** */
	void opCmc ();

	/**
	@brief Do an 8-bit cmp.
	*/
	void opCmp (quint8 dest, quint8 src);

	/**
	@brief Do a 16-bit cmp.
	*/
	void opCmp (quint16 dest, quint16 src);

	/**
	@brief Do an 8-bit dec.
	*/
	void opDec (quint8 src, quint8 &ret);

	/**
	@brief Do a 16-bit dec.
	*/
	void opDec (quint16 src, quint16 &ret);

	/**
	@brief Do an 8-bit div.
	*/
	bool opDiv (quint8 src);

	/**
	@brief Do a 16-bit div.
	*/
	bool opDiv (quint16 src);

	/**
	@brief Do an 8-bit idiv.
	*/
	void opIdiv (quint8 src);

	/**
	@brief Do a 16-bit idiv.
	*/
	void opIdiv (quint16 src);

	/**
	@brief Do an 8-bit imul.
	*/
	void opImul (quint8 src);

	/**
	@brief Do a 16-bit imul.
	*/
	void opImul (quint16 src);

	/**
	@brief Do an 8-bit inc.
	*/
	void opInc (quint8 src, quint8 &ret);

	/**
	@brief Do a 16-bit inc.
	*/
	void opInc (quint16 src, quint16 &ret);

	/**
	@brief Do an 8-bit mul.
	*/
	void opMul (quint8 src);

	/**
	@brief Do a 16-bit mul.
	*/
	void opMul (quint16 src);

	/**
	@brief Do an 8-bit neg.
	*/
	void opNeg (quint8 dest, quint8 &ret);

	/**
	@brief Do a 16-bit neg.
	*/
	void opNeg (quint16 dest, quint16 &ret);

	/**
	@brief Do an 8-bit or.
	*/
	void opOr (quint8 dest, quint8 src, quint8 &ret);

	/**
	@brief Do a 16-bit or.
	*/
	void opOr (quint16 dest, quint16 src, quint16 &ret);

	/**
	@brief Do an 8-bit rcl.
	*/
	void opRcl (quint8 dest, quint32 cnt, quint8 &ret);

	/**
	@brief Do a 16-bit rcl.
	*/
	void opRcl (quint16 dest, quint32 cnt, quint16 &ret);

	/**
	@brief Do an 8-bit rcr.
	*/
	void opRcr (quint8 dest, quint32 cnt, quint8 &ret);

	/**
	@brief Do a 16-bit rcr.
	*/
	void opRcr (quint16 dest, quint32 cnt, quint16 &ret);

	/**
	@brief Do an 8-bit rol.
	*/
	void opRol (quint8 dest, quint8 cnt, quint8 &ret);

	/**
	@brief Do a 16-bit rol.
	*/
	void opRol (quint16 dest, quint8 cnt, quint16 &ret);

	/**
	@brief Do an 8-bit ror.
	*/
	void opRor (quint8 dest, quint8 cnt, quint8 &ret);

	/**
	@brief Do a 16-bit ror.
	*/
	void opRor (quint16 dest, quint8 cnt, quint16 &ret);

	/**
	@brief Do an 8-bit sal.
	*/
	void opSal (quint8 dest, quint32 cnt, quint8 &ret);

	/**
	@brief Do a 16-bit sal.
	*/
	void opSal (quint16 dest, quint32 cnt, quint16 &ret);

	/**
	@brief Do an 8-bit sar.
	*/
	void opSar (quint8 dest, quint32 cnt, quint8 &ret);

	/**
	@brief Do a 16-bit sar.
	*/
	void opSar (quint16 dest, quint32 cnt, quint16 &ret);

	/**
	@brief Do an 8-bit sbb.
	*/
	void opSbb (quint8 dest, quint8 src, quint8 &ret);

	/**
	@brief Do a 16-bit sbb.
	*/
	void opSbb (quint16 dest, quint16 src, quint16 &ret);

	/**
	@brief Do an 8-bit shl.
	*/
	void opShl (quint8 dest, quint32 cnt, quint8 &ret);

	/**
	@brief Do a 16-bit shl.
	*/
	void opShl (quint16 dest, quint32 cnt, quint16 &ret);

	/**
	@brief Do an 8-bit shr.
	*/
	void opShr (quint8 dest, quint32 cnt, quint8 &ret);

	/**
	@brief Do a 16-bit shr.
	*/
	void opShr (quint16 dest, quint32 cnt, quint16 &ret);

	/**
	@brief Do an 8-bit sub.
	*/
	void opSub (quint8 dest, quint8 src, quint8 &ret);

	/**
	@brief Do a 16-bit sub.
	*/
	void opSub (quint16 dest, quint16 src, quint16 &ret);

	/**
	@brief Do an 8-bit test.
	*/
	void opTest (quint8 dest, quint8 src);

	/**
	@brief Do a 16-bit test
	*/
	void opTest (quint16 dest, quint16 src);

	/**
	@brief Do an 8-bit xor.
	*/
	void opXor (quint8 dest, quint8 src, quint8 &ret);

	/**
	@brief Do a 16-bit xor.
	*/
	void opXor (quint16 dest, quint16 src, quint16 &ret);

}; //end class ArithmeticLogicUnit

#endif //EMUCPU__ARITHMETIC_LOGIC_UNIT_HH

