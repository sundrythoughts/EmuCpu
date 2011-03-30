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


#include "ArithmeticLogicUnit.hh"

#include "CpuComponents.hh"
#include "Utility.hh"
#include "Register.hh"
#include "ExecutionUnit.hh"
#include <iostream>

class ArithmeticLogicUnitPrivate {
public:
	CpuComponents *m_cpu;
	ExecutionUnit *m_eunit;
};

ArithmeticLogicUnit::ArithmeticLogicUnit () {
	p = new ArithmeticLogicUnitPrivate;
}

ArithmeticLogicUnit::~ArithmeticLogicUnit () {
	delete p;
}

void
ArithmeticLogicUnit::connectTo (CpuComponents &cpu) {
	p->m_cpu = &cpu;
	p->m_eunit = &cpu.getExecutionUnit ();
}

void
ArithmeticLogicUnit::updateFlagAddAF (uint8 result8) {
	p->m_eunit->setRegFlagsAF (result8 > (result8 & 0xF));
}

void
ArithmeticLogicUnit::updateFlagSubAF (int8 result8) {
	p->m_eunit->setRegFlagsAF (result8 & 0x08); //FIXME
}

void
ArithmeticLogicUnit::updateFlagAddCF (uint8 result8, uint16 result16) {
	p->m_eunit->setRegFlagsCF (result16 > 0xFF);
}

void
ArithmeticLogicUnit::updateFlagAddCF (uint16 result16, uint32 result32) {
	p->m_eunit->setRegFlagsCF (result32 > 0xFFFF);
}

void
ArithmeticLogicUnit::updateFlagSubCF (uint8 result8, int16 result16) {
	p->m_eunit->setRegFlagsCF (result16 < 0);
}

void
ArithmeticLogicUnit::updateFlagSubCF (uint16 result16, int32 result32) {
	p->m_eunit->setRegFlagsCF (result32 < 0);
}

void
ArithmeticLogicUnit::updateFlagAddOF (uint8 orig_dest, uint8 src, uint8 dest) {
	bool a = Utility::getMsb (orig_dest);
	bool b = Utility::getMsb (src);
	bool c = Utility::getMsb (dest);
	p->m_eunit->setRegFlagsOF (a == b && a != c);
}

void
ArithmeticLogicUnit::updateFlagAddOF (uint16 orig_dest, uint16 src, uint16 dest) {
	bool a = Utility::getMsb (orig_dest);
	bool b = Utility::getMsb (src);
	bool c = Utility::getMsb (dest);
	p->m_eunit->setRegFlagsOF (a == b && a != c);
}

void
ArithmeticLogicUnit::updateFlagSubOF (uint8 orig_dest, uint8 src, uint8 dest) {
	bool a = Utility::getMsb (orig_dest);
	bool b = Utility::getMsb (src);
	bool c = Utility::getMsb (dest);
	p->m_eunit->setRegFlagsOF (a != b && a != c);
}

void
ArithmeticLogicUnit::updateFlagSubOF (uint16 orig_dest, uint16 src, uint16 dest) {
	bool a = Utility::getMsb (orig_dest);
	bool b = Utility::getMsb (src);
	bool c = Utility::getMsb (dest);
	p->m_eunit->setRegFlagsOF (a != b && a != c);
}

void
ArithmeticLogicUnit::updateFlagPF (uint8 val) {
	uint32 count = 0;
	while (val) {
		if (val & 1) {
			++count;
		}
		val >>= 1;
	}

	p->m_eunit->setRegFlagsPF (!(count & 1));
}

void
ArithmeticLogicUnit::updateFlagSF (uint8 val) {
	p->m_eunit->setRegFlagsSF (Utility::getMsb (val));
}

void
ArithmeticLogicUnit::updateFlagSF (uint16 val) {
	p->m_eunit->setRegFlagsSF (Utility::getMsb (val));
}

void
ArithmeticLogicUnit::updateFlagZF (uint8 val) {
	p->m_eunit->setRegFlagsZF (!val);
}

void
ArithmeticLogicUnit::updateFlagZF (uint16 val) {
	p->m_eunit->setRegFlagsZF (!val);
}

