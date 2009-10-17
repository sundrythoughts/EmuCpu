#include "NumberWrapper.hh"
#include "Register.hh"
#include "Immediate.hh"
#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char **argv) {
	int i = 13;
	NumberWrapper w1;
	Immediate<int> *ptr = new Immediate<int> (i);
	w1.init<int> (ptr, true);

	//NumberWrapper w2 (w1);

	cout << w1.get<int> () << endl;
	//cout << w2.get<int> () << endl;
}

