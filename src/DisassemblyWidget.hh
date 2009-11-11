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
@file DisassemblyWidget.hh
@brief Widget for displaying the disassembly.
*/

#ifndef JAF__DISASSEMBLY_WIDGET_HH
#define JAF__DISASSEMBLY_WIDGET_HH

#include <QtCore>
#include <QtGui>

#include "ui_DisassemblyWidget.h"

/**
@class DisassemblyWidget
@brief Widget for displaying the disassembly
*/
class DisassemblyWidget : public QWidget, protected Ui::DisassemblyWidget {
	Q_OBJECT

public:
	/** */
	DisassemblyWidget (QWidget *parent = 0);

	/** */
	void reset ();

public slots:
	/** */
	void enableDisableToggle (bool b);

	/** */
	void addNextInstruction (QString seg_off, QString mcode, QString asm_code, QString addr_mode);

signals:
	/** */
	void enableDisable (bool b);

}; //end class DisassemblyWidget

#endif //JAF__DISASSEMBLY_WIDGET_HH

