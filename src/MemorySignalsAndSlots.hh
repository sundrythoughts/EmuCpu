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
@file MemorySignalsAndSlots.hh
@brief Memory signal translation layer between Sigc++ and Qt.
*/

#ifndef JAF__MEMORY_SIGNALS_AND_SLOTS_HH
#define JAF__MEMORY_SIGNALS_AND_SLOTS_HH

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
	/** */
	void sigcSlotValueChanged (int addr, unsigned char val);

	/** */
	void sigcSlotResized (size_t sz);

	/** */
	void sigcSlotReloaded (const unsigned char *arr, size_t sz);

	/** */
	sigc::signal<void, size_t>& sigcSignalResize ();

public slots:
	/** */
	void enableDisable (bool b);

	/** */
	void resize (size_t sz);

signals:
	/** */
	void valueChanged (int addr, unsigned char val);

	/** */
	void resized (size_t sz);

	/** */
	void reloaded (const unsigned char *arr, size_t sz);

}; //end class MemorySignalsAndSlots

#endif //JAF__MEMORY_SIGNALS_AND_SLOTS_HH

