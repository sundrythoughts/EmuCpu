#ifndef TERMINAL_WIDGET_HH
#define TERMINAL_WIDGET_HH

#include <QtCore>
#include <QtGui>

#include "ui_TerminalWidget.h"

class TerminalWidget : public QWidget, protected Ui::TerminalWidget {
	Q_OBJECT

public:
	TerminalWidget (QWidget *parent = 0) : QWidget (parent) {
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

#endif //TERMINAL_WIDGET_HH

