#ifndef CPU_HH
#define CPU_HH

#include "ExecutionUnit.hh"
#include "BusInterfaceUnit.hh"
#include "Memory.hh"

#include "Loader.hh"

#include <iostream>
#include <sigc++/sigc++.h>

#include <QThread>

class Cpu : public QThread {
	Q_OBJECT

	enum CpuStateEnum {
		CPU_STATE_RUN,
		CPU_STATE_SINGLE_STEP,
		CPU_STATE_PAUSE
	};

	CpuStateEnum m_cpu_state;

	Memory m_mem;
public: //FIXME - only public temporarly
	ExecutionUnit m_eunit;
	BusInterfaceUnit m_biu;

private:
	Loader m_loader;

	bool m_thread_run;

public:
	Cpu (size_t mem_size = 1048576, QObject *parent = 0) : QThread (parent) {
		m_mem.resize (mem_size);

		m_cpu_state = CPU_STATE_PAUSE;

		m_eunit.connectTo (m_biu);
		m_biu.connectTo (m_mem);

		m_loader.connectTo (m_mem);
		m_loader.connectTo (m_eunit);
		m_loader.connectTo (m_biu);
	}

	ExecutionUnit& getExecutionUnit () {
		return m_eunit;
	}

	BusInterfaceUnit& getBusInterfaceUnit () {
		return m_biu;
	}

	Memory& getMemory () {
		return m_mem;
	}

protected:
	//override
	virtual void run () {
		m_thread_run = true;

		//while (m_thread_run) {
			/*switch (m_cpu_state) {
			case CPU_STATE_RUN:
				break;
			case CPU_STATE_SINGLE_STEP:
				break;
			case CPU_STATE_PAUSE:
				break;
			}*/
			//exec ();

			//std::cout << "here" << std::endl;
		//}
	}

public slots:
	void startCpu () {
		std::cout << "startCpu ()" << std::endl;
		m_cpu_state = CPU_STATE_RUN;
	}

	void pauseCpu () {
		std::cout << "pauseCpu ()" << std::endl;
		m_cpu_state = CPU_STATE_PAUSE;
	}

	void resetCpu () {
		std::cout << "resetCpu ()" << std::endl;
	}

	void singleStepCpu () {
		std::cout << "singleStepCpu ()" << std::endl;
		m_cpu_state = CPU_STATE_SINGLE_STEP;
	}

	void loadFile (QString file_name) {
		m_loader.loadFile (file_name.toStdString ());
	}
};

#endif //CPU_HH

