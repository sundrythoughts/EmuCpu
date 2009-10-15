#ifndef JAF__CPU_HH
#define JAF__CPU_HH

#include "ExecutionUnit.hh"
#include "BusInterfaceUnit.hh"
#include "Memory.hh"
#include "InstructionDecoder.hh"

#include "Loader.hh"

#include <iostream>
#include <sigc++/sigc++.h>

#include <QThread>
#include <QMutex>

class Cpu : public QThread {
	Q_OBJECT

	enum CpuStateEnum {
		CPU_STATE_RUN,
		CPU_STATE_SINGLE_STEP,
		CPU_STATE_PAUSE
	};

	CpuStateEnum m_cpu_state;

	Memory m_mem;
	ExecutionUnit m_eunit;
	BusInterfaceUnit m_biu;
	InstructionDecoder m_decoder;

private:
	Loader m_loader;

	QMutex m_mutex;
	bool m_thread_run;

public:
	Cpu (QObject *parent = 0) : QThread (parent) {
		m_cpu_state = CPU_STATE_PAUSE;

		m_eunit.connectTo (m_biu);

		m_biu.connectTo (m_mem);

		m_decoder.connectTo (m_biu);
		m_decoder.connectTo (m_eunit);

		m_loader.connectTo (m_mem);
		m_loader.connectTo (m_eunit);
		m_loader.connectTo (m_biu);
	}

	ExecutionUnit& getExecutionUnit ();

	BusInterfaceUnit& getBusInterfaceUnit ();

	Memory& getMemory ();

protected:
	//override
	virtual void run ();

public slots:
	void startCpu ();

	void pauseCpu ();

	void resetCpu ();

	void singleStepCpu ();

	void shutdownCpu ();

	void loadFile (QString file_name);
};

#endif //JAF__CPU_HH

