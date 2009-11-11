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


#include "ProxyLayer.hh"

void
ProxyLayer::connectCpuAndUi (Cpu &cpu, Sim86Window &win) {
	connectCpuSignalsToUiSlots (cpu, win);
	connectUiSignalsToCpuSlots (win, cpu);
}

void
ProxyLayer::connectCpuSignalsToUiSlots (Cpu &cpu, Sim86Window &win) {
	//connect Cpu sigc++ signals to ProxyLayer
	cpu.getExecutionUnit ().getRegAX ().signalValueChanged ().connect (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegAX));
	cpu.getExecutionUnit ().getRegBX ().signalValueChanged ().connect (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegBX));
	cpu.getExecutionUnit ().getRegCX ().signalValueChanged ().connect (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegCX));
	cpu.getExecutionUnit ().getRegDX ().signalValueChanged ().connect (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegDX));

	cpu.getExecutionUnit ().getRegSI ().signalValueChanged ().connect (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegSI));
	cpu.getExecutionUnit ().getRegDI ().signalValueChanged ().connect (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegDI));

	cpu.getExecutionUnit ().getRegBP ().signalValueChanged ().connect (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegBP));
	cpu.getExecutionUnit ().getRegSP ().signalValueChanged ().connect (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegSP));

	cpu.getExecutionUnit ().getRegFlags ().signalValueChanged ().connect (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlags));

	cpu.getBusInterfaceUnit ().getSegRegCS ().signalValueChanged ().connect (sigc::mem_fun (m_sreg_s_s, &SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegCS));
	cpu.getBusInterfaceUnit ().getSegRegDS ().signalValueChanged ().connect (sigc::mem_fun (m_sreg_s_s, &SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegDS));
	cpu.getBusInterfaceUnit ().getSegRegES ().signalValueChanged ().connect (sigc::mem_fun (m_sreg_s_s, &SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegES));
	cpu.getBusInterfaceUnit ().getSegRegSS ().signalValueChanged ().connect (sigc::mem_fun (m_sreg_s_s, &SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegSS));

	cpu.getBusInterfaceUnit ().getRegIP ().signalValueChanged ().connect (sigc::mem_fun (m_sreg_s_s, &SegmentRegisterSignalsAndSlots::sigcSlotValueChangedRegIP));

	cpu.getMemory ().signalValueChanged ().connect (sigc::mem_fun (m_mem_s_s, &MemorySignalsAndSlots::sigcSlotValueChanged));
	cpu.getMemory ().signalResized ().connect (sigc::mem_fun (m_mem_s_s, &MemorySignalsAndSlots::sigcSlotResized));
	cpu.getMemory ().signalReloaded ().connect (sigc::mem_fun (m_mem_s_s, &MemorySignalsAndSlots::sigcSlotReloaded));

	cpu.getInstructionDecoder ().signalNextInstruction ().connect (sigc::mem_fun (m_disasm_s_s, &DisassemblySignalsAndSlots::sigcSlotNextInstruction));

	cpu.getExecutionUnit ().signalStackPush ().connect (sigc::mem_fun (m_stack_s_s, &StackSignalsAndSlots::sigcSlotStackPush));
	cpu.getExecutionUnit ().signalStackPop ().connect (sigc::mem_fun (m_stack_s_s, &StackSignalsAndSlots::sigcSlotStackPop));

	//connect ProxyLayer Qt signals to Sim86Window Qt slots

	//Flag Register Widget Signals and Slots
	QObject::connect (&m_flag_reg_s_s, SIGNAL(valueChangedFlags (unsigned short)),
		          &win.getFlagsWidget (), SLOT(setFlags (unsigned short)));

	//Segment Register Widget Signals and Slots
	QObject::connect (&m_sreg_s_s, SIGNAL(valueChangedSegRegCS (unsigned short)),
		          &win.getSegmentRegistersWidget (), SLOT(setSegRegCS (unsigned short)));
	QObject::connect (&m_sreg_s_s, SIGNAL(valueChangedSegRegDS (unsigned short)),
		          &win.getSegmentRegistersWidget (), SLOT(setSegRegDS (unsigned short)));
	QObject::connect (&m_sreg_s_s, SIGNAL(valueChangedSegRegES (unsigned short)),
		          &win.getSegmentRegistersWidget (), SLOT(setSegRegES (unsigned short)));
	QObject::connect (&m_sreg_s_s, SIGNAL(valueChangedSegRegSS (unsigned short)),
		          &win.getSegmentRegistersWidget (), SLOT(setSegRegSS (unsigned short)));
	QObject::connect (&m_sreg_s_s, SIGNAL(valueChangedRegIP (unsigned short)),
		          &win.getSegmentRegistersWidget (), SLOT(setRegIP (unsigned short)));

	//General Register Widget Signals and Slots
	QObject::connect (&m_gen_reg_s_s, SIGNAL(valueChangedRegAX (unsigned short)),
		          &win.getGeneralRegistersWidget (), SLOT(setRegAX (unsigned short)));
	QObject::connect (&m_gen_reg_s_s, SIGNAL(valueChangedRegBX (unsigned short)),
		          &win.getGeneralRegistersWidget (), SLOT(setRegBX (unsigned short)));
	QObject::connect (&m_gen_reg_s_s, SIGNAL(valueChangedRegCX (unsigned short)),
		          &win.getGeneralRegistersWidget (), SLOT(setRegCX (unsigned short)));
	QObject::connect (&m_gen_reg_s_s, SIGNAL(valueChangedRegDX (unsigned short)),
		          &win.getGeneralRegistersWidget (), SLOT(setRegDX (unsigned short)));
	QObject::connect (&m_gen_reg_s_s, SIGNAL(valueChangedRegSI (unsigned short)),
		          &win.getGeneralRegistersWidget (), SLOT(setRegSI (unsigned short)));
	QObject::connect (&m_gen_reg_s_s, SIGNAL(valueChangedRegDI (unsigned short)),
		          &win.getGeneralRegistersWidget (), SLOT(setRegDI (unsigned short)));
	QObject::connect (&m_gen_reg_s_s, SIGNAL(valueChangedRegBP (unsigned short)),
		          &win.getGeneralRegistersWidget (), SLOT(setRegBP (unsigned short)));
	QObject::connect (&m_gen_reg_s_s, SIGNAL(valueChangedRegSP (unsigned short)),
		          &win.getGeneralRegistersWidget (), SLOT(setRegSP (unsigned short)));

	//Memory Widget Signals and Slots
	QObject::connect (&m_mem_s_s, SIGNAL(valueChanged (int, unsigned char)),
		          &win.getMemoryWidget (), SLOT(setMemoryAddress (int, unsigned char)));
	QObject::connect (&m_mem_s_s, SIGNAL(resized (size_t)),
		          &win.getMemoryWidget (), SLOT(resize (size_t)));
	QObject::connect (&m_mem_s_s, SIGNAL(reloaded (const unsigned char*, size_t)),
		          &win.getMemoryWidget (), SLOT(setAllMemoryAddresses (const unsigned char*, size_t)));

	//Disassembly Widget Signals and Slots
	QObject::connect (&m_disasm_s_s, SIGNAL(nextInstruction (QString, QString, QString, QString)),
		          &win.getDisassemblyWidget (), SLOT(addNextInstruction (QString, QString, QString, QString)));

	//Stack Widget Signals and Slots
	QObject::connect (&m_stack_s_s, SIGNAL(stackPush (unsigned short, unsigned short, unsigned short)),
		          &win.getStackWidget (), SLOT(push (unsigned short, unsigned short, unsigned short)));
	QObject::connect (&m_stack_s_s, SIGNAL(stackPop ()),
		          &win.getStackWidget (), SLOT(pop ()));
}

