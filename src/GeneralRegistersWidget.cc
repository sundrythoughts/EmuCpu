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


#include "GeneralRegistersWidget.hh"

GeneralRegistersWidget::GeneralRegistersWidget (QWidget *parent) : QDockWidget (parent) {
	setupUi (this);
}

void
GeneralRegistersWidget::reset () {
	setRegAX (0);
	setRegBX (0);
	setRegCX (0);
	setRegDX (0);
	setRegSI (0);
	setRegDI (0);
	setRegBP (0);
	setRegSP (0);
}


void
GeneralRegistersWidget::enableDisableToggle (bool b) {
	if (b) {
		show ();
	}
	else {
		hide ();
	}

	Q_EMIT enableDisable (b);
}


void
GeneralRegistersWidget::setRegAX (unsigned short i) {
	m_ln_ax->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
GeneralRegistersWidget::setRegBX (unsigned short i) {
	m_ln_bx->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
GeneralRegistersWidget::setRegCX (unsigned short i) {
	m_ln_cx->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
GeneralRegistersWidget::setRegDX (unsigned short i) {
	m_ln_dx->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
GeneralRegistersWidget::setRegSI (unsigned short i) {
	m_ln_si->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
GeneralRegistersWidget::setRegDI (unsigned short i) {
	m_ln_di->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
GeneralRegistersWidget::setRegBP (unsigned short i) {
	m_ln_bp->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
GeneralRegistersWidget::setRegSP (unsigned short i) {
	m_ln_sp->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}

