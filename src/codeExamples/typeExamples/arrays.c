#include <stdio.h>

int main() {

	char testCharArray[100] = "Hello World";
	printf("\n%s\n", testCharArray);

	int testIntArray[100];

	for (int i = 0; i < 100; ++i) {
		testIntArray[i] = i;
	}

	for (int i = 0; i < 100; ++i) {
		printf("testIntArray Value = %i, ", testIntArray[i]);
	}

	return 0;
}
