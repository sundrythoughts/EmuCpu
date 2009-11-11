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
@file TerminalWidget.hh
@brief Widget for displaying the terminal.
*/

#ifndef JAF__TERMINAL_WIDGET_HH
#define JAF__TERMINAL_WIDGET_HH

#include <QtCore>
#include <QtGui>

#include "ui_TerminalWidget.h"

/**
@class TerminalWidget
@brief Widget for displaying the terminal.
*/
class TerminalWidget : public QWidget, protected Ui::TerminalWidget {
	Q_OBJECT

public:
	/** */
	TerminalWidget (QWidget *parent = 0) : QWidget (parent) {
		setupUi (this);
	}

	/** */
	void reset ();

public slots:
	/** */
	void enableDisableToggle (bool b) {
		if (b) {
			show ();
		}
		else {
			hide ();
		}
	}

}; //end class TerminalWidget

#endif //JAF__TERMINAL_WIDGET_HH

