#include "Operand.hh"
#include <iostream>

using namespace std;

int main (int argc, char **argv) {
	g_type_init ();

	{//Test 1
		GValue *v1 = (GValue*)g_malloc0 (sizeof(GValue));
		g_value_init (v1, G_TYPE_INT);
		g_value_set_int (v1, 13);
		int i1 = g_value_get_int (v1);

		Operand op1 (Operand::REG, v1);
		int i2 = g_value_get_int (op1.get_value ());

		if ((i1 == 13) && (i2 == 13)) {
			cout << "Test 1: Passed" << endl;
		}
		else {
			cout << "Test 1: Failed" << endl;
		}
	}//end Test 1

	{//Test 2
		GValue *v1 = (GValue*)g_malloc0 (sizeof(GValue));
		g_value_init (v1, G_TYPE_INT);
		GValue *v2 = (GValue*)g_malloc0 (sizeof(GValue));
		g_value_init (v1, G_TYPE_INT);
		GValue *v3 = (GValue*)g_malloc0 (sizeof(GValue));
	}//end Test 2
}
