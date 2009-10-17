/**
@file SegmentRegistersWidget.hh
@brief Widget for displaying the segment registers.
*/

#ifndef JAF__SEGMENT_REGISTERS_WIDGET_HH
#define JAF__SEGMENT_REGISTERS_WIDGET_HH

#include <QtCore>
#include <QtGui>

#include "ui_SegmentRegistersWidget.h"


/**
@class SegmentRegistersWidget
@brief Widget for displaying the segment registers.
*/
class SegmentRegistersWidget : public QDockWidget, protected Ui::SegmentRegistersWidget {
	Q_OBJECT

public:
	/** */
	SegmentRegistersWidget (QWidget *parent = 0) : QDockWidget (parent) {
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

	/** */
	void setSegRegCS (unsigned short i) {
		m_ln_cs->setText (QString::number (i, 16).toUpper ());
	}

	/** */
	void setSegRegDS (unsigned short i) {
		m_ln_ds->setText (QString::number (i, 16).toUpper ());
	}

	/** */
	void setSegRegES (unsigned short i) {
		m_ln_es->setText (QString::number (i, 16).toUpper ());
	}

	/** */
	void setSegRegSS (unsigned short i) {
		m_ln_ss->setText (QString::number (i, 16).toUpper ());
	}

	/** */
	void setRegIP (unsigned short i) {
		m_ln_ip->setText (QString::number (i, 16).toUpper ());
	}

}; //end class SegmentRegistersWidget

#endif //JAF__SEGMENT_REGISTERS_WIDGET_HH

