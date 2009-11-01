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
//#include <iostream>

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
ArithmeticLogicUnit::updateFlagCF (unsigned char result8, unsigned short result16) {
	//p->m_eunit->setRegFlagsCF (result8 == result16);
	p->m_eunit->setRegFlagsCF (result16 > 0xFF);
}

void
ArithmeticLogicUnit::updateFlagCF (unsigned short result16, unsigned int result32) {
	//p->m_eunit->setRegFlagsCF (result16 == result32);
	p->m_eunit->setRegFlagsCF (result32 > 0xFFFF);
}

void
ArithmeticLogicUnit::updateFlagOF (bool msb_before, bool msb_after) {
	p->m_eunit->setRegFlagsOF (msb_before != msb_after);
}

void
ArithmeticLogicUnit::updateFlagPF (unsigned char val) {
	unsigned int count = 0;
	//val &= 0xFF;
	while (val) {
		if (val & 1) {
			++count;
		}
		val >>= 1;
	}

	p->m_eunit->setRegFlagsPF (!(count & 1));
}

void
ArithmeticLogicUnit::updateFlagPF (unsigned short val) {
	unsigned int count = 0;
	//val &= 0xFF;
	while (val) {
		if (val & 1) {
			++count;
		}
		val >>= 1;
	}

	p->m_eunit->setRegFlagsPF (!(count & 1));
}

void
ArithmeticLogicUnit::updateFlagSF (unsigned char val) {
	p->m_eunit->setRegFlagsSF (Utility::get_bit (val, sizeof(val) - 1));
}

void
ArithmeticLogicUnit::updateFlagSF (unsigned short val) {
	p->m_eunit->setRegFlagsSF (Utility::get_bit (val, sizeof(val) - 1));
}

void
ArithmeticLogicUnit::updateFlagZF (unsigned char val) {
	p->m_eunit->setRegFlagsZF (!val);
}

void
ArithmeticLogicUnit::updateFlagZF (unsigned short val) {
	p->m_eunit->setRegFlagsZF (!val);
}

void
ArithmeticLogicUnit::opAdc (unsigned char dest, unsigned char src, unsigned char &ret) {
	bool cf = p->m_eunit->getRegFlagsCF ();
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);

	unsigned short result = dest + src;
	if (cf) {
		result += 1;
	}

	ret = (unsigned char)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opAdc (unsigned short dest, unsigned short src, unsigned short &ret) {
	bool cf = p->m_eunit->getRegFlagsCF ();
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);

	unsigned int result = dest + src;
	if (cf) {
		result += 1;
	}

	ret = (unsigned short)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opAdd (unsigned char dest, unsigned char src, unsigned char &ret) {
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);
	unsigned short result = dest + src;

	ret = (unsigned char)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opAdd (unsigned short dest, unsigned short src, unsigned short &ret) {
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);
	unsigned int result = dest + src;

	ret = (unsigned short)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opAnd (unsigned char dest, unsigned char src, unsigned char &ret) {
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);
	unsigned short result = dest & src;
	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	ret = (unsigned char)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opAnd (unsigned short dest, unsigned short src, unsigned short &ret) {
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);
	unsigned int result = dest & src;
	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	ret = (unsigned short)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
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
ArithmeticLogicUnit::opCmp (unsigned char dest, unsigned char src) {
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);
	unsigned short result = dest - src;
	unsigned char ret = (unsigned short)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opCmp (unsigned short dest, unsigned short src) {
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);
	unsigned int result = dest - src;
	unsigned short ret = (unsigned short)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

#if 0
/** FIXME */
template<typename TDest, typename TSrc>
void cmps (TDest &dest, TSrc &src, TDest &result);
#endif

void
ArithmeticLogicUnit::opDec (unsigned char dest, unsigned char &ret) {
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);
	unsigned short result = --dest;
	ret = (unsigned char)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opDec (unsigned short dest, unsigned short &ret) {
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);
	unsigned int result = --dest;
	ret = (unsigned short)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opDiv (unsigned char src) {
	Register<unsigned short> ax = p->m_eunit->getRegAX ();
	Register<unsigned char> &al = p->m_eunit->getRegAL ();
	Register<unsigned char> &ah = p->m_eunit->getRegAH ();

	if (src == 0) {
		//FIXME - interrupt 0
	}

	Register<unsigned char> tmp = ax / src;

	if (tmp > 0xFF) {
		//FIXME - interrupt 0
	}
	else {
		al = tmp; //FIXME - this has a problem
		ah = ax % src;
	}
}