void
ProxyLayer::connectUiSignalsToCpuSlots (Sim86Window &win, Cpu &cpu) {
	QObject::connect (&win, SIGNAL(startCpu ()),
	                  &cpu, SLOT(startCpu ()));
	QObject::connect (&win, SIGNAL(pauseCpu ()),
	                  &cpu, SLOT(pauseCpu ()));
	QObject::connect (&win, SIGNAL(singleStepCpu ()),
	                  &cpu, SLOT(singleStepCpu ()));
	QObject::connect (&win, SIGNAL(resetCpu ()),
	                  &cpu, SLOT(resetCpu ()));
	QObject::connect (&win, SIGNAL(loadFile (QString)),
	                  &cpu, SLOT(loadFile (QString)));
	QObject::connect (&win, SIGNAL(setSpeed (int)),
	                  &cpu, SLOT(setSpeed (int)));

	QObject::connect (&win.getMemoryWidget (), SIGNAL(enableDisable (bool)),
	                  &m_mem_s_s, SLOT(enableDisable (bool)));
	QObject::connect (&win.getDisassemblyWidget (), SIGNAL(enableDisable (bool)),
	                  &m_disasm_s_s, SLOT(enableDisable (bool)));
	QObject::connect (&win.getFlagsWidget (), SIGNAL(enableDisable (bool)),
	                  &m_flag_reg_s_s, SLOT(enableDisable (bool)));
	QObject::connect (&win.getGeneralRegistersWidget (), SIGNAL(enableDisable (bool)),
	                  &m_gen_reg_s_s, SLOT(enableDisable (bool)));
	QObject::connect (&win.getSegmentRegistersWidget (), SIGNAL(enableDisable (bool)),
	                  &m_sreg_s_s, SLOT(enableDisable (bool)));
	QObject::connect (&win.getStackWidget (), SIGNAL(enableDisable (bool)),
	                  &m_stack_s_s, SLOT(enableDisable (bool)));
}

