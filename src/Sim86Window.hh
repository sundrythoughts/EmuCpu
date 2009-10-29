/**
@file Sim86Window.hh
@brief Main emulator window.
*/

#ifndef JAF__SIM_86_WINDOW_HH
#define JAF__SIM_86_WINDOW_HH

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

/**
@class Sim86Window
@brief Main emulator window.
*/
class Sim86Window : public QMainWindow, protected Ui::Sim86Window {
	Q_OBJECT

	FlagsWidget m_flags_widget;
	GeneralRegistersWidget m_general_registers_widget;
	SegmentRegistersWidget m_segment_registers_widget;
	StackWidget m_stack_widget;
	DisassemblyWidget m_disassembly_widget;
	MemoryWidget m_memory_widget;
	TerminalWidget m_terminal_widget;

public:
	/** */
	Sim86Window (QWidget *parent = 0);

	/** */
	FlagsWidget& getFlagsWidget ();

	/** */
	GeneralRegistersWidget& getGeneralRegistersWidget ();

	/** */
	SegmentRegistersWidget& getSegmentRegistersWidget ();

	/** */
	StackWidget& getStackWidget ();

	/** */
	DisassemblyWidget& getDisassemblyWidget ();

	/** */
	MemoryWidget& getMemoryWidget ();

	/** */
	TerminalWidget& getTerminalWidget ();

private slots:
	/** */
	void enableDisableToggleDisassembly (bool b);

	/** */
	void enableDisableToggleMemory (bool b);

	/** */
	void openFile ();

signals:
	/** */
	void startCpu ();

	/** */
	void resetCpu ();

	/** */
	void pauseCpu ();

	/** */
	void singleStepCpu ();

	/** */
	void loadFile (QString file_name);

	/** */
	void setSpeed (int i);

}; //end class Sim86Window

#endif //JAF__SIM_86_WINDOW_HH

