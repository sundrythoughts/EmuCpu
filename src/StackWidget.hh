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
	StackWidget (QWidget *parent = 0) : QDockWidget (parent) {
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

		emit enableDisable (b);
	}

signals:
	/** */
	void enableDisable (bool b);

}; //end class StackWidget

#endif //JAF__STACK_WIDGET_HH

