/**
@file Cpu.hh
@brief Manage a thread that holds all the components of a Cpu.
*/

#ifndef JAF__CPU_HH
#define JAF__CPU_HH

#include "ExecutionUnit.hh"
#include "ArithmeticLogicUnit.hh"
#include "BusInterfaceUnit.hh"
#include "Memory.hh"
#include "InstructionDecoder.hh"

#include "Loader.hh"

#include <iostream>
#include <sigc++/sigc++.h>

#include <QThread>
#include <QMutex>

class ExecutionUnit;
class BusInterfaceUnit;
class ArithmeticLogicUnit;
class BusInterfaceUnit;
class Memory;
class CpuPrivate;

/**
@class Cpu
@brief Manage a thread that holds all the components of a Cpu.
*/
class Cpu : public QThread {
	Q_OBJECT

	CpuPrivate *p;

	enum CpuStateEnum {
		CPU_STATE_RUN,
		CPU_STATE_SINGLE_STEP,
		CPU_STATE_PAUSE
	};

	CpuStateEnum m_cpu_state;
	QMutex m_mutex;
	bool m_thread_run;

public:
	/** */
	Cpu (QObject *parent = 0);

	/** */
	~Cpu ();

	/** */
	ExecutionUnit& getExecutionUnit ();

	/** */
	BusInterfaceUnit& getBusInterfaceUnit ();

	/** */
	Memory& getMemory ();

	/** */
	ArithmeticLogicUnit& getArithmeticLogicUnit ();

protected:
	//override
	/** */
	virtual void run ();

public slots:
	/** */
	void startCpu ();

	/** */
	void pauseCpu ();

	/** */
	void resetCpu ();

	/** */
	void singleStepCpu ();

	/** */
	void shutdownCpu ();

	/** */
	void loadFile (QString file_name);
}; //end class Cpu

#endif //JAF__CPU_HH

