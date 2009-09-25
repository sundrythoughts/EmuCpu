#include <cstdio>
#include <iostream>

using namespace std;

class Klass {
public:
	void func () {
		cout << "void" << endl;
	}

	void func (const unsigned char &v) {
		cout << "char" << endl;
	}

	void func (const unsigned short &v) {
		cout << "short" << endl;
	}

	void func (const unsigned int &v) {
		cout << "int" << endl;
	}
};

void
Klass::func () {
	cout << "void" << endl;
}

void
Klass::func (const unsigned char &v) {
	cout << "char" << endl;
}

void
Klass::func (const unsigned short &v) {
	cout << "short" << endl;
}

void
Klass::func (const unsigned int &v) {
	cout << "int" << endl;
}

int main (int argc, char **argv) {
	Klass k;
	unsigned char n = 10;
	k.func (n);

	return 0;
}
