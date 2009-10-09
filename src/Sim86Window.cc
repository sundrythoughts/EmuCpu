#include "Sim86Window.hh"

Sim86Window::Sim86Window (QWidget *parent) : QMainWindow (parent) {
	setupUi (this);

	//add widgets
	addDockWidget (Qt::LeftDockWidgetArea, &m_stack_widget);
	addDockWidget (Qt::LeftDockWidgetArea, &m_flags_widget);
	addDockWidget (Qt::LeftDockWidgetArea, &m_general_registers_widget);
	addDockWidget (Qt::LeftDockWidgetArea, &m_segment_registers_widget);

	QVBoxLayout *layout_disassembly = new QVBoxLayout ();
	layout_disassembly->addWidget(&m_disassembly_widget);
	m_tab_disassembly->setLayout(layout_disassembly);

	QVBoxLayout *layout_memory = new QVBoxLayout ();
	layout_memory->addWidget(&m_memory_widget);
	m_tab_memory->setLayout(layout_memory);

	QVBoxLayout *layout_terminal = new QVBoxLayout ();
	layout_terminal->addWidget(&m_terminal_widget);
	m_tab_terminal->setLayout(layout_terminal);

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

	//std::cout << actions ().size () << std::endl;

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

	connect (m_act_file_open, SIGNAL(triggered ()), this, SLOT(openFile ()));
}

