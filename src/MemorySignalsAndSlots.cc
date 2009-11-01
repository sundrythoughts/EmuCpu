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


#include "MemorySignalsAndSlots.hh"
#include <iostream>

/* SIGC++ SLOTS */
void
MemorySignalsAndSlots::sigcSlotValueChanged (int addr, unsigned char val) {
	emit valueChanged (addr, val);
}

void
MemorySignalsAndSlots::sigcSlotResized (size_t sz) {
	emit resized (sz);
}

void
MemorySignalsAndSlots::sigcSlotReloaded (const unsigned char *arr, size_t sz) {
	emit reloaded (arr, sz);
}

/* SIGC++ SIGNALS */
sigc::signal<void, size_t>&
MemorySignalsAndSlots::sigcSignalResize () {
	return m_sigc_signal_resize;
}

/* QT SLOTS */
void
MemorySignalsAndSlots::enableDisable (bool b) {
	blockSignals (!b);
}

void
MemorySignalsAndSlots::resize (size_t sz) {
}

