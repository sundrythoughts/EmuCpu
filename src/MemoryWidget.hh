#ifndef JAF__MEMORY_WIDGET_HH
#define JAF__MEMORY_WIDGET_HH

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
		//resize (100000);
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

	void setMemoryAddress (int addr, unsigned char val);

	void setAllMemoryAddresses (const unsigned char *arr, size_t sz);

private:
	void setTableWidgetRowFromStrings (int row, const QString &raw_mem, const QString &ascii);
};

#endif //JAF__MEMORY_WIDGET_HH

