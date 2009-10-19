#include "Memory.hh"
#include <cstdio>

Memory::Memory () {
}


void
Memory::resize (size_t sz, bool clr) {
	if (clr) {
		m_memory.clear ();
	}

	m_memory.resize (sz, 0);

	m_signal_resized (m_memory.size ());
}


unsigned char
Memory::operator[] (size_t index) const {
	return m_memory[index];
}


size_t
Memory::size () const {
	return m_memory.size ();
}


unsigned char*
Memory::data () {
	return m_memory.data ();
}


sigc::signal<void, int, unsigned char>&
Memory::signalValueChanged () {
	return m_signal_value_changed;
}


sigc::signal<void, size_t>&
Memory::signalResized () {
	return m_signal_resized;
}


sigc::signal<void, const unsigned char*, size_t>&
Memory::signalReloaded () {
	return m_signal_reloaded;
}


void
Memory::emitValueChangedForAll () const {
	for (size_t i = 0; i < m_memory.size (); ++i) {
		m_signal_value_changed.emit (i, m_memory[i]);
	}
}

void
Memory::emitSignalReloaded (){
	m_signal_reloaded.emit (data (), size ());
}

void
Memory::printMemoryDump (size_t start, size_t end) {
	while (start < m_memory.size () && start < end) {
		std::printf ("%u: %x\n", start, m_memory[start]);

		++start;
	}
}
