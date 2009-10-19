#include "Cpu.hh"
#include "Sim86Window.hh"
#include "ProxyLayer.hh"

#include <QApplication>

#include <iostream>

int main (int argc, char **argv) {
	QApplication app (argc, argv);

	Sim86Window sim;
	Cpu cpu;
	ProxyLayer proxy;

	proxy.connectCpuAndUi (cpu, sim);

	cpu.getMemory ().resize (48001);

	QObject::connect (&app, SIGNAL(aboutToQuit ()),
	                  &cpu, SLOT(shutdownCpu ()));

	//cpu.start ();

	sim.showMaximized ();

	return app.exec ();
}

