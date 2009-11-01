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
#include "ExecutionUnit.hh"
#include "BusInterfaceUnit.hh"
#include "Memory.hh"
#include <iostream>
#include <cstdio>

using namespace std;

static bool ps;

static void print_passed (int i) {
	cout << "Test " << i << ": Passed" << endl;
}

static void print_failed (int i) {
	cout << "Test " << i << ": Failed" << endl;
	ps = false;
}

int main (int argc, char **argv) {
	Memory mem;
	mem.resize (1048576);
	BusInterfaceUnit biu;
	biu.connectTo (mem);
	ExecutionUnit eu;
	eu.connectTo (biu);
	ArithmeticLogicUnit alu;
	alu.connectTo (eu);
	int TEST_NUMBER = 0;

	{//Test 1
		++TEST_NUMBER;
		ps = true;

		eu.setRegFlagsCF (true);
		unsigned char ret;
	//	cout << "here" << endl;
		alu.opAdc (3, 5, ret);

		if (ret != 9) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 1


	{//Test 2
		++TEST_NUMBER;
		ps = true;

		eu.setRegFlagsCF (true);
		unsigned short ret;
		alu.opAdc (3, 5, ret);

		if (ret != 9) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 2


	{//Test 3
		++TEST_NUMBER;
		ps = true;

		unsigned char ret;
		alu.opAdd (3, 5, ret);

		if (ret != 8) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 3


	{//Test 4
		++TEST_NUMBER;
		ps = true;

		unsigned short ret;
		alu.opAdd (3, 5, ret);

		if (ret != 8) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 4


	{//Test 5
		++TEST_NUMBER;
		ps = true;

		unsigned char ret;
		alu.opAnd (3, 5, ret);

		if (ret != 1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 5


	{//Test 6
		++TEST_NUMBER;
		ps = true;

		unsigned short ret;
		alu.opAnd (3, 5, ret);

		if (ret != 1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 6


	{//Test 7
		++TEST_NUMBER;
		ps = true;

		eu.setRegFlagsCF (true);
		alu.opCmc ();

		if (eu.getRegFlagsCF () != false) {
			print_failed (TEST_NUMBER);
		}

		alu.opCmc ();

		if (eu.getRegFlagsCF () != true) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 7


	{//Test 8
		++TEST_NUMBER;
		ps = true;

		unsigned char ret;
		alu.opCmp ((unsigned char)5, (unsigned char)3);

		if (true) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 8


	{//Test 9
		++TEST_NUMBER;
		ps = true;

		unsigned short ret;
		alu.opCmp ((unsigned short)5, (unsigned short)3);

		if (true) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 9


	{//Test 10
		++TEST_NUMBER;
		ps = true;

		unsigned char ret;
		alu.opDec (5, ret);

		if (ret != 4) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 10


	{//Test 11
		++TEST_NUMBER;
		ps = true;

		unsigned short ret;
		alu.opDec (5, ret);

		if (ret != 4) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 11


	{//Test 12
		++TEST_NUMBER;
		ps = true;

		eu.setRegAX (17);
		alu.opDiv ((unsigned char)3);
		unsigned char al = eu.getRegAL ();
		unsigned char ah = eu.getRegAH ();

		if (al != 5) {
			print_failed (TEST_NUMBER);
		}

		if (ah != 2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 12


	{//Test 13
		++TEST_NUMBER;
		ps = true;

		eu.setRegDX (0);
		eu.setRegAX (17);
		alu.opDiv ((unsigned short)3);
		unsigned short ax = eu.getRegAX ();
		unsigned short dx = eu.getRegDX ();

		if (ax != 5) {
			print_failed (TEST_NUMBER);
		}

		if (dx != 2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 13


	{//Test 14
		++TEST_NUMBER;
		ps = true;

		eu.setRegAX (17);
		alu.opIdiv ((unsigned char)-3);
		unsigned char al = eu.getRegAL ();
		unsigned char ah = eu.getRegAH ();

		if (al != (unsigned char)-5) {
			print_failed (TEST_NUMBER);
		}

		if (ah != (unsigned char)2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 14


	{//Test 15
		++TEST_NUMBER;
		ps = true;

		eu.setRegDX (0);
		eu.setRegAX (17);
		alu.opIdiv ((unsigned short)-3);
		unsigned short ax = eu.getRegAX ();
		unsigned short dx = eu.getRegDX ();

		if (ax != (unsigned short)-5) {
			print_failed (TEST_NUMBER);
		}

		if (dx != (unsigned short)2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 15


	{//Test 16
		++TEST_NUMBER;
		ps = true;

		eu.setRegAL (-5);
		alu.opImul ((unsigned char)3);
		unsigned short ax = eu.getRegAX ();

		if (ax != (unsigned short)-15) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 16


	{//Test 17
		++TEST_NUMBER;
		ps = true;

		eu.setRegAX (-5);
		alu.opImul ((unsigned short)3);

		unsigned int dx_ax;
		unsigned short *dx_ax_ptr = (unsigned short*)&dx_ax;

		unsigned short ax = eu.getRegAX ();
		unsigned short dx = eu.getRegDX ();

		dx_ax_ptr[0] = ax;
		dx_ax_ptr[1] = dx;

		if (dx_ax != (unsigned int)-15) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 17


	{//Test 18
		++TEST_NUMBER;
		ps = true;

		unsigned char ret;
		alu.opInc (5, ret);

		if (ret != 6) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 18


	{//Test 19
		++TEST_NUMBER;
		ps = true;

		unsigned short ret;
		alu.opInc (5, ret);

		if (ret != 6) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 19


	{//Test 20
		++TEST_NUMBER;
		ps = true;

		eu.setRegAL (5);
		alu.opMul ((unsigned char)3);
		unsigned short ax = eu.getRegAX ();

		if (ax != 15) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 20


	{//Test 21
		++TEST_NUMBER;
		ps = true;

		eu.setRegAX (5);
		alu.opMul ((unsigned short)3);

		unsigned int dx_ax = 0;
		unsigned short *dx_ax_ptr = (unsigned short*)&dx_ax;

		unsigned short ax = eu.getRegAX ();
		unsigned short dx = eu.getRegDX ();

		dx_ax_ptr[0] = ax;
		dx_ax_ptr[1] = dx;

		//cout << dx << ":" << ax << " = " << dx_ax << endl;
		if (dx_ax != 15) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 21


	{//Test 22
		++TEST_NUMBER;
		ps = true;

		unsigned char ret;
		alu.opNeg (5, ret);

		if (ret != 0xFB) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 22


	{//Test 23
		++TEST_NUMBER;
		ps = true;

		unsigned short ret;
		alu.opNeg (5, ret);

		if (ret != 0xFFFB) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 23


	{//Test 24
		++TEST_NUMBER;
		ps = true;

		unsigned char ret;
		alu.opOr (3, 5, ret);

		if (ret != 7) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 24


	{//Test 25
		++TEST_NUMBER;
		ps = true;

		unsigned short ret;
		alu.opOr (3, 5, ret);

		if (ret != 7) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 25


	{//Test 26
		++TEST_NUMBER;
		ps = true;

		unsigned char ret;
		eu.setRegFlagsCF (true);
		alu.opRcl (2, 3, ret);

		if (ret != 0x14) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 26


	{//Test 27
		++TEST_NUMBER;
		ps = true;

		unsigned short ret;
		eu.setRegFlagsCF (true);
		alu.opRcl (2, 3, ret);

		if (ret != 0x0014) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 27


	{//Test 28
		++TEST_NUMBER;
		ps = true;

		unsigned char ret;
		eu.setRegFlagsCF (true);
		alu.opRcr (2, 3, ret);

		if (ret != 0xA0) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 28


	{//Test 29
		++TEST_NUMBER;
		ps = true;

		unsigned short ret;
		eu.setRegFlagsCF (true);
		alu.opRcr (2, 3, ret);

		if (ret != 0xA000) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 29


	{//Test 30
		++TEST_NUMBER;
		ps = true;

		unsigned char ret;
		alu.opRol (2, 3, ret);

		if (ret != 0x10) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 30


	{//Test 31
		++TEST_NUMBER;
		ps = true;

		unsigned short ret;
		alu.opRol (2, 3, ret);

		if (ret != 0x0010) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 31


	{//Test 32
		++TEST_NUMBER;
		ps = true;

		unsigned char ret;
		alu.opRor (2, 3, ret);

		if (ret != 0x40) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 32


	{//Test 33
		++TEST_NUMBER;
		ps = true;

		unsigned short ret;
		alu.opRor (2, 3, ret);

		if (ret != 0x4000) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 33


	{//Test 34
		++TEST_NUMBER;
		ps = true;

		unsigned char ret;
		alu.opSal (2, 3, ret);

		if (ret != 0x10) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 34


	{//Test 35
		++TEST_NUMBER;
		ps = true;

		unsigned short ret;
		alu.opSal (2, 3, ret);

		if (ret != 0x0010) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 35


	{//Test 36
		++TEST_NUMBER;
		ps = true;

		unsigned char ret;
		alu.opSar (0x80, 3, ret);

		if (ret != 0xF0) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 36


	{//Test 37
		++TEST_NUMBER;
		ps = true;

		unsigned short ret;
		alu.opSar (0x8000, 3, ret);

		if (ret != 0xF000) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 37


	{//Test 38
		++TEST_NUMBER;
		ps = true;

		eu.setRegFlagsCF (true);
		unsigned char ret;
		alu.opSbb (5, 3, ret);

		if (ret != 1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 38


	{//Test 39
		++TEST_NUMBER;
		ps = true;

		eu.setRegFlagsCF (true);
		unsigned short ret;
		alu.opSbb (5, 3, ret);

		if (ret != 1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 39


	{//Test 40
		++TEST_NUMBER;
		ps = true;

		unsigned char ret;
		alu.opShl (2, 3, ret);

		if (ret != 0x10) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 40


	{//Test 41
		++TEST_NUMBER;
		ps = true;

		unsigned short ret;
		alu.opShl (2, 3, ret);

		if (ret != 0x0010) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 41


	{//Test 42
		++TEST_NUMBER;
		ps = true;

		unsigned char ret;
		alu.opShr (0x80, 3, ret);

		if (ret != 0x10) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 42


	{//Test 43
		++TEST_NUMBER;
		ps = true;

		unsigned short ret;
		alu.opShr (0x8000, 3, ret);

		if (ret != 0x1000) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 43


	{//Test 44
		++TEST_NUMBER;
		ps = true;

		unsigned char ret;
		alu.opSub (5, 3, ret);

		if (ret != 2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 44


	{//Test 45
		++TEST_NUMBER;
		ps = true;

		unsigned short ret;
		alu.opSub (5, 3, ret);

		if (ret != 2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 45


	{//Test 46
		++TEST_NUMBER;
		ps = true;

		unsigned char ret;
		alu.opTest ((unsigned char)5, (unsigned char)3);

		if (true) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 46


	{//Test 47
		++TEST_NUMBER;
		ps = true;

		unsigned short ret;
		alu.opTest ((unsigned short)5, (unsigned short)3);

		if (true) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 47


	{//Test 48
		++TEST_NUMBER;
		ps = true;

		unsigned char ret;
		alu.opXor (3, 5, ret);

		if (ret != 6) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 48


	{//Test 49
		++TEST_NUMBER;
		ps = true;

		unsigned short ret;
		alu.opXor (3, 5, ret);

		if (ret != 6) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 49


	{//Test 50
		++TEST_NUMBER;
		ps = true;

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 50
}

