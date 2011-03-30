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
@file FlagRegisterSignalsAndSlots.hh
@brief Flag register signal translation layer between Sigc++ and Qt.
*/

#ifndef SIM8086__FLAG_REGISTER_SIGNALS_AND_SLOTS_HH
#define SIM8086__FLAG_REGISTER_SIGNALS_AND_SLOTS_HH

#include <QObject>

/**
@class FlagRegisterSignalsAndSlots
@brief Flag register signal translation layer between Sigc++ and Qt.
*/
class FlagRegisterSignalsAndSlots : public QObject {
	Q_OBJECT

public:
	/** @brief Sigc++ -> Qt translation slot when FLAGS register is changed. */
	void sigcSlotValueChangedFlags (unsigned short i);

public Q_SLOTS:
	/** @brief FIXME */
	void enableDisable (bool b);

Q_SIGNALS:
	/** @brief Qt signal emitted when FLAGS register is changed. */
	void valueChangedFlags (unsigned short i);

}; //end class FlagRegisterSignalsAndSlots

#endif //SIM8086__FLAG_REGISTER_SIGNALS_AND_SLOTS_HH

