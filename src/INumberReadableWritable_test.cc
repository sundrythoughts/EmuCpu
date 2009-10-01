#include "Register.hh"
#include "MemoryAddress.hh"
#include "Immediate.hh"
#include "INumberReadableWritable.hh"

#include "Memory.hh"

#include <iostream>

using namespace std;

int main (int argc, char **argv) {
	{
		Memory memory (1048576);

		INumberReadableWritable<int> *reg = new Register<int> (13);
		INumberReadableWritable<int> *reg2 = new Register<int> (21);
		INumberReadableWritable<int> *mem = new MemoryAddress<int> (&memory, 0, 0);
		INumberReadableWritable<int> *imm = new Immediate<int> (25);

		cout << "reg: " << *reg << endl;
		cout << "reg2: " << *reg2 << endl;
		cout << "mem: " << *mem << endl;
		cout << "imm: " << *imm << endl;

		//cout << "*reg = *mem: " << (*reg = *mem) << endl;
		*mem = *reg;
		cout << endl;

		cout << "reg: " << *reg << endl;
		cout << "reg2: " << *reg2 << endl;
		cout << "mem: " << *mem << endl;
		cout << "imm: " << *imm << endl;

		delete imm;
		delete mem;
		delete reg2;
		delete reg;
	}

	{
		int i1 = 10, i2 = 2;
		Register<int> tmp = 10;
		Register<int> dest;

		dest = tmp;
		dest += 7;

		cout << endl;
		cout << tmp << endl;
		cout << dest << endl;
	}
}

