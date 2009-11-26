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
@file TerminalSignalsAndSlots.hh
@brief Terminal signal translation layer between Sigc++ and Qt.
*/

#ifndef JAF__TERMINAL_SIGNALS_AND_SLOTS_HH
#define JAF__TERMINAL_SIGNALS_AND_SLOTS_HH

#include <sigc++/sigc++.h>
#include <QObject>

/**
@class TerminalSignalsAndSlots
@brief Terminal signal translation layer between Sigc++ and Qt.
*/
class TerminalSignalsAndSlots : public QObject {
	Q_OBJECT

	sigc::signal<void, char> m_sigc_signal_terminal_output;

public:
	/** Sigc++ slot for terminal input */
	void sigcSlotTerminalInput (char c);

	/** Sigc++ signal for terminal output */
	sigc::signal<void, char>& sigcSignalTerminalOutput ();

public Q_SLOTS:
	/** Enable or disable the widget */
	void enableDisableToggle (bool b);

	/** Qt slot for terminal output */
	void terminalOutput (char c);

Q_SIGNALS:
	/** */
	void terminalInput (char c);

}; //end class TerminalSignalsAndSlots

#endif //JAF__TERMINAL_SIGNALS_AND_SLOTS_HH

