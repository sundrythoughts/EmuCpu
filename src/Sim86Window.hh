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
#include "SoundWidget.hh"

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
	SoundWidget m_sound_widget;

	QFileDialog *m_file_widget;

public:
	/** */
	Sim86Window (QWidget *parent = 0);

	/** @brief Get the FlagsWidget. */
	FlagsWidget& getFlagsWidget ();

	/** @brief Get the GeneralRegistersWidget. */
	GeneralRegistersWidget& getGeneralRegistersWidget ();

	/** @brief Get the SegmentRegisterWidget. */
	SegmentRegistersWidget& getSegmentRegistersWidget ();

	/** @brief Get the StackWidget. */
	StackWidget& getStackWidget ();

	/** @brief Get the DisassemblyWidget. */
	DisassemblyWidget& getDisassemblyWidget ();

	/** @brief Get the MemoryWidget. */
	MemoryWidget& getMemoryWidget ();

	/** @brief Get the TerminalWidget. */
	TerminalWidget& getTerminalWidget ();

	/** @brief Get the SoundWidget. */
	SoundWidget& getSoundWidget ();

private Q_SLOTS:
	//Enable/disable the dissassembly output
	void enableDisableToggleDisassembly (bool b);

	//Enable/disable the memory output
	void enableDisableToggleMemory (bool b);

	//Open an executable file
	void openFile ();

	//Reset the Ui to its default state
	void resetUi ();

Q_SIGNALS:
	/** @brief Run the Cpu. */
	void startCpu ();

	/** @brief Reset the Cpu. */
	void resetCpu ();

	/** @brief Pause the Cpu. */
	void pauseCpu ();

	/** @brief Single-step the Cpu. */
	void singleStepCpu ();

	/** @brief Load a new executable and maybe load Sim86OS. */
	void loadFile (QString file_name, bool load_sim86os);

	/** @brief Set the execution speed of the Cpu. */
	void setSpeed (int i);

	/** @brief Enable/disable the database testing. */
	void enableDatabase (bool b);

}; //end class Sim86Window

#endif //JAF__SIM_86_WINDOW_HH

