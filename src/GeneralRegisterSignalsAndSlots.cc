#include "GeneralRegisterSignalsAndSlots.hh"

/* SIGC++ SLOTS */
void
GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegAX (unsigned short i) {
	emit valueChangedRegAX (i);
}

void
GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegBX (unsigned short i) {
	emit valueChangedRegBX (i);
}

void
GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegCX (unsigned short i) {
	emit valueChangedRegCX (i);
}

void
GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegDX (unsigned short i) {
	emit valueChangedRegDX (i);
}

void
GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegSI (unsigned short i) {
	emit valueChangedRegSI (i);
}

void
GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegDI (unsigned short i) {
	emit valueChangedRegDI (i);
}

void
GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegBP (unsigned short i) {
	emit valueChangedRegBP (i);
}

void
GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegSP (unsigned short i) {
	emit valueChangedRegSP (i);
}

/* QT SLOTS */
void
GeneralRegisterSignalsAndSlots::enableDisable (bool b) {
	blockSignals (b);
}

