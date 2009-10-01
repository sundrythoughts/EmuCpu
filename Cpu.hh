#ifndef CPU_HH
#define CPU_HH

#include <QObject>

class Cpu : public QObject {
	Q_OBJECT

public:
	Cpu (QObject *parent = 0) : QObject (parent) {
	}

public slots:

signals:
	void signalValueChangedSRegCS (unsigned short i);
	void signalValueChangedSRegDS (unsigned short i);
	void signalValueChangedSRegES (unsigned short i);
	void signalValueChangedSRegSS (unsigned short i);

	void signalValueChangedRegIP (unsigned short i);

	void signalValueChangedRegAX (unsigned short i);
	void signalValueChangedRegBX (unsigned short i);
	void signalValueChangedRegCX (unsigned short i);
	void signalValueChangedRegDX (unsigned short i);

	void signalValueChangedRegSI (unsigned short i);
	void signalValueChangedRegDI (unsigned short i);

	void signalValueChangedRegBP (unsigned short i);
	void signalValueChangedRegSP (unsigned short i);

	void signalValueChangedRegFlags (unsigned short i);

	void signalValueChangedFlagAF (bool b);
	void signalValueChangedFlagCF (bool b);
	void signalValueChangedFlagDF (bool b);
	void signalValueChangedFlagIF (bool b);
	void signalValueChangedFlagOF (bool b);
	void signalValueChangedFlagPF (bool b);
	void signalValueChangedFlagSF (bool b);
	void signalValueChangedFlagTF (bool b);
	void signalValueChangedFlagZF (bool b);
};

#endif //CPU_HH

