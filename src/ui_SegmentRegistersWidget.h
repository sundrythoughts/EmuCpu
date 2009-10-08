/********************************************************************************
** Form generated from reading ui file 'SegmentRegistersWidget.ui'
**
** Created: Tue Oct 6 20:52:36 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SEGMENTREGISTERSWIDGET_H
#define UI_SEGMENTREGISTERSWIDGET_H

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

class Ui_SegmentRegistersWidget
{
public:
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *m_ln_cs;
    QLineEdit *m_ln_ds;
    QLabel *label_3;
    QLineEdit *m_ln_es;
    QLabel *label_4;
    QLineEdit *m_ln_ss;
    QLabel *label_2;
    QLineEdit *m_ln_ip;
    QLabel *label_5;

    void setupUi(QDockWidget *SegmentRegistersWidget)
    {
        if (SegmentRegistersWidget->objectName().isEmpty())
            SegmentRegistersWidget->setObjectName(QString::fromUtf8("SegmentRegistersWidget"));
        SegmentRegistersWidget->resize(299, 228);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        SegmentRegistersWidget->setFont(font);
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
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        m_ln_cs = new QLineEdit(dockWidgetContents);
        m_ln_cs->setObjectName(QString::fromUtf8("m_ln_cs"));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setWeight(50);
        m_ln_cs->setFont(font2);
        m_ln_cs->setReadOnly(true);

        gridLayout->addWidget(m_ln_cs, 0, 1, 1, 1);

        m_ln_ds = new QLineEdit(dockWidgetContents);
        m_ln_ds->setObjectName(QString::fromUtf8("m_ln_ds"));
        m_ln_ds->setFont(font2);
        m_ln_ds->setReadOnly(true);

        gridLayout->addWidget(m_ln_ds, 1, 1, 1, 1);

        label_3 = new QLabel(dockWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        m_ln_es = new QLineEdit(dockWidgetContents);
        m_ln_es->setObjectName(QString::fromUtf8("m_ln_es"));
        m_ln_es->setFont(font2);
        m_ln_es->setReadOnly(true);

        gridLayout->addWidget(m_ln_es, 2, 1, 1, 1);

        label_4 = new QLabel(dockWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        m_ln_ss = new QLineEdit(dockWidgetContents);
        m_ln_ss->setObjectName(QString::fromUtf8("m_ln_ss"));
        m_ln_ss->setFont(font2);
        m_ln_ss->setReadOnly(true);

        gridLayout->addWidget(m_ln_ss, 3, 1, 1, 1);

        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        m_ln_ip = new QLineEdit(dockWidgetContents);
        m_ln_ip->setObjectName(QString::fromUtf8("m_ln_ip"));
        m_ln_ip->setFont(font2);
        m_ln_ip->setReadOnly(true);

        gridLayout->addWidget(m_ln_ip, 4, 1, 1, 1);

        label_5 = new QLabel(dockWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        SegmentRegistersWidget->setWidget(dockWidgetContents);

        retranslateUi(SegmentRegistersWidget);

        QMetaObject::connectSlotsByName(SegmentRegistersWidget);
    } // setupUi

    void retranslateUi(QDockWidget *SegmentRegistersWidget)
    {
        SegmentRegistersWidget->setWindowTitle(QApplication::translate("SegmentRegistersWidget", "Segment Registers", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SegmentRegistersWidget", "CS:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SegmentRegistersWidget", "ES:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SegmentRegistersWidget", "SS:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SegmentRegistersWidget", "DS:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SegmentRegistersWidget", "IP:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(SegmentRegistersWidget);
    } // retranslateUi

};

namespace Ui {
    class SegmentRegistersWidget: public Ui_SegmentRegistersWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEGMENTREGISTERSWIDGET_H
