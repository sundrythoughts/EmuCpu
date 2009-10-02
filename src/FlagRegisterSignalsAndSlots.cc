#include "FlagRegisterSignalsAndSlots.hh"

void
FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlags (unsigned short i) {
	emit valueChangedFlags (i);
}

void
FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagAF (bool b) {
	emit valueChangedFlagAF (b);
}

void
FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagCF (bool b) {
	emit valueChangedFlagCF (b);
}

void
FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagDF (bool b) {
	emit valueChangedFlagDF (b);
}

void
FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagIF (bool b) {
	emit valueChangedFlagIF (b);
}

void
FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagOF (bool b) {
	emit valueChangedFlagOF (b);
}

void
FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagPF (bool b) {
	emit valueChangedFlagPF (b);
}

void
FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagSF (bool b) {
	emit valueChangedFlagSF (b);
}

void
FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagTF (bool b) {
	emit valueChangedFlagTF (b);
}

void
FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagZF (bool b) {
	emit valueChangedFlagZF (b);
}

void
FlagRegisterSignalsAndSlots::enable () {
	blockSignals (false);
}

void
FlagRegisterSignalsAndSlots::disable () {
	blockSignals (true);
}


