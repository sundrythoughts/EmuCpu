#include "Immediate.hh"
#include <iostream>

using namespace std;

int main (int argc, char **argv) {
	INumberReadableWritable<int> *imm = new Immediate<int> (13);

	cout << *imm << endl;

	*imm = 10;

	cout << *imm << endl;

	delete imm;
}

