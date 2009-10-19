#include "FlagRegisterSignalsAndSlots.hh"

/* SIGC++ SLOTS */
void
FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlags (unsigned short i) {
	emit valueChangedFlags (i);
}

/* QT SLOTS */
void
FlagRegisterSignalsAndSlots::enableDisable (bool b) {
	blockSignals (!b);
}


