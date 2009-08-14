#include "ArithmeticLogicUnit.hh"
#include "ExecutionUnit.hh"
#include "BusInterfaceUnit.hh"
#include "Memory.hh"
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
	ExecutionUnit eu;
	eu.connect_to (biu);
	ArithmeticLogicUnit alu;
	alu.connect_to (eu);
	int TEST_NUMBER = 0;

	{//Test 1
		++TEST_NUMBER;
		ps = true;

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 1
}
