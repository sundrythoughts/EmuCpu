/**
@file FlagsWidget.hh
@brief Widget for displaying the flags.
*/

#ifndef JAF__FLAGS_WIDGET_HH
#define JAF__FLAGS_WIDGET_HH

#include <QtCore>
#include <QtGui>

#include "ui_FlagsWidget.h"

/**
@class FlagsWidget
@brief Widget for displaying the flags
*/
class FlagsWidget : public QDockWidget, protected Ui::FlagsWidget {
	Q_OBJECT

public:
	/** */
	FlagsWidget (QWidget *parent = 0);

public slots:
	/** */
	void enableDisableToggle (bool b);

	/** */
	void setFlags (unsigned short i);

signals:
	/** */
	void enableDisable (bool b);

private:
	void setFlagCF (bool v);
	void setFlagPF (bool v);
	void setFlagAF (bool v);
	void setFlagZF (bool v);
	void setFlagSF (bool v);
	void setFlagTF (bool v);
	void setFlagIF (bool v);
	void setFlagDF (bool v);
	void setFlagOF (bool v);

}; //end class FlagsWidget

#endif //JAF__FLAGS_WIDGET_HH

