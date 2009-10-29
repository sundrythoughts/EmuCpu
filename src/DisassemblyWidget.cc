#include "DisassemblyWidget.hh"
#include <iostream>

DisassemblyWidget::DisassemblyWidget (QWidget *parent) : QWidget (parent) {
	setupUi (this);
}

void
DisassemblyWidget::enableDisableToggle (bool b) {
	if (b) {
		show ();
	}
	else {
		hide ();
	}

	emit enableDisable (b);
}


void
DisassemblyWidget::addNextInstruction (QString seg_off, QString mcode, QString asm_code, QString addr_mode) {
	seg_off = seg_off.toUpper ();
	mcode = mcode.toUpper ();
	asm_code = asm_code.toUpper ();

	m_txt_disasm->append (seg_off + '\t' + mcode + '\t' + asm_code + '\t' + addr_mode);

	m_tbl_disasm->setItem (0, 0, m_tbl_disasm->takeItem (1, 0));
	m_tbl_disasm->setItem (0, 1, m_tbl_disasm->takeItem (1, 1));
	m_tbl_disasm->setItem (0, 2, m_tbl_disasm->takeItem (1, 2));
	m_tbl_disasm->setItem (0, 3, m_tbl_disasm->takeItem (1, 3));

	QTableWidgetItem *seg_off_item = new QTableWidgetItem (seg_off);
	QTableWidgetItem *mcode_item = new QTableWidgetItem (mcode);
	QTableWidgetItem *asm_code_item = new QTableWidgetItem (asm_code);
	QTableWidgetItem *addr_mode_item = new QTableWidgetItem (addr_mode);

	m_tbl_disasm->setItem (1, 0, seg_off_item);
	m_tbl_disasm->setItem (1, 1, mcode_item);
	m_tbl_disasm->setItem (1, 2, asm_code_item);
	m_tbl_disasm->setItem (1, 3, addr_mode_item);
}

