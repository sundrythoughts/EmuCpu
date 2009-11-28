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


#include "TerminalWidget.hh"
#include <iostream>

TerminalWidget::TerminalWidget (QWidget *parent) : QWidget (parent) {
	setupUi (this);
}

void
TerminalWidget::reset () {
	//FIXME
}

void
TerminalWidget::enableDisableToggle (bool b) {
	if (b) {
		show ();
	}
	else {
		hide ();
	}

	Q_EMIT enableDisable (b);
}

void
TerminalWidget::terminalInput (char c) {
	m_txt_terminal->insertPlainText (QChar (c));
}

void
TerminalWidget::keyPressEvent (QKeyEvent *event) {
	QChar ch = event->text ().toAscii ().at (0);
	if (!ch.isPrint ()) {
		QWidget::keyPressEvent (event);
		return;
	}
	m_txt_terminal->insertPlainText (ch);
	Q_EMIT terminalOutput (ch.toAscii ());
}

void
TerminalWidget::mousePressEvent (QMouseEvent *event) {
	//FIXME - this should be more intuitive for the user
	setFocus ();
}

