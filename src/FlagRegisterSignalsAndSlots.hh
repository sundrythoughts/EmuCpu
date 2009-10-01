#ifndef FLAG_REGISTER_SIGNALS_AND_SLOTS_HH
#define FLAG_REGISTER_SIGNALS_AND_SLOTS_HH

#include <QObject>

class FlagRegisterSignalsAndSlots : public QObject {
	Q_OBJECT

public:
	void sigcSlotValueChangedFlagAF (bool b);
	void sigcSlotValueChangedFlagCF (bool b);
	void sigcSlotValueChangedFlagDF (bool b);
	void sigcSlotValueChangedFlagIF (bool b);
	void sigcSlotValueChangedFlagOF (bool b);
	void sigcSlotValueChangedFlagPF (bool b);
	void sigcSlotValueChangedFlagSF (bool b);
	void sigcSlotValueChangedFlagTF (bool b);
	void sigcSlotValueChangedFlagZF (bool b);

public slots:
	void enable ();
	void disable ();

signals:
	//1-bit flag signals
	void valueChangedFlagAF (bool b);
	void valueChangedFlagCF (bool b);
	void valueChangedFlagDF (bool b);
	void valueChangedFlagIF (bool b);
	void valueChangedFlagOF (bool b);
	void valueChangedFlagPF (bool b);
	void valueChangedFlagSF (bool b);
	void valueChangedFlagTF (bool b);
	void valueChangedFlagZF (bool b);
};

#endif //FLAG_REGISTER_SIGNALS_AND_SLOTS_HH

