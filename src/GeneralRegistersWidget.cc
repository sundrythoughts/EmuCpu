#include "GeneralRegistersWidget.hh"

GeneralRegistersWidget::GeneralRegistersWidget (QWidget *parent) : QDockWidget (parent) {
	setupUi (this);
}


void
GeneralRegistersWidget::enableDisableToggle (bool b) {
	if (b) {
		show ();
	}
	else {
		hide ();
	}

	emit enableDisable (b);
}


void
GeneralRegistersWidget::setRegAX (unsigned short i) {
	m_ln_ax->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
GeneralRegistersWidget::setRegBX (unsigned short i) {
	m_ln_bx->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
GeneralRegistersWidget::setRegCX (unsigned short i) {
	m_ln_cx->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
GeneralRegistersWidget::setRegDX (unsigned short i) {
	m_ln_dx->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
GeneralRegistersWidget::setRegSI (unsigned short i) {
	m_ln_si->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
GeneralRegistersWidget::setRegDI (unsigned short i) {
	m_ln_di->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
GeneralRegistersWidget::setRegBP (unsigned short i) {
	m_ln_bp->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
GeneralRegistersWidget::setRegSP (unsigned short i) {
	m_ln_sp->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}

