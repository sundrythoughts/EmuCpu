#include "SegmentRegisterSignalsAndSlots.hh"

void
SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegCS (unsigned short i) {
	emit valueChangedSegRegCS (i);
}

void
SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegDS (unsigned short i) {
	emit valueChangedSegRegDS (i);
}

void
SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegES (unsigned short i) {
	emit valueChangedSegRegES (i);
}

void
SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegSS (unsigned short i) {
	emit valueChangedSegRegSS (i);
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
