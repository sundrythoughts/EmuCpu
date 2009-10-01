#include "Utility.hh"
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
	int TEST_NUMBER = 0;

	{//Test 1
		++TEST_NUMBER;
		ps = true;

		unsigned short n = 0;
		Utility::set_bit (n, 3);

		if (n != 8) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 1


	{//Test 2
		++TEST_NUMBER;
		ps = true;

		unsigned short n = ~0;
		Utility::clear_bit (n, 2);

		if (n != 0xFFFB) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 2

	{//Test 3
		++TEST_NUMBER;
		ps = true;

		unsigned short n = 0xF11F;
		bool b1 = Utility::get_bit (n, 0);
		bool b2 = Utility::get_bit (n, 4);
		bool b3 = Utility::get_bit (n, 7);

		if (b1 != 1) {
			print_failed (TEST_NUMBER);
		}

		if (b2 != 1) {
			print_failed (TEST_NUMBER);
		}

		if (b3 != 0) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 3
}

