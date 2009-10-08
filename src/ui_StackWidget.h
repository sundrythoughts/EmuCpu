/********************************************************************************
** Form generated from reading ui file 'StackWidget.ui'
**
** Created: Tue Oct 6 20:52:36 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_STACKWIDGET_H
#define UI_STACKWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHeaderView>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StackWidget
{
public:
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QTableWidget *m_tbl_stack;

    void setupUi(QDockWidget *StackWidget)
    {
        if (StackWidget->objectName().isEmpty())
            StackWidget->setObjectName(QString::fromUtf8("StackWidget"));
        StackWidget->resize(346, 422);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        StackWidget->setFont(font);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_tbl_stack = new QTableWidget(dockWidgetContents);
        if (m_tbl_stack->columnCount() < 2)
            m_tbl_stack->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        m_tbl_stack->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        m_tbl_stack->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        m_tbl_stack->setObjectName(QString::fromUtf8("m_tbl_stack"));
        m_tbl_stack->setShowGrid(true);
        m_tbl_stack->setGridStyle(Qt::SolidLine);
        m_tbl_stack->setColumnCount(2);

        verticalLayout->addWidget(m_tbl_stack);

        StackWidget->setWidget(dockWidgetContents);

        retranslateUi(StackWidget);

        QMetaObject::connectSlotsByName(StackWidget);
    } // setupUi

    void retranslateUi(QDockWidget *StackWidget)
    {
        StackWidget->setWindowTitle(QApplication::translate("StackWidget", "Stack", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = m_tbl_stack->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("StackWidget", "Address", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = m_tbl_stack->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("StackWidget", "Value", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(StackWidget);
    } // retranslateUi

};

namespace Ui {
    class StackWidget: public Ui_StackWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STACKWIDGET_H
