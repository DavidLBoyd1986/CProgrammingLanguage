#include <stdlib.h>
#include <stdio.h>

int main()
{
	int number_array[] = {100, 200, 300, 400, 500};
	int *arr_ptr = number_array;

	size_t size_of_array = sizeof(number_array) / sizeof(int);

	printf("Array VALUE \t Pointer VALUE \n");
	for (int i = 0; i < size_of_array; i++) {
		printf("%d \t %d \n", number_array[i], *(arr_ptr + i));
	}

	printf("\nThe () are required for *(arr_ptr + i)\n");
	printf("Below is an example of not using (). ex: *arr_ptr + i\n\n");

	for (int i = 0; i < size_of_array; i++) {
		printf("%p \t %d \n", &arr_ptr, *arr_ptr + i);
	}
	return EXIT_SUCCESS;
}
