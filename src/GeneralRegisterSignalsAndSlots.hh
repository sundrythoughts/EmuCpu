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
@file GeneralRegisterSignalsAndSlots.hh
@brief General register signal translation layer between Sigc++ and Qt.
*/

#ifndef SIM8086__GENERAL_REGISTER_SIGNALS_AND_SLOTS_HH
#define SIM8086__GENERAL_REGISTER_SIGNALS_AND_SLOTS_HH

#include <QObject>

/**
@class GeneralRegisterSignalsAndSlots
@brief General register signal translation layer between Sigc++ and Qt.
*/
class GeneralRegisterSignalsAndSlots : public QObject {
	Q_OBJECT

public:
	/** @brief Sigc++ -> QT translation slot for register AX. */
	void sigcSlotValueChangedRegAX (unsigned short i);

	/** @brief Sigc++ -> QT translation slot for register BX. */
	void sigcSlotValueChangedRegBX (unsigned short i);

	/** @brief Sigc++ -> QT translation slot for register CX. */
	void sigcSlotValueChangedRegCX (unsigned short i);

	/** @brief Sigc++ -> QT translation slot for register DX. */
	void sigcSlotValueChangedRegDX (unsigned short i);

	/** @brief Sigc++ -> QT translation slot for register SI. */
	void sigcSlotValueChangedRegSI (unsigned short i);

	/** @brief Sigc++ -> QT translation slot for register DI. */
	void sigcSlotValueChangedRegDI (unsigned short i);

	/** @brief Sigc++ -> QT translation slot for register BP. */
	void sigcSlotValueChangedRegBP (unsigned short i);

	/** @brief Sigc++ -> QT translation slot for register SP. */
	void sigcSlotValueChangedRegSP (unsigned short i);

public Q_SLOTS:
	/** @brief The widget has been enabled/disabled. */
	void enableDisable (bool b);

Q_SIGNALS:
	/** @brief QT signal for register AX. */
	void valueChangedRegAX (unsigned short i);

	/** @brief QT signal for register BX. */
	void valueChangedRegBX (unsigned short i);

	/** @brief QT signal for register CX. */
	void valueChangedRegCX (unsigned short i);

	/** @brief QT signal for register DX. */
	void valueChangedRegDX (unsigned short i);

	/** @brief QT signal for register SI. */
	void valueChangedRegSI (unsigned short i);

	/** @brief QT signal for register DI. */
	void valueChangedRegDI (unsigned short i);

	/** @brief QT signal for register BP. */
	void valueChangedRegBP (unsigned short i);

	/** @brief QT signal for register SP. */
	void valueChangedRegSP (unsigned short i);

}; //end class GeneralRegisterSignalsAndSlots

#endif //SIM8086__GENERAL_REGISTER_SIGNALS_AND_SLOTS_HH

