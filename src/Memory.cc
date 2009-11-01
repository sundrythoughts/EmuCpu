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
