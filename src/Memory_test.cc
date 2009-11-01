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
	int TEST_NUMBER = 0;

	{//Test 1
		++TEST_NUMBER;
		ps = true;
		unsigned int addr = 0;
		int src = 250;
		int dest;
		mem.write (addr, src);
		if (!mem.read (addr, dest)) {
			print_failed (TEST_NUMBER);
		}
		if (src != dest) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 1


	{//Test 2
		++TEST_NUMBER;
		ps = true;
		unsigned int addr = 1048575;
		char src = 'J';
		char dest;
		mem.write (addr, src);
		if (!mem.read (addr, dest)) {
			print_failed (TEST_NUMBER);
		}
		if (src != dest) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 2


	{//Test 3
		++TEST_NUMBER;
		ps = true;
		unsigned int addr = 1048575;
		int src = 10;
		int dest;
		mem.write (addr, src);
		if (mem.read (addr, dest)) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 3

	{//Test 4
		++TEST_NUMBER;
		ps = true;

		unsigned int addr = 0;
		mem.write (addr, 0x10203040);
		addr = 10;
		mem.write (addr, (short)0x1234);

		mem.print_memory_dump (0, 12);

		addr = 1048575;
		mem.write (addr, (unsigned char)0x72);
		mem.print_memory_dump (1048570, 1048576);

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 4
}

