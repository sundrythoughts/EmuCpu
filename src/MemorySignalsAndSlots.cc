#include "MemorySignalsAndSlots.hh"

/* SIGC++ SLOTS */
void
MemorySignalsAndSlots::sigcSlotValueChanged (int addr, unsigned char val) {
	emit valueChanged (addr, val);
}

void
MemorySignalsAndSlots::sigcSlotResized (size_t sz) {
	emit resized (sz);
}

void
MemorySignalsAndSlots::sigcSlotReloaded (const unsigned char *arr, size_t sz) {
	emit reloaded (arr, sz);
}

/* SIGC++ SIGNALS */
sigc::signal<void, size_t>&
MemorySignalsAndSlots::sigcSignalResize () {
	return m_sigc_signal_resize;
}

/* QT SLOTS */
void
MemorySignalsAndSlots::enableDisable (bool b) {
	blockSignals (b);
}

void
MemorySignalsAndSlots::resize (size_t sz) {
}

