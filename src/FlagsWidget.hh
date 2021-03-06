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
@file FlagsWidget.hh
@brief Widget for displaying the flags.
*/

#ifndef EMUCPU__FLAGS_WIDGET_HH
#define EMUCPU__FLAGS_WIDGET_HH

#include <QtCore>
#include <QtGui>

#include "ui_FlagsWidget.hh"

/**
@class FlagsWidget
@brief Widget for displaying the flags
*/
class FlagsWidget : public QDockWidget, protected Ui::FlagsWidget {
	Q_OBJECT

public:
	/** */
	FlagsWidget (QWidget *parent = 0);

	/** */
	void reset ();

public Q_SLOTS:
	/** */
	void enableDisableToggle (bool b);

	/** @brief Set the flags to a new value. */
	void setFlags (unsigned short i);

Q_SIGNALS:
	/** */
	void enableDisable (bool b);

private:
	void setFlagCF (bool v);
	void setFlagPF (bool v);
	void setFlagAF (bool v);
	void setFlagZF (bool v);
	void setFlagSF (bool v);
	void setFlagTF (bool v);
	void setFlagIF (bool v);
	void setFlagDF (bool v);
	void setFlagOF (bool v);

}; //end class FlagsWidget

#endif //EMUCPU__FLAGS_WIDGET_HH

