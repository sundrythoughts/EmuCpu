#ifndef SEGMENT_REGISTER_SIGNALS_AND_SLOTS_HH
#define SEGMENT_REGISTER_SIGNALS_AND_SLOTS_HH

#include <QObject>

class SegmentRegisterSignalsAndSlots : public QObject {
	Q_OBJECT

public:
	void sigcSlotValueChangedSRegCS (unsigned short i);
	void sigcSlotValueChangedSRegDS (unsigned short i);
	void sigcSlotValueChangedSRegES (unsigned short i);
	void sigcSlotValueChangedSRegSS (unsigned short i);
	void sigcSlotValueChangedRegIP (unsigned short i);

public slots:
	void enable ();
	void disable ();

signals:
	//segment register signals
	void valueChangedSRegCS (unsigned short i);
	void valueChangedSRegDS (unsigned short i);
	void valueChangedSRegES (unsigned short i);
	void valueChangedSRegSS (unsigned short i);

	//instruction pointer signals
	void valueChangedRegIP (unsigned short i);
};

#endif //SEGMENT_REGISTER_SIGNALS_AND_SLOTS_HH

