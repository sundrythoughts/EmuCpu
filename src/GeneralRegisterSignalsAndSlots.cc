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


#include "GeneralRegisterSignalsAndSlots.hh"

/* SIGC++ SLOTS */
void
GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegAX (unsigned short i) {
	emit valueChangedRegAX (i);
}

void
GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegBX (unsigned short i) {
	emit valueChangedRegBX (i);
}

void
GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegCX (unsigned short i) {
	emit valueChangedRegCX (i);
}

void
GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegDX (unsigned short i) {
	emit valueChangedRegDX (i);
}

void
GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegSI (unsigned short i) {
	emit valueChangedRegSI (i);
}

void
GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegDI (unsigned short i) {
	emit valueChangedRegDI (i);
}

void
GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegBP (unsigned short i) {
	emit valueChangedRegBP (i);
}

void
GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegSP (unsigned short i) {
	emit valueChangedRegSP (i);
}

/* QT SLOTS */
void
GeneralRegisterSignalsAndSlots::enableDisable (bool b) {
	blockSignals (!b);
}

