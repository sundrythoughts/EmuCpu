#include "ExecutionUnit.hh"
#include <iostream>

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
	ExecutionUnit cpu;
	int TEST_NUMBER = 0;

	{//Test 1
		++TEST_NUMBER;
		ps = true;
		cpu.set_reg_ah (1);
		cpu.set_reg_al (1);
		if (cpu.get_reg_ax () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 1


	{//Test 2
		++TEST_NUMBER;
		ps = true;
		cpu.set_reg_bh (1);
		cpu.set_reg_bl (1);
		if (cpu.get_reg_bx () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 2


	{//Test 3
		++TEST_NUMBER;
		ps = true;
		cpu.set_reg_ch (1);
		cpu.set_reg_cl (1);
		if (cpu.get_reg_cx () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 3


	{//Test 4
		++TEST_NUMBER;
		ps = true;
		cpu.set_reg_ch (1);
		cpu.set_reg_cl (1);
		if (cpu.get_reg_cx () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 4


	{//Test 5
		++TEST_NUMBER;
		ps = true;
		cpu.set_reg_ax (257);

		if (cpu.get_reg_ah () != 1) {
			print_failed (TEST_NUMBER);
		}
		if (cpu.get_reg_al () != 1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 5


	{//Test 6
		++TEST_NUMBER;
		ps = true;
		cpu.set_reg_bx (257);

		if (cpu.get_reg_bh () != 1) {
			print_failed (TEST_NUMBER);
		}
		if (cpu.get_reg_bl () != 1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 6


	{//Test 7
		++TEST_NUMBER;
		ps = true;
		cpu.set_reg_cx (257);

		if (cpu.get_reg_ch () != 1) {
			print_failed (TEST_NUMBER);
		}
		if (cpu.get_reg_cl () != 1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 7


	{//Test 8
		++TEST_NUMBER;
		ps = true;
		cpu.set_reg_dx (257);

		if (cpu.get_reg_dh () != 1) {
			print_failed (TEST_NUMBER);
		}
		if (cpu.get_reg_dl () != 1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 8


	{//Test 9
		++TEST_NUMBER;
		ps = true;
		cpu.set_reg_ax (257);

		if (cpu.get_reg_ax () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 9


	{//Test 10
		++TEST_NUMBER;
		ps = true;
		cpu.set_reg_bx (257);

		if (cpu.get_reg_bx () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 10


	{//Test 11
		++TEST_NUMBER;
		ps = true;
		cpu.set_reg_cx (257);

		if (cpu.get_reg_cx () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 11


	{//Test 12
		++TEST_NUMBER;
		ps = true;
		cpu.set_reg_dx (257);

		if (cpu.get_reg_dx () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 12


	{//Test 13
		++TEST_NUMBER;
		ps = true;
		cpu.set_reg_di (257);

		if (cpu.get_reg_di () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 13

	{//Test 14
		++TEST_NUMBER;
		ps = true;
		cpu.set_reg_si (257);

		if (cpu.get_reg_si () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 14


	{//Test 15
		++TEST_NUMBER;
		ps = true;
		cpu.set_reg_bp (257);

		if (cpu.get_reg_bp () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 15


	{//Test 16
		++TEST_NUMBER;
		ps = true;
		cpu.set_reg_sp (257);

		if (cpu.get_reg_sp () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 16


	{//Test 17
		++TEST_NUMBER;
		ps = true;
		cpu.set_reg_flags (257);

		if (cpu.get_reg_flags () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 17


	{//Test 18
		++TEST_NUMBER;
		ps = true;

		cpu.set_reg_flags_af (true);
		if (cpu.get_reg_flags_af () != true) {
			print_failed (TEST_NUMBER);
		}

		cpu.set_reg_flags_af (false);
		if (cpu.get_reg_flags_af () != false) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 18


	{//Test 19
		++TEST_NUMBER;
		ps = true;

		cpu.set_reg_flags_cf (true);
		if (cpu.get_reg_flags_cf () != true) {
			print_failed (TEST_NUMBER);
		}

		cpu.set_reg_flags_cf (false);
		if (cpu.get_reg_flags_cf () != false) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 19


	{//Test 20
		++TEST_NUMBER;
		ps = true;

		cpu.set_reg_flags_df (true);
		if (cpu.get_reg_flags_df () != true) {
			print_failed (TEST_NUMBER);
		}

		cpu.set_reg_flags_df (false);
		if (cpu.get_reg_flags_df () != false) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 20


	{//Test 21
		++TEST_NUMBER;
		ps = true;

		cpu.set_reg_flags_if (true);
		if (cpu.get_reg_flags_if () != true) {
			print_failed (TEST_NUMBER);
		}

		cpu.set_reg_flags_if (false);
		if (cpu.get_reg_flags_if () != false) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 21


	{//Test 22
		++TEST_NUMBER;
		ps = true;

		cpu.set_reg_flags_of (true);
		if (cpu.get_reg_flags_of () != true) {
			print_failed (TEST_NUMBER);
		}

		cpu.set_reg_flags_of (false);
		if (cpu.get_reg_flags_of () != false) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 22


	{//Test 23
		++TEST_NUMBER;
		ps = true;

		cpu.set_reg_flags_pf (true);
		if (cpu.get_reg_flags_pf () != true) {
			print_failed (TEST_NUMBER);
		}

		cpu.set_reg_flags_pf (false);
		if (cpu.get_reg_flags_pf () != false) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 23


	{//Test 24
		++TEST_NUMBER;
		ps = true;

		cpu.set_reg_flags_sf (true);
		if (cpu.get_reg_flags_sf () != true) {
			print_failed (TEST_NUMBER);
		}

		cpu.set_reg_flags_sf (false);
		if (cpu.get_reg_flags_sf () != false) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 24


	{//Test 25
		++TEST_NUMBER;
		ps = true;

		cpu.set_reg_flags_tf (true);
		if (cpu.get_reg_flags_tf () != true) {
			print_failed (TEST_NUMBER);
		}

		cpu.set_reg_flags_tf (false);
		if (cpu.get_reg_flags_tf () != false) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 25


	{//Test 26
		++TEST_NUMBER;
		ps = true;

		cpu.set_reg_flags_zf (true);
		if (cpu.get_reg_flags_zf () != true) {
			print_failed (TEST_NUMBER);
		}

		cpu.set_reg_flags_zf (false);
		if (cpu.get_reg_flags_zf () != false) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 26
}

