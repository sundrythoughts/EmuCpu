#include "StorageUnit.hh"
#include <iostream>

using namespace std;

int main (int argc, char **argv) {
	StorageUnit su (10);
	unsigned int i = 1367;
	su.write (i, 1);
	i = 0;
	cout << i << " : ";
	su.read (i, 1);
	cout << i << endl;
	su.debugPrint (cout);
}

