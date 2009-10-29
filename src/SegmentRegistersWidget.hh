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
	SegmentRegistersWidget (QWidget *parent = 0);

public slots:
	/** */
	void enableDisableToggle (bool b);

	/** */
	void setSegRegCS (unsigned short i);

	/** */
	void setSegRegDS (unsigned short i);

	/** */
	void setSegRegES (unsigned short i);

	/** */
	void setSegRegSS (unsigned short i);

	/** */
	void setRegIP (unsigned short i);

signals:
	/** */
	void enableDisable (bool b);

}; //end class SegmentRegistersWidget

#endif //JAF__SEGMENT_REGISTERS_WIDGET_HH

