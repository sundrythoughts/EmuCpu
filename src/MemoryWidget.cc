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


#include "MemoryWidget.hh"

MemoryWidget::MemoryWidget (QWidget *parent) : QWidget (parent) {
	setupUi (this);

	//FIXME - temp test
	//resize (100000);
}


void
MemoryWidget::enableDisableToggle (bool b) {
	if (b) {
		show ();
	}
	else {
		hide ();
	}

	emit enableDisable (b);
}


void
MemoryWidget::resize (size_t sz) {
	int curr_cnt = m_tbl_memory->rowCount ();
	size_t mod = sz % 16;
	sz /= 16;
	if (mod) {
		++sz;
	}
	m_tbl_memory->setRowCount (sz);
	for (size_t i = curr_cnt; i < sz; ++i) {
		QTableWidgetItem *item = new QTableWidgetItem (QString::number (i * 16, 16).toUpper ().rightJustified (5, '0'));
		m_tbl_memory->setVerticalHeaderItem (i, item);
	}
	//std::cout << "resize" << std::endl;
}


//FIXME - doesn't check for validity of QTableWidgetItem
void
MemoryWidget::setMemoryAddress (int addr, unsigned char val) {
	//std::cout << "setMemoryAddress: " << addr << ", " << (unsigned int)val << std::endl;

	int row_index = addr / 16;
	int elmt_index = addr % 16;

	QTableWidgetItem *mem = m_tbl_memory->item (row_index, 0);
	QTableWidgetItem *ascii = m_tbl_memory->item (row_index, 1);

	if (!mem || !ascii) {
		return;
	}

	QString mem_str = m_tbl_memory->item (row_index, 0)->text ();
	mem_str.replace (" - ", " ");
	QStringList list = mem_str.split (' ', QString::SkipEmptyParts);
	list[elmt_index] = QString::number (val, 16).toUpper ().rightJustified (2, '0');
	mem_str.clear ();
	int i;
	for (i = 0; i < list.size () - 1; ++i) {
		mem_str += list[i];
		if (i == 7) {
			mem_str += " - ";
		}
		else {
			mem_str += ' ';
		}
	}
	mem_str += list[i];
	m_tbl_memory->item (row_index, 0)->setText (mem_str);

	QString ascii_str = m_tbl_memory->item (row_index, 1)->text ();
	ascii_str[elmt_index] = QChar (val);
	m_tbl_memory->item (row_index, 1)->setText (ascii_str);
}


void
MemoryWidget::setAllMemoryAddresses (const unsigned char *arr, size_t sz) {
	//FIXME
	//std::cout << "setAllMemoryAddresses" << std::endl;
	//for (size_t i = 0; i < sz; ++i) {
	//	std::cout << (unsigned int)arr[i] << ' ';
	//}
	//std::cout << std::endl;
	QString raw_mem, ascii;
	QChar ascii_char;
	size_t row = 0;
	size_t key = 1;
	size_t i;
	for (i = 0; i < sz; ++i, ++key) {
		raw_mem += QString::number (arr[i], 16).toUpper ().rightJustified (2, '0');
		ascii_char = (char)arr[i];

		if (ascii_char.isPrint ()) {
			ascii += ascii_char;
		}
		else {
			ascii += '.';
		}

		if (key == 16 || i == sz - 1) {
			setTableWidgetRowFromStrings (row, raw_mem, ascii);

			//std::cout << raw_mem.toStdString () << " : " << QString::number (row, 16).toStdString () << std::endl;

			raw_mem.clear ();
			ascii.clear ();
			++row;
			key = 0;
		}
		else if (key == 8) {
			raw_mem += " - ";
		}
		else {
			raw_mem += ' ';
		}
	}
}


void
MemoryWidget::setTableWidgetRowFromStrings (int row, const QString &raw_mem, const QString &ascii) {
	QTableWidgetItem *item_raw_mem = m_tbl_memory->item (row, 0);
	if (!item_raw_mem) {
		item_raw_mem = new QTableWidgetItem ();
		m_tbl_memory->setItem (row, 0, item_raw_mem);
	}
	item_raw_mem->setText (raw_mem);

	QTableWidgetItem *item_ascii = m_tbl_memory->item (row, 1);
	if (!item_ascii) {
		item_ascii = new QTableWidgetItem ();
		m_tbl_memory->setItem (row, 1, item_ascii);
	}
	item_ascii->setText (ascii);
}

