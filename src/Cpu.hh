#ifndef CPU_HH
#define CPU_HH

#include "ExecutionUnit.hh"
#include "BusInterfaceUnit.hh"
#include "Memory.hh"

#include "Loader.hh"

#include "FlagRegisterSignalsAndSlots.hh"
#include "MemorySignalsAndSlots.hh"
#include "GeneralRegisterSignalsAndSlots.hh"
#include "SegmentRegisterSignalsAndSlots.hh"

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
public:
	ExecutionUnit m_eunit;
	BusInterfaceUnit m_biu;

private:
	Loader m_loader;

	GeneralRegisterSignalsAndSlots m_gen_reg_s_s;
	FlagRegisterSignalsAndSlots m_flag_reg_s_s;
	SegmentRegisterSignalsAndSlots m_sreg_s_s;
	MemorySignalsAndSlots m_mem_s_s;

	bool m_thread_run;

public:
	Cpu (size_t mem_size = 1048576, QObject *parent = 0) : QThread (parent), m_mem (mem_size) {
		m_cpu_state = CPU_STATE_PAUSE;

		m_eunit.connectTo (m_biu);
		m_biu.connectTo (m_mem);

		m_loader.connectTo (m_mem);
		m_loader.connectTo (m_eunit);
		m_loader.connectTo (m_biu);

		//connect sigc++ signals to Qt signals
		m_eunit.getRegAX ().connectToSignalValueChanged (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegAX));
		m_eunit.getRegBX ().connectToSignalValueChanged (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegBX));
		m_eunit.getRegCX ().connectToSignalValueChanged (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegCX));
		m_eunit.getRegDX ().connectToSignalValueChanged (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegDX));

		m_eunit.getRegSI ().connectToSignalValueChanged (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegSI));
		m_eunit.getRegDI ().connectToSignalValueChanged (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegDI));

		m_eunit.getRegBP ().connectToSignalValueChanged (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegBP));
		m_eunit.getRegSP ().connectToSignalValueChanged (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegSP));

		m_eunit.getRegFlags ().connectToSignalValueChanged (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlags));

		//m_eunit.connectToSignalValueChangedRegFlags (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlags));
		m_eunit.connectToSignalValueChangedRegFlagsAF (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagAF));
		m_eunit.connectToSignalValueChangedRegFlagsCF (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagCF));
		m_eunit.connectToSignalValueChangedRegFlagsDF (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagDF));
		m_eunit.connectToSignalValueChangedRegFlagsIF (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagIF));
		m_eunit.connectToSignalValueChangedRegFlagsOF (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagOF));
		m_eunit.connectToSignalValueChangedRegFlagsPF (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagPF));
		m_eunit.connectToSignalValueChangedRegFlagsSF (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagSF));
		m_eunit.connectToSignalValueChangedRegFlagsTF (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagTF));
		m_eunit.connectToSignalValueChangedRegFlagsZF (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagZF));

		m_biu.getSegRegCS ().connectToSignalValueChanged (sigc::mem_fun (m_sreg_s_s, &SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegCS));
		m_biu.getSegRegDS ().connectToSignalValueChanged (sigc::mem_fun (m_sreg_s_s, &SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegDS));
		m_biu.getSegRegES ().connectToSignalValueChanged (sigc::mem_fun (m_sreg_s_s, &SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegES));
		m_biu.getSegRegSS ().connectToSignalValueChanged (sigc::mem_fun (m_sreg_s_s, &SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegSS));

		m_biu.getRegIP ().connectToSignalValueChanged (sigc::mem_fun (m_sreg_s_s, &SegmentRegisterSignalsAndSlots::sigcSlotValueChangedRegIP));
	}

	/** */
	GeneralRegisterSignalsAndSlots& getGeneralRegisterSignalsAndSlots ();

	/** */
	FlagRegisterSignalsAndSlots& getFlagRegisterSignalsAndSlots ();

	/** */
	SegmentRegisterSignalsAndSlots& getSegmentRegisterSignalsAndSlots ();

	/** */
	MemorySignalsAndSlots& getMemorySignalsAndSlots ();

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

