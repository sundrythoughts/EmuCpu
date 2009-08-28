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
	Memory mem (1048576);
	BusInterfaceUnit biu;
	biu.connect_to (mem);
	ExecutionUnit eu;
	eu.connect_to (biu);
	ArithmeticLogicUnit alu;
	alu.connect_to (eu);
	int TEST_NUMBER = 0;

	{//Test 1
		++TEST_NUMBER;
		ps = true;

		eu.set_reg_flags_cf (true);
		unsigned char ret;
		alu.op_adc_8 (3, 5, ret);

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

		eu.set_reg_flags_cf (true);
		unsigned short ret;
		alu.op_adc_16 (3, 5, ret);

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
		alu.op_add_8 (3, 5, ret);

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
		alu.op_add_16 (3, 5, ret);

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
		alu.op_and_8 (3, 5, ret);

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
		alu.op_and_16 (3, 5, ret);

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

		eu.set_reg_flags_cf (true);
		alu.op_cmc ();

		if (eu.get_reg_flags_cf () != false) {
			print_failed (TEST_NUMBER);
		}

		alu.op_cmc ();

		if (eu.get_reg_flags_cf () != true) {
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
		alu.op_cmp_8 (5, 3);

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
		alu.op_cmp_16 (5, 3);

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
		alu.op_dec_8 (5, ret);

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
		alu.op_dec_16 (5, ret);

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

		eu.set_reg_ax (17);
		alu.op_div_8 (3);
		unsigned char al = eu.get_reg_al ();
		unsigned char ah = eu.get_reg_ah ();

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

		eu.set_reg_dx (0);
		eu.set_reg_ax (17);
		alu.op_div_16 (3);
		unsigned short ax = eu.get_reg_ax ();
		unsigned short dx = eu.get_reg_dx ();

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

		eu.set_reg_ax (17);
		alu.op_idiv_8 (-3);
		unsigned char al = eu.get_reg_al ();
		unsigned char ah = eu.get_reg_ah ();

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

		eu.set_reg_dx (0);
		eu.set_reg_ax (17);
		alu.op_idiv_16 (-3);
		unsigned short ax = eu.get_reg_ax ();
		unsigned short dx = eu.get_reg_dx ();

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

		eu.set_reg_al (-5);
		alu.op_imul_8 (3);
		unsigned short ax = eu.get_reg_ax ();

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

		eu.set_reg_ax (-5);
		alu.op_imul_16 (3);

		unsigned int dx_ax;
		unsigned short *dx_ax_ptr = (unsigned short*)&dx_ax;

		unsigned short ax = eu.get_reg_ax ();
		unsigned short dx = eu.get_reg_dx ();

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
		alu.op_inc_8 (5, ret);

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
		alu.op_inc_16 (5, ret);

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

		eu.set_reg_al (5);
		alu.op_mul_8 (3);
		unsigned short ax = eu.get_reg_ax ();

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

		eu.set_reg_ax (5);
		alu.op_mul_16 (3);

		unsigned int dx_ax;
		unsigned short *dx_ax_ptr = (unsigned short*)&dx_ax;

		unsigned short ax = eu.get_reg_ax ();
		unsigned short dx = eu.get_reg_dx ();

		dx_ax_ptr[0] = ax;
		dx_ax_ptr[1] = dx;

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
		alu.op_neg_8 (5, ret);

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
		alu.op_neg_16 (5, ret);

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
		alu.op_or_8 (3, 5, ret);

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
		alu.op_or_16 (3, 5, ret);

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
		eu.set_reg_flags_cf (true);
		alu.op_rcl_8 (2, 3, ret);

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
		eu.set_reg_flags_cf (true);
		alu.op_rcl_16 (2, 3, ret);

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
		eu.set_reg_flags_cf (true);
		alu.op_rcr_8 (2, 3, ret);

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
		eu.set_reg_flags_cf (true);
		alu.op_rcr_16 (2, 3, ret);

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
		alu.op_rol_8 (2, 3, ret);

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
		alu.op_rol_16 (2, 3, ret);

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
		alu.op_ror_8 (2, 3, ret);

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
		alu.op_ror_16 (2, 3, ret);

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
		alu.op_sal_8 (2, 3, ret);

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
		alu.op_sal_16 (2, 3, ret);

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
		alu.op_sar_8 (0x80, 3, ret);

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
		alu.op_sar_16 (0x8000, 3, ret);

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

		eu.set_reg_flags_cf (true);
		unsigned char ret;
		alu.op_sbb_8 (5, 3, ret);

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

		eu.set_reg_flags_cf (true);
		unsigned short ret;
		alu.op_sbb_16 (5, 3, ret);

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
		alu.op_shl_8 (2, 3, ret);

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
		alu.op_shl_16 (2, 3, ret);

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
		alu.op_shr_8 (0x80, 3, ret);

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
		alu.op_shr_16 (0x8000, 3, ret);

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
		alu.op_sub_8 (5, 3, ret);

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
		alu.op_sub_16 (5, 3, ret);

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
		alu.op_test_8 (5, 3);

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
		alu.op_test_16 (5, 3);

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
		alu.op_xor_8 (3, 5, ret);

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
		alu.op_xor_16 (3, 5, ret);

		if (ret != 6) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 49
}

