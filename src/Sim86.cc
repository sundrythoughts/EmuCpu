#include "Cpu.hh"
#include "Sim86Window.hh"

#include <QApplication>

static void connectUiAndCpu (Sim86Window &win, Cpu &cpu) {
	//Flag Register Widget Signals and Slots
	QObject::connect (&cpu.getFlagRegisterSignalsAndSlots (), SIGNAL(valueChangedFlags (unsigned short)),
	                  &win.getFlagsWidget (), SLOT(setFlags (unsigned short)));
	QObject::connect (&cpu.getFlagRegisterSignalsAndSlots (), SIGNAL(valueChangedFlagAF (bool)),
	                  &win.getFlagsWidget (), SLOT(setFlagAF (bool)));
	QObject::connect (&cpu.getFlagRegisterSignalsAndSlots (), SIGNAL(valueChangedFlagCF (bool)),
	                  &win.getFlagsWidget (), SLOT(setFlagCF (bool)));
	QObject::connect (&cpu.getFlagRegisterSignalsAndSlots (), SIGNAL(valueChangedFlagDF (bool)),
	                  &win.getFlagsWidget (), SLOT(setFlagDF (bool)));
	QObject::connect (&cpu.getFlagRegisterSignalsAndSlots (), SIGNAL(valueChangedFlagIF (bool)),
	                  &win.getFlagsWidget (), SLOT(setFlagIF (bool)));
	QObject::connect (&cpu.getFlagRegisterSignalsAndSlots (), SIGNAL(valueChangedFlagOF (bool)),
	                  &win.getFlagsWidget (), SLOT(setFlagOF (bool)));
	QObject::connect (&cpu.getFlagRegisterSignalsAndSlots (), SIGNAL(valueChangedFlagPF (bool)),
	                  &win.getFlagsWidget (), SLOT(setFlagPF (bool)));
	QObject::connect (&cpu.getFlagRegisterSignalsAndSlots (), SIGNAL(valueChangedFlagSF (bool)),
	                  &win.getFlagsWidget (), SLOT(setFlagSF (bool)));
	QObject::connect (&cpu.getFlagRegisterSignalsAndSlots (), SIGNAL(valueChangedFlagTF (bool)),
	                  &win.getFlagsWidget (), SLOT(setFlagTF (bool)));
	QObject::connect (&cpu.getFlagRegisterSignalsAndSlots (), SIGNAL(valueChangedFlagZF (bool)),
	                  &win.getFlagsWidget (), SLOT(setFlagZF (bool)));

	//Segment Register Widget Signals and Slots
	QObject::connect (&cpu.getSegmentRegisterSignalsAndSlots (), SIGNAL(valueChangedSegRegCS (unsigned short)),
	                  &win.getSegmentRegistersWidget (), SLOT(setSegRegCS (unsigned short)));
	QObject::connect (&cpu.getSegmentRegisterSignalsAndSlots (), SIGNAL(valueChangedSegRegDS (unsigned short)),
	                  &win.getSegmentRegistersWidget (), SLOT(setSegRegDS (unsigned short)));
	QObject::connect (&cpu.getSegmentRegisterSignalsAndSlots (), SIGNAL(valueChangedSegRegES (unsigned short)),
	                  &win.getSegmentRegistersWidget (), SLOT(setSegRegES (unsigned short)));
	QObject::connect (&cpu.getSegmentRegisterSignalsAndSlots (), SIGNAL(valueChangedSegRegSS (unsigned short)),
	                  &win.getSegmentRegistersWidget (), SLOT(setSegRegSS (unsigned short)));
	QObject::connect (&cpu.getSegmentRegisterSignalsAndSlots (), SIGNAL(valueChangedRegIP (unsigned short)),
	                  &win.getSegmentRegistersWidget (), SLOT(setRegIP (unsigned short)));

	//General Register Widget Signals and Slots
	QObject::connect (&cpu.getGeneralRegisterSignalsAndSlots (), SIGNAL(valueChangedRegAX (unsigned short)),
	                  &win.getGeneralRegistersWidget (), SLOT(setRegAX (unsigned short)));
	QObject::connect (&cpu.getGeneralRegisterSignalsAndSlots (), SIGNAL(valueChangedRegBX (unsigned short)),
	                  &win.getGeneralRegistersWidget (), SLOT(setRegBX (unsigned short)));
	QObject::connect (&cpu.getGeneralRegisterSignalsAndSlots (), SIGNAL(valueChangedRegCX (unsigned short)),
	                  &win.getGeneralRegistersWidget (), SLOT(setRegCX (unsigned short)));
	QObject::connect (&cpu.getGeneralRegisterSignalsAndSlots (), SIGNAL(valueChangedRegDX (unsigned short)),
	                  &win.getGeneralRegistersWidget (), SLOT(setRegDX (unsigned short)));
	QObject::connect (&cpu.getGeneralRegisterSignalsAndSlots (), SIGNAL(valueChangedRegSI (unsigned short)),
	                  &win.getGeneralRegistersWidget (), SLOT(setRegSI (unsigned short)));
	QObject::connect (&cpu.getGeneralRegisterSignalsAndSlots (), SIGNAL(valueChangedRegDI (unsigned short)),
	                  &win.getGeneralRegistersWidget (), SLOT(setRegDI (unsigned short)));
	QObject::connect (&cpu.getGeneralRegisterSignalsAndSlots (), SIGNAL(valueChangedRegBP (unsigned short)),
	                  &win.getGeneralRegistersWidget (), SLOT(setRegBP (unsigned short)));
	QObject::connect (&cpu.getGeneralRegisterSignalsAndSlots (), SIGNAL(valueChangedRegSP (unsigned short)),
	                  &win.getGeneralRegistersWidget (), SLOT(setRegSP (unsigned short)));
}

int main (int argc, char **argv) {
	QApplication app (argc, argv);

	Sim86Window sim;
	Cpu cpu;

	connectUiAndCpu (sim, cpu);

	cpu.m_eunit.setRegFlags (0);
	cpu.m_eunit.setRegFlagsCF (true);
	cpu.m_eunit.setRegFlagsPF (true);
	cpu.m_eunit.setRegFlagsIF (true);

	cpu.m_biu.setSegRegCS (0xFFF1);
	cpu.m_biu.setSegRegDS (0xFFF2);
	cpu.m_biu.setSegRegES (0xFFF3);
	cpu.m_biu.setSegRegSS (0xFFF4);
	cpu.m_biu.setRegIP (0xFFF5);

	cpu.m_eunit.setRegSP (0xFF);

	cpu.start ();

	sim.show ();

	return app.exec ();
}

