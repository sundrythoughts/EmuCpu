#include "BusInterfaceUnit.hh"
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
	Memory mem (1048576);
	BusInterfaceUnit biu;
	biu.connect_to (mem);
	int TEST_NUMBER = 0;

	{//Test 1
		++TEST_NUMBER;
		ps = true;
		biu.set_sreg_cs (257);

		if (biu.get_sreg_cs () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 1


	{//Test 2
		++TEST_NUMBER;
		ps = true;
		biu.set_sreg_ds (257);

		if (biu.get_sreg_ds () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 2


	{//Test 3
		++TEST_NUMBER;
		ps = true;
		biu.set_sreg_es (257);

		if (biu.get_sreg_es () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 3


	{//Test 4
		++TEST_NUMBER;
		ps = true;
		biu.set_sreg_ss (257);

		if (biu.get_sreg_ss () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 4


	{//Test 5
		++TEST_NUMBER;
		ps = true;
		biu.set_reg_ip (257);

		if (biu.get_reg_ip () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 5

	{//Test 6
		++TEST_NUMBER;
		ps = true;
		unsigned short seg = 0;
		unsigned short offset = 0;
		int src = 250;
		int *dest;
		biu.write (seg, offset, src);
		if (!biu.read (seg, offset, dest)) {
			print_failed (TEST_NUMBER);
		}
		if (src != *dest) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 6


	{//Test 7
		++TEST_NUMBER;
		ps = true;
		unsigned short seg = 0xF000;
		unsigned short offset = 0xFFFF;
		char src = 'J';
		char *dest;
		biu.write (seg, offset, src);
		if (!biu.read (seg, offset, dest)) {
			print_failed (TEST_NUMBER);
		}
		if (src != *dest) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 7


	{//Test 8
		++TEST_NUMBER;
		ps = true;
		unsigned short seg = 0xF000;
		unsigned short offset = 0xFFFF;
		int src = 10;
		int *dest;
		biu.write (seg, offset, src);
		if (biu.read (seg, offset, dest)) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 8

	{//Test 9
		++TEST_NUMBER;
		ps = true;

		unsigned short seg = 0x0;
		unsigned short offset = 0x0;
		if (!biu.write (seg, offset, 0x10203040)) {
			print_failed (TEST_NUMBER);
		}
		offset = 10;
		if (!biu.write (seg, offset, (short)0x1234)) {
			print_failed (TEST_NUMBER);
		}

		mem.print_memory_dump (0, 12);

		seg = 0xF000;
		offset = 0xFFFF;
		if (!biu.write (seg, offset, (unsigned char)0x72)) {
			print_failed (TEST_NUMBER);
		}
		mem.print_memory_dump (1048570, 1048576);

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 9
}

