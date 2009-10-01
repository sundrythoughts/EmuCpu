#include "MemorySignalsAndSlots.hh"

void
MemorySignalsAndSlots::enable () {
	blockSignals (false);
}

void
MemorySignalsAndSlots::disable () {
	blockSignals (true);
}
