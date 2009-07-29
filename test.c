#include <stdio.h>

int main (int argc, char **argv) {
	char *str = "";
	printf ("%c\n%s\n", *str, &str[1]);

	return 0;
}
