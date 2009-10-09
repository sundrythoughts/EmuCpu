#include "ProxyLayer.hh"

void
ProxyLayer::connectCpuAndUi (Cpu &cpu, Sim86Window &win) {
	connectCpuSignalsToUiSlots (cpu, win);
	connectUiSignalsToCpuSlots (win, cpu);
}

void
ProxyLayer::connectCpuSignalsToUiSlots (Cpu &cpu, Sim86Window &win) {
	//connect Cpu sigc++ signals to ProxyLayer
	cpu.getExecutionUnit ().getRegAX ().signalValueChanged ().connect (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegAX));
	cpu.getExecutionUnit ().getRegBX ().signalValueChanged ().connect (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegBX));
	cpu.getExecutionUnit ().getRegCX ().signalValueChanged ().connect (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegCX));
	cpu.getExecutionUnit ().getRegDX ().signalValueChanged ().connect (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegDX));

	cpu.getExecutionUnit ().getRegSI ().signalValueChanged ().connect (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegSI));
	cpu.getExecutionUnit ().getRegDI ().signalValueChanged ().connect (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegDI));

	cpu.getExecutionUnit ().getRegBP ().signalValueChanged ().connect (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegBP));
	cpu.getExecutionUnit ().getRegSP ().signalValueChanged ().connect (sigc::mem_fun (m_gen_reg_s_s, &GeneralRegisterSignalsAndSlots::sigcSlotValueChangedRegSP));

	cpu.getExecutionUnit ().getRegFlags ().signalValueChanged ().connect (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlags));

	cpu.getExecutionUnit ().connectToSignalValueChangedRegFlagsAF (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagAF));
	cpu.getExecutionUnit ().connectToSignalValueChangedRegFlagsCF (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagCF));
	cpu.getExecutionUnit ().connectToSignalValueChangedRegFlagsDF (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagDF));
	cpu.getExecutionUnit ().connectToSignalValueChangedRegFlagsIF (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagIF));
	cpu.getExecutionUnit ().connectToSignalValueChangedRegFlagsOF (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagOF));
	cpu.getExecutionUnit ().connectToSignalValueChangedRegFlagsPF (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagPF));
	cpu.getExecutionUnit ().connectToSignalValueChangedRegFlagsSF (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagSF));
	cpu.getExecutionUnit ().connectToSignalValueChangedRegFlagsTF (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagTF));
	cpu.getExecutionUnit ().connectToSignalValueChangedRegFlagsZF (sigc::mem_fun (m_flag_reg_s_s, &FlagRegisterSignalsAndSlots::sigcSlotValueChangedFlagZF));

	cpu.getBusInterfaceUnit ().getSegRegCS ().signalValueChanged ().connect (sigc::mem_fun (m_sreg_s_s, &SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegCS));
	cpu.getBusInterfaceUnit ().getSegRegDS ().signalValueChanged ().connect (sigc::mem_fun (m_sreg_s_s, &SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegDS));
	cpu.getBusInterfaceUnit ().getSegRegES ().signalValueChanged ().connect (sigc::mem_fun (m_sreg_s_s, &SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegES));
	cpu.getBusInterfaceUnit ().getSegRegSS ().signalValueChanged ().connect (sigc::mem_fun (m_sreg_s_s, &SegmentRegisterSignalsAndSlots::sigcSlotValueChangedSRegSS));

	cpu.getBusInterfaceUnit ().getRegIP ().signalValueChanged ().connect (sigc::mem_fun (m_sreg_s_s, &SegmentRegisterSignalsAndSlots::sigcSlotValueChangedRegIP));

	cpu.getMemory ().signalValueChanged ().connect (sigc::mem_fun (m_mem_s_s, &MemorySignalsAndSlots::sigcSlotValueChanged));
	cpu.getMemory ().signalResized ().connect (sigc::mem_fun (m_mem_s_s, &MemorySignalsAndSlots::sigcSlotResized));
	cpu.getMemory ().signalReloaded ().connect (sigc::mem_fun (m_mem_s_s, &MemorySignalsAndSlots::sigcSlotReloaded));

	//connect ProxyLayer Qt signals to Sim86Window Qt slots

	//Flag Register Widget Signals and Slots
	QObject::connect (&m_flag_reg_s_s, SIGNAL(valueChangedFlags (unsigned short)),
		          &win.getFlagsWidget (), SLOT(setFlags (unsigned short)));
	QObject::connect (&m_flag_reg_s_s, SIGNAL(valueChangedFlagAF (bool)),
		          &win.getFlagsWidget (), SLOT(setFlagAF (bool)));
	QObject::connect (&m_flag_reg_s_s, SIGNAL(valueChangedFlagCF (bool)),
		          &win.getFlagsWidget (), SLOT(setFlagCF (bool)));
	QObject::connect (&m_flag_reg_s_s, SIGNAL(valueChangedFlagDF (bool)),
		          &win.getFlagsWidget (), SLOT(setFlagDF (bool)));
	QObject::connect (&m_flag_reg_s_s, SIGNAL(valueChangedFlagIF (bool)),
		          &win.getFlagsWidget (), SLOT(setFlagIF (bool)));
	QObject::connect (&m_flag_reg_s_s, SIGNAL(valueChangedFlagOF (bool)),
		          &win.getFlagsWidget (), SLOT(setFlagOF (bool)));
	QObject::connect (&m_flag_reg_s_s, SIGNAL(valueChangedFlagPF (bool)),
		          &win.getFlagsWidget (), SLOT(setFlagPF (bool)));
	QObject::connect (&m_flag_reg_s_s, SIGNAL(valueChangedFlagSF (bool)),
		          &win.getFlagsWidget (), SLOT(setFlagSF (bool)));
	QObject::connect (&m_flag_reg_s_s, SIGNAL(valueChangedFlagTF (bool)),
		          &win.getFlagsWidget (), SLOT(setFlagTF (bool)));
	QObject::connect (&m_flag_reg_s_s, SIGNAL(valueChangedFlagZF (bool)),
		          &win.getFlagsWidget (), SLOT(setFlagZF (bool)));

	//Segment Register Widget Signals and Slots
	QObject::connect (&m_sreg_s_s, SIGNAL(valueChangedSegRegCS (unsigned short)),
		          &win.getSegmentRegistersWidget (), SLOT(setSegRegCS (unsigned short)));
	QObject::connect (&m_sreg_s_s, SIGNAL(valueChangedSegRegDS (unsigned short)),
		          &win.getSegmentRegistersWidget (), SLOT(setSegRegDS (unsigned short)));
	QObject::connect (&m_sreg_s_s, SIGNAL(valueChangedSegRegES (unsigned short)),
		          &win.getSegmentRegistersWidget (), SLOT(setSegRegES (unsigned short)));
	QObject::connect (&m_sreg_s_s, SIGNAL(valueChangedSegRegSS (unsigned short)),
		          &win.getSegmentRegistersWidget (), SLOT(setSegRegSS (unsigned short)));
	QObject::connect (&m_sreg_s_s, SIGNAL(valueChangedRegIP (unsigned short)),
		          &win.getSegmentRegistersWidget (), SLOT(setRegIP (unsigned short)));

	//General Register Widget Signals and Slots
	QObject::connect (&m_gen_reg_s_s, SIGNAL(valueChangedRegAX (unsigned short)),
		          &win.getGeneralRegistersWidget (), SLOT(setRegAX (unsigned short)));
	QObject::connect (&m_gen_reg_s_s, SIGNAL(valueChangedRegBX (unsigned short)),
		          &win.getGeneralRegistersWidget (), SLOT(setRegBX (unsigned short)));
	QObject::connect (&m_gen_reg_s_s, SIGNAL(valueChangedRegCX (unsigned short)),
		          &win.getGeneralRegistersWidget (), SLOT(setRegCX (unsigned short)));
	QObject::connect (&m_gen_reg_s_s, SIGNAL(valueChangedRegDX (unsigned short)),
		          &win.getGeneralRegistersWidget (), SLOT(setRegDX (unsigned short)));
	QObject::connect (&m_gen_reg_s_s, SIGNAL(valueChangedRegSI (unsigned short)),
		          &win.getGeneralRegistersWidget (), SLOT(setRegSI (unsigned short)));
	QObject::connect (&m_gen_reg_s_s, SIGNAL(valueChangedRegDI (unsigned short)),
		          &win.getGeneralRegistersWidget (), SLOT(setRegDI (unsigned short)));
	QObject::connect (&m_gen_reg_s_s, SIGNAL(valueChangedRegBP (unsigned short)),
		          &win.getGeneralRegistersWidget (), SLOT(setRegBP (unsigned short)));
	QObject::connect (&m_gen_reg_s_s, SIGNAL(valueChangedRegSP (unsigned short)),
		          &win.getGeneralRegistersWidget (), SLOT(setRegSP (unsigned short)));

	//Memory Widget Signals and Slots
	QObject::connect (&m_mem_s_s, SIGNAL(valueChanged (int, unsigned char)),
		          &win.getMemoryWidget (), SLOT(setMemoryAddress (int, unsigned char)));
	QObject::connect (&m_mem_s_s, SIGNAL(resized (size_t)),
		          &win.getMemoryWidget (), SLOT(resize (size_t)));
	QObject::connect (&m_mem_s_s, SIGNAL(reloaded (const unsigned char*, size_t)),
		          &win.getMemoryWidget (), SLOT(setAllMemoryAddresses (const unsigned char*, size_t)));

	//Stack Widget Signals and Slots
	//FIXME

	//Disassembly Widget Signals and Slots
	//FIXME
	
}

void
ProxyLayer::connectUiSignalsToCpuSlots (Sim86Window &win, Cpu &cpu) {
	QObject::connect (&win, SIGNAL(startCpu ()),
	                  &cpu, SLOT(startCpu ()));
	QObject::connect (&win, SIGNAL(pauseCpu ()),
	                  &cpu, SLOT(pauseCpu ()));
	QObject::connect (&win, SIGNAL(singleStepCpu ()),
	                  &cpu, SLOT(singleStepCpu ()));
	QObject::connect (&win, SIGNAL(resetCpu ()),
	                  &cpu, SLOT(resetCpu ()));
	QObject::connect (&win, SIGNAL(loadFile (QString)),
	                  &cpu, SLOT(loadFile (QString)));
}

