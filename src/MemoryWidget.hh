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

