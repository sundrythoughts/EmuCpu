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


#include "DisassemblyWidget.hh"
#include <iostream>

DisassemblyWidget::DisassemblyWidget (QWidget *parent) : QWidget (parent) {
	setupUi (this);
}

void
DisassemblyWidget::reset () {
	m_tbl_disasm->clearContents ();
	m_txt_disasm->clear ();
}

void
DisassemblyWidget::enableDisableToggle (bool b) {
	if (b) {
		show ();
	}
	else {
		hide ();
	}

	Q_EMIT enableDisable (b);
}


void
DisassemblyWidget::addNextInstruction (QString seg_off, QString mcode, QString asm_code, QString addr_mode) {
	seg_off = seg_off.toUpper ();
	mcode = mcode.toUpper ();
	asm_code = asm_code.toUpper ();

	m_txt_disasm->append (seg_off + '\t' + mcode + '\t' + asm_code + "\t\t" + addr_mode);


#if 0 //FIXME - table looks good but is very slow
	//FIXME - this may not work in 8.04
	QTextCursor cur (m_txt_disasm->textCursor());
	QTextTable *txt_tbl = cur.currentTable ();
	if (!txt_tbl) {
		txt_tbl = cur.insertTable (1, 4);
	}
	else {
		txt_tbl->appendRows (1);
	}

	QTextTableCell cell = txt_tbl->cellAt (txt_tbl->rows () - 1, 0);
	QTextCursor cell_cur = cell.firstCursorPosition ();
	cell_cur.insertText (seg_off);

	cell = txt_tbl->cellAt (txt_tbl->rows () - 1, 1);
	cell_cur = cell.firstCursorPosition ();
	cell_cur.insertText (mcode);

	cell = txt_tbl->cellAt (txt_tbl->rows () - 1, 2);
	cell_cur = cell.firstCursorPosition ();
	cell_cur.insertText (asm_code);

	cell = txt_tbl->cellAt (txt_tbl->rows () - 1, 3);
	cell_cur = cell.firstCursorPosition ();
	cell_cur.insertText (addr_mode);

	m_txt_disasm->setTextCursor (cur);
#endif

	//FIXME - it would be nice to have this in an HTML table
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

	m_tbl_disasm->resizeColumnsToContents ();
}

