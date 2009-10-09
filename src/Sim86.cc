#include "Cpu.hh"
#include "Sim86Window.hh"
#include "ProxyLayer.hh"

#include <QApplication>

int main (int argc, char **argv) {
	QApplication app (argc, argv);

	Sim86Window sim;
	Cpu cpu;
	ProxyLayer proxy;

	proxy.connectCpuAndUi (cpu, sim);

	/*
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

	cpu.loadFile ("../testing/TEST5.OBJ");
	*/

	QObject::connect (&app, SIGNAL(aboutToQuit ()),
	                  &cpu, SLOT(shutdownCpu ()));

	cpu.start ();

	sim.show ();

	return app.exec ();
}

