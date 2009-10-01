#ifndef CPU_HH
#define CPU_HH

#include "ExecutionUnit.hh"
#include "BusInterfaceUnit.hh"
#include "Memory.hh"

#include <iostream>

#include <QObject>

class Cpu : public QObject {
	Q_OBJECT

	Memory m_mem;
	ExecutionUnit m_eunit;
	BusInterfaceUnit m_biu;

public:
	Cpu (size_t mem_size = 1048576, QObject *parent = 0) : QObject (parent), m_mem (mem_size) {
	}

public slots:
	void startCpu () {
		std::cout << "startCpu ()" << std::endl;
	}

	void pauseCpu () {
		std::cout << "pauseCpu ()" << std::endl;
	}

	void resetCpu () {
		std::cout << "resetCpu ()" << std::endl;
	}

	void singleStepCpu () {
		std::cout << "singleStepCpu ()" << std::endl;
	}

signals:

	//segment register signals
	void signalValueChangedSRegCS (unsigned short i);
	void signalValueChangedSRegDS (unsigned short i);
	void signalValueChangedSRegES (unsigned short i);
	void signalValueChangedSRegSS (unsigned short i);

	//instruction pointer signals
	void signalValueChangedRegIP (unsigned short i);

	//16-bit general registers signals
	void signalValueChangedRegAX (unsigned short i);
	void signalValueChangedRegBX (unsigned short i);
	void signalValueChangedRegCX (unsigned short i);
	void signalValueChangedRegDX (unsigned short i);
	void signalValueChangedRegSI (unsigned short i);
	void signalValueChangedRegDI (unsigned short i);
	void signalValueChangedRegBP (unsigned short i);
	void signalValueChangedRegSP (unsigned short i);

	//16-bit flag register signal
	void signalValueChangedRegFlags (unsigned short i);

	//1-bit flag signals
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

