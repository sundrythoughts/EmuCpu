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

/** */

#ifndef JAF__IO_PORTS_HH
#define JAF__IO_PORTS_HH

#include <sigc++/sigc++.h>
#include <queue>

class CpuComponents;
class IOPortsPrivate;

/** */
class IOPorts {
	IOPortsPrivate *p;

public:
	/** */
	IOPorts ();

	/** */
	~IOPorts ();

	/** Create a connection to the CpuComponents. */
	void connectTo (CpuComponents &cpu);

	/** */
	sigc::signal<void, char>& signalCharOutput ();

	/** */
	sigc::signal<void, unsigned short, unsigned short> signalSoundOutput ();

	/** */
	void charInput (char c);

	/** */
	std::queue<char>& charInputQueue ();

	/** */
	void reset ();

private:
	void playSound (unsigned short freq, unsigned short duration);
};

#endif //JAF__IO_PORTS_HH

