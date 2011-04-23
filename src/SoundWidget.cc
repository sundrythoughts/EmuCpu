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

#include "SoundWidget.hh"
#include <iostream>

SoundWidget::SoundWidget (QWidget *parent) : QWidget (parent) {
	setupUi (this);
}

SoundWidget::~SoundWidget () {
}

void
SoundWidget::reset () {
	m_lcd_frequency->display (0);
	m_lcd_duration->display (0);
}

void
SoundWidget::enableDisableToggle (bool b) {
	if (b) {
		show ();
	}
	else {
		hide ();
	}

	Q_EMIT enableDisable (b);
}

void
SoundWidget::playSound (unsigned short freq, unsigned short duration) {
	m_lcd_frequency->display (freq);
	m_lcd_duration->display (duration);
}

