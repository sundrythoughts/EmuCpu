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

#include "IOPorts.hh"
#include "CpuComponents.hh"
#include "ToneGenerator.hh"
#include <iostream>

class IOPortsPrivate {
public:
	CpuComponents *m_cpu;

	sigc::signal<void, char> m_signal_char_out;
	sigc::signal<void, unsigned short, unsigned short> m_signal_sound_out;

	std::queue<char> m_char_input_q;

	ToneGenerator m_tone_gen;
};

IOPorts::IOPorts () {
	p = new IOPortsPrivate ();
	p->m_signal_sound_out.connect (sigc::mem_fun(*this, &IOPorts::playSound));
}

IOPorts::~IOPorts () {
	delete p;
}

void
IOPorts::connectTo (CpuComponents &cpu) {
	p->m_cpu = &cpu;
}

sigc::signal<void, char>&
IOPorts::signalCharOutput () {
	return p->m_signal_char_out;
}

sigc::signal<void,
             unsigned short,
             unsigned short>
IOPorts::signalSoundOutput () {
	return p->m_signal_sound_out;
}

void
IOPorts::charInput (char c) {
	p->m_char_input_q.push (c);
}

std::queue<char>&
IOPorts::charInputQueue () {
	return p->m_char_input_q;
}

void
IOPorts::reset () {
	while (!p->m_char_input_q.empty ()) {
		p->m_char_input_q.pop ();
	}
}

void
IOPorts::playSound (unsigned short freq, unsigned short duration) {
	p->m_tone_gen.play ((float)freq, duration);
}