void
ArithmeticLogicUnit::opDiv (unsigned short src) {
	Register<unsigned short> &ax = p->m_eunit->getRegAX ();
	Register<unsigned short> &dx = p->m_eunit->getRegDX ();

	unsigned int dx_ax = dx;
	dx_ax <<= 16;
	dx_ax += ax;

	if (src == 0) {
		//FIXME - interrupt 0
	}

	Register<unsigned short> tmp = dx_ax / src;

	if (tmp > (unsigned short)0xFFFF) {
		//FIXME - interrupt 0
	}

	else {
		ax = tmp; //FIXME - this has a linking problem
		dx = dx_ax % src;
	}
}

void
ArithmeticLogicUnit::opIdiv (unsigned char src) {
	Register<unsigned short> ax = p->m_eunit->getRegAX ();
	Register<unsigned char> &al = p->m_eunit->getRegAL ();
	Register<unsigned char> &ah = p->m_eunit->getRegAH ();

	if (src == 0) {
		//FIXME - interrupt 0
	}

	char tmp = (short)ax / (char)src;
	//if ((tmp > 0x7F) || (tmp < 0x80)) {
	//	//FIXME - interrupt 0
	//}
	//else {
		al = tmp;
		ah = (short)ax % (char)src;
	//}
}

void
ArithmeticLogicUnit::opIdiv (unsigned short src) {
	Register<unsigned short> &ax = p->m_eunit->getRegAX ();
	Register<unsigned short> &dx = p->m_eunit->getRegDX ();
	unsigned int dx_ax = dx;
	dx_ax <<= 16;
	dx_ax += ax;

	if (src == 0) {
		//FIXME - interrupt 0
	}

	short tmp = (int)dx_ax / (short)src;
	//if ((tmp > 0x7FFF) || (tmp < 0x8000)) {
	//	//FIXME - interrupt 0
	//}
	//else {
		ax = tmp;
		dx = (int)dx_ax % (short)tmp;
	//}
}

void
ArithmeticLogicUnit::opImul (unsigned char src) {
	Register<unsigned short> &ax = p->m_eunit->getRegAX ();
	Register<unsigned char> &al = p->m_eunit->getRegAL ();
	Register<unsigned char> &ah = p->m_eunit->getRegAH ();

	ax = (char)src * (char)al;
	unsigned char al_sign_ext = (Utility::get_bit (al, sizeof(unsigned char) - 1)) ? 0xFF : 0;

	if (ah == al_sign_ext) {
		p->m_eunit->setRegFlagsCF (false);
	}
	else {
		p->m_eunit->setRegFlagsCF (true);
		p->m_eunit->setRegFlagsOF (true);
	}
}

void
ArithmeticLogicUnit::opImul (unsigned short src) {
	Register<unsigned short> &ax = p->m_eunit->getRegAX ();
	Register<unsigned short> &dx = p->m_eunit->getRegDX ();
	unsigned int dx_ax = dx;
	dx_ax <<= 16;
	dx_ax += ax;
	unsigned short *dx_ax_ptr = (unsigned short*)&dx_ax;

	dx_ax = (short)src * (short)ax;
	p->m_eunit->setRegAX (dx_ax_ptr[0]);
	p->m_eunit->setRegDX (dx_ax_ptr[1]);
	unsigned short ax_sign_ext = (Utility::get_bit (ax, sizeof(unsigned short) - 1)) ? 0xFFFF : 0;

	if (dx == ax_sign_ext) {
		p->m_eunit->setRegFlagsCF (false);
	}
	else {
		p->m_eunit->setRegFlagsCF (true);
		p->m_eunit->setRegFlagsOF (true);
	}
}

