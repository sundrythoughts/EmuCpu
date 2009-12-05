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

/**
@file IOPorts.hh
@brief Control the input and output ports of the Cpu.
*/

#ifndef JAF__IO_PORTS_HH
#define JAF__IO_PORTS_HH

#include <sigc++/sigc++.h>
#include <queue>

class CpuComponents;
class IOPortsPrivate;

/**
@class IOPorts
@brief Control the input and output ports of the Cpu.
*/
class IOPorts {
	IOPortsPrivate *p;

public:
	/** */
	IOPorts ();

	/** */
	~IOPorts ();

	/** Create a connection to the CpuComponents. */
	void connectTo (CpuComponents &cpu);

	/** Get the signalCharOutput signal. */
	sigc::signal<void, char>& signalCharOutput ();

	/** Get the signalSoundOutput signal. */
	sigc::signal<void, unsigned short, unsigned short> signalSoundOutput ();

	/** Queue a character from the terminal. */
	void charInput (char c);

	/** Get the character queue. */
	std::queue<char>& charInputQueue ();

	/** Set everything back to its default state. */
	void reset ();

private:
	//play a sound through the ToneGenerator
	void playSound (unsigned short freq, unsigned short duration);
};

#endif //JAF__IO_PORTS_HH

