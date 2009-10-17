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

	union FlagsMask {
		unsigned short flags;
		struct {
			unsigned int f_cf : 1;
			unsigned int __res1 : 1;
			unsigned int f_pf : 1;
			unsigned int __res2 : 1;
			unsigned int f_af : 1;
			unsigned int __res3 : 1;
			unsigned int f_zf : 1;
			unsigned int f_sf : 1;
			unsigned int f_tf : 1;
			unsigned int f_if : 1;
			unsigned int f_df : 1;
			unsigned int f_of : 1;
			unsigned int __res4 : 1;
			unsigned int __res5 : 1;
			unsigned int __res6 : 1;
			unsigned int __res7 : 1;
		};
	};

public:
	/** */
	FlagsWidget (QWidget *parent = 0) : QDockWidget (parent) {
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
	void setFlags (unsigned short i) {
		FlagsMask mask;
		mask.flags = i;

		setFlagCF (mask.f_cf);
		setFlagPF (mask.f_pf);
		setFlagAF (mask.f_af);
		setFlagZF (mask.f_zf);
		setFlagSF (mask.f_sf);
		setFlagTF (mask.f_tf);
		setFlagIF (mask.f_if);
		setFlagDF (mask.f_df);
		setFlagOF (mask.f_of);
	}

	//FIXME - I don't think these are needed
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

}; //end class FlagsWidget

#endif //JAF__FLAGS_WIDGET_HH

