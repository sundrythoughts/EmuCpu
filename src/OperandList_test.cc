#include "OperandList.hh"
#include "Immediate.hh"
#include <iostream>

using namespace std;

int main (int argc, char **argv) {
	OperandList ops;
	cout << ops.src ().isNull () << endl;
	cout << ops.dest ().isNull () << endl;

	ops.src ().init<int> (new Immediate<int> (10), true);
	cout << ops.src ().get<int> () << endl;
	cout << ops.src ().isNull () << endl;
	ops.reset ();
	cout << ops.src ().isNull () << endl;
}

