#include <stdio.h>

int main() {

	int c, i, nwhite, nother, ndigit[10];
	nwhite = nother = 0;

	// initialize array to all 0 values
	for (i = 0; i < 10; i++) {
		ndigit[i] = 0;
	}

	// This while loop is nothing but a wrapper to the switch
	while ((c = getchar()) != EOF) {

		// Switch example
		switch (c) {
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			// c - '0' somehow gets the correct array index for array[1234567890]
			ndigit[c-'0']++;
			break;
		case ' ':
		case '\n':
		case '\t':
			nwhite++;
			break;
		default:
			nother++;
			break;
		}
	}

	// Output
	printf("digits =");
	for (i = 0; i < 10; i++) {
		printf(" %d", ndigit[i]);
	}
	printf(", white space = %d, other = %d\n", nwhite, nother);

	return 0;
}