void
ArithmeticLogicUnit::opAdc (uint8 dest, uint8 src, uint8 &ret) {
	bool cf = p->m_eunit->getRegFlagsCF ();
	uint8 orig_dest = dest;

	uint16 result = dest + src;
	if (cf) {
		result += 1;
	}

	ret = (uint8)result;

	//FIXME - fix flags
	updateFlagAddCF (ret, result);
	updateFlagAddOF (orig_dest, src, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opAdc (uint16 dest, uint16 src, uint16 &ret) {
	bool cf = p->m_eunit->getRegFlagsCF ();
	uint16 orig_dest = dest;

	uint32 result = dest + src;
	if (cf) {
		result += 1;
	}

	ret = (uint16)result;

	//FIXME - fix flags
	//updateFlagAddAF (ret);
	updateFlagAddCF (ret, result);
	updateFlagAddOF (orig_dest, src, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opAdd (uint8 dest, uint8 src, uint8 &ret) {
	uint8 orig_dest = dest;
	uint16 result = dest + src;

	ret = (uint8)result;

	//FIXME - fix flags
	//updateFlagAddAF (ret);
	updateFlagAddCF (ret, result);
	updateFlagAddOF (orig_dest, src, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opAdd (uint16 dest, uint16 src, uint16 &ret) {
	uint16 orig_dest = dest;
	uint32 result = dest + src;

	ret = (uint16)result;

	//FIXME - fix flags
	//updateFlagAddAF (ret);
	updateFlagAddCF (ret, result);
	updateFlagAddOF (orig_dest, src, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opAnd (uint8 dest, uint8 src, uint8 &ret) {
	uint16 result = dest & src;
	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	ret = (uint8)result;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opAnd (uint16 dest, uint16 src, uint16 &ret) {
	uint32 result = dest & src;
	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	ret = (uint16)result;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opCmc () {
	bool cf = p->m_eunit->getRegFlagsCF ();
	p->m_eunit->setRegFlagsCF (cf ^ 1);

}

void
ArithmeticLogicUnit::opCmp (uint8 dest, uint8 src) {
	uint8 orig_dest = dest;
	int16 result = (int8)dest - (int8)src;
	uint8 ret = dest - src;

	//FIXME - fix flags
	//updateFlagSubAF (ret);
	updateFlagSubCF (ret, result);
	updateFlagSubOF (orig_dest, src, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opCmp (uint16 dest, uint16 src) {
	uint16 orig_dest = dest;
	int32 result = dest - src;
	uint16 ret = dest - src;

	//FIXME - fix flags
	//updateFlagSubAF (ret);
	updateFlagSubCF (ret, result);
	updateFlagSubOF (orig_dest, src, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opDec (uint8 dest, uint8 &ret) {
	uint8 orig_dest = dest;
	int16 result = --dest;
	ret = (uint8)result;

	//FIXME - fix flags
	//updateFlagSubAF (ret);
	updateFlagSubOF (orig_dest, 1, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opDec (uint16 dest, uint16 &ret) {
	uint16 orig_dest = dest;
	int32 result = --dest;
	ret = (uint16)result;

	//FIXME - fix flags
	//updateFlagSubAF (ret);
	updateFlagSubOF (orig_dest, 1, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

bool
ArithmeticLogicUnit::opDiv (uint8 src) {
	Register<uint16> ax = p->m_eunit->getRegAX ();
	Register<uint8> &al = p->m_eunit->getRegAL ();
	Register<uint8> &ah = p->m_eunit->getRegAH ();

	if (src == 0) {
		//interrupt 0
		return false;
	}

	//Register<uint8> tmp = ax / src;
	uint16 tmp = ax / src;

	if (tmp > 0xFF) {
		//interrupt 0
		return false;
	}
	else {
		al = tmp; //FIXME - this has a problem
		ah = ax % src;
	}

	return true;
}

bool
ArithmeticLogicUnit::opDiv (uint16 src) {
	Register<uint16> &ax = p->m_eunit->getRegAX ();
	Register<uint16> &dx = p->m_eunit->getRegDX ();

	uint32 dx_ax = dx;
	dx_ax <<= 16;
	dx_ax += ax;

	if (src == 0) {
		//interrupt 0
		return false;
	}

	//Register<uint16> tmp = dx_ax / src;
	uint32 tmp = dx_ax / src;

	if (tmp > 0xFFFF) {
		//interrupt 0
		return false;
	}
	else {
		ax = tmp; //FIXME - this has a linking problem
		dx = dx_ax % src;
	}

	return true;
}

void
ArithmeticLogicUnit::opIdiv (uint8 src) {
	Register<uint16> ax = p->m_eunit->getRegAX ();
	Register<uint8> &al = p->m_eunit->getRegAL ();
	Register<uint8> &ah = p->m_eunit->getRegAH ();

	if (src == 0) {
		//FIXME - interrupt 0
		std::cerr << "FIXME: ALU::opDiv (): interrupt 0" << std::endl;
		return;
	}

	int8 tmp = (int16)ax / (int8)src;
	//if ((tmp > 0x7F) || (tmp < 0x80)) {
	//	//FIXME - interrupt 0
	//}
	//else {
		al = tmp;
		ah = (int16)ax % (int8)src;
	//}
}

void
ArithmeticLogicUnit::opIdiv (uint16 src) {
	Register<uint16> &ax = p->m_eunit->getRegAX ();
	Register<uint16> &dx = p->m_eunit->getRegDX ();
	uint32 dx_ax = dx;
	dx_ax <<= 16;
	dx_ax += ax;

	if (src == 0) {
		//FIXME - interrupt 0
		std::cerr << "FIXME: ALU::opDiv (): interrupt 0" << std::endl;
		return;
	}

	int16 tmp = (int32)dx_ax / (int16)src;
	//if ((tmp > 0x7FFF) || (tmp < 0x8000)) {
	//	//FIXME - interrupt 0
	//}
	//else {
		ax = tmp;
		dx = (int32)dx_ax % (int16)tmp;
	//}
}

void
ArithmeticLogicUnit::opImul (uint8 src) {
	Register<uint16> &ax = p->m_eunit->getRegAX ();
	Register<uint8> &al = p->m_eunit->getRegAL ();
	Register<uint8> &ah = p->m_eunit->getRegAH ();

	ax = (int8)src * (int8)al;
	uint8 al_sign_ext = (Utility::getBit (al, (sizeof(uint8) << 3) - 1)) ? 0xFF : 0;

	if (ah == al_sign_ext) {
		p->m_eunit->setRegFlagsCF (false);
	}
	else {
		p->m_eunit->setRegFlagsCF (true);
		p->m_eunit->setRegFlagsOF (true);
	}
}

void
ArithmeticLogicUnit::opImul (uint16 src) {
	Register<uint16> &ax = p->m_eunit->getRegAX ();
	Register<uint16> &dx = p->m_eunit->getRegDX ();
	uint32 dx_ax = dx;
	dx_ax <<= 16;
	dx_ax += ax;
	uint16 *dx_ax_ptr = (uint16*)&dx_ax;

	dx_ax = (int16)src * (int16)ax;
	p->m_eunit->setRegAX (dx_ax_ptr[0]);
	p->m_eunit->setRegDX (dx_ax_ptr[1]);
	uint16 ax_sign_ext = (Utility::getBit (ax, (sizeof(uint16) << 3) - 1)) ? 0xFFFF : 0;

	if (dx == ax_sign_ext) {
		p->m_eunit->setRegFlagsCF (false);
	}
	else {
		p->m_eunit->setRegFlagsCF (true);
		p->m_eunit->setRegFlagsOF (true);
	}
}

void
ArithmeticLogicUnit::opInc (uint8 dest, uint8 &ret) {
	uint8 orig_dest = dest;
	uint16 result = ++dest;
	ret = (uint8)result;

	//FIXME - fix flags
	//updateFlagAddAF (ret);
	updateFlagAddOF (orig_dest, 1, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opInc (uint16 dest, uint16 &ret) {
	uint16 orig_dest = dest;
	uint32 result = ++dest;
	ret = (uint16)result;

	//FIXME - fix flags
	//updateFlagAddAF (ret);
	updateFlagAddOF (orig_dest, 1, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opMul (uint8 src) {
	Register<uint16> &ax = p->m_eunit->getRegAX ();
	Register<uint8> &al = p->m_eunit->getRegAL ();
	Register<uint8> &ah = p->m_eunit->getRegAH ();

	ax = src * al;

	if (ah == 0) {
		p->m_eunit->setRegFlagsCF (false);
	}
	else {
		p->m_eunit->setRegFlagsCF (true);
		p->m_eunit->setRegFlagsOF (true);
	}
}

void
ArithmeticLogicUnit::opMul (uint16 src) {
	Register<uint16> &ax = p->m_eunit->getRegAX ();
	Register<uint16> &dx = p->m_eunit->getRegDX ();
	uint32 dx_ax = dx;
	dx_ax <<= 16;
	dx_ax += ax;
	uint16 *dx_ax_ptr = (uint16*)&dx_ax;

	dx_ax = src * ax;
	p->m_eunit->setRegAX (dx_ax_ptr[0]);
	p->m_eunit->setRegDX (dx_ax_ptr[1]);

	if (dx == 0) {
		p->m_eunit->setRegFlagsCF (false);
	}
	else {
		p->m_eunit->setRegFlagsCF (true);
		p->m_eunit->setRegFlagsOF (true);
	}
}

void
ArithmeticLogicUnit::opNeg (uint8 dest, uint8 &ret) {
	dest = ~dest;
	uint8 r;
	opAdd (dest, 1, r);

	ret = (uint8)r;
}

void
ArithmeticLogicUnit::opNeg (uint16 dest, uint16 &ret) {
	dest = ~dest;
	uint16 r;
	opAdd (dest, 1, r);

	ret = (uint16)r;
}

void
ArithmeticLogicUnit::opOr (uint8 dest, uint8 src, uint8 &ret) {
	uint16 result = dest | src;
	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	ret = (uint8)result;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opOr (uint16 dest, uint16 src, uint16 &ret) {
	uint32 result = dest | src;
	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	ret = (uint16)result;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opRcl (uint8 dest, uint32 cnt, uint8 &ret) {
	uint32 tmp_cnt = cnt;
	bool tmpCF;
	while (tmp_cnt != 0) {
		tmpCF = p->m_eunit->getRegFlagsCF ();
		p->m_eunit->setRegFlagsCF (Utility::getMsb (dest)); //msb
		dest <<= 1;
		dest += tmpCF;
		tmp_cnt -= 1;
	}

	if (tmp_cnt == 1) {
		//of = msb(dest) ^ cf
		p->m_eunit->setRegFlagsOF (Utility::getMsb (dest) ^ p->m_eunit->getRegFlagsCF ());
	}

	ret = (uint8)dest;
}

void
ArithmeticLogicUnit::opRcl (uint16 dest, uint32 cnt, uint16 &ret) {
	uint32 tmp_cnt = cnt;
	bool tmpCF;
	while (tmp_cnt != 0) {
		tmpCF = p->m_eunit->getRegFlagsCF ();
		p->m_eunit->setRegFlagsCF (Utility::getMsb (dest)); //msb
		dest <<= 1;
		dest += tmpCF;
		tmp_cnt -= 1;
	}

	if (tmp_cnt == 1) {
		//of = msb(dest) ^ cf
		p->m_eunit->setRegFlagsOF (Utility::getMsb (dest) ^ p->m_eunit->getRegFlagsCF ());
	}

	ret = (uint16)dest;
}

void
ArithmeticLogicUnit::opRcr (uint8 dest, uint32 cnt, uint8 &ret) {
	uint32 tmp_cnt = cnt;
	bool tmpCF;
	while (tmp_cnt != 0) {
		tmpCF = p->m_eunit->getRegFlagsCF ();
		p->m_eunit->setRegFlagsCF (Utility::getLsb (dest)); //lsb
		dest >>= 1;
		Utility::setBit (dest, (sizeof(dest) << 3) - 1, tmpCF);
		tmp_cnt -= 1;
	}

	if (tmp_cnt == 1) {
		//of = lsb(dest) ^ cf
		p->m_eunit->setRegFlagsOF (Utility::getLsb (dest) ^ p->m_eunit->getRegFlagsCF ());
	}

	ret = (uint8)dest;
}

void
ArithmeticLogicUnit::opRcr (uint16 dest, uint32 cnt, uint16 &ret) {
	uint32 tmp_cnt = cnt;
	bool tmpCF;
	while (tmp_cnt != 0) {
		tmpCF = p->m_eunit->getRegFlagsCF ();
		p->m_eunit->setRegFlagsCF (Utility::getLsb (dest)); //lsb
		dest >>= 1;
		Utility::setBit (dest, (sizeof(dest) << 3) - 1, tmpCF);
		tmp_cnt -= 1;
	}

	if (tmp_cnt == 1) {
		//of = lsb(dest) ^ cf
		p->m_eunit->setRegFlagsOF (Utility::getLsb (dest) ^ p->m_eunit->getRegFlagsCF ());
	}

	ret = (uint16)dest;
}

void
ArithmeticLogicUnit::opRol (uint8 dest, uint8 cnt, uint8 &ret) {
	uint8 tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getMsb (dest));
		dest <<= 1;
		dest += p->m_eunit->getRegFlagsCF ();
		tmp_cnt -= 1;
	}

	ret = (uint8)dest;
}

void
ArithmeticLogicUnit::opRol (uint16 dest, uint8 cnt, uint16 &ret) {
	uint8 tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getMsb (dest));
		dest <<= 1;
		dest += p->m_eunit->getRegFlagsCF ();
		tmp_cnt -= 1;
	}

	ret = (uint16)dest;
}

void
ArithmeticLogicUnit::opRor (uint8 dest, uint8 cnt, uint8 &ret) {
	uint8 tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getLsb (dest));
		dest >>= 1;
		Utility::setBit (dest, (sizeof(dest) << 3) - 1, p->m_eunit->getRegFlagsCF ());
		tmp_cnt -= 1;
	}

	ret = (uint8)dest;
}

void
ArithmeticLogicUnit::opRor (uint16 dest, uint8 cnt, uint16 &ret) {
	uint8 tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getLsb (dest));
		dest >>= 1;
		Utility::setBit (dest, (sizeof(dest) << 3) - 1, p->m_eunit->getRegFlagsCF ());
		tmp_cnt -= 1;
	}

	ret = (uint16)dest;
}

void
ArithmeticLogicUnit::opSal (uint8 dest, uint32 cnt, uint8 &ret) {
	uint32 tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getMsb (dest));
		dest <<= 1;
		tmp_cnt -= 1;
	}

	ret = (uint8)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opSal (uint16 dest, uint32 cnt, uint16 &ret) {
	uint32 tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getMsb (dest));
		dest <<= 1;
		tmp_cnt -= 1;
	}

	ret = (uint16)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opSar (uint8 dest, uint32 cnt, uint8 &ret) {
	uint32 tmp_cnt = cnt;
	bool tmp_msb = Utility::getMsb (dest);
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getLsb (dest));
		dest >>= 1;
		Utility::setBit (dest, (sizeof(dest) << 3) - 1, tmp_msb);
		tmp_cnt -= 1;
	}

	ret = (uint8)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opSar (uint16 dest, uint32 cnt, uint16 &ret) {
	uint32 tmp_cnt = cnt;
	bool tmp_msb = Utility::getMsb (dest);
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getLsb (dest));
		dest >>= 1;
		Utility::setBit (dest, (sizeof(dest) << 3) - 1, tmp_msb);
		tmp_cnt -= 1;
	}

	ret = (uint16)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opSbb (uint8 dest, uint8 src, uint8 &ret) {
	uint8 orig_dest = dest;
	bool cf = p->m_eunit->getRegFlagsCF ();

	int16 result = dest - src - cf;

	ret = (uint8)result;

	//FIXME - fix flags
	//updateFlagSubAF (ret);
	updateFlagSubCF (ret, result);
	updateFlagSubOF (orig_dest, src, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opSbb (uint16 dest, uint16 src, uint16 &ret) {
	uint16 orig_dest = dest;
	bool cf = p->m_eunit->getRegFlagsCF ();

	int32 result = dest - src - cf;

	ret = (uint16)result;

	//FIXME - fix flags
	//updateFlagSubAF (ret);
	updateFlagSubCF (ret, result);
	updateFlagSubOF (orig_dest, src, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opShl (uint8 dest, uint32 cnt, uint8 &ret) {
	uint32 tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getMsb (dest));
		dest <<= 1;
		tmp_cnt -= 1;
	}

	ret = (uint8)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opShl (uint16 dest, uint32 cnt, uint16 &ret) {
	uint32 tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getMsb (dest));
		dest <<= 1;
		tmp_cnt -= 1;
	}

	ret = (uint16)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opShr (uint8 dest, uint32 cnt, uint8 &ret) {
	uint32 tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getLsb (dest));
		dest >>= 1;
		tmp_cnt -= 1;
	}

	ret = (uint8)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opShr (uint16 dest, uint32 cnt, uint16 &ret) {
	uint32 tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getLsb (dest));
		dest >>= 1;
		tmp_cnt -= 1;
	}

	ret = (uint16)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opSub (uint8 dest, uint8 src, uint8 &ret) {
	uint8 orig_dest = dest;
	int16 result = dest - src;
	ret = (uint8)result;

	//FIXME - fix flags
	//updateFlagSubAF (ret);
	updateFlagSubCF (ret, result);
	updateFlagSubOF (orig_dest, src, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opSub (uint16 dest, uint16 src, uint16 &ret) {
	uint16 orig_dest = dest;
	int32 result = dest - src;
	ret = (uint16)result;

	//FIXME - fix flags
	//updateFlagSubAF (ret);
	updateFlagSubCF (ret, result);
	updateFlagSubOF (orig_dest, src, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opTest (uint8 dest, uint8 src) {
	uint16 result = dest & src;
	uint8 ret = (uint8)result;

	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opTest (uint16 dest, uint16 src) {
	uint32 result = dest & src;
	uint16 ret = (uint16)result;

	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opXor (uint8 dest, uint8 src, uint8 &ret) {
	uint16 result = dest ^ src;
	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	ret = (uint8)result;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opXor (uint16 dest, uint16 src, uint16 &ret) {
	uint32 result = dest ^ src;
	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	ret = (uint16)result;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

