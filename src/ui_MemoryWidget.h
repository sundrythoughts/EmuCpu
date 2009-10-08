/********************************************************************************
** Form generated from reading ui file 'MemoryWidget.ui'
**
** Created: Tue Oct 6 20:52:36 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MEMORYWIDGET_H
#define UI_MEMORYWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MemoryWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *m_tbl_memory;

    void setupUi(QWidget *MemoryWidget)
    {
        if (MemoryWidget->objectName().isEmpty())
            MemoryWidget->setObjectName(QString::fromUtf8("MemoryWidget"));
        MemoryWidget->resize(733, 640);
        verticalLayout = new QVBoxLayout(MemoryWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_tbl_memory = new QTableWidget(MemoryWidget);
        if (m_tbl_memory->columnCount() < 2)
            m_tbl_memory->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        m_tbl_memory->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        m_tbl_memory->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (m_tbl_memory->rowCount() < 1)
            m_tbl_memory->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        m_tbl_memory->setVerticalHeaderItem(0, __qtablewidgetitem2);
        m_tbl_memory->setObjectName(QString::fromUtf8("m_tbl_memory"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        m_tbl_memory->setFont(font);

        verticalLayout->addWidget(m_tbl_memory);


        retranslateUi(MemoryWidget);

        QMetaObject::connectSlotsByName(MemoryWidget);
    } // setupUi

    void retranslateUi(QWidget *MemoryWidget)
    {
        MemoryWidget->setWindowTitle(QApplication::translate("MemoryWidget", "Form", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = m_tbl_memory->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MemoryWidget", "Raw Data", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = m_tbl_memory->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MemoryWidget", "ASCII Data", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = m_tbl_memory->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MemoryWidget", "1", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MemoryWidget);
    } // retranslateUi

};

namespace Ui {
    class MemoryWidget: public Ui_MemoryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMORYWIDGET_H
