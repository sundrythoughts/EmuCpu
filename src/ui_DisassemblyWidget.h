/********************************************************************************
** Form generated from reading ui file 'DisassemblyWidget.ui'
**
** Created: Tue Oct 6 20:52:36 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DISASSEMBLYWIDGET_H
#define UI_DISASSEMBLYWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DisassemblyWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *m_tbl_prev_next_dis;
    QTableWidget *m_tbl_all_dis;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_btn_clear;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *DisassemblyWidget)
    {
        if (DisassemblyWidget->objectName().isEmpty())
            DisassemblyWidget->setObjectName(QString::fromUtf8("DisassemblyWidget"));
        DisassemblyWidget->resize(453, 444);
        verticalLayout = new QVBoxLayout(DisassemblyWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_tbl_prev_next_dis = new QTableWidget(DisassemblyWidget);
        if (m_tbl_prev_next_dis->columnCount() < 4)
            m_tbl_prev_next_dis->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        m_tbl_prev_next_dis->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        m_tbl_prev_next_dis->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        m_tbl_prev_next_dis->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        m_tbl_prev_next_dis->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (m_tbl_prev_next_dis->rowCount() < 2)
            m_tbl_prev_next_dis->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        m_tbl_prev_next_dis->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        m_tbl_prev_next_dis->setVerticalHeaderItem(1, __qtablewidgetitem5);
        m_tbl_prev_next_dis->setObjectName(QString::fromUtf8("m_tbl_prev_next_dis"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_tbl_prev_next_dis->sizePolicy().hasHeightForWidth());
        m_tbl_prev_next_dis->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        m_tbl_prev_next_dis->setFont(font);

        verticalLayout->addWidget(m_tbl_prev_next_dis);

        m_tbl_all_dis = new QTableWidget(DisassemblyWidget);
        if (m_tbl_all_dis->columnCount() < 4)
            m_tbl_all_dis->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        m_tbl_all_dis->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        m_tbl_all_dis->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        m_tbl_all_dis->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        m_tbl_all_dis->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        m_tbl_all_dis->setObjectName(QString::fromUtf8("m_tbl_all_dis"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_tbl_all_dis->sizePolicy().hasHeightForWidth());
        m_tbl_all_dis->setSizePolicy(sizePolicy1);
        m_tbl_all_dis->setFont(font);

        verticalLayout->addWidget(m_tbl_all_dis);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_btn_clear = new QPushButton(DisassemblyWidget);
        m_btn_clear->setObjectName(QString::fromUtf8("m_btn_clear"));
        m_btn_clear->setFont(font);

        horizontalLayout->addWidget(m_btn_clear);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DisassemblyWidget);

        QMetaObject::connectSlotsByName(DisassemblyWidget);
    } // setupUi

    void retranslateUi(QWidget *DisassemblyWidget)
    {
        DisassemblyWidget->setWindowTitle(QApplication::translate("DisassemblyWidget", "Form", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = m_tbl_prev_next_dis->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DisassemblyWidget", "Address", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = m_tbl_prev_next_dis->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DisassemblyWidget", "Machine Code", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = m_tbl_prev_next_dis->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("DisassemblyWidget", "Assembly Code", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = m_tbl_prev_next_dis->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("DisassemblyWidget", "Addressing Mode", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = m_tbl_prev_next_dis->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("DisassemblyWidget", "Previous", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = m_tbl_prev_next_dis->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("DisassemblyWidget", "Next", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = m_tbl_all_dis->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("DisassemblyWidget", "Address", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = m_tbl_all_dis->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("DisassemblyWidget", "Machine Code", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = m_tbl_all_dis->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("DisassemblyWidget", "Assembly Code", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = m_tbl_all_dis->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("DisassemblyWidget", "Addressing Mode", 0, QApplication::UnicodeUTF8));
        m_btn_clear->setText(QApplication::translate("DisassemblyWidget", "Clear", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(DisassemblyWidget);
    } // retranslateUi

};

namespace Ui {
    class DisassemblyWidget: public Ui_DisassemblyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISASSEMBLYWIDGET_H
