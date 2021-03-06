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
@file SoundSignalsAndSlots.hh
@brief Sound signal translation layer between Sigc++ and Qt.
*/

#ifndef EMUCPU__SOUND_SIGNALS_AND_SLOTS_HH
#define EMUCPU__SOUND_SIGNALS_AND_SLOTS_HH

#include <QObject>

/**
@class SoundSignalsAndSlots
@brief Sound signal translation layer between Sigc++ and Qt.
*/
class SoundSignalsAndSlots : public QObject {
	Q_OBJECT

public:
	/** @brief Sigc++ slot called when a sound is played. */
	void sigcSlotPlaySound (unsigned short freq, unsigned short duration);

public Q_SLOTS:
	/** @brief Enable/disable the sound. */
	void enableDisable (bool b);

Q_SIGNALS:
	/** @brief Qt signal called when a sound is played. */
	void playSound (unsigned short freq, unsigned short duration);

}; //end class SoundSignalsAndSlots

#endif //EMUCPU__SOUND_SIGNALS_AND_SLOTS_HH

