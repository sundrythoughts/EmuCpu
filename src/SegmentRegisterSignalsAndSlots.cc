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


#include "SegmentRegisterSignalsAndSlots.hh"

void
SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegCS (unsigned short i) {
	Q_EMIT valueChangedSegRegCS (i);
}

void
SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegDS (unsigned short i) {
	Q_EMIT valueChangedSegRegDS (i);
}

void
SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegES (unsigned short i) {
	Q_EMIT valueChangedSegRegES (i);
}

void
SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegSS (unsigned short i) {
	Q_EMIT valueChangedSegRegSS (i);
}

void
SegmentRegisterSignalsAndSlots::sigcSlotValueChangedRegIP (unsigned short i) {
	Q_EMIT valueChangedRegIP (i);
}

void
SegmentRegisterSignalsAndSlots::enableDisable (bool b) {
	blockSignals (!b);
}

