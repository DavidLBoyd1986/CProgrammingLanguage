#include <stdio.h>

int main() {

	// % is the modulo operator
	for (int i = 0; i < 100; i++) {
		if (i % 2 == 0) {
			printf("%i, ", i);
		}
	}

	double test1 = 20;
	double test2 = 3;
	double answer1 = (int) test1 % (int) test2;
	printf("\ndouble answer = %g\n", answer1);

	return 0;
};
