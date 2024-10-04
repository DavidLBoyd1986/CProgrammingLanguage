#include <stdio.h>

int main() {

	// % is the modulo operator
	for (int i = 0; i < 100; i++) {
		if (i % 2 == 0) {
			printf("%i, ", i);
		}
	}

	return 0;
};
