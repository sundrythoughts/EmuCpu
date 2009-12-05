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
@file SoundWidget.hh
@brief Widget for displaying the sound.
*/

#ifndef JAF__SOUND_WIDGET_HH
#define JAF__SOUND_WIDGET_HH

#include <QtCore>
#include <QtGui>

#include "ui_SoundWidget.h"

/**
@class SoundWidget
@brief Widget for displaying the sound.
*/
class SoundWidget : public QWidget, protected Ui::SoundWidget {
	Q_OBJECT

public:
	/** */
	SoundWidget (QWidget *parent = 0);

	/** */
	~SoundWidget ();

	/** @brief Set the widget to its default state. */
	void reset ();

public Q_SLOTS:
	/** @brief Enable/disable this widget display. */
	void enableDisableToggle (bool b);

	/** @brief Play a tone of a particular frequency and duration. */
	void playSound (unsigned short freq, unsigned short duration);

Q_SIGNALS:
	/** @brief This widget display has been enabled/disabled. */
	void enableDisable (bool b);

}; //end class SoundWidget

#endif //JAF__SOUND_WIDGET_HH

