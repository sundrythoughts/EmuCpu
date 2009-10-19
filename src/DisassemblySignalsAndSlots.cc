#include "DisassemblySignalsAndSlots.hh"

/* SIGC++ SLOTS */

void
DisassemblySignalsAndSlots::sigcSlotNextInstruction (const std::string &s1, const std::string &s2, const std::string &s3, const std::string &s4) {
	emit nextInstruction (s1.c_str (), s2.c_str (), s3.c_str (), s4.c_str ());
}

/* QT SLOTS */
void
DisassemblySignalsAndSlots::enableDisable (bool b) {
	blockSignals (!b);
}

