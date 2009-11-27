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
@file GeneralRegistersWidget.hh
@brief Widget for displaying the general registers.
*/

#ifndef JAF__GENERAL_REGISTERS_WIDGET_HH
#define JAF__GENERAL_REGISTERS_WIDGET_HH

#include <QtCore>
#include <QtGui>

#include "ui_GeneralRegistersWidget.h"

#include <iostream>

/**
@class GeneralRegistersWidget
@brief Widget for displaying the general registers.
*/
class GeneralRegistersWidget : public QDockWidget, protected Ui::GeneralRegistersWidget {
	Q_OBJECT

public:
	/** */
	GeneralRegistersWidget (QWidget *parent = 0);

	/** */
	void reset ();

public Q_SLOTS:
	/** */
	void enableDisableToggle (bool b);

	/** Set register AX. */
	void setRegAX (unsigned short i);

	/** Set register BX. */
	void setRegBX (unsigned short i);

	/** Set register CX. */
	void setRegCX (unsigned short i);

	/** Set register DX. */
	void setRegDX (unsigned short i);

	/** Set register SI. */
	void setRegSI (unsigned short i);

	/** Set register DI. */
	void setRegDI (unsigned short i);

	/** Set register BP. */
	void setRegBP (unsigned short i);

	/** Set register SP. */
	void setRegSP (unsigned short i);

Q_SIGNALS:
	/** */
	void enableDisable (bool b);

}; //end class GeneralRegistersWidget

#endif //JAF__GENERAL_REGISTERS_WIDGET_HH

