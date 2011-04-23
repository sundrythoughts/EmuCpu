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


#include "TerminalWidget.hh"
#include <iostream>

TerminalWidget::TerminalWidget (QWidget *parent) : QWidget (parent) {
	setupUi (this);

	m_vertical_layout->insertWidget (0, &m_txt_terminal);
	connect (&m_txt_terminal, SIGNAL(charTyped (char)), this, SIGNAL(terminalOutput (char)));
	connect (m_btn_clear, SIGNAL(clicked ()), &m_txt_terminal, SLOT(clear ()));
}

void
TerminalWidget::reset () {
	m_txt_terminal.clear ();
}

void
TerminalWidget::terminalInput (char c) {
	QChar ch = c;
	if (ch.isPrint () || ch == '\n' || ch == '\r') {
		m_txt_terminal.insertPlainText (QChar (c));
	}
}

