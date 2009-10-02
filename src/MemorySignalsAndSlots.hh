#ifndef MEMORY_SIGNALS_AND_SLOTS_HH
#define MEMORY_SIGNALS_AND_SLOTS_HH

#include <QObject>

class MemorySignalsAndSlots : public QObject {
	Q_OBJECT

public slots:
	void enable ();
	void disable ();

signals:
	void valueChanged (int phys_addr, unsigned char val);
};

#endif //MEMORY_SIGNALS_AND_SLOTS_HH

