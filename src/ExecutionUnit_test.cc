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


#include "ExecutionUnit.hh"
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

template<typename T>
static void value_changed (const T& val) {
	cout << "value_changed: " << val << endl;
}

int main (int argc, char **argv) {
	ExecutionUnit cpu;

	//return 0;
	//cpu.getRegAX ().signal_value_changed ().connect (sigc::ptr_fun (&value_changed<unsigned short>));

	int TEST_NUMBER = 0;

	{//Test 1
		++TEST_NUMBER;
		ps = true;
		cpu.setRegAH (1);
		cpu.setRegAL (1);
		if (cpu.getRegAX () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 1


	{//Test 2
		++TEST_NUMBER;
		ps = true;
		cpu.setRegBH (1);
		cpu.setRegBL (1);
		if (cpu.getRegBX () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 2


	{//Test 3
		++TEST_NUMBER;
		ps = true;
		cpu.setRegCH (1);
		cpu.setRegCL (1);
		if (cpu.getRegCX () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 3


	{//Test 4
		++TEST_NUMBER;
		ps = true;
		cpu.setRegCH (1);
		cpu.setRegCL (1);
		if (cpu.getRegCX () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 4


	{//Test 5
		++TEST_NUMBER;
		ps = true;
		cpu.setRegAX (257);

		if (cpu.getRegAH () != 1) {
			print_failed (TEST_NUMBER);
		}
		if (cpu.getRegAL () != 1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 5


	{//Test 6
		++TEST_NUMBER;
		ps = true;
		cpu.setRegBX (257);

		if (cpu.getRegBH () != 1) {
			print_failed (TEST_NUMBER);
		}
		if (cpu.getRegBL () != 1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 6


	{//Test 7
		++TEST_NUMBER;
		ps = true;
		cpu.setRegCX (257);

		if (cpu.getRegCH () != 1) {
			print_failed (TEST_NUMBER);
		}
		if (cpu.getRegCL () != 1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 7


	{//Test 8
		++TEST_NUMBER;
		ps = true;
		cpu.setRegDX (257);

		if (cpu.getRegDH () != 1) {
			print_failed (TEST_NUMBER);
		}
		if (cpu.getRegDL () != 1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 8


	{//Test 9
		++TEST_NUMBER;
		ps = true;
		cpu.setRegAX (257);

		if (cpu.getRegAX () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 9


	{//Test 10
		++TEST_NUMBER;
		ps = true;
		cpu.setRegBX (257);

		if (cpu.getRegBX () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 10


	{//Test 11
		++TEST_NUMBER;
		ps = true;
		cpu.setRegCX (257);

		if (cpu.getRegCX () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 11


	{//Test 12
		++TEST_NUMBER;
		ps = true;
		cpu.setRegDX (257);

		if (cpu.getRegDX () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 12


	{//Test 13
		++TEST_NUMBER;
		ps = true;
		cpu.setRegDI (257);

		if (cpu.getRegDI () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 13

	{//Test 14
		++TEST_NUMBER;
		ps = true;
		cpu.setRegSI (257);

		if (cpu.getRegSI () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 14


	{//Test 15
		++TEST_NUMBER;
		ps = true;
		cpu.setRegBP (257);

		if (cpu.getRegBP () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 15


	{//Test 16
		++TEST_NUMBER;
		ps = true;
		cpu.setRegSP (257);

		if (cpu.getRegSP () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 16


	{//Test 17
		++TEST_NUMBER;
		ps = true;
		cpu.setRegFlags (257);

		if (cpu.getRegFlags () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 17


	{//Test 18
		++TEST_NUMBER;
		ps = true;

		cpu.setRegFlagsAF (true);
		if (cpu.getRegFlagsAF () != true) {
			print_failed (TEST_NUMBER);
		}

		cpu.setRegFlagsAF (false);
		if (cpu.getRegFlagsAF () != false) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 18


	{//Test 19
		++TEST_NUMBER;
		ps = true;

		cpu.setRegFlagsCF (true);
		if (cpu.getRegFlagsCF () != true) {
			print_failed (TEST_NUMBER);
		}

		cpu.setRegFlagsCF (false);
		if (cpu.getRegFlagsCF () != false) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 19


	{//Test 20
		++TEST_NUMBER;
		ps = true;

		cpu.setRegFlagsDF (true);
		if (cpu.getRegFlagsDF () != true) {
			print_failed (TEST_NUMBER);
		}

		cpu.setRegFlagsDF (false);
		if (cpu.getRegFlagsDF () != false) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 20


	{//Test 21
		++TEST_NUMBER;
		ps = true;

		cpu.setRegFlagsIF (true);
		if (cpu.getRegFlagsIF () != true) {
			print_failed (TEST_NUMBER);
		}

		cpu.setRegFlagsIF (false);
		if (cpu.getRegFlagsIF () != false) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 21


	{//Test 22
		++TEST_NUMBER;
		ps = true;

		cpu.setRegFlagsOF (true);
		if (cpu.getRegFlagsOF () != true) {
			print_failed (TEST_NUMBER);
		}

		cpu.setRegFlagsOF (false);
		if (cpu.getRegFlagsOF () != false) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 22


	{//Test 23
		++TEST_NUMBER;
		ps = true;

		cpu.setRegFlagsPF (true);
		if (cpu.getRegFlagsPF () != true) {
			print_failed (TEST_NUMBER);
		}

		cpu.setRegFlagsPF (false);
		if (cpu.getRegFlagsPF () != false) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 23


	{//Test 24
		++TEST_NUMBER;
		ps = true;

		cpu.setRegFlagsSF (true);
		if (cpu.getRegFlagsSF () != true) {
			print_failed (TEST_NUMBER);
		}

		cpu.setRegFlagsSF (false);
		if (cpu.getRegFlagsSF () != false) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 24


	{//Test 25
		++TEST_NUMBER;
		ps = true;

		cpu.setRegFlagsTF (true);
		if (cpu.getRegFlagsTF () != true) {
			print_failed (TEST_NUMBER);
		}

		cpu.setRegFlagsTF (false);
		if (cpu.getRegFlagsTF () != false) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 25


	{//Test 26
		++TEST_NUMBER;
		ps = true;

		cpu.setRegFlagsZF (true);
		if (cpu.getRegFlagsZF () != true) {
			print_failed (TEST_NUMBER);
		}

		cpu.setRegFlagsZF (false);
		if (cpu.getRegFlagsZF () != false) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 26
}

