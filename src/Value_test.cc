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


#include "Value.hh"
#include <iostream>
#include <string>
#include <vector>

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
	int TEST_NUMBER = 1;


	{//Test 1
		ps = true;
		Value v;
		if (!v.init<string> ()) {
			print_failed (TEST_NUMBER);
		}

		string s1 = "Joseph";

		if (!v.setValue (s1)) {
			print_failed (TEST_NUMBER);
		}

		string s2;

		if (!v.getValue (s2)) {
			print_failed (TEST_NUMBER);
		}

		if (s1 != s2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 1


	{//Test 2
		++TEST_NUMBER;

		ps = true;

		Value v;
		if (!v.init<string> ()) {
			print_failed (TEST_NUMBER);
		}

		string s1 = "Joseph";

		if (!v.setValue (s1)) {
			print_failed (TEST_NUMBER);
		}

		string s2;

		if (!v.getValue (s2)) {
			print_failed (TEST_NUMBER);
		}

		if (s1 != s2) {
			print_failed (TEST_NUMBER);
		}

		if (!v.free ()) {
			print_failed (TEST_NUMBER);
		}

		if (!v.init<int> ()) {
			print_failed (TEST_NUMBER);
		}

		int i1 = 13;

		if (!v.setValue (i1)) {
			print_failed (TEST_NUMBER);
		}

		int i2;

		if (!v.getValue (i2)) {
			print_failed (TEST_NUMBER);
		}

		if (i1 != i2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 2


	{//Test 3
		++TEST_NUMBER;

		ps = true;

		Value v1, v2;
		int i1, i2;
		if (!v1.init<int> ()) {
			print_failed (TEST_NUMBER);
		}

		if (!v2.init<int> ()) {
			print_failed (TEST_NUMBER);
		}

		if (!v1.setValue (5)) {
			print_failed (TEST_NUMBER);
		}

		if (!v1.copy (v2)) {
			print_failed (TEST_NUMBER);
		}


		if (!v2.setValue (13)) {
			print_failed (TEST_NUMBER);
		}

		if (!v1.getValue (i1)) {
			print_failed (TEST_NUMBER);
		}

		if (!v2.getValue (i2)) {
			print_failed (TEST_NUMBER);
		}

		if (i1 == i2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 3


	{//Test 4
		++TEST_NUMBER;

		ps = true;

		Value v;
		if (!v.init<int> ()) {
			print_failed (TEST_NUMBER);
		}

		int i = 10;

		if (!v.setValue (i)) {
			print_failed (TEST_NUMBER);
		}

		if (&i == v.getPointer ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 4


	{//Test 5
		++TEST_NUMBER;

		ps = true;

		Value v;
		int *i1 = new int ();
		*i1 = 17;

		if (!v.init<int*> (true)) {
			print_failed (TEST_NUMBER);
		}

		if (!v.setValue (i1)) {
			print_failed (TEST_NUMBER);
		}

		int *i2;
		if (!v.getValue (i2)) {
			print_failed (TEST_NUMBER);
		}

		if (i1 != i2) {
			print_failed (TEST_NUMBER);
		}

		if (*i1 != *i2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 5


	{//Test 6
		++TEST_NUMBER;

		ps = true;

		Value v;

		if (!v.init<void*> ()) {
			print_failed (TEST_NUMBER);
		}

		if (!v.setValue ((void*)0)) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 6


	{//Test 7
		++TEST_NUMBER;

		Value v;

		if (!v.init<int> ()) {
			print_failed (TEST_NUMBER);
		}

		if (!v.setValue (13)) {
			print_failed (TEST_NUMBER);
		}

		int opsz = 32;
		if (opsz == 16) {
			short i;
			if (!v.getValue (i)) {
				print_failed (TEST_NUMBER);
			}
		}
		else if (opsz == 32) {
			int i;
			if (!v.getValue (i)) {
				print_failed (TEST_NUMBER);
			}

			print_passed (TEST_NUMBER);
		}
		else if (opsz == 64) {
			long int i;
			if (!v.getValue (i)) {
				print_failed (TEST_NUMBER);
			}
		}
		else {
			print_failed (TEST_NUMBER);
		}

	}//end Test 7


	{//Test 8
		++TEST_NUMBER;

		ps = true;

		Value v;

		if (!v.init<std::string> ()) {
			print_failed (TEST_NUMBER);
		}

		if (!v.setValue (std::string ("Joseph Freeman"))) {
			print_failed (TEST_NUMBER);
		}

		std::string *sp;
		if (!v.getValuePointer (sp)) {
			print_failed (TEST_NUMBER);
		}

		if (sp != v.getPointer ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}		
	}//end Test 8

	{//Test 9
		++TEST_NUMBER;

		ps = true;

		vector<Value> v;
		v.resize (10);

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 9
}

