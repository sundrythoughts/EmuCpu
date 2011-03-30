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

#ifndef SIM8086__STACK_WIDGET_HH
#define SIM8086__STACK_WIDGET_HH

#include <QtCore>
#include <QtGui>

#include "ui_StackWidget.hh"

/**
@class StackWidget
@brief Widget for displaying the stack.
*/
class StackWidget : public QDockWidget, protected Ui::StackWidget {
	Q_OBJECT

public:
	/** */
	StackWidget (QWidget *parent = 0);

	/** @brief Set this widget to its default values. */
	void reset ();

public Q_SLOTS:
	/** @brief Enable/disable this widget display. */
	void enableDisableToggle (bool b);

	/** @brief Add a set of values to the stack widget. */
	void push (unsigned short seg, unsigned short off, unsigned short val);

	/** @brief Remove the top set of values from the stack widget. */
	void pop ();

Q_SIGNALS:
	/** @brief This widget has benn enabled/disabled. */
	void enableDisable (bool b);

}; //end class StackWidget

#endif //SIM8086__STACK_WIDGET_HH

