#ifndef MEMORY_WIDGET_HH
#define MEMORY_WIDGET_HH

#include <QtCore>
#include <QtGui>

#include "ui_MemoryWidget.h"

class MemoryWidget : public QWidget, protected Ui::MemoryWidget {
	Q_OBJECT

public:
	MemoryWidget (QWidget *parent = 0) : QWidget (parent) {
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

#endif //MEMORY_WIDGET_HH

