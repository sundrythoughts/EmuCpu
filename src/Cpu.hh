#ifndef CPU_HH
#define CPU_HH

#include "ExecutionUnit.hh"
#include "BusInterfaceUnit.hh"
#include "Memory.hh"

#include "FlagRegisterSignalsAndSlots.hh"
#include "MemorySignalsAndSlots.hh"
#include "GeneralRegisterSignalsAndSlots.hh"
#include "SegmentRegisterSignalsAndSlots.hh"

#include <iostream>
#include <sigc++/sigc++.h>

#include <QObject>

class Cpu : public QObject {
	Q_OBJECT

	Memory m_mem;
	ExecutionUnit m_eunit;
	BusInterfaceUnit m_biu;

	GeneralRegisterSignalsAndSlots m_gen_reg_s_s;
	FlagRegisterSignalsAndSlots m_flag_reg_s_s;
	SegmentRegisterSignalsAndSlots m_sreg_s_s;
	MemorySignalsAndSlots m_mem_s_s;

public:
	Cpu (size_t mem_size = 1048576, QObject *parent = 0) : QObject (parent), m_mem (mem_size) {
		m_eunit.connectTo (m_biu);
		m_biu.connectTo (m_mem);

		//connect sigc++ signals to Qt signals
		m_eunit.getRegAX ().connectToSignalValueChanged (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegAX));
		m_eunit.getRegBX ().connectToSignalValueChanged (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegBX));
		m_eunit.getRegCX ().connectToSignalValueChanged (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegCX));
		m_eunit.getRegDX ().connectToSignalValueChanged (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegDX));

		m_eunit.getRegSI ().connectToSignalValueChanged (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegSI));
		m_eunit.getRegDI ().connectToSignalValueChanged (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegDI));

		m_eunit.getRegBP ().connectToSignalValueChanged (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegBP));
		m_eunit.getRegSP ().connectToSignalValueChanged (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegSP));

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
	}

	GeneralRegisterSignalsAndSlots& getGeneralRegisterSignalsAndSlots ();

	FlagRegisterSignalsAndSlots& getFlagRegisterSignalsAndSlots ();

	SegmentRegisterSignalsAndSlots& getSegmentRegisterSignalsAndSlots ();

	MemorySignalsAndSlots& getMemorySignalsAndSlots ();

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
};

#endif //CPU_HH

