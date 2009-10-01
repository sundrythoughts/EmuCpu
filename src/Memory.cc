#include "Memory.hh"
#include <cstdio>

void
Memory::printMemoryDump (size_t start, size_t end) {
	while (start < m_memory.size () && start < end) {
		std::printf ("%u: %x\n", start, m_memory[start]);

		++start;
	}
}
