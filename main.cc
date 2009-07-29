#include <stdio.h>
#include <iostream>

#include "InstructionDecoder8086.hh"

using namespace std;

int main (int argc, char **argv) {
	InstructionDecoder8086 id;
	cout << id.disassemble () << endl;
}
