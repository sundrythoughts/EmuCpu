#ifndef GENERAL_REGISTERS_WIDGET_HH
#define GENERAL_REGISTERS_WIDGET_HH

#include <QtCore>
#include <QtGui>

#include "ui_GeneralRegistersWidget.h"

#include <iostream>

class GeneralRegistersWidget : public QDockWidget, protected Ui::GeneralRegistersWidget {
	Q_OBJECT

public:
	GeneralRegistersWidget (QWidget *parent = 0) : QDockWidget (parent) {
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

	void setRegAX (unsigned short i) {
		m_ln_ax->setText (QString::number (i, 16));
	}

	void setRegBX (unsigned short i) {
		m_ln_bx->setText (QString::number (i, 16));
	}

	void setRegCX (unsigned short i) {
		m_ln_cx->setText (QString::number (i, 16));
	}

	void setRegDX (unsigned short i) {
		m_ln_dx->setText (QString::number (i, 16));
	}

	void setRegSI (unsigned short i) {
		m_ln_si->setText (QString::number (i, 16));
	}

	void setRegDI (unsigned short i) {
		m_ln_di->setText (QString::number (i, 16));
	}

	void setRegBP (unsigned short i) {
		m_ln_bp->setText (QString::number (i, 16));
	}

	void setRegSP (unsigned short i) {
		m_ln_sp->setText (QString::number (i, 16));
	}
};

#endif //GENERAL_REGISTERS_WIDGET_HH

