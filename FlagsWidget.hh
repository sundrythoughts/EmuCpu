#ifndef FLAGS_WIDGET_HH
#define FLAGS_WIDGET_HH

#include <QtCore>
#include <QtGui>

#include "ui_FlagsWidget.h"

class FlagsWidget : public QDockWidget, protected Ui::FlagsWidget {
	Q_OBJECT

public:
	FlagsWidget (QWidget *parent = 0) : QDockWidget (parent) {
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

	void setFlagCF (bool v) {
		m_lcd_cf->display (v);
	}

	void setFlagPF (bool v) {
		m_lcd_pf->display (v);
	}

	void setFlagAF (bool v) {
		m_lcd_af->display (v);
	}

	void setFlagZF (bool v) {
		m_lcd_zf->display (v);
	}

	void setFlagSF (bool v) {
		m_lcd_sf->display (v);
	}

	void setFlagTF (bool v) {
		m_lcd_tf->display (v);
	}

	void setFlagIF (bool v) {
		m_lcd_if->display (v);
	}

	void setFlagDF (bool v) {
		m_lcd_df->display (v);
	}

	void setFlagOF (bool v) {
		m_lcd_of->display (v);
	}
};

#endif //FLAGS_WIDGET_HH

