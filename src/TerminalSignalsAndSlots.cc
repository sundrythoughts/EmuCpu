#include "TerminalSignalsAndSlots.hh"


/* SIGC++ SLOTS */
void
TerminalSignalsAndSlots::sigcSlotCpuOutput (char c) {
	Q_EMIT terminalInput (c);
}

void
TerminalSignalsAndSlots::terminalOutput (char c) {
	m_sigc_signal_cpu_input.emit (c); //FIXME emit in sigc++ is conflicting with emit in QT
}

/* SIGC++ SIGNALS */
sigc::signal<void, char>&
TerminalSignalsAndSlots::sigcSignalCpuInput () {
	return m_sigc_signal_cpu_input;
}

/* QT SLOTS */
void
TerminalSignalsAndSlots::enableDisable (bool b) {
	blockSignals (!b);
}

