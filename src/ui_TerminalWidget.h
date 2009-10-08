/********************************************************************************
** Form generated from reading ui file 'TerminalWidget.ui'
**
** Created: Tue Oct 6 20:52:36 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TERMINALWIDGET_H
#define UI_TERMINALWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TerminalWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *m_txt_terminal;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_btn_clear;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *TerminalWidget)
    {
        if (TerminalWidget->objectName().isEmpty())
            TerminalWidget->setObjectName(QString::fromUtf8("TerminalWidget"));
        TerminalWidget->resize(531, 544);
        verticalLayout = new QVBoxLayout(TerminalWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_txt_terminal = new QTextEdit(TerminalWidget);
        m_txt_terminal->setObjectName(QString::fromUtf8("m_txt_terminal"));

        verticalLayout->addWidget(m_txt_terminal);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_btn_clear = new QPushButton(TerminalWidget);
        m_btn_clear->setObjectName(QString::fromUtf8("m_btn_clear"));

        horizontalLayout->addWidget(m_btn_clear);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(TerminalWidget);
        QObject::connect(m_btn_clear, SIGNAL(clicked()), m_txt_terminal, SLOT(clear()));

        QMetaObject::connectSlotsByName(TerminalWidget);
    } // setupUi

    void retranslateUi(QWidget *TerminalWidget)
    {
        TerminalWidget->setWindowTitle(QApplication::translate("TerminalWidget", "Form", 0, QApplication::UnicodeUTF8));
        m_txt_terminal->setStyleSheet(QString());
        m_btn_clear->setText(QApplication::translate("TerminalWidget", "Clear", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(TerminalWidget);
    } // retranslateUi

};

namespace Ui {
    class TerminalWidget: public Ui_TerminalWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TERMINALWIDGET_H
