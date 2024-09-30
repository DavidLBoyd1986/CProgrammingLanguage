#include <stdio.h>
#include <stdlib.h>


float testFloat = 56.321;

int main() {

	short convertFloat = (short) testFloat;

	printf("\nConverted float: %i\n", convertFloat);

	return 1;
}
