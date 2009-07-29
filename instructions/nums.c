#include <stdio.h>

int main (int argc, char **argv) {
	int i;
	for (i = 0; i <= 0xff; ++i) {
		printf ("%x%%\n", i);
	}
}
