#ifndef DISASSEMBLY_WIDGET_HH
#define DISASSEMBLY_WIDGET_HH

#include <QtCore>
#include <QtGui>

#include "ui_DisassemblyWidget.h"

class DisassemblyWidget : public QWidget, protected Ui::DisassemblyWidget {
	Q_OBJECT

public:
	DisassemblyWidget (QWidget *parent = 0) : QWidget (parent) {
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

#endif //DISASSEMBLY_WIDGET_HH

