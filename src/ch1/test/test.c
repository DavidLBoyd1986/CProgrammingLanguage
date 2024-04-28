#include <stdio.h>

void printArray(int array[], int size);

int main()
{
	/* %d prints the int value of a string */
	printf("%d\n", 6);
	printf("%d\n", 'a');
	printf("%d\n", 'b');
	printf("%d\n", 'c');
	printf("-------------\n");
	/* No Strings, char[] arrays are strings */
	printf("%s\n", "a");
	printf("%s\n", "b");
	printf("%s\n", "c");
	printf("a");
	printf("b");
	printf("c");
	printf("\n");
	printf("-------------\n");
	char helloString[] = "Hello, World!";
	printf("%s\n", helloString);
	printf("-------------\n");
	int arraySize = 20;
	int testArray[arraySize];
	int numOfInputs = 0;
	for (int t = 0; t < 11; t++){
		testArray[t] = t;
		numOfInputs++;
	}
	printArray(testArray, numOfInputs);
	return 0;

}

void printArray(int array[], int size){
	for (int n = 0; n < size; n++){
		printf("%d\n", array[n]);
	}
}
