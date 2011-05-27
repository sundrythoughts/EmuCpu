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
ArithmeticLogicUnit::updateFlagAddAF (quint8 result8) {
	p->m_eunit->setRegFlagsAF (result8 > (result8 & 0xF));
}

void
ArithmeticLogicUnit::updateFlagSubAF (qint8 result8) {
	p->m_eunit->setRegFlagsAF (result8 & 0x08); //FIXME
}

void
ArithmeticLogicUnit::updateFlagAddCF (quint8 result8, quint16 result16) {
	p->m_eunit->setRegFlagsCF (result16 > 0xFF);
}

void
ArithmeticLogicUnit::updateFlagAddCF (quint16 result16, quint32 result32) {
	p->m_eunit->setRegFlagsCF (result32 > 0xFFFF);
}

void
ArithmeticLogicUnit::updateFlagSubCF (quint8 result8, qint16 result16) {
	p->m_eunit->setRegFlagsCF (result16 < 0);
}

void
ArithmeticLogicUnit::updateFlagSubCF (quint16 result16, qint32 result32) {
	p->m_eunit->setRegFlagsCF (result32 < 0);
}

void
ArithmeticLogicUnit::updateFlagAddOF (quint8 orig_dest, quint8 src, quint8 dest) {
	bool a = Utility::getMsb (orig_dest);
	bool b = Utility::getMsb (src);
	bool c = Utility::getMsb (dest);
	p->m_eunit->setRegFlagsOF (a == b && a != c);
}

void
ArithmeticLogicUnit::updateFlagAddOF (quint16 orig_dest, quint16 src, quint16 dest) {
	bool a = Utility::getMsb (orig_dest);
	bool b = Utility::getMsb (src);
	bool c = Utility::getMsb (dest);
	p->m_eunit->setRegFlagsOF (a == b && a != c);
}

void
ArithmeticLogicUnit::updateFlagSubOF (quint8 orig_dest, quint8 src, quint8 dest) {
	bool a = Utility::getMsb (orig_dest);
	bool b = Utility::getMsb (src);
	bool c = Utility::getMsb (dest);
	p->m_eunit->setRegFlagsOF (a != b && a != c);
}

void
ArithmeticLogicUnit::updateFlagSubOF (quint16 orig_dest, quint16 src, quint16 dest) {
	bool a = Utility::getMsb (orig_dest);
	bool b = Utility::getMsb (src);
	bool c = Utility::getMsb (dest);
	p->m_eunit->setRegFlagsOF (a != b && a != c);
}

void
ArithmeticLogicUnit::updateFlagPF (quint8 val) {
	quint32 count = 0;
	while (val) {
		if (val & 1) {
			++count;
		}
		val >>= 1;
	}

	p->m_eunit->setRegFlagsPF (!(count & 1));
}

void
ArithmeticLogicUnit::updateFlagSF (quint8 val) {
	p->m_eunit->setRegFlagsSF (Utility::getMsb (val));
}

void
ArithmeticLogicUnit::updateFlagSF (quint16 val) {
	p->m_eunit->setRegFlagsSF (Utility::getMsb (val));
}

void
ArithmeticLogicUnit::updateFlagZF (quint8 val) {
	p->m_eunit->setRegFlagsZF (!val);
}

void
ArithmeticLogicUnit::updateFlagZF (quint16 val) {
	p->m_eunit->setRegFlagsZF (!val);
}

