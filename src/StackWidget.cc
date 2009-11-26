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


#include "StackWidget.hh"
#include <iostream>

StackWidget::StackWidget (QWidget *parent) : QDockWidget (parent) {
	setupUi (this);
}

void
StackWidget::reset () {
	m_txt_stack->clear ();
}

void
StackWidget::enableDisableToggle (bool b) {
	if (b) {
		show ();
	}
	else {
		hide ();
	}

	Q_EMIT enableDisable (b);
}

void
StackWidget::push (unsigned short seg, unsigned short off, unsigned short val) {
	QString s;
	s = QString::number (seg, 16).rightJustified (4, '0').toUpper ();
	s += ":";
	s += QString::number (off, 16).rightJustified (4, '0').toUpper ();
	s += "    ";
	s += QString::number (val, 16).rightJustified (4, '0').toUpper ();
	s += "\n";

	QTextCursor cur = m_txt_stack->textCursor ();
	cur.movePosition (QTextCursor::Start);
	cur.insertText (s);
	m_txt_stack->setTextCursor (cur);
}

void
StackWidget::pop () {
	QTextCursor cur = m_txt_stack->textCursor ();
	cur.movePosition (QTextCursor::Start);
	cur.select (QTextCursor::LineUnderCursor);
	cur.removeSelectedText ();
	cur.deleteChar ();
	m_txt_stack->setTextCursor (cur);
}

