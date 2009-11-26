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
@file StackWidget.hh
@brief Widget for displaying the stack.
*/

#ifndef JAF__STACK_WIDGET_HH
#define JAF__STACK_WIDGET_HH

#include <QtCore>
#include <QtGui>

#include "ui_StackWidget.h"

/**
@class StackWidget
@brief Widget for displaying the stack.
*/
class StackWidget : public QDockWidget, protected Ui::StackWidget {
	Q_OBJECT

public:
	/** */
	StackWidget (QWidget *parent = 0);

	/** */
	void reset ();

public Q_SLOTS:
	/** */
	void enableDisableToggle (bool b);

	/** */
	void push (unsigned short seg, unsigned short off, unsigned short val);

	/** */
	void pop ();

Q_SIGNALS:
	/** */
	void enableDisable (bool b);

}; //end class StackWidget

#endif //JAF__STACK_WIDGET_HH