void
ArithmeticLogicUnit::opAdc (quint8 dest, quint8 src, quint8 &ret) {
	bool cf = p->m_eunit->getRegFlagsCF ();
	quint8 orig_dest = dest;

	quint16 result = dest + src;
	if (cf) {
		result += 1;
	}

	ret = (quint8)result;

	//FIXME - fix flags
	updateFlagAddCF (ret, result);
	updateFlagAddOF (orig_dest, src, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opAdc (quint16 dest, quint16 src, quint16 &ret) {
	bool cf = p->m_eunit->getRegFlagsCF ();
	quint16 orig_dest = dest;

	quint32 result = dest + src;
	if (cf) {
		result += 1;
	}

	ret = (quint16)result;

	//FIXME - fix flags
	//updateFlagAddAF (ret);
	updateFlagAddCF (ret, result);
	updateFlagAddOF (orig_dest, src, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opAdd (quint8 dest, quint8 src, quint8 &ret) {
	quint8 orig_dest = dest;
	quint16 result = dest + src;

	ret = (quint8)result;

	//FIXME - fix flags
	//updateFlagAddAF (ret);
	updateFlagAddCF (ret, result);
	updateFlagAddOF (orig_dest, src, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opAdd (quint16 dest, quint16 src, quint16 &ret) {
	quint16 orig_dest = dest;
	quint32 result = dest + src;

	ret = (quint16)result;

	//FIXME - fix flags
	//updateFlagAddAF (ret);
	updateFlagAddCF (ret, result);
	updateFlagAddOF (orig_dest, src, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opAnd (quint8 dest, quint8 src, quint8 &ret) {
	quint16 result = dest & src;
	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	ret = (quint8)result;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opAnd (quint16 dest, quint16 src, quint16 &ret) {
	quint32 result = dest & src;
	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	ret = (quint16)result;

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
ArithmeticLogicUnit::opCmp (quint8 dest, quint8 src) {
	quint8 orig_dest = dest;
	qint16 result = (qint8)dest - (qint8)src;
	quint8 ret = dest - src;

	//FIXME - fix flags
	//updateFlagSubAF (ret);
	updateFlagSubCF (ret, result);
	updateFlagSubOF (orig_dest, src, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opCmp (quint16 dest, quint16 src) {
	quint16 orig_dest = dest;
	qint32 result = dest - src;
	quint16 ret = dest - src;

	//FIXME - fix flags
	//updateFlagSubAF (ret);
	updateFlagSubCF (ret, result);
	updateFlagSubOF (orig_dest, src, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opDec (quint8 dest, quint8 &ret) {
	quint8 orig_dest = dest;
	qint16 result = --dest;
	ret = (quint8)result;

	//FIXME - fix flags
	//updateFlagSubAF (ret);
	updateFlagSubOF (orig_dest, 1, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opDec (quint16 dest, quint16 &ret) {
	quint16 orig_dest = dest;
	qint32 result = --dest;
	ret = (quint16)result;

	//FIXME - fix flags
	//updateFlagSubAF (ret);
	updateFlagSubOF (orig_dest, 1, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

bool
ArithmeticLogicUnit::opDiv (quint8 src) {
	Register<quint16> ax = p->m_eunit->getRegAX ();
	Register<quint8> &al = p->m_eunit->getRegAL ();
	Register<quint8> &ah = p->m_eunit->getRegAH ();

	if (src == 0) {
		//interrupt 0
		return false;
	}

	//Register<quint8> tmp = ax / src;
	quint16 tmp = ax / src;

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
ArithmeticLogicUnit::opDiv (quint16 src) {
	Register<quint16> &ax = p->m_eunit->getRegAX ();
	Register<quint16> &dx = p->m_eunit->getRegDX ();

	quint32 dx_ax = dx;
	dx_ax <<= 16;
	dx_ax += ax;

	if (src == 0) {
		//interrupt 0
		return false;
	}

	//Register<quint16> tmp = dx_ax / src;
	quint32 tmp = dx_ax / src;

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
ArithmeticLogicUnit::opIdiv (quint8 src) {
	Register<quint16> ax = p->m_eunit->getRegAX ();
	Register<quint8> &al = p->m_eunit->getRegAL ();
	Register<quint8> &ah = p->m_eunit->getRegAH ();

	if (src == 0) {
		//FIXME - interrupt 0
		std::cerr << "FIXME: ALU::opDiv (): interrupt 0" << std::endl;
		return;
	}

	qint8 tmp = (qint16)ax / (qint8)src;
	//if ((tmp > 0x7F) || (tmp < 0x80)) {
	//	//FIXME - interrupt 0
	//}
	//else {
		al = tmp;
		ah = (qint16)ax % (qint8)src;
	//}
}

void
ArithmeticLogicUnit::opIdiv (quint16 src) {
	Register<quint16> &ax = p->m_eunit->getRegAX ();
	Register<quint16> &dx = p->m_eunit->getRegDX ();
	quint32 dx_ax = dx;
	dx_ax <<= 16;
	dx_ax += ax;

	if (src == 0) {
		//FIXME - interrupt 0
		std::cerr << "FIXME: ALU::opDiv (): interrupt 0" << std::endl;
		return;
	}

	qint16 tmp = (qint32)dx_ax / (qint16)src;
	//if ((tmp > 0x7FFF) || (tmp < 0x8000)) {
	//	//FIXME - interrupt 0
	//}
	//else {
		ax = tmp;
		dx = (qint32)dx_ax % (qint16)tmp;
	//}
}

void
ArithmeticLogicUnit::opImul (quint8 src) {
	Register<quint16> &ax = p->m_eunit->getRegAX ();
	Register<quint8> &al = p->m_eunit->getRegAL ();
	Register<quint8> &ah = p->m_eunit->getRegAH ();

	ax = (qint8)src * (qint8)al;
	quint8 al_sign_ext = (Utility::getBit (al, (sizeof(quint8) << 3) - 1)) ? 0xFF : 0;

	if (ah == al_sign_ext) {
		p->m_eunit->setRegFlagsCF (false);
	}
	else {
		p->m_eunit->setRegFlagsCF (true);
		p->m_eunit->setRegFlagsOF (true);
	}
}

void
ArithmeticLogicUnit::opImul (quint16 src) {
	Register<quint16> &ax = p->m_eunit->getRegAX ();
	Register<quint16> &dx = p->m_eunit->getRegDX ();
	quint32 dx_ax = dx;
	dx_ax <<= 16;
	dx_ax += ax;
	quint16 *dx_ax_ptr = (quint16*)&dx_ax;

	dx_ax = (qint16)src * (qint16)ax;
	p->m_eunit->setRegAX (dx_ax_ptr[0]);
	p->m_eunit->setRegDX (dx_ax_ptr[1]);
	quint16 ax_sign_ext = (Utility::getBit (ax, (sizeof(quint16) << 3) - 1)) ? 0xFFFF : 0;

	if (dx == ax_sign_ext) {
		p->m_eunit->setRegFlagsCF (false);
	}
	else {
		p->m_eunit->setRegFlagsCF (true);
		p->m_eunit->setRegFlagsOF (true);
	}
}

void
ArithmeticLogicUnit::opInc (quint8 dest, quint8 &ret) {
	quint8 orig_dest = dest;
	quint16 result = ++dest;
	ret = (quint8)result;

	//FIXME - fix flags
	//updateFlagAddAF (ret);
	updateFlagAddOF (orig_dest, 1, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opInc (quint16 dest, quint16 &ret) {
	quint16 orig_dest = dest;
	quint32 result = ++dest;
	ret = (quint16)result;

	//FIXME - fix flags
	//updateFlagAddAF (ret);
	updateFlagAddOF (orig_dest, 1, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opMul (quint8 src) {
	Register<quint16> &ax = p->m_eunit->getRegAX ();
	Register<quint8> &al = p->m_eunit->getRegAL ();
	Register<quint8> &ah = p->m_eunit->getRegAH ();

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
ArithmeticLogicUnit::opMul (quint16 src) {
	Register<quint16> &ax = p->m_eunit->getRegAX ();
	Register<quint16> &dx = p->m_eunit->getRegDX ();
	quint32 dx_ax = dx;
	dx_ax <<= 16;
	dx_ax += ax;
	quint16 *dx_ax_ptr = (quint16*)&dx_ax;

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
ArithmeticLogicUnit::opNeg (quint8 dest, quint8 &ret) {
	dest = ~dest;
	quint8 r;
	opAdd (dest, 1, r);

	ret = (quint8)r;
}

void
ArithmeticLogicUnit::opNeg (quint16 dest, quint16 &ret) {
	dest = ~dest;
	quint16 r;
	opAdd (dest, 1, r);

	ret = (quint16)r;
}

void
ArithmeticLogicUnit::opOr (quint8 dest, quint8 src, quint8 &ret) {
	quint16 result = dest | src;
	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	ret = (quint8)result;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opOr (quint16 dest, quint16 src, quint16 &ret) {
	quint32 result = dest | src;
	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	ret = (quint16)result;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opRcl (quint8 dest, quint32 cnt, quint8 &ret) {
	quint32 tmp_cnt = cnt;
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

	ret = (quint8)dest;
}

void
ArithmeticLogicUnit::opRcl (quint16 dest, quint32 cnt, quint16 &ret) {
	quint32 tmp_cnt = cnt;
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

	ret = (quint16)dest;
}

void
ArithmeticLogicUnit::opRcr (quint8 dest, quint32 cnt, quint8 &ret) {
	quint32 tmp_cnt = cnt;
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

	ret = (quint8)dest;
}

void
ArithmeticLogicUnit::opRcr (quint16 dest, quint32 cnt, quint16 &ret) {
	quint32 tmp_cnt = cnt;
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

	ret = (quint16)dest;
}

void
ArithmeticLogicUnit::opRol (quint8 dest, quint8 cnt, quint8 &ret) {
	quint8 tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getMsb (dest));
		dest <<= 1;
		dest += p->m_eunit->getRegFlagsCF ();
		tmp_cnt -= 1;
	}

	ret = (quint8)dest;
}

void
ArithmeticLogicUnit::opRol (quint16 dest, quint8 cnt, quint16 &ret) {
	quint8 tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getMsb (dest));
		dest <<= 1;
		dest += p->m_eunit->getRegFlagsCF ();
		tmp_cnt -= 1;
	}

	ret = (quint16)dest;
}

void
ArithmeticLogicUnit::opRor (quint8 dest, quint8 cnt, quint8 &ret) {
	quint8 tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getLsb (dest));
		dest >>= 1;
		Utility::setBit (dest, (sizeof(dest) << 3) - 1, p->m_eunit->getRegFlagsCF ());
		tmp_cnt -= 1;
	}

	ret = (quint8)dest;
}

void
ArithmeticLogicUnit::opRor (quint16 dest, quint8 cnt, quint16 &ret) {
	quint8 tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getLsb (dest));
		dest >>= 1;
		Utility::setBit (dest, (sizeof(dest) << 3) - 1, p->m_eunit->getRegFlagsCF ());
		tmp_cnt -= 1;
	}

	ret = (quint16)dest;
}

void
ArithmeticLogicUnit::opSal (quint8 dest, quint32 cnt, quint8 &ret) {
	quint32 tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getMsb (dest));
		dest <<= 1;
		tmp_cnt -= 1;
	}

	ret = (quint8)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opSal (quint16 dest, quint32 cnt, quint16 &ret) {
	quint32 tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getMsb (dest));
		dest <<= 1;
		tmp_cnt -= 1;
	}

	ret = (quint16)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opSar (quint8 dest, quint32 cnt, quint8 &ret) {
	quint32 tmp_cnt = cnt;
	bool tmp_msb = Utility::getMsb (dest);
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getLsb (dest));
		dest >>= 1;
		Utility::setBit (dest, (sizeof(dest) << 3) - 1, tmp_msb);
		tmp_cnt -= 1;
	}

	ret = (quint8)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opSar (quint16 dest, quint32 cnt, quint16 &ret) {
	quint32 tmp_cnt = cnt;
	bool tmp_msb = Utility::getMsb (dest);
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getLsb (dest));
		dest >>= 1;
		Utility::setBit (dest, (sizeof(dest) << 3) - 1, tmp_msb);
		tmp_cnt -= 1;
	}

	ret = (quint16)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opSbb (quint8 dest, quint8 src, quint8 &ret) {
	quint8 orig_dest = dest;
	bool cf = p->m_eunit->getRegFlagsCF ();

	qint16 result = dest - src - cf;

	ret = (quint8)result;

	//FIXME - fix flags
	//updateFlagSubAF (ret);
	updateFlagSubCF (ret, result);
	updateFlagSubOF (orig_dest, src, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opSbb (quint16 dest, quint16 src, quint16 &ret) {
	quint16 orig_dest = dest;
	bool cf = p->m_eunit->getRegFlagsCF ();

	qint32 result = dest - src - cf;

	ret = (quint16)result;

	//FIXME - fix flags
	//updateFlagSubAF (ret);
	updateFlagSubCF (ret, result);
	updateFlagSubOF (orig_dest, src, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opShl (quint8 dest, quint32 cnt, quint8 &ret) {
	quint32 tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getMsb (dest));
		dest <<= 1;
		tmp_cnt -= 1;
	}

	ret = (quint8)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opShl (quint16 dest, quint32 cnt, quint16 &ret) {
	quint32 tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getMsb (dest));
		dest <<= 1;
		tmp_cnt -= 1;
	}

	ret = (quint16)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opShr (quint8 dest, quint32 cnt, quint8 &ret) {
	quint32 tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getLsb (dest));
		dest >>= 1;
		tmp_cnt -= 1;
	}

	ret = (quint8)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opShr (quint16 dest, quint32 cnt, quint16 &ret) {
	quint32 tmp_cnt = cnt;
	while (tmp_cnt != 0) {
		p->m_eunit->setRegFlagsCF (Utility::getLsb (dest));
		dest >>= 1;
		tmp_cnt -= 1;
	}

	ret = (quint16)dest;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opSub (quint8 dest, quint8 src, quint8 &ret) {
	quint8 orig_dest = dest;
	qint16 result = dest - src;
	ret = (quint8)result;

	//FIXME - fix flags
	//updateFlagSubAF (ret);
	updateFlagSubCF (ret, result);
	updateFlagSubOF (orig_dest, src, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opSub (quint16 dest, quint16 src, quint16 &ret) {
	quint16 orig_dest = dest;
	qint32 result = dest - src;
	ret = (quint16)result;

	//FIXME - fix flags
	//updateFlagSubAF (ret);
	updateFlagSubCF (ret, result);
	updateFlagSubOF (orig_dest, src, ret);
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opTest (quint8 dest, quint8 src) {
	quint16 result = dest & src;
	quint8 ret = (quint8)result;

	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opTest (quint16 dest, quint16 src) {
	quint32 result = dest & src;
	quint16 ret = (quint16)result;

	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opXor (quint8 dest, quint8 src, quint8 &ret) {
	quint16 result = dest ^ src;
	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	ret = (quint8)result;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

void
ArithmeticLogicUnit::opXor (quint16 dest, quint16 src, quint16 &ret) {
	quint32 result = dest ^ src;
	p->m_eunit->setRegFlagsCF (false);
	p->m_eunit->setRegFlagsOF (false);

	ret = (quint16)result;

	//FIXME - fix flags
	updateFlagPF (ret);
	updateFlagSF (ret);
	updateFlagZF (ret);
}