void
ArithmeticLogicUnit::opInc (unsigned char dest, unsigned char &ret) {
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);
	unsigned short result = ++dest;
	ret = (unsigned char)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opInc (unsigned short dest, unsigned short &ret) {
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);
	unsigned int result = ++dest;
	ret = (unsigned short)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opMul (unsigned char src) {
	Register<unsigned short> &ax = p->m_eunit->getRegAX ();
	Register<unsigned char> &al = p->m_eunit->getRegAL ();
	Register<unsigned char> &ah = p->m_eunit->getRegAH ();

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
ArithmeticLogicUnit::opMul (unsigned short src) {
	Register<unsigned short> &ax = p->m_eunit->getRegAX ();
	Register<unsigned short> &dx = p->m_eunit->getRegDX ();
	unsigned int dx_ax = dx;
	dx_ax <<= 16;
	dx_ax += ax;
	unsigned short *dx_ax_ptr = (unsigned short*)&dx_ax;

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
ArithmeticLogicUnit::opNeg (unsigned char dest, unsigned char &ret) {
	dest = ~dest;
	unsigned char r;
	opAdd (dest, 1, r);

	ret = (unsigned char)r;
}

void
ArithmeticLogicUnit::opNeg (unsigned short dest, unsigned short &ret) {
	dest = ~dest;
	unsigned short r;
	opAdd (dest, 1, r);

	ret = (unsigned short)r;
}

void
ArithmeticLogicUnit::opOr (unsigned char dest, unsigned char src, unsigned char &ret) {
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);
	unsigned short result = dest | src;
	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	ret = (unsigned char)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opOr (unsigned short dest, unsigned short src, unsigned short &ret) {
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);
	unsigned int result = dest | src;
	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	ret = (unsigned short)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opRcl (unsigned char dest, unsigned int cnt, unsigned char &ret) {
	unsigned int tmp_cnt = cnt;
	bool tmpCF;
	while (tmp_cnt != 0) {
		tmpCF = p->m_eunit->getRegFlagsCF ();
		p->m_eunit->setRegFlagsCF (Utility::get_bit (dest, (sizeof(dest) << 3) - 1)); //msb
		dest <<= 1;
		dest += tmpCF;
		tmp_cnt -= 1;
	}

	if (tmp_cnt == 1) {
		//of = msb(dest) ^ cf
		p->m_eunit->setRegFlagsOF (Utility::get_bit (dest, (sizeof(dest) << 3) - 1) ^ p->m_eunit->getRegFlagsCF ());
	}

	ret = (unsigned char)dest;
}

void
ArithmeticLogicUnit::opRcl (unsigned short dest, unsigned int cnt, unsigned short &ret) {
	unsigned int tmp_cnt = cnt;
	bool tmpCF;
	while (tmp_cnt != 0) {
		tmpCF = p->m_eunit->getRegFlagsCF ();
		p->m_eunit->setRegFlagsCF (Utility::get_bit (dest, (sizeof(dest) << 3) - 1)); //msb
		dest <<= 1;
		dest += tmpCF;
		tmp_cnt -= 1;
	}

	if (tmp_cnt == 1) {
		//of = msb(dest) ^ cf
		p->m_eunit->setRegFlagsOF (Utility::get_bit (dest, (sizeof(dest) << 3) - 1) ^ p->m_eunit->getRegFlagsCF ());
	}

	ret = (unsigned short)dest;
}

void
ArithmeticLogicUnit::opRcr (unsigned char dest, unsigned int cnt, unsigned char &ret) {
	unsigned int tmp_cnt = cnt;
	bool tmpCF;
	while (tmp_cnt != 0) {
		tmpCF = p->m_eunit->getRegFlagsCF ();
		p->m_eunit->setRegFlagsCF (Utility::get_bit (dest, 0)); //msb
		dest >>= 1;
		Utility::set_bit (dest, (sizeof(dest) << 3) - 1, tmpCF);
		tmp_cnt -= 1;
	}

	if (tmp_cnt == 1) {
		//of = lsb(dest) ^ cf
		p->m_eunit->setRegFlagsOF (Utility::get_bit (dest, 0) ^ p->m_eunit->getRegFlagsCF ());
	}

	ret = (unsigned char)dest;
}

void
ArithmeticLogicUnit::opRcr (unsigned short dest, unsigned int cnt, unsigned short &ret) {
	unsigned int tmp_cnt = cnt;
	bool tmpCF;
	while (tmp_cnt != 0) {
		tmpCF = p->m_eunit->getRegFlagsCF ();
		p->m_eunit->setRegFlagsCF (Utility::get_bit (dest, 0)); //msb
		dest >>= 1;
		Utility::set_bit (dest, (sizeof(dest) << 3) - 1, tmpCF);
		tmp_cnt -= 1;
	}

	if (tmp_cnt == 1) {
		//of = lsb(dest) ^ cf
		p->m_eunit->setRegFlagsOF (Utility::get_bit (dest, 0) ^ p->m_eunit->getRegFlagsCF ());
	}

	ret = (unsigned short)dest;
}

void
ArithmeticLogicUnit::opRol (unsigned char dest, unsigned int cnt, unsigned char &ret) {
	unsigned int tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::get_bit (dest, (sizeof(dest) << 3) - 1));
		dest <<= 1;
		dest += p->m_eunit->getRegFlagsCF ();
		tmp_cnt -= 1;
	}

	ret = (unsigned char)dest;
}

void
ArithmeticLogicUnit::opRol (unsigned short dest, unsigned int cnt, unsigned short &ret) {
	unsigned int tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::get_bit (dest, (sizeof(dest) << 3) - 1));
		dest <<= 1;
		dest += p->m_eunit->getRegFlagsCF ();
		tmp_cnt -= 1;
	}

	ret = (unsigned short)dest;
}

