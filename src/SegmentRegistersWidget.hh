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
@file SegmentRegistersWidget.hh
@brief Widget for displaying the segment registers.
*/

#ifndef JAF__SEGMENT_REGISTERS_WIDGET_HH
#define JAF__SEGMENT_REGISTERS_WIDGET_HH

#include <QtCore>
#include <QtGui>

#include "ui_SegmentRegistersWidget.h"


/**
@class SegmentRegistersWidget
@brief Widget for displaying the segment registers.
*/
class SegmentRegistersWidget : public QDockWidget, protected Ui::SegmentRegistersWidget {
	Q_OBJECT

public:
	/** */
	SegmentRegistersWidget (QWidget *parent = 0);

public slots:
	/** */
	void enableDisableToggle (bool b);

	/** */
	void setSegRegCS (unsigned short i);

	/** */
	void setSegRegDS (unsigned short i);

	/** */
	void setSegRegES (unsigned short i);

	/** */
	void setSegRegSS (unsigned short i);

	/** */
	void setRegIP (unsigned short i);

signals:
	/** */
	void enableDisable (bool b);

}; //end class SegmentRegistersWidget

#endif //JAF__SEGMENT_REGISTERS_WIDGET_HH

