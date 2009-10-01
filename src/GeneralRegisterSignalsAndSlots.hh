#ifndef GENERAL_REGISTER_SIGNALS_AND_SLOTS_HH
#define GENERAL_REGISTER_SIGNALS_AND_SLOTS_HH

#include <QObject>

class GeneralRegisterSignalsAndSlots : public QObject {
	Q_OBJECT

public:
	void sigcSlotValueChangedRegAX (unsigned short i);
	void sigcSlotValueChangedRegBX (unsigned short i);
	void sigcSlotValueChangedRegCX (unsigned short i);
	void sigcSlotValueChangedRegDX (unsigned short i);
	void sigcSlotValueChangedRegSI (unsigned short i);
	void sigcSlotValueChangedRegDI (unsigned short i);
	void sigcSlotValueChangedRegBP (unsigned short i);
	void sigcSlotValueChangedRegSP (unsigned short i);

public slots:
	void enable ();
	void disable ();

signals:
	//16-bit general registers signals
	void valueChangedRegAX (unsigned short i);
	void valueChangedRegBX (unsigned short i);
	void valueChangedRegCX (unsigned short i);
	void valueChangedRegDX (unsigned short i);
	void valueChangedRegSI (unsigned short i);
	void valueChangedRegDI (unsigned short i);
	void valueChangedRegBP (unsigned short i);
	void valueChangedRegSP (unsigned short i);
};

#endif //GENERAL_REGISTER_SIGNALS_AND_SLOTS_HH

