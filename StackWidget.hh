#ifndef STACK_WIDGET_HH
#define STACK_WIDGET_HH

#include <QtCore>
#include <QtGui>

#include "ui_StackWidget.h"

class StackWidget : public QDockWidget, protected Ui::StackWidget {
	Q_OBJECT

public:
	StackWidget (QWidget *parent = 0) : QDockWidget (parent) {
		setupUi (this);
	}

public slots:
	void enableDisableToggle (bool b) {
		if (b) {
			show ();
		}
		else {
			hide ();
		}
	}
};

#endif //STACK_WIDGET_HH

