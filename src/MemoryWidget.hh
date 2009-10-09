#ifndef MEMORY_WIDGET_HH
#define MEMORY_WIDGET_HH

#include <QtCore>
#include <QtGui>

#include <iostream>

#include "ui_MemoryWidget.h"

class MemoryWidget : public QWidget, protected Ui::MemoryWidget {
	Q_OBJECT

public:
	MemoryWidget (QWidget *parent = 0) : QWidget (parent) {
		setupUi (this);

		//FIXME - temp test
		resize (100000);
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

	void resize (size_t sz) {
		int curr_cnt = m_tbl_memory->rowCount ();
		m_tbl_memory->setRowCount (sz);
		for (size_t i = curr_cnt; i < sz; ++i) {
			QTableWidgetItem *item = new QTableWidgetItem (QString::number (i, 16).toUpper ().rightJustified (5, '0'));
			m_tbl_memory->setVerticalHeaderItem (i, item);
		}
	}

	void setMemoryAddress (int addr, unsigned char val) {
		//if (addr >= m_tbl_memory->rowCount ()) {
		//	m_tbl_memory->setRowCount (addr);
		//}

		//QTableWidgetItem *item = new QTableWidgetItem (QString::number (val).toUpper ());
		//m_tbl_memory->setItem (addr, 0, item);
		//std::cout << (unsigned int)val << ' ';
		//FIXME
	}

	void setAllMemoryAddresses (const unsigned char *arr, size_t sz) {
		//FIXME
	}
};

#endif //MEMORY_WIDGET_HH

