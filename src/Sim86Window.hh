/*
 * sim8086 -- Emulates an Intel 8086 processor
 * Copyright (C) 2009  Joseph Freeman (jfree143dev AT gmail DOT com)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


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

private Q_SLOTS:
	/** */
	void enableDisableToggleDisassembly (bool b);

	/** */
	void enableDisableToggleMemory (bool b);

	/** */
	void openFile ();

	/** */
	void resetUi ();

Q_SIGNALS:
	/** */
	void startCpu ();

	/** */
	void resetCpu ();

	/** */
	void pauseCpu ();

	/** */
	void singleStepCpu ();

	/** */
	void loadFile (QString file_name, bool load_sim86os);

	/** */
	void setSpeed (int i);

}; //end class Sim86Window

#endif //JAF__SIM_86_WINDOW_HH

