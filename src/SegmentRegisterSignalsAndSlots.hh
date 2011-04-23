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
@file SegmentRegisterSignalsAndSlots.hh
@brief Segment register signal translation layer between Sigc++ and Qt.
*/

#ifndef EMUCPU__SEGMENT_REGISTER_SIGNALS_AND_SLOTS_HH
#define EMUCPU__SEGMENT_REGISTER_SIGNALS_AND_SLOTS_HH

#include <QObject>

/**
@class SegmentRegisterSignalsAndSlots
@brief Segment register signal translation layer between Sigc++ and Qt.
*/
class SegmentRegisterSignalsAndSlots : public QObject {
	Q_OBJECT

public:
	/** @brief Sigc++ slot called when CS is changed. */
	void sigcSlotValueChangedSRegCS (unsigned short i);

	/** @brief Sigc++ slot called when DS is changed. */
	void sigcSlotValueChangedSRegDS (unsigned short i);

	/** @brief Sigc++ slot called when ES is changed. */
	void sigcSlotValueChangedSRegES (unsigned short i);

	/** @brief Sigc++ slot called when SS is changed. */
	void sigcSlotValueChangedSRegSS (unsigned short i);

	/** @brief Sigc++ slot called when IP is changed. */
	void sigcSlotValueChangedRegIP (unsigned short i);

public Q_SLOTS:
	/** @brief Enable/disable the segment registers. */
	void enableDisable (bool b);

Q_SIGNALS:
	//segment register signals

	/** @brief Qt signal emitted when CS is changed. */
	void valueChangedSegRegCS (unsigned short i);

	/** @brief Qt signal emitted when DS is changed. */
	void valueChangedSegRegDS (unsigned short i);

	/** @brief Qt signal emitted when ES is changed. */
	void valueChangedSegRegES (unsigned short i);

	/** @brief Qt signal emitted when SS is changed. */
	void valueChangedSegRegSS (unsigned short i);

	//instruction pointer signals

	/** @brief Qt signal emitted when IP is changed. */
	void valueChangedRegIP (unsigned short i);

}; //end class SegmentRegisterSignalsAndSlots

#endif //EMUCPU__SEGMENT_REGISTER_SIGNALS_AND_SLOTS_HH

