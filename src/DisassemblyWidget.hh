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
@file DisassemblyWidget.hh
@brief Widget for displaying the disassembly.
*/

#ifndef EMUCPU__DISASSEMBLY_WIDGET_HH
#define EMUCPU__DISASSEMBLY_WIDGET_HH

#include <QtCore>
#include <QtGui>

#include "ui_DisassemblyWidget.hh"

/**
@class DisassemblyWidget
@brief Widget for displaying the disassembly
*/
class DisassemblyWidget : public QWidget, protected Ui::DisassemblyWidget {
	Q_OBJECT

public:
	/** */
	DisassemblyWidget (QWidget *parent = 0);

	/** @brief Clear the widget. */
	void reset ();

public Q_SLOTS:
	/** @brief Enable/disable widget. */
	void enableDisableToggle (bool b);

	/** @brief Add dissassembly to widget. */
	void addNextInstruction (QString seg_off, QString mcode, QString asm_code, QString addr_mode);

Q_SIGNALS:
	/** @brief The widget has been enabled/disabled. */
	void enableDisable (bool b);

}; //end class DisassemblyWidget

#endif //EMUCPU__DISASSEMBLY_WIDGET_HH

