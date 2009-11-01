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

