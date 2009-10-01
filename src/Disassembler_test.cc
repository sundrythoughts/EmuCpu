#include "Disassembler.hh"
#include <string>

int main (int argc, char **argv) {
	std::FILE *f = fopen ("opcode", "r");
	unsigned char byte;
	std::string dis;
	
	while (fread (&byte, 1, 1, f)) {
		J::Disassembler::disassemble (&byte, dis);
	}
}
