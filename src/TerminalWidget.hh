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
@file TerminalWidget.hh
@brief Widget for displaying the terminal.
*/

#ifndef EMUCPU__TERMINAL_WIDGET_HH
#define EMUCPU__TERMINAL_WIDGET_HH

#include <QtCore>
#include <QtGui>
#include "TerminalTextEdit.hh"

#include "ui_TerminalWidget.hh"

/**
@class TerminalWidget
@brief Widget for displaying the terminal.
*/
class TerminalWidget : public QWidget, protected Ui::TerminalWidget {
	Q_OBJECT
	TerminalTextEdit m_txt_terminal;

public:
	/** */
	TerminalWidget (QWidget *parent = 0);

	/** @brief Set the widget back to its default state. */
	void reset ();

public Q_SLOTS:
	/** @brief Write a character onto the terminal. */
	void terminalInput (char c);

Q_SIGNALS:
	/** @brief Character read from the terminal. */
	void terminalOutput (char c);

}; //end class TerminalWidget

#endif //EMUCPU__TERMINAL_WIDGET_HH

