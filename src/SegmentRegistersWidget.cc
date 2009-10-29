#include "SegmentRegistersWidget.hh"


SegmentRegistersWidget::SegmentRegistersWidget (QWidget *parent) : QDockWidget (parent) {
	setupUi (this);
}


void
SegmentRegistersWidget::enableDisableToggle (bool b) {
	if (b) {
		show ();
	}
	else {
		hide ();
	}

	emit enableDisable (b);
}


void
SegmentRegistersWidget::setSegRegCS (unsigned short i) {
	m_ln_cs->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
SegmentRegistersWidget::setSegRegDS (unsigned short i) {
	m_ln_ds->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
SegmentRegistersWidget::setSegRegES (unsigned short i) {
	m_ln_es->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
SegmentRegistersWidget::setSegRegSS (unsigned short i) {
	m_ln_ss->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}


void
SegmentRegistersWidget::setRegIP (unsigned short i) {
	m_ln_ip->setText (QString::number (i, 16).rightJustified (4, '0').toUpper ());
}

