#include "FlagsWidget.hh"

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

FlagsWidget::FlagsWidget (QWidget *parent) : QDockWidget (parent) {
	setupUi (this);
}

void
FlagsWidget::enableDisableToggle (bool b) {
	if (b) {
		show ();
	}
	else {
		hide ();
	}

	emit enableDisable (b);
}

void
FlagsWidget::setFlags (unsigned short i) {
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


void
FlagsWidget::setFlagCF (bool v) {
	m_lcd_cf->display (v);
}

void
FlagsWidget::setFlagPF (bool v) {
	m_lcd_pf->display (v);
}

void
FlagsWidget::setFlagAF (bool v) {
	m_lcd_af->display (v);
}

void
FlagsWidget::setFlagZF (bool v) {
	m_lcd_zf->display (v);
}

void
FlagsWidget::setFlagSF (bool v) {
	m_lcd_sf->display (v);
}

void
FlagsWidget::setFlagTF (bool v) {
	m_lcd_tf->display (v);
}

void
FlagsWidget::setFlagIF (bool v) {
	m_lcd_if->display (v);
}

void
FlagsWidget::setFlagDF (bool v) {
	m_lcd_df->display (v);
}

void
FlagsWidget::setFlagOF (bool v) {
	m_lcd_of->display (v);
}
