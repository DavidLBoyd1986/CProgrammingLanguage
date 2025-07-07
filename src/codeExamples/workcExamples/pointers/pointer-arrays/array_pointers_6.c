#include <stdlib.h>
#include <stdio.h>

int main()
{
	int number_array[] = {13, 14, 11, 10, 12, 11};

	size_t size_of_array = sizeof(number_array) / sizeof(int);

	printf("ADDRESS \t VALUE \n");
	for (int i = 0; i < size_of_array; i++) {
		printf("%p \t %d \n", &number_array[i], number_array[i]);
	}

	return EXIT_SUCCESS;
}
