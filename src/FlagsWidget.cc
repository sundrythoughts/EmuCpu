/*
 * sim8086 -- Emulates an Intel 8086 processor
 * Copyright (C) 2009  Joseph Freeman (jfree143dev AT gmail DOT com)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


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
FlagsWidget::reset () {
	setFlags (0);
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
