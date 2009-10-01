#include "SegmentRegisterSignalsAndSlots.hh"

void
SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegCS (unsigned short i) {
	emit valueChangedSRegCS (i);
}

void
SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegDS (unsigned short i) {
	emit valueChangedSRegDS (i);
}

void
SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegES (unsigned short i) {
	emit valueChangedSRegES (i);
}

void
SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegSS (unsigned short i) {
	emit valueChangedSRegSS (i);
}

void
SegmentRegisterSignalsAndSlots::sigcSlotValueChangedRegIP (unsigned short i) {
	emit valueChangedRegIP (i);
}

void
SegmentRegisterSignalsAndSlots::enable () {
	blockSignals (false);
}

void
SegmentRegisterSignalsAndSlots::disable () {
	blockSignals (true);
}
