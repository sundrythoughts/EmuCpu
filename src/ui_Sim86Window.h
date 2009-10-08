/********************************************************************************
** Form generated from reading ui file 'Sim86Window.ui'
**
** Created: Tue Oct 6 20:52:36 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SIM86WINDOW_H
#define UI_SIM86WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sim86Window
{
public:
    QAction *m_act_file_new;
    QAction *m_act_file_open;
    QAction *m_act_file_quit;
    QAction *m_act_view_regs;
    QAction *m_act_view_sregs;
    QAction *m_act_view_flags;
    QAction *m_act_view_memory;
    QAction *m_act_view_disassembly;
    QAction *m_act_view_stack;
    QAction *m_act_debug_nmi;
    QAction *m_act_debug_intr;
    QAction *m_act_debug_reset;
    QAction *m_act_run_start;
    QAction *m_act_run_halt;
    QAction *m_act_run_single_step;
    QAction *actionEnable_Database;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *m_tab_widget;
    QWidget *m_tab_disassembly;
    QWidget *m_tab_memory;
    QWidget *m_tab_terminal;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSettings;
    QMenu *menuDebug;
    QMenu *menuRun;
    QMenu *menuTesting;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Sim86Window)
    {
        if (Sim86Window->objectName().isEmpty())
            Sim86Window->setObjectName(QString::fromUtf8("Sim86Window"));
        Sim86Window->resize(750, 642);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Sim86Window->sizePolicy().hasHeightForWidth());
        Sim86Window->setSizePolicy(sizePolicy);
        Sim86Window->setUnifiedTitleAndToolBarOnMac(true);
        m_act_file_new = new QAction(Sim86Window);
        m_act_file_new->setObjectName(QString::fromUtf8("m_act_file_new"));
        m_act_file_open = new QAction(Sim86Window);
        m_act_file_open->setObjectName(QString::fromUtf8("m_act_file_open"));
        m_act_file_quit = new QAction(Sim86Window);
        m_act_file_quit->setObjectName(QString::fromUtf8("m_act_file_quit"));
        m_act_view_regs = new QAction(Sim86Window);
        m_act_view_regs->setObjectName(QString::fromUtf8("m_act_view_regs"));
        m_act_view_regs->setCheckable(true);
        m_act_view_regs->setChecked(true);
        m_act_view_sregs = new QAction(Sim86Window);
        m_act_view_sregs->setObjectName(QString::fromUtf8("m_act_view_sregs"));
        m_act_view_sregs->setCheckable(true);
        m_act_view_sregs->setChecked(true);
        m_act_view_flags = new QAction(Sim86Window);
        m_act_view_flags->setObjectName(QString::fromUtf8("m_act_view_flags"));
        m_act_view_flags->setCheckable(true);
        m_act_view_flags->setChecked(true);
        m_act_view_memory = new QAction(Sim86Window);
        m_act_view_memory->setObjectName(QString::fromUtf8("m_act_view_memory"));
        m_act_view_memory->setCheckable(true);
        m_act_view_memory->setChecked(true);
        m_act_view_disassembly = new QAction(Sim86Window);
        m_act_view_disassembly->setObjectName(QString::fromUtf8("m_act_view_disassembly"));
        m_act_view_disassembly->setCheckable(true);
        m_act_view_disassembly->setChecked(true);
        m_act_view_stack = new QAction(Sim86Window);
        m_act_view_stack->setObjectName(QString::fromUtf8("m_act_view_stack"));
        m_act_view_stack->setCheckable(true);
        m_act_view_stack->setChecked(true);
        m_act_debug_nmi = new QAction(Sim86Window);
        m_act_debug_nmi->setObjectName(QString::fromUtf8("m_act_debug_nmi"));
        m_act_debug_intr = new QAction(Sim86Window);
        m_act_debug_intr->setObjectName(QString::fromUtf8("m_act_debug_intr"));
        m_act_debug_reset = new QAction(Sim86Window);
        m_act_debug_reset->setObjectName(QString::fromUtf8("m_act_debug_reset"));
        m_act_run_start = new QAction(Sim86Window);
        m_act_run_start->setObjectName(QString::fromUtf8("m_act_run_start"));
        m_act_run_halt = new QAction(Sim86Window);
        m_act_run_halt->setObjectName(QString::fromUtf8("m_act_run_halt"));
        m_act_run_single_step = new QAction(Sim86Window);
        m_act_run_single_step->setObjectName(QString::fromUtf8("m_act_run_single_step"));
        actionEnable_Database = new QAction(Sim86Window);
        actionEnable_Database->setObjectName(QString::fromUtf8("actionEnable_Database"));
        actionEnable_Database->setCheckable(true);
        centralwidget = new QWidget(Sim86Window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_tab_widget = new QTabWidget(centralwidget);
        m_tab_widget->setObjectName(QString::fromUtf8("m_tab_widget"));
        m_tab_disassembly = new QWidget();
        m_tab_disassembly->setObjectName(QString::fromUtf8("m_tab_disassembly"));
        m_tab_disassembly->setEnabled(true);
        m_tab_widget->addTab(m_tab_disassembly, QString());
        m_tab_memory = new QWidget();
        m_tab_memory->setObjectName(QString::fromUtf8("m_tab_memory"));
        m_tab_widget->addTab(m_tab_memory, QString());
        m_tab_terminal = new QWidget();
        m_tab_terminal->setObjectName(QString::fromUtf8("m_tab_terminal"));
        m_tab_widget->addTab(m_tab_terminal, QString());

        verticalLayout->addWidget(m_tab_widget);

        Sim86Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Sim86Window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 750, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuDebug = new QMenu(menubar);
        menuDebug->setObjectName(QString::fromUtf8("menuDebug"));
        menuRun = new QMenu(menubar);
        menuRun->setObjectName(QString::fromUtf8("menuRun"));
        menuTesting = new QMenu(menubar);
        menuTesting->setObjectName(QString::fromUtf8("menuTesting"));
        Sim86Window->setMenuBar(menubar);
        statusbar = new QStatusBar(Sim86Window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Sim86Window->setStatusBar(statusbar);
        toolBar = new QToolBar(Sim86Window);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        Sim86Window->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuRun->menuAction());
        menubar->addAction(menuDebug->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menuTesting->menuAction());
        menuFile->addAction(m_act_file_new);
        menuFile->addAction(m_act_file_open);
        menuFile->addSeparator();
        menuFile->addAction(m_act_file_quit);
        menuSettings->addAction(m_act_view_regs);
        menuSettings->addAction(m_act_view_sregs);
        menuSettings->addAction(m_act_view_flags);
        menuSettings->addAction(m_act_view_stack);
        menuSettings->addAction(m_act_view_memory);
        menuSettings->addAction(m_act_view_disassembly);
        menuDebug->addAction(m_act_debug_nmi);
        menuDebug->addAction(m_act_debug_intr);
        menuDebug->addAction(m_act_debug_reset);
        menuRun->addAction(m_act_run_start);
        menuRun->addAction(m_act_run_halt);
        menuRun->addAction(m_act_run_single_step);
        menuTesting->addAction(actionEnable_Database);
        toolBar->addAction(m_act_file_new);
        toolBar->addAction(m_act_file_open);
        toolBar->addSeparator();
        toolBar->addAction(m_act_debug_nmi);
        toolBar->addAction(m_act_debug_intr);
        toolBar->addAction(m_act_debug_reset);
        toolBar->addSeparator();
        toolBar->addAction(m_act_run_start);
        toolBar->addAction(m_act_run_halt);
        toolBar->addAction(m_act_run_single_step);

        retranslateUi(Sim86Window);

        m_tab_widget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Sim86Window);
    } // setupUi

    void retranslateUi(QMainWindow *Sim86Window)
    {
        Sim86Window->setWindowTitle(QApplication::translate("Sim86Window", "MainWindow", 0, QApplication::UnicodeUTF8));
        m_act_file_new->setText(QApplication::translate("Sim86Window", "New", 0, QApplication::UnicodeUTF8));
        m_act_file_new->setShortcut(QApplication::translate("Sim86Window", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        m_act_file_open->setText(QApplication::translate("Sim86Window", "Open", 0, QApplication::UnicodeUTF8));
        m_act_file_open->setShortcut(QApplication::translate("Sim86Window", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        m_act_file_quit->setText(QApplication::translate("Sim86Window", "Quit", 0, QApplication::UnicodeUTF8));
        m_act_file_quit->setShortcut(QApplication::translate("Sim86Window", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        m_act_view_regs->setText(QApplication::translate("Sim86Window", "General Registers", 0, QApplication::UnicodeUTF8));
        m_act_view_sregs->setText(QApplication::translate("Sim86Window", "Segment Registers", 0, QApplication::UnicodeUTF8));
        m_act_view_flags->setText(QApplication::translate("Sim86Window", "Flags", 0, QApplication::UnicodeUTF8));
        m_act_view_memory->setText(QApplication::translate("Sim86Window", "Memory", 0, QApplication::UnicodeUTF8));
        m_act_view_disassembly->setText(QApplication::translate("Sim86Window", "Disassembly", 0, QApplication::UnicodeUTF8));
        m_act_view_stack->setText(QApplication::translate("Sim86Window", "Stack", 0, QApplication::UnicodeUTF8));
        m_act_debug_nmi->setText(QApplication::translate("Sim86Window", "NMI", 0, QApplication::UnicodeUTF8));
        m_act_debug_nmi->setShortcut(QApplication::translate("Sim86Window", "Alt+N", 0, QApplication::UnicodeUTF8));
        m_act_debug_intr->setText(QApplication::translate("Sim86Window", "INTR", 0, QApplication::UnicodeUTF8));
        m_act_debug_intr->setShortcut(QApplication::translate("Sim86Window", "Alt+I", 0, QApplication::UnicodeUTF8));
        m_act_debug_reset->setText(QApplication::translate("Sim86Window", "RESET", 0, QApplication::UnicodeUTF8));
        m_act_debug_reset->setShortcut(QApplication::translate("Sim86Window", "Alt+R", 0, QApplication::UnicodeUTF8));
        m_act_run_start->setText(QApplication::translate("Sim86Window", "Start", 0, QApplication::UnicodeUTF8));
        m_act_run_start->setShortcut(QApplication::translate("Sim86Window", "F5", 0, QApplication::UnicodeUTF8));
        m_act_run_halt->setText(QApplication::translate("Sim86Window", "Halt", 0, QApplication::UnicodeUTF8));
        m_act_run_halt->setShortcut(QApplication::translate("Sim86Window", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        m_act_run_single_step->setText(QApplication::translate("Sim86Window", "Single-step", 0, QApplication::UnicodeUTF8));
        m_act_run_single_step->setShortcut(QApplication::translate("Sim86Window", "F7", 0, QApplication::UnicodeUTF8));
        actionEnable_Database->setText(QApplication::translate("Sim86Window", "Enable Database", 0, QApplication::UnicodeUTF8));
        m_tab_widget->setTabText(m_tab_widget->indexOf(m_tab_disassembly), QApplication::translate("Sim86Window", "Disassembly", 0, QApplication::UnicodeUTF8));
        m_tab_widget->setTabText(m_tab_widget->indexOf(m_tab_memory), QApplication::translate("Sim86Window", "Memory", 0, QApplication::UnicodeUTF8));
        m_tab_widget->setTabText(m_tab_widget->indexOf(m_tab_terminal), QApplication::translate("Sim86Window", "Terminal", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("Sim86Window", "File", 0, QApplication::UnicodeUTF8));
        menuSettings->setTitle(QApplication::translate("Sim86Window", "View", 0, QApplication::UnicodeUTF8));
        menuDebug->setTitle(QApplication::translate("Sim86Window", "Debug", 0, QApplication::UnicodeUTF8));
        menuRun->setTitle(QApplication::translate("Sim86Window", "Run", 0, QApplication::UnicodeUTF8));
        menuTesting->setTitle(QApplication::translate("Sim86Window", "Testing", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("Sim86Window", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Sim86Window: public Ui_Sim86Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIM86WINDOW_H
