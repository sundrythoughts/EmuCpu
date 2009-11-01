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

