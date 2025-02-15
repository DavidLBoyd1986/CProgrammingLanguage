#include <stdio.h>

int testarray[] = { 1, 3, 5, 6, 8, 20 };

int main() {

	for (int i = 0; i <= 5; i++) {
		printf("\nArray[%i] = %i\n", i, testarray[i]);
	}

	char testchararray[] = "test char array";
	int size_of_tcarray = sizeof(testchararray) / sizeof(testchararray[0]);


	for (int i = 0; i <= size_of_tcarray; i++) {
		printf("\nArray[%i] = %c\n", i, testchararray[i]);
	}
}
