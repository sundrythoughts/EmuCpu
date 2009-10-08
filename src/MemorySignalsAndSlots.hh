#ifndef MEMORY_SIGNALS_AND_SLOTS_HH
#define MEMORY_SIGNALS_AND_SLOTS_HH

#include <sigc++/sigc++.h>
#include <QObject>

class MemorySignalsAndSlots : public QObject {
	Q_OBJECT

	sigc::signal<void, size_t> m_sigc_signal_resize;

public:
	void sigcSlotValueChanged (int addr, unsigned char val);
	void sigcSlotResized (size_t sz);

	sigc::signal<void, size_t>& sigcSignalResize ();

public slots:
	void enableDisable (bool b);
	void resize (size_t sz);

signals:
	void valueChanged (int addr, unsigned char val);
	void resized (size_t sz);
};

#endif //MEMORY_SIGNALS_AND_SLOTS_HH

