/*
 * emucpu -- Emulates processors
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

#ifndef EMUCPU__IO_PORTS_HH
#define EMUCPU__IO_PORTS_HH

#include <sigc++/sigc++.h>
#include <queue>

#include <QtGlobal>

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

	/** @brief Create a connection to the CpuComponents. */
	void connectTo (CpuComponents &cpu);

	/** @brief Get the signalCharOutput signal. */
	sigc::signal<void, char>& signalCharOutput ();

	/** @brief Get the signalSoundOutput signal. */
	sigc::signal<void, quint16, quint16> signalSoundOutput ();

	/** @brief Queue a character from the terminal. */
	void charInput (char c);

	/** @brief Get the character queue. */
	std::queue<char>& charInputQueue ();

	/** @brief Set everything back to its default state. */
	void reset ();

private:
	//play a sound through the ToneGenerator
	void playSound (quint16 freq, quint16 duration);
};

#endif //EMUCPU__IO_PORTS_HH

