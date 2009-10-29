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

public slots:
	/** */
	void enableDisableToggle (bool b);

	/** */
	void setRegAX (unsigned short i);

	/** */
	void setRegBX (unsigned short i);

	/** */
	void setRegCX (unsigned short i);

	/** */
	void setRegDX (unsigned short i);

	/** */
	void setRegSI (unsigned short i);

	/** */
	void setRegDI (unsigned short i);

	/** */
	void setRegBP (unsigned short i);

	/** */
	void setRegSP (unsigned short i);

signals:
	/** */
	void enableDisable (bool b);

}; //end class GeneralRegistersWidget

#endif //JAF__GENERAL_REGISTERS_WIDGET_HH

