#include "MemoryAddress.hh"
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

	MemoryAddress<long int> addr (&mem, 0, 16);
	addr = 0;
	addr += 1048575;

	mem.print_memory_dump (0, 25);
}

