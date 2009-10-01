#include <QApplication>
#include "Sim86Window.hh"

using namespace std;

int main (int argc, char **argv) {
	QApplication app (argc, argv);

	Sim86Window sim;
	sim.show ();

	return app.exec ();
}

