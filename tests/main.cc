#include "Number.hh"
#include <iostream>
#include <sigc++/sigc++.h>

using namespace std;

static void valueChanged (int i) {
	cout << "valueChanged: " << i << endl;
}

int main (int argc, char **argv) {
	Number<int> *r1 = new Number<int> (10);
	Number<short> *r2 = new Number<short> (13);
	Number<int> *r3 = new Number<int> (0);

	r1->connectToSignalValueChanged (sigc::ptr_fun (&valueChanged));
	r2->connectToSignalValueChanged (sigc::ptr_fun (&valueChanged));
	r3->connectToSignalValueChanged (sigc::ptr_fun (&valueChanged));

	cout << *r1 << endl;

	delete r1;
	delete r2;
	delete r3;
}

