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

