/********************************************************************************
** Form generated from reading ui file 'GeneralRegistersWidget.ui'
**
** Created: Tue Oct 6 20:52:36 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GENERALREGISTERSWIDGET_H
#define UI_GENERALREGISTERSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeneralRegistersWidget
{
public:
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *m_ln_ax;
    QLabel *label_2;
    QLineEdit *m_ln_bx;
    QLabel *label_3;
    QLineEdit *m_ln_cx;
    QLabel *label_4;
    QLineEdit *m_ln_dx;
    QLabel *label_5;
    QLineEdit *m_ln_si;
    QLabel *label_6;
    QLineEdit *m_ln_di;
    QLabel *label_7;
    QLineEdit *m_ln_bp;
    QLabel *label_8;
    QLineEdit *m_ln_sp;

    void setupUi(QDockWidget *GeneralRegistersWidget)
    {
        if (GeneralRegistersWidget->objectName().isEmpty())
            GeneralRegistersWidget->setObjectName(QString::fromUtf8("GeneralRegistersWidget"));
        GeneralRegistersWidget->resize(210, 341);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        GeneralRegistersWidget->setFont(font);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(dockWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        m_ln_ax = new QLineEdit(dockWidgetContents);
        m_ln_ax->setObjectName(QString::fromUtf8("m_ln_ax"));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setWeight(50);
        m_ln_ax->setFont(font2);
        m_ln_ax->setReadOnly(true);

        gridLayout->addWidget(m_ln_ax, 0, 1, 1, 1);

        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        m_ln_bx = new QLineEdit(dockWidgetContents);
        m_ln_bx->setObjectName(QString::fromUtf8("m_ln_bx"));
        m_ln_bx->setFont(font2);
        m_ln_bx->setReadOnly(true);

        gridLayout->addWidget(m_ln_bx, 1, 1, 1, 1);

        label_3 = new QLabel(dockWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        m_ln_cx = new QLineEdit(dockWidgetContents);
        m_ln_cx->setObjectName(QString::fromUtf8("m_ln_cx"));
        m_ln_cx->setFont(font2);
        m_ln_cx->setReadOnly(true);

        gridLayout->addWidget(m_ln_cx, 2, 1, 1, 1);

        label_4 = new QLabel(dockWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        m_ln_dx = new QLineEdit(dockWidgetContents);
        m_ln_dx->setObjectName(QString::fromUtf8("m_ln_dx"));
        m_ln_dx->setFont(font2);
        m_ln_dx->setReadOnly(true);

        gridLayout->addWidget(m_ln_dx, 3, 1, 1, 1);

        label_5 = new QLabel(dockWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        m_ln_si = new QLineEdit(dockWidgetContents);
        m_ln_si->setObjectName(QString::fromUtf8("m_ln_si"));
        m_ln_si->setFont(font2);
        m_ln_si->setReadOnly(true);

        gridLayout->addWidget(m_ln_si, 4, 1, 1, 1);

        label_6 = new QLabel(dockWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        m_ln_di = new QLineEdit(dockWidgetContents);
        m_ln_di->setObjectName(QString::fromUtf8("m_ln_di"));
        m_ln_di->setFont(font2);
        m_ln_di->setReadOnly(true);

        gridLayout->addWidget(m_ln_di, 5, 1, 1, 1);

        label_7 = new QLabel(dockWidgetContents);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        m_ln_bp = new QLineEdit(dockWidgetContents);
        m_ln_bp->setObjectName(QString::fromUtf8("m_ln_bp"));
        m_ln_bp->setFont(font2);
        m_ln_bp->setReadOnly(true);

        gridLayout->addWidget(m_ln_bp, 6, 1, 1, 1);

        label_8 = new QLabel(dockWidgetContents);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 7, 0, 1, 1);

        m_ln_sp = new QLineEdit(dockWidgetContents);
        m_ln_sp->setObjectName(QString::fromUtf8("m_ln_sp"));
        m_ln_sp->setFont(font2);
        m_ln_sp->setReadOnly(true);

        gridLayout->addWidget(m_ln_sp, 7, 1, 1, 1);

        GeneralRegistersWidget->setWidget(dockWidgetContents);

        retranslateUi(GeneralRegistersWidget);

        QMetaObject::connectSlotsByName(GeneralRegistersWidget);
    } // setupUi

    void retranslateUi(QDockWidget *GeneralRegistersWidget)
    {
        GeneralRegistersWidget->setWindowTitle(QApplication::translate("GeneralRegistersWidget", "General Registers", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GeneralRegistersWidget", "AX:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("GeneralRegistersWidget", "BX:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("GeneralRegistersWidget", "CX:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("GeneralRegistersWidget", "DX:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("GeneralRegistersWidget", "SI:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("GeneralRegistersWidget", "DI:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("GeneralRegistersWidget", "BP:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("GeneralRegistersWidget", "SP:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(GeneralRegistersWidget);
    } // retranslateUi

};

namespace Ui {
    class GeneralRegistersWidget: public Ui_GeneralRegistersWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERALREGISTERSWIDGET_H
