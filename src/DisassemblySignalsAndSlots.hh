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
@file DisassemblySignalsAndSlots.hh
@brief Disassembly signal translation layer between Sigc++ and Qt.
*/

#ifndef SIM8086__DISASSEMBLY_SIGNALS_AND_SLOTS_HH
#define SIM8086__DISASSEMBLY_SIGNALS_AND_SLOTS_HH

#include <string>
#include <QtCore>

/**
@class DisassemblySignalsAndSlots
@brief Disassembly signal translation layer between Sigc++ and Qt.
*/
class DisassemblySignalsAndSlots : public QObject {
	Q_OBJECT

public:
	/** @brief Sigc++ -> QT translation slot for the next instruction. */
	void sigcSlotNextInstruction (const std::string&, const std::string&, const std::string&, const std::string&);

public Q_SLOTS:
	/** @brief Enable/disable disassembly. */
	void enableDisable (bool b);

Q_SIGNALS:
	/** @brief Qt slot for the next instruction. */
	void nextInstruction (QString seg_off, QString mcode, QString asm_code, QString addr_mode);

}; //end class DisassemblySignalsAndSlots

#endif //SIM8086__DISASSEMBLY_SIGNALS_AND_SLOTS_HH

