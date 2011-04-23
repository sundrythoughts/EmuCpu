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
@file MemorySignalsAndSlots.hh
@brief Memory signal translation layer between Sigc++ and Qt.
*/

#ifndef EMUCPU__MEMORY_SIGNALS_AND_SLOTS_HH
#define EMUCPU__MEMORY_SIGNALS_AND_SLOTS_HH

#include <sigc++/sigc++.h>
#include <QObject>

/**
@class MemorySignalsAndSlots
@brief Memory signal translation layer between Sigc++ and Qt.
*/
class MemorySignalsAndSlots : public QObject {
	Q_OBJECT

	sigc::signal<void, size_t> m_sigc_signal_resize;

public:
	/** @brief Sigc++ slot called when a memory address' value is changed. */
	void sigcSlotValueChanged (int addr, unsigned char val);

	/** @brief Sigc++ slot called when memory is resized. */
	void sigcSlotResized (size_t sz);

	/** @brief Sigc++ slot called when all the memory addressess' values are changed. */
	void sigcSlotReloaded (const unsigned char *arr, size_t sz);

	/** @brief Sigc++ signal emitted when a memory resize request is given. */
	sigc::signal<void, size_t>& sigcSignalResize ();

public Q_SLOTS:
	/** @brief Qt slot called when the memory is enabled/disabled. */
	void enableDisable (bool b);

	/** @brief Qt slot called when there is a request to resize the memory. */
	void resize (size_t sz);

Q_SIGNALS:
	/** @brief Qt signal emitted when a memory address' value is changed. */
	void valueChanged (int addr, unsigned char val);

	/** @brief Qt signal emitted when memory is resized. */
	void resized (size_t sz);

	/** @brief Qt signal emitted when all the memory addressess' values are changed. */
	void reloaded (const unsigned char *arr, size_t sz);

}; //end class MemorySignalsAndSlots

#endif //EMUCPU__MEMORY_SIGNALS_AND_SLOTS_HH

