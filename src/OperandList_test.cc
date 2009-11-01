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

