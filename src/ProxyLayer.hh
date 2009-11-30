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
@file ProxyLayer.hh
@brief Signal translation layer between the Gui and the Cpu.
*/

#ifndef JAF__PROXY_LAYER_HH
#define JAF__PROXY_LAYER_HH

#include "Cpu.hh"
#include "Sim86Window.hh"

#include "FlagRegisterSignalsAndSlots.hh"
#include "MemorySignalsAndSlots.hh"
#include "GeneralRegisterSignalsAndSlots.hh"
#include "SegmentRegisterSignalsAndSlots.hh"
#include "DisassemblySignalsAndSlots.hh"
#include "StackSignalsAndSlots.hh"
#include "TerminalSignalsAndSlots.hh"
#include "SoundSignalsAndSlots.hh"

#include <sigc++/sigc++.h>
#include <QtCore>

/**
@class ProxyLayer
@brief Signal translation layer between the Gui and the Cpu.
*/
class ProxyLayer : public QObject {
	Q_OBJECT

	GeneralRegisterSignalsAndSlots m_gen_reg_s_s;
	FlagRegisterSignalsAndSlots m_flag_reg_s_s;
	SegmentRegisterSignalsAndSlots m_sreg_s_s;
	MemorySignalsAndSlots m_mem_s_s;
	DisassemblySignalsAndSlots m_disasm_s_s;
	StackSignalsAndSlots m_stack_s_s;
	TerminalSignalsAndSlots m_terminal_s_s;
	SoundSignalsAndSlots m_sound_s_s;

public:
	/** */
	ProxyLayer () {
	}

	/** */
	void connectCpuAndUi (Cpu &cpu, Sim86Window &win);

private:
	void connectCpuSignalsToUiSlots (Cpu &cpu, Sim86Window &win);
	void connectUiSignalsToCpuSlots (Sim86Window &win, Cpu &cpu);
}; //end class ProxyLayer

#endif //JAF__PROXY_LAYER_HH

