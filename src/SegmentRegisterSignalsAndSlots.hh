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
	void enableDisable (bool b);

signals:
	//segment register signals
	void valueChangedSegRegCS (unsigned short i);
	void valueChangedSegRegDS (unsigned short i);
	void valueChangedSegRegES (unsigned short i);
	void valueChangedSegRegSS (unsigned short i);

	//instruction pointer signals
	void valueChangedRegIP (unsigned short i);
};

#endif //SEGMENT_REGISTER_SIGNALS_AND_SLOTS_HH

