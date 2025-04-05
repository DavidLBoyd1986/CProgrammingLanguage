#include <stdlib.h>
#include <stdio.h>

int main()
{
	int number_array[] = {100, 200, 300, 400, 500};
	int *arr_ptr = number_array;

	size_t size_of_array = sizeof(number_array) / sizeof(int);

	printf("ADDRESS \t VALUE \n");
	for (int i = 0; i < size_of_array; i++) {
		printf("%p \t %d \n", arr_ptr + i, *(arr_ptr + i));
	}

	return EXIT_SUCCESS;
}
