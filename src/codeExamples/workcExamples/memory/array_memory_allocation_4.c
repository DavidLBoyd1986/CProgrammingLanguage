#include <stdlib.h>
#include <stdio.h>

int main()
{
	// How to create an int array using dynamic memory
	int *int_ptr = (int *)malloc(10 * sizeof(int));

	if (int_ptr == NULL) {
		printf("Memory not allocated! \n");
		return EXIT_FAILURE;
	}
	// Size of dynamically allocted pointer will be wrong
	// Does not know the size of the entire block of memory
	// It only returns the size of pointers, 8 bytes.
	printf("Size of int_ptr: %lu \n", sizeof(int_ptr)); //Wrong
	printf("Size of value referenced by int_ptr: %lu \n", sizeof(*int_ptr));

	free(int_ptr);

	int len_int_ptr = sizeof(int_ptr) / sizeof(*int_ptr);
	printf("Length of int_ptr array is: %d\n", len_int_ptr);

	return EXIT_SUCCESS;
}