void
ArithmeticLogicUnit::opRor (unsigned char dest, unsigned int cnt, unsigned char &ret) {
	unsigned int tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::get_bit (dest, 0));
		dest >>= 1;
		Utility::set_bit (dest, (sizeof(dest) << 3) - 1, p->m_eunit->getRegFlagsCF ());
		tmp_cnt -= 1;
	}

	ret = (unsigned char)dest;
}

void
ArithmeticLogicUnit::opRor (unsigned short dest, unsigned int cnt, unsigned short &ret) {
	unsigned int tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::get_bit (dest, 0));
		dest >>= 1;
		Utility::set_bit (dest, (sizeof(dest) << 3) - 1, p->m_eunit->getRegFlagsCF ());
		tmp_cnt -= 1;
	}

	ret = (unsigned short)dest;
}

void
ArithmeticLogicUnit::opSal (unsigned char dest, unsigned int cnt, unsigned char &ret) {
	unsigned int tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::get_bit (dest, (sizeof(dest) << 3) - 1));
		dest <<= 1;
		tmp_cnt -= 1;
	}

	ret = (unsigned char)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opSal (unsigned short dest, unsigned int cnt, unsigned short &ret) {
	unsigned int tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::get_bit (dest, (sizeof(dest) << 3) - 1));
		dest <<= 1;
		tmp_cnt -= 1;
	}

	ret = (unsigned short)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opSar (unsigned char dest, unsigned int cnt, unsigned char &ret) {
	unsigned int tmp_cnt = cnt;
	bool tmp_msb = Utility::get_bit (dest, (sizeof(dest) << 3) - 1);
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::get_bit (dest, 0));
		dest >>= 1;
		Utility::set_bit (dest, (sizeof(dest) << 3) - 1, tmp_msb);
		tmp_cnt -= 1;
	}

	ret = (unsigned char)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opSar (unsigned short dest, unsigned int cnt, unsigned short &ret) {
	unsigned int tmp_cnt = cnt;
	bool tmp_msb = Utility::get_bit (dest, (sizeof(dest) << 3) - 1);
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::get_bit (dest, 0));
		dest >>= 1;
		Utility::set_bit (dest, (sizeof(dest) << 3) - 1, tmp_msb);
		tmp_cnt -= 1;
	}

	ret = (unsigned short)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opSbb (unsigned char dest, unsigned char src, unsigned char &ret) {
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);
	bool cf = p->m_eunit->getRegFlagsCF ();

	unsigned short result = dest - src - cf;

	ret = (unsigned char)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opSbb (unsigned short dest, unsigned short src, unsigned short &ret) {
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);
	bool cf = p->m_eunit->getRegFlagsCF ();

	unsigned int result = dest - src - cf;

	ret = (unsigned short)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opShl (unsigned char dest, unsigned int cnt, unsigned char &ret) {
	unsigned int tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::get_bit (dest, (sizeof(dest) << 3) - 1));
		dest <<= 1;
		tmp_cnt -= 1;
	}

	ret = (unsigned char)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opShl (unsigned short dest, unsigned int cnt, unsigned short &ret) {
	unsigned int tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::get_bit (dest, (sizeof(dest) << 3) - 1));
		dest <<= 1;
		tmp_cnt -= 1;
	}

	ret = (unsigned short)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opShr (unsigned char dest, unsigned int cnt, unsigned char &ret) {
	unsigned int tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::get_bit (dest, 0));
		dest >>= 1;
		tmp_cnt -= 1;
	}

	ret = (unsigned char)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opShr (unsigned short dest, unsigned int cnt, unsigned short &ret) {
	unsigned int tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::get_bit (dest, 0));
		dest >>= 1;
		tmp_cnt -= 1;
	}

	ret = (unsigned short)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opSub (unsigned char dest, unsigned char src, unsigned char &ret) {
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);
	unsigned short result = dest - src;
	ret = (unsigned char)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opSub (unsigned short dest, unsigned char src, unsigned short &ret) {
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);
	unsigned int result = dest - src;
	ret = (unsigned short)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opTest (unsigned char dest, unsigned char src) {
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);
	unsigned short result = dest & src;
	unsigned char ret = (unsigned char)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opTest (unsigned short dest, unsigned char src) {
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);
	unsigned int result = dest & src;
	unsigned short ret = (unsigned short)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opXor (unsigned char dest, unsigned char src, unsigned char &ret) {
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);
	unsigned short result = dest ^ src;
	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	ret = (unsigned char)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opXor (unsigned short dest, unsigned short src, unsigned short &ret) {
	bool msb_before = Utility::get_bit (dest, sizeof(dest) - 1);
	unsigned int result = dest ^ src;
	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	ret = (unsigned short)result;

	//FIXME - fix flags
	updateFlagCF (ret, result);
	updateFlagOF (msb_before, Utility::get_bit (ret, sizeof(ret) - 1));
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

