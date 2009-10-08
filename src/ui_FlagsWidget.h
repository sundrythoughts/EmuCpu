/********************************************************************************
** Form generated from reading ui file 'FlagsWidget.ui'
**
** Created: Tue Oct 6 20:52:36 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_FLAGSWIDGET_H
#define UI_FLAGSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FlagsWidget
{
public:
    QWidget *dockWidgetContents;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLCDNumber *m_lcd_cf;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLCDNumber *m_lcd_pf;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLCDNumber *m_lcd_af;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLCDNumber *m_lcd_zf;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QLCDNumber *m_lcd_sf;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QLCDNumber *m_lcd_tf;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_7;
    QLCDNumber *m_lcd_if;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_8;
    QLCDNumber *m_lcd_df;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_9;
    QLCDNumber *m_lcd_of;

    void setupUi(QDockWidget *FlagsWidget)
    {
        if (FlagsWidget->objectName().isEmpty())
            FlagsWidget->setObjectName(QString::fromUtf8("FlagsWidget"));
        FlagsWidget->resize(510, 122);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        FlagsWidget->setFont(font);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        horizontalLayout = new QHBoxLayout(dockWidgetContents);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(dockWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        m_lcd_cf = new QLCDNumber(dockWidgetContents);
        m_lcd_cf->setObjectName(QString::fromUtf8("m_lcd_cf"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_lcd_cf->sizePolicy().hasHeightForWidth());
        m_lcd_cf->setSizePolicy(sizePolicy);
        m_lcd_cf->setFrameShape(QFrame::StyledPanel);
        m_lcd_cf->setNumDigits(1);
        m_lcd_cf->setMode(QLCDNumber::Bin);
        m_lcd_cf->setSegmentStyle(QLCDNumber::Flat);

        verticalLayout->addWidget(m_lcd_cf);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        m_lcd_pf = new QLCDNumber(dockWidgetContents);
        m_lcd_pf->setObjectName(QString::fromUtf8("m_lcd_pf"));
        sizePolicy.setHeightForWidth(m_lcd_pf->sizePolicy().hasHeightForWidth());
        m_lcd_pf->setSizePolicy(sizePolicy);
        m_lcd_pf->setFrameShape(QFrame::StyledPanel);
        m_lcd_pf->setNumDigits(1);
        m_lcd_pf->setMode(QLCDNumber::Bin);
        m_lcd_pf->setSegmentStyle(QLCDNumber::Flat);

        verticalLayout_2->addWidget(m_lcd_pf);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(dockWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        m_lcd_af = new QLCDNumber(dockWidgetContents);
        m_lcd_af->setObjectName(QString::fromUtf8("m_lcd_af"));
        sizePolicy.setHeightForWidth(m_lcd_af->sizePolicy().hasHeightForWidth());
        m_lcd_af->setSizePolicy(sizePolicy);
        m_lcd_af->setFrameShape(QFrame::StyledPanel);
        m_lcd_af->setNumDigits(1);
        m_lcd_af->setMode(QLCDNumber::Bin);
        m_lcd_af->setSegmentStyle(QLCDNumber::Flat);

        verticalLayout_3->addWidget(m_lcd_af);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_4 = new QLabel(dockWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_4);

        m_lcd_zf = new QLCDNumber(dockWidgetContents);
        m_lcd_zf->setObjectName(QString::fromUtf8("m_lcd_zf"));
        sizePolicy.setHeightForWidth(m_lcd_zf->sizePolicy().hasHeightForWidth());
        m_lcd_zf->setSizePolicy(sizePolicy);
        m_lcd_zf->setFrameShape(QFrame::StyledPanel);
        m_lcd_zf->setNumDigits(1);
        m_lcd_zf->setMode(QLCDNumber::Bin);
        m_lcd_zf->setSegmentStyle(QLCDNumber::Flat);

        verticalLayout_4->addWidget(m_lcd_zf);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_5 = new QLabel(dockWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_5);

        m_lcd_sf = new QLCDNumber(dockWidgetContents);
        m_lcd_sf->setObjectName(QString::fromUtf8("m_lcd_sf"));
        sizePolicy.setHeightForWidth(m_lcd_sf->sizePolicy().hasHeightForWidth());
        m_lcd_sf->setSizePolicy(sizePolicy);
        m_lcd_sf->setFrameShape(QFrame::StyledPanel);
        m_lcd_sf->setNumDigits(1);
        m_lcd_sf->setMode(QLCDNumber::Bin);
        m_lcd_sf->setSegmentStyle(QLCDNumber::Flat);

        verticalLayout_5->addWidget(m_lcd_sf);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_6 = new QLabel(dockWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_6);

        m_lcd_tf = new QLCDNumber(dockWidgetContents);
        m_lcd_tf->setObjectName(QString::fromUtf8("m_lcd_tf"));
        sizePolicy.setHeightForWidth(m_lcd_tf->sizePolicy().hasHeightForWidth());
        m_lcd_tf->setSizePolicy(sizePolicy);
        m_lcd_tf->setFrameShape(QFrame::StyledPanel);
        m_lcd_tf->setNumDigits(1);
        m_lcd_tf->setMode(QLCDNumber::Bin);
        m_lcd_tf->setSegmentStyle(QLCDNumber::Flat);

        verticalLayout_6->addWidget(m_lcd_tf);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_7 = new QLabel(dockWidgetContents);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_7);

        m_lcd_if = new QLCDNumber(dockWidgetContents);
        m_lcd_if->setObjectName(QString::fromUtf8("m_lcd_if"));
        sizePolicy.setHeightForWidth(m_lcd_if->sizePolicy().hasHeightForWidth());
        m_lcd_if->setSizePolicy(sizePolicy);
        m_lcd_if->setFrameShape(QFrame::StyledPanel);
        m_lcd_if->setNumDigits(1);
        m_lcd_if->setMode(QLCDNumber::Bin);
        m_lcd_if->setSegmentStyle(QLCDNumber::Flat);

        verticalLayout_7->addWidget(m_lcd_if);


        horizontalLayout->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_8 = new QLabel(dockWidgetContents);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_8);

        m_lcd_df = new QLCDNumber(dockWidgetContents);
        m_lcd_df->setObjectName(QString::fromUtf8("m_lcd_df"));
        sizePolicy.setHeightForWidth(m_lcd_df->sizePolicy().hasHeightForWidth());
        m_lcd_df->setSizePolicy(sizePolicy);
        m_lcd_df->setFrameShape(QFrame::StyledPanel);
        m_lcd_df->setNumDigits(1);
        m_lcd_df->setMode(QLCDNumber::Bin);
        m_lcd_df->setSegmentStyle(QLCDNumber::Flat);

        verticalLayout_8->addWidget(m_lcd_df);


        horizontalLayout->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_9 = new QLabel(dockWidgetContents);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_9);

        m_lcd_of = new QLCDNumber(dockWidgetContents);
        m_lcd_of->setObjectName(QString::fromUtf8("m_lcd_of"));
        sizePolicy.setHeightForWidth(m_lcd_of->sizePolicy().hasHeightForWidth());
        m_lcd_of->setSizePolicy(sizePolicy);
        m_lcd_of->setFrameShape(QFrame::StyledPanel);
        m_lcd_of->setNumDigits(1);
        m_lcd_of->setMode(QLCDNumber::Bin);
        m_lcd_of->setSegmentStyle(QLCDNumber::Flat);

        verticalLayout_9->addWidget(m_lcd_of);


        horizontalLayout->addLayout(verticalLayout_9);

        FlagsWidget->setWidget(dockWidgetContents);

        retranslateUi(FlagsWidget);

        QMetaObject::connectSlotsByName(FlagsWidget);
    } // setupUi

    void retranslateUi(QDockWidget *FlagsWidget)
    {
        FlagsWidget->setWindowTitle(QApplication::translate("FlagsWidget", "Flags", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FlagsWidget", "CF", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FlagsWidget", "PF", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("FlagsWidget", "AF", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FlagsWidget", "ZF", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("FlagsWidget", "SF", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("FlagsWidget", "TF", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("FlagsWidget", "IF", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("FlagsWidget", "DF", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("FlagsWidget", "OF", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(FlagsWidget);
    } // retranslateUi

};

namespace Ui {
    class FlagsWidget: public Ui_FlagsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLAGSWIDGET_H
