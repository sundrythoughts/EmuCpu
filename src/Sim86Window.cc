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


#include "Sim86Window.hh"

Sim86Window::Sim86Window (QWidget *parent) : QMainWindow (parent) {
	setupUi (this);

	//add widgets
	addDockWidget (Qt::LeftDockWidgetArea, &m_flags_widget);
	addDockWidget (Qt::LeftDockWidgetArea, &m_general_registers_widget);
	addDockWidget (Qt::LeftDockWidgetArea, &m_segment_registers_widget);
	addDockWidget (Qt::RightDockWidgetArea, &m_stack_widget);

	QVBoxLayout *layout_disassembly = new QVBoxLayout ();
	layout_disassembly->addWidget (&m_disassembly_widget);
	m_tab_disassembly->setLayout (layout_disassembly);

	QVBoxLayout *layout_memory = new QVBoxLayout ();
	layout_memory->addWidget (&m_memory_widget);
	m_tab_memory->setLayout (layout_memory);

	m_hbox_devices->addWidget (&m_terminal_widget);
	m_hbox_devices->addWidget (&m_sound_widget);

	m_file_widget = new QFileDialog (this, tr("Load executable..."), "TEST8086", tr("Executables(*.obj);;All Files(*.*)"));
	m_file_widget->setFileMode (QFileDialog::ExistingFile);

	//add actions
	addAction (m_act_file_new);
	addAction (m_act_file_open);
	addAction (m_act_file_quit);
	addAction (m_act_view_regs);
	addAction (m_act_view_sregs);
	addAction (m_act_view_flags);
	addAction (m_act_view_stack);
	addAction (m_act_view_memory);
	addAction (m_act_view_disassembly);
	addAction (m_act_debug_nmi);
	addAction (m_act_debug_intr);
	addAction (m_act_debug_reset);
	addAction (m_act_run_start);
	addAction (m_act_run_halt);
	addAction (m_act_run_single_step);

	//connect signals
	connect (m_act_view_regs, SIGNAL(toggled (bool)), &m_general_registers_widget, SLOT(enableDisableToggle (bool)));
	connect (m_act_view_sregs, SIGNAL(toggled (bool)), &m_segment_registers_widget, SLOT(enableDisableToggle (bool)));
	connect (m_act_view_flags, SIGNAL(toggled (bool)), &m_flags_widget, SLOT(enableDisableToggle (bool)));
	connect (m_act_view_stack, SIGNAL(toggled (bool)), &m_stack_widget, SLOT(enableDisableToggle (bool)));
	connect (m_act_view_memory, SIGNAL(toggled (bool)), &m_memory_widget, SLOT(enableDisableToggle (bool)));
	connect (m_act_view_memory, SIGNAL(toggled (bool)), this, SLOT(enableDisableToggleMemory (bool)));
	connect (m_act_view_disassembly, SIGNAL(toggled (bool)), &m_disassembly_widget, SLOT(enableDisableToggle (bool)));
	connect (m_act_view_disassembly, SIGNAL(toggled (bool)), this, SLOT(enableDisableToggleDisassembly (bool)));

	connect (m_act_run_start, SIGNAL(triggered ()), this, SIGNAL(startCpu ()));
	connect (m_act_run_halt, SIGNAL(triggered ()), this, SIGNAL(pauseCpu ()));
	connect (m_act_run_single_step, SIGNAL(triggered ()), this, SIGNAL(singleStepCpu ()));

	connect (m_act_debug_reset, SIGNAL(triggered ()), this, SIGNAL(resetCpu ()));
	connect (this, SIGNAL(resetCpu ()), this, SLOT(resetUi ()));

	connect (m_act_file_open, SIGNAL(triggered ()), this, SLOT(openFile ()));

	connect (m_act_file_quit, SIGNAL(triggered ()), qApp, SLOT(quit ()));

	connect (m_sld_speed, SIGNAL(valueChanged (int)), this, SIGNAL(setSpeed (int)));
}


FlagsWidget&
Sim86Window::getFlagsWidget () {
	return m_flags_widget;
}


GeneralRegistersWidget&
Sim86Window::getGeneralRegistersWidget () {
	return m_general_registers_widget;
}


SegmentRegistersWidget&
Sim86Window::getSegmentRegistersWidget () {
	return m_segment_registers_widget;
}


StackWidget&
Sim86Window::getStackWidget () {
	return m_stack_widget;
}


DisassemblyWidget&
Sim86Window::getDisassemblyWidget () {
	return m_disassembly_widget;
}


MemoryWidget&
Sim86Window::getMemoryWidget () {
	return m_memory_widget;
}


TerminalWidget&
Sim86Window::getTerminalWidget () {
	return m_terminal_widget;
}

SoundWidget&
Sim86Window::getSoundWidget () {
	return m_sound_widget;
}


void
Sim86Window::enableDisableToggleDisassembly (bool b) {
	m_tab_widget->setTabEnabled (m_tab_widget->indexOf (m_tab_disassembly), b);
}


void
Sim86Window::enableDisableToggleMemory (bool b) {
	m_tab_widget->setTabEnabled (m_tab_widget->indexOf (m_tab_memory), b);
}


void
Sim86Window::openFile () {
	QStringList file_name;
	if (m_file_widget->exec ()) {
		file_name = m_file_widget->selectedFiles ();
	}
	if (!file_name.empty ()) {
		Q_EMIT resetCpu ();
		Q_EMIT loadFile (file_name[0], m_act_load_sim86os->isChecked ());
	}
	else {
		//FIXME - can't open file
	}
}

void
Sim86Window::resetUi () {
	getFlagsWidget ().reset ();
	getGeneralRegistersWidget ().reset ();
	getSegmentRegistersWidget ().reset ();
	getStackWidget ().reset ();
	getDisassemblyWidget ().reset ();
	getTerminalWidget ().reset ();
	getSoundWidget ().reset ();
}

