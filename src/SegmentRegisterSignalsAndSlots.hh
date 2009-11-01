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
@file SegmentRegisterSignalsAndSlots.hh
@brief Segment register signal translation layer between Sigc++ and Qt.
*/

#ifndef JAF__SEGMENT_REGISTER_SIGNALS_AND_SLOTS_HH
#define JAF__SEGMENT_REGISTER_SIGNALS_AND_SLOTS_HH

#include <QObject>

/**
@class SegmentRegisterSignalsAndSlots
@brief Segment register signal translation layer between Sigc++ and Qt.
*/
class SegmentRegisterSignalsAndSlots : public QObject {
	Q_OBJECT

public:
	/** */
	void sigcSlotValueChangedSRegCS (unsigned short i);

	/** */
	void sigcSlotValueChangedSRegDS (unsigned short i);

	/** */
	void sigcSlotValueChangedSRegES (unsigned short i);

	/** */
	void sigcSlotValueChangedSRegSS (unsigned short i);

	/** */
	void sigcSlotValueChangedRegIP (unsigned short i);

public slots:
	/** */
	void enableDisable (bool b);

signals:
	//segment register signals

	/** */
	void valueChangedSegRegCS (unsigned short i);

	/** */
	void valueChangedSegRegDS (unsigned short i);

	/** */
	void valueChangedSegRegES (unsigned short i);

	/** */
	void valueChangedSegRegSS (unsigned short i);

	//instruction pointer signals

	/** */
	void valueChangedRegIP (unsigned short i);

}; //end class SegmentRegisterSignalsAndSlots

#endif //JAF__SEGMENT_REGISTER_SIGNALS_AND_SLOTS_HH

