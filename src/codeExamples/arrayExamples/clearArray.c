#include <stdio.h>

int main() {

	char testArrayOne[100] = "Test Array";
	int arraySize = 10;
	
	printf("\nArray String = %s\n", testArrayOne);

	while (arraySize >= 0) {
		printf("\nArray Char = %c\n", testArrayOne[arraySize]);
		printf("Array String = %s\n", testArrayOne);
		testArrayOne[arraySize] = '\0';
		arraySize--;
	}
	printf("\nArray String = %s\n", testArrayOne);

	char testArrayTwo[100] = "Test Array";
	arraySize = 10;
	
	printf("\nArray String = %s\n", testArrayTwo);
	testArrayTwo[0] = '\0';
	printf("\nArray String = %s\n", testArrayTwo);

	while (arraySize >= 0) {
		printf("\nArray Char = %c\n", testArrayTwo[arraySize]);
		printf("Array String = %s\n", testArrayTwo);
		arraySize--;
	}
}
