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


#include "SegmentRegistersWidget.hh"


SegmentRegistersWidget::SegmentRegistersWidget (QWidget *parent) : QDockWidget (parent) {
	setupUi (this);
}

void
SegmentRegistersWidget::reset () {
	setSegRegCS (0);
	setSegRegDS (0);
	setSegRegES (0);
	setSegRegSS (0);
	setRegIP (0);
}


void
SegmentRegistersWidget::enableDisableToggle (bool b) {
	if (b) {
		show ();
	}
	else {
		hide ();
	}

	Q_EMIT enableDisable (b);
}


void
SegmentRegistersWidget::setSegRegCS (unsigned short i) {
	m_ln_cs->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
SegmentRegistersWidget::setSegRegDS (unsigned short i) {
	m_ln_ds->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
SegmentRegistersWidget::setSegRegES (unsigned short i) {
	m_ln_es->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
SegmentRegistersWidget::setSegRegSS (unsigned short i) {
	m_ln_ss->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
SegmentRegistersWidget::setRegIP (unsigned short i) {
	m_ln_ip->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}

