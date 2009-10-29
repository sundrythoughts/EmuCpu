/**
@file MemoryWidget.hh
@brief Widget for displaying the memory.
*/

#ifndef JAF__MEMORY_WIDGET_HH
#define JAF__MEMORY_WIDGET_HH

#include <QtCore>
#include <QtGui>

#include <iostream>

#include "ui_MemoryWidget.h"

/**
@class MemoryWidget
@brief Widget for displaying the memory.
*/
class MemoryWidget : public QWidget, protected Ui::MemoryWidget {
	Q_OBJECT

public:
	/** */
	MemoryWidget (QWidget *parent = 0);

public slots:
	/** */
	void enableDisableToggle (bool b);

	/** */
	void resize (size_t sz);

	/** */
	void setMemoryAddress (int addr, unsigned char val);

	/** */
	void setAllMemoryAddresses (const unsigned char *arr, size_t sz);

signals:
	/** */
	void enableDisable (bool b);

private:
	void setTableWidgetRowFromStrings (int row, const QString &raw_mem, const QString &ascii);

}; //end namespace MemoryWidget

#endif //JAF__MEMORY_WIDGET_HH

