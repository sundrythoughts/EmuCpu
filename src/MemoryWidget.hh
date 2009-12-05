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
@file MemoryWidget.hh
@brief Widget for displaying the memory.
*/

#ifndef JAF__MEMORY_WIDGET_HH
#define JAF__MEMORY_WIDGET_HH

#include <QtCore>
#include <QtGui>

#include <iostream>

#include "ui_MemoryWidget.h"

/**
@class MemoryWidget
@brief Widget for displaying the memory.
*/
class MemoryWidget : public QWidget, protected Ui::MemoryWidget {
	Q_OBJECT

public:
	/** */
	MemoryWidget (QWidget *parent = 0);

public Q_SLOTS:
	/** @brief Enable/disable this widget display. */
	void enableDisableToggle (bool b);

	/** @brief Resize the amount of data displayed in the widget. */
	void resize (size_t sz);

	/** @brief Update a memory address in the display to show a new value. */
	void setMemoryAddress (int addr, unsigned char val);

	/** @brief Reset all memory addresses in the display to show new values. */
	void setAllMemoryAddresses (const unsigned char *arr, size_t sz);

Q_SIGNALS:
	/** @brief The display widget has been enabled/disabled. */
	void enableDisable (bool b);

private:
	//internal use for manipulating which value in a row will be updated
	void setTableWidgetRowFromStrings (int row, const QString &raw_mem, const QString &ascii);

}; //end namespace MemoryWidget

#endif //JAF__MEMORY_WIDGET_HH

