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
@file TerminalTextEdit.hh
@brief Overrides key presses and mouse presses to act as a terminal.
*/

#ifndef SIM8086__TERMINAL_TEXT_EDIT_HH
#define SIM8086__TERMINAL_TEXT_EDIT_HH

#include <QtCore>
#include <QtGui>

/**
@class TerminalTextEdit
@brief Overrides key presses and mouse presses to act as a terminal.
*/
class TerminalTextEdit : public QTextEdit {
	Q_OBJECT

public:
	/** */
	TerminalTextEdit (QWidget *parent = 0);

	//override
	/** @brief Grab key presses. */
	virtual void keyPressEvent (QKeyEvent *event);

	//override
	/** @brief Grab mouse presses. */
	virtual void mousePressEvent (QMouseEvent *event);

private Q_SLOTS:
	void scrollToCursor ();

Q_SIGNALS:
	/** @brief Qt signal emitted when a keyboard printable character is pressed. */
	void charTyped (char c);

}; //class TerminalTextEdit

#endif //SIM8086__TERMINAL_TEXT_EDIT_HH

