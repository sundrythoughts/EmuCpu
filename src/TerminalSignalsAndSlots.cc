#include "TerminalSignalsAndSlots.hh"


/* SIGC++ SLOTS */
void
TerminalSignalsAndSlots::sigcSlotTerminalInput (char c) {
	Q_EMIT terminalInput (c);
}

void
TerminalSignalsAndSlots::terminalOutput (char c) {
	m_sigc_signal_terminal_output.emit (c);
}

/* SIGC++ SIGNALS */
sigc::signal<void, char>&
TerminalSignalsAndSlots::sigcSignalTerminalOutput () {
	return m_sigc_signal_terminal_output;
}

/* QT SLOTS */
void
TerminalSignalsAndSlots::enableDisableToggle (bool b) {
	blockSignals (!b);
}

