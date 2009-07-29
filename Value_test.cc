#include "Value.hh"
#include <iostream>
#include <string>

using namespace std;
using namespace Jaf;

static void print_passed (int i) {
	cout << "Test " << i << ": Passed" << endl;
}

static void print_failed (int i) {
	cout << "Test " << i << ": Failed" << endl;
}


int main (int argc, char **argv) {

	int TEST_NUMBER = 1;

	{//Test 1
		Value v;
		if (!v.init<string> ()) {
			print_failed (TEST_NUMBER);
		}

		string s1 = "Joseph";

		if (!v.set_value (s1)) {
			print_failed (TEST_NUMBER);
		}

		string s2;

		if (!v.get_value (s2)) {
			print_failed (TEST_NUMBER);
		}

		if (s1 != s2) {
			print_failed (TEST_NUMBER);
		}

		print_passed (TEST_NUMBER);
	}//end Test 1


	{//Test 2
		++TEST_NUMBER;

		Value v;
		if (!v.init<string> ()) {
			print_failed (TEST_NUMBER);
		}

		string s1 = "Joseph";

		if (!v.set_value (s1)) {
			print_failed (TEST_NUMBER);
		}

		string s2;

		if (!v.get_value (s2)) {
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

		if (!v.set_value (i1)) {
			print_failed (TEST_NUMBER);
		}

		int i2;

		if (!v.get_value (i2)) {
			print_failed (TEST_NUMBER);
		}

		if (i1 != i2) {
			print_failed (TEST_NUMBER);
		}

		print_passed (TEST_NUMBER);
	}//end Test 2


	{//Test 3
		++TEST_NUMBER;

		Value v1, v2;
		int i1, i2;
		if (!v1.init<int> ()) {
			print_failed (TEST_NUMBER);
		}

		if (!v2.init<int> ()) {
			print_failed (TEST_NUMBER);
		}

		if (!v1.set_value (5)) {
			print_failed (TEST_NUMBER);
		}

		if (!v1.copy (v2)) {
			print_failed (TEST_NUMBER);
		}


		if (!v2.set_value (13)) {
			print_failed (TEST_NUMBER);
		}

		if (!v1.get_value (i1)) {
			print_failed (TEST_NUMBER);
		}

		if (!v2.get_value (i2)) {
			print_failed (TEST_NUMBER);
		}

		if (i1 == i2) {
			print_failed (TEST_NUMBER);
		}

		print_passed (TEST_NUMBER);
	}//end Test 3


	{//Test 4
		++TEST_NUMBER;

		Value v;
		if (!v.init<int> ()) {
			print_failed (TEST_NUMBER);
		}

		int i = 10;

		if (!v.set_value (i)) {
			print_failed (TEST_NUMBER);
		}

		if (&i == v.get_pointer ()) {
			print_failed (TEST_NUMBER);
		}

		print_passed (TEST_NUMBER);
	}//end Test 4


	{//Test 5
		++TEST_NUMBER;

		Value v;
		int *i1 = new int ();
		*i1 = 17;

		if (!v.init<int*> ()) {
			print_failed (TEST_NUMBER);
		}

		if (!v.set_value (i1)) {
			print_failed (TEST_NUMBER);
		}

		int *i2;
		if (!v.get_value (i2)) {
			print_failed (TEST_NUMBER);
		}

		if (i1 != i2) {
			print_failed (TEST_NUMBER);
		}

		if (*i1 != *i2) {
			print_failed (TEST_NUMBER);
		}

		delete i1;

		print_passed (TEST_NUMBER);
	}//end Test 5


	{//Test 6
		++TEST_NUMBER;

		Value v;

		if (!v.init<void*> ()) {
			print_failed (TEST_NUMBER);
		}

		if (!v.set_value ((void*)0)) {
			print_failed (TEST_NUMBER);
		}

		print_passed (TEST_NUMBER);
	}//end Test 6
}

