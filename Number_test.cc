#include "Number.hh"
#include <iostream>
#include <stdio.h>

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
	cout << "value-changed: " << val << endl;
}

int main (int argc, char **argv) {
	int TEST_NUMBER = 0;

//#if 0
	{
		unsigned int n1 = 10;
		unsigned int n2 = 3;
		Number<unsigned int> num2 (n2);

		n1 += num2;
		cout << n1 << endl;
	}
//#endif

	{//Test 1
		++TEST_NUMBER;
		ps = true;

		int n1 = 5;
		Number<int> num1 (n1);

		if (-5 != -num1) {
			print_failed (TEST_NUMBER);
		}

		if (-num1 != -5) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 1


	{//Test 2
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 0xF0;
		Number<unsigned char> num1 (n1);

		if (0x0F != ~num1) {
			print_failed (TEST_NUMBER);
		}

		if (~num1 != 0x0F) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 2


	{//Test 3
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 1;
		Number<unsigned char> num1 (n1);

		if (0 != !num1) {
			print_failed (TEST_NUMBER);
		}

		if (!num1 != 0) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 3


	{//Test 4
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		Number<unsigned char> num1 (n1);

		if (11 != ++num1) {
			print_failed (TEST_NUMBER);
		}

		if (++num1 != 12) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 4


	{//Test 5
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		Number<unsigned char> num1 (n1);

		if (10 != num1++) {
			print_failed (TEST_NUMBER);
		}

		if (num1++ != 11) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 5


	{//Test 6
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		Number<unsigned char> num1 (n1);

		if (9 != --num1) {
			print_failed (TEST_NUMBER);
		}

		if (--num1 != 8) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 6


	{//Test 7
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		Number<unsigned char> num1 (n1);

		if (10 != num1--) {
			print_failed (TEST_NUMBER);
		}

		if (num1-- != 9) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 7


	{//Test 8
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 13;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 = num2;

		if (num1.get_value () != num2.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (num1 != num2) {
			print_failed (TEST_NUMBER);
		}

		if (num2 != num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 8


	{//Test 9
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 5123;
		unsigned char n2 = 13;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 = num2;

		if (num1.get_value () != num2.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (num1 != num2) {
			print_failed (TEST_NUMBER);
		}

		if (num2 != num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 9


	{//Test 10
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned short n2 = 13;
		Number<unsigned int> num1 (n1);

		num1 = n2;

		if (num1.get_value () != n2) {
			print_failed (TEST_NUMBER);
		}

		if (n2 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 10


	{//Test 11
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 13;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 += num2;

		if (num1.get_value () != 23) {
			print_failed (TEST_NUMBER);
		}

		if (23 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 11


	{//Test 12
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 13;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 += num2;

		if (num1.get_value () != 513) {
			print_failed (TEST_NUMBER);
		}

		if (513 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 12


	{//Test 13
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 13;
		Number<unsigned int> num1 (n1);

		num1 += n2;

		if (num1.get_value () != 513) {
			print_failed (TEST_NUMBER);
		}

		if (513 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 13


	{//Test 14
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 23;
		unsigned char n2 = 13;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 -= num2;

		if (num1.get_value () != 10) {
			print_failed (TEST_NUMBER);
		}

		if (10 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 14


	{//Test 15
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 10;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 -= num2;

		if (num1.get_value () != 490) {
			print_failed (TEST_NUMBER);
		}

		if (490 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 15


	{//Test 16
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 13;
		Number<unsigned int> num1 (n1);

		num1 -= n2;

		if (num1.get_value () != 487) {
			print_failed (TEST_NUMBER);
		}

		if (487 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 16


	{//Test 17
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 2;
		unsigned char n2 = 10;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 *= num2;

		if (num1.get_value () != 20) {
			print_failed (TEST_NUMBER);
		}

		if (20 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 17


	{//Test 18
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 10;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 *= num2;

		if (num1.get_value () != 5000) {
			print_failed (TEST_NUMBER);
		}

		if (5000 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 18


	{//Test 19
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 10;
		Number<unsigned int> num1 (n1);

		num1 *= n2;

		if (num1.get_value () != 5000) {
			print_failed (TEST_NUMBER);
		}

		if (5000 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 19


	{//Test 20
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 2;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 /= num2;

		if (num1.get_value () != 5) {
			print_failed (TEST_NUMBER);
		}

		if (5 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 20


	{//Test 21
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 10;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 /= num2;

		if (num1.get_value () != 50) {
			print_failed (TEST_NUMBER);
		}

		if (50 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 21


	{//Test 22
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 10;
		Number<unsigned int> num1 (n1);

		num1 /= n2;

		if (num1.get_value () != 50) {
			print_failed (TEST_NUMBER);
		}

		if (50 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 22


	{//Test 23
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 2;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 %= num2;

		if (num1.get_value () != 0) {
			print_failed (TEST_NUMBER);
		}

		if (0 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 23


	{//Test 24
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 10;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 %= num2;

		if (num1.get_value () != 0) {
			print_failed (TEST_NUMBER);
		}

		if (0 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 24


	{//Test 25
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 10;
		Number<unsigned int> num1 (n1);

		num1 %= n2;

		if (num1.get_value () != 0) {
			print_failed (TEST_NUMBER);
		}

		if (0 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 25


	{//Test 26
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 2;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 ^= num2;

		if (num1.get_value () != 8) {
			print_failed (TEST_NUMBER);
		}

		if (8 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 26


	{//Test 27
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 10;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 ^= num2;

		if (num1.get_value () != 510) {
			print_failed (TEST_NUMBER);
		}

		if (510 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 27


	{//Test 28
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 10;
		Number<unsigned int> num1 (n1);

		num1 ^= n2;

		if (num1.get_value () != 510) {
			print_failed (TEST_NUMBER);
		}

		if (510 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 28


	{//Test 29
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 2;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 &= num2;

		if (num1.get_value () != 2) {
			print_failed (TEST_NUMBER);
		}

		if (2 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 29


	{//Test 30
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 10;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 &= num2;

		if (num1.get_value () != 0) {
			print_failed (TEST_NUMBER);
		}

		if (0 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 30


	{//Test 31
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 10;
		Number<unsigned int> num1 (n1);

		num1 &= n2;

		if (num1.get_value () != 0) {
			print_failed (TEST_NUMBER);
		}

		if (0 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 31


	{//Test 32
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 2;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 |= num2;

		if (num1.get_value () != 10) {
			print_failed (TEST_NUMBER);
		}

		if (10 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 32


	{//Test 33
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 10;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 |= num2;

		if (num1.get_value () != 510) {
			print_failed (TEST_NUMBER);
		}

		if (510 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 33


	{//Test 34
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 10;
		Number<unsigned int> num1 (n1);

		num1 |= n2;

		if (num1.get_value () != 510) {
			print_failed (TEST_NUMBER);
		}

		if (510 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 34


	{//Test 35
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 2;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 >>= num2;

		if (num1.get_value () != 2) {
			print_failed (TEST_NUMBER);
		}

		if (2 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 35


	{//Test 36
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 >>= num2;

		if (num1.get_value () != 15) {
			print_failed (TEST_NUMBER);
		}

		if (15 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 36


	{//Test 37
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);

		num1 >>= n2;

		if (num1.get_value () != 15) {
			print_failed (TEST_NUMBER);
		}

		if (15 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 37


	{//Test 38
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 2;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 <<= num2;

		if (num1.get_value () != 40) {
			print_failed (TEST_NUMBER);
		}

		if (40 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 38


	{//Test 39
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		num1 <<= num2;

		if (num1.get_value () != 16000) {
			print_failed (TEST_NUMBER);
		}

		if (16000 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 39


	{//Test 40
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);

		num1 <<= n2;

		if (num1.get_value () != 16000) {
			print_failed (TEST_NUMBER);
		}

		if (16000 != num1.get_value ()) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 40


	{//Test 41
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 2;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 + num2 != 12) {
			print_failed (TEST_NUMBER);
		}

		if (12 != num1 + num2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 41


	{//Test 42
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 + num2 != 505) {
			print_failed (TEST_NUMBER);
		}

		if (505 != num1 + num2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 42


	{//Test 43
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);

		if (num1 + n2 != 505) {
			print_failed (TEST_NUMBER);
		}

		if (505 != num1 + n2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 43


	{//Test 44
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 2;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 - num2 != 8) {
			print_failed (TEST_NUMBER);
		}

		if (8 != num1 - num2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 44


	{//Test 45
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 - num2 != 495) {
			print_failed (TEST_NUMBER);
		}

		if (495 != num1 - num2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 45


	{//Test 46
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);

		if (num1 - n2 != 495) {
			print_failed (TEST_NUMBER);
		}

		if (495 != num1 - n2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 46


	{//Test 47
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 2;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 * num2 != 20) {
			print_failed (TEST_NUMBER);
		}

		if (20 != num1 * num2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 47


	{//Test 48
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 * num2 != 2500) {
			print_failed (TEST_NUMBER);
		}

		if (2500 != num1 * num2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 48


	{//Test 49
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);

		if (num1 * n2 != 2500) {
			print_failed (TEST_NUMBER);
		}

		if (2500 != num1 * n2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 49


	{//Test 50
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 2;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 / num2 != 5) {
			print_failed (TEST_NUMBER);
		}

		if (5 != num1 / num2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 50


	{//Test 51
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 / num2 != 100) {
			print_failed (TEST_NUMBER);
		}

		if (100 != num1 / num2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 51


	{//Test 52
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);

		if (num1 / n2 != 100) {
			print_failed (TEST_NUMBER);
		}

		if (100 != num1 / n2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 52


	{//Test 53
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 2;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 % num2 != 0) {
			print_failed (TEST_NUMBER);
		}

		if (0 != num1 % num2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 53


	{//Test 54
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 % num2 != 0) {
			print_failed (TEST_NUMBER);
		}

		if (0 != num1 % num2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 54


	{//Test 55
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);

		if (num1 % n2 != 0) {
			print_failed (TEST_NUMBER);
		}

		if (0 != num1 % n2) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 55


	{//Test 56
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 2;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		if ((num1 ^ num2) != 8) {
			print_failed (TEST_NUMBER);
		}

		if (8 != (num1 ^ num2)) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 56


	{//Test 57
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		if ((num1 ^ num2) != 497) {
			print_failed (TEST_NUMBER);
		}

		if (497 != (num1 ^ num2)) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 57


	{//Test 58
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);

		if ((num1 ^ n2) != 497) {
			print_failed (TEST_NUMBER);
		}

		if (497 != (num1 ^ n2)) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 58


	{//Test 59
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 2;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		if ((num1 & num2) != 2) {
			print_failed (TEST_NUMBER);
		}

		if (2 != (num1 & num2)) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 59


	{//Test 60
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		if ((num1 & num2) != 4) {
			print_failed (TEST_NUMBER);
		}

		if (4 != (num1 & num2)) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 60


	{//Test 61
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);

		if ((num1 & n2) != 4) {
			print_failed (TEST_NUMBER);
		}

		if (4 != (num1 & n2)) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 61


	{//Test 62
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 2;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		if ((num1 | num2) != 10) {
			print_failed (TEST_NUMBER);
		}

		if (10 != (num1 | num2)) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 62


	{//Test 63
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		if ((num1 | num2) != 501) {
			print_failed (TEST_NUMBER);
		}

		if (501 != (num1 | num2)) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 63


	{//Test 64
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);

		if ((num1 | n2) != 501) {
			print_failed (TEST_NUMBER);
		}

		if (501 != (num1 | n2)) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 64


	{//Test 65
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 2;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		if ((num1 << num2) != 40) {
			print_failed (TEST_NUMBER);
		}

		if (40 != (num1 << num2)) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 65


	{//Test 66
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		if ((num1 << num2) != 16000) {
			print_failed (TEST_NUMBER);
		}

		if (16000 != (num1 << num2)) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 66


	{//Test 67
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);

		if ((num1 << n2) != 16000) {
			print_failed (TEST_NUMBER);
		}

		if (16000 != (num1 << n2)) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 67


	{//Test 68
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 2;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		if ((num1 >> num2) != 2) {
			print_failed (TEST_NUMBER);
		}

		if (2 != (num1 >> num2)) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 68


	{//Test 69
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		if ((num1 >> num2) != 15) {
			print_failed (TEST_NUMBER);
		}

		if (15 != (num1 >> num2)) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 69


	{//Test 70
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);

		if ((num1 >> n2) != 15) {
			print_failed (TEST_NUMBER);
		}

		if (15 != (num1 >> n2)) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 70


	{//Test 71
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 2;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 == num2) {
			print_failed (TEST_NUMBER);
		}

		if (num2 == num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 71


	{//Test 72
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 == num2) {
			print_failed (TEST_NUMBER);
		}

		if (num2 == num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 72


	{//Test 73
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 500;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);

		if (num1 == n2) {
			print_failed (TEST_NUMBER);
		}

		if (n2 == num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 73


	{//Test 74
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 10;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 != num2) {
			print_failed (TEST_NUMBER);
		}

		if (num2 != num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 74


	{//Test 75
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 5;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 != num2) {
			print_failed (TEST_NUMBER);
		}

		if (num2 != num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 75


	{//Test 76
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 5;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);

		if (num1 != n2) {
			print_failed (TEST_NUMBER);
		}

		if (n2 != num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 76


	{//Test 77
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 13;
		unsigned char n2 = 10;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 < num2) {
			print_failed (TEST_NUMBER);
		}

		num1 = 10;
		num2 = 13;

		if (num2 < num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 77


	{//Test 78
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 13;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 < num2) {
			print_failed (TEST_NUMBER);
		}

		num1 = 5;
		num2 = 13;

		if (num2 < num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 78


	{//Test 79
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 13;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);

		if (num1 < n2) {
			print_failed (TEST_NUMBER);
		}

		num1 = 5;
		n2 = 13;

		if (n2 < num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 79


	{//Test 80
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 13;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 > num2) {
			print_failed (TEST_NUMBER);
		}

		num1 = 13;
		num2 = 10;

		if (num2 > num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 80


	{//Test 81
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 5;
		unsigned char n2 = 13;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 > num2) {
			print_failed (TEST_NUMBER);
		}

		num1 = 13;
		num2 = 5;

		if (num2 > num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 81


	{//Test 82
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 5;
		unsigned char n2 = 13;
		Number<unsigned int> num1 (n1);

		if (num1 > n2) {
			print_failed (TEST_NUMBER);
		}

		num1 = 13;
		n2 = 5;

		if (n2 > num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 82


	{//Test 83
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 13;
		unsigned char n2 = 10;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 <= num2) {
			print_failed (TEST_NUMBER);
		}

		num1 = 10;
		num2 = 13;

		if (num2 <= num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 83


	{//Test 84
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 13;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 <= num2) {
			print_failed (TEST_NUMBER);
		}

		num1 = 5;
		num2 = 13;

		if (num2 <= num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 84


	{//Test 85
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 13;
		unsigned char n2 = 5;
		Number<unsigned int> num1 (n1);

		if (num1 <= n2) {
			print_failed (TEST_NUMBER);
		}

		num1 = 5;
		n2 = 13;

		if (n2 <= num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 85


	{//Test 86
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 13;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 >= num2) {
			print_failed (TEST_NUMBER);
		}

		num1 = 13;
		num2 = 10;

		if (num2 >= num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 86


	{//Test 87
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 5;
		unsigned char n2 = 13;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 >= num2) {
			print_failed (TEST_NUMBER);
		}

		num1 = 13;
		num2 = 5;

		if (num2 >= num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 87


	{//Test 88
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 5;
		unsigned char n2 = 13;
		Number<unsigned int> num1 (n1);

		if (num1 >= n2) {
			print_failed (TEST_NUMBER);
		}

		num1 = 13;
		n2 = 5;

		if (n2 >= num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 88


	{//Test 89
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 10;
		unsigned char n2 = 0;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 && num2) {
			print_failed (TEST_NUMBER);
		}

		if (num2 && num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 89


	{//Test 90
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 5;
		unsigned char n2 = 0;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 && num2) {
			print_failed (TEST_NUMBER);
		}

		if (num2 && num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 90


	{//Test 91
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 5;
		unsigned char n2 = 0;
		Number<unsigned int> num1 (n1);

		if (num1 && n2) {
			print_failed (TEST_NUMBER);
		}

		if (n2 && num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 91


	{//Test 92
		++TEST_NUMBER;
		ps = true;

		unsigned char n1 = 0;
		unsigned char n2 = 0;
		Number<unsigned char> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 || num2) {
			print_failed (TEST_NUMBER);
		}

		if (num2 || num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 92


	{//Test 93
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 0;
		unsigned char n2 = 0;
		Number<unsigned int> num1 (n1);
		Number<unsigned char> num2 (n2);

		if (num1 || num2) {
			print_failed (TEST_NUMBER);
		}

		if (num2 || num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 93


	{//Test 94
		++TEST_NUMBER;
		ps = true;

		unsigned int n1 = 0;
		unsigned char n2 = 0;
		Number<unsigned int> num1 (n1);

		if (num1 || n2) {
			print_failed (TEST_NUMBER);
		}

		if (n2 || num1) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 94
}

