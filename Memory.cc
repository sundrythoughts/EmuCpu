#include "Memory.hh"
#include <cstdio>

void
Memory::print_memory_dump (unsigned int start, unsigned int end) {
	while (start < m_memory.size () && start < end) {
		std::printf ("%u: %x\n", start, m_memory[start]);

		++start;
	}
}
