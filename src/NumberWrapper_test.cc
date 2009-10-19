#include "NumberWrapper.hh"
#include "Register.hh"
#include "Immediate.hh"
#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char **argv) {
	NumberWrapper vec[2];
	//NumberWrapper w;

	Immediate<char> *ptr = new Immediate<char> (10);
	vec[0].init<char> (ptr, true);

	//vec[0].free ();
	//vec[1].free ();

	//cout << vec[0].toString () << endl;
	//cout << vec[1].toString () << endl;
}

