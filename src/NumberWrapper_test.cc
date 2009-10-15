#include "NumberWrapper.hh"
#include "Register.hh"
#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char **argv) {
	INumberReadableWritable<int> *i = new Register<int> ();
	*i = 13;
	NumberWrapper w1;
	w1.init<int> (*i, true);

	NumberWrapper w2 (w1);
}

