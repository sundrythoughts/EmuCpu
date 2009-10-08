#ifndef SIM_86_WINDOW_HH
#define SIM_86_WINDOW_HH

#include <QtCore>
#include <QtGui>

#include "ui_Sim86Window.h"

#include "FlagsWidget.hh"
#include "GeneralRegistersWidget.hh"
#include "SegmentRegistersWidget.hh"
#include "StackWidget.hh"
#include "DisassemblyWidget.hh"
#include "MemoryWidget.hh"
#include "TerminalWidget.hh"

#include <iostream>

class Sim86Window : public QMainWindow, protected Ui::Sim86Window {
	Q_OBJECT

	FlagsWidget m_flags_widget;
	GeneralRegistersWidget m_general_registers_widget;
	SegmentRegistersWidget m_segment_registers_widget;
	StackWidget m_stack_widget;
	DisassemblyWidget m_disassembly_widget;
	MemoryWidget m_memory_widget;
	TerminalWidget m_terminal_widget;

private slots:
	void enableDisableToggleDisassembly (bool b) {
		m_tab_widget->setTabEnabled (m_tab_widget->indexOf (m_tab_disassembly), b);
	}

	void enableDisableToggleMemory (bool b) {
		m_tab_widget->setTabEnabled (m_tab_widget->indexOf (m_tab_memory), b);
	}

signals:
	void startCpu ();
	void resetCpu ();
	void pauseCpu ();
	void singleStepCpu ();
	void loadFile (QString file_name);

public:
	Sim86Window (QWidget *parent = 0);

	FlagsWidget& getFlagsWidget () {
		return m_flags_widget;
	}

	GeneralRegistersWidget& getGeneralRegistersWidget () {
		return m_general_registers_widget;
	}

	SegmentRegistersWidget& getSegmentRegistersWidget () {
		return m_segment_registers_widget;
	}

	StackWidget& getStackWidget () {
		return m_stack_widget;
	}

	DisassemblyWidget& getDisassemblyWidget () {
		return m_disassembly_widget;
	}

	MemoryWidget& getMemoryWidget () {
		return m_memory_widget;
	}

	TerminalWidget& getTerminalWidget () {
		return m_terminal_widget;
	}
};

#endif //SIM_86_WINDOW_HH

