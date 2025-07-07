#include <stdlib.h>
#include <stdio.h>

int main()
{
	int some_uninitialized_var;
	int *some_ptr = &some_uninitialized_var;

	int *another_ptr = NULL;

	printf("\n");
	printf("---------------ADDRESS-----------------\n");
	printf("Address pointed to by some_ptr is: %p \n", some_ptr);
	printf("Address pointed to by another_ptr is: %p \n", another_ptr);

	printf("---------------VALUE-----------------\n");
	// Dereferences an uninitialized value, returns junk data
	printf("Value referenced by some_ptr is: %d \n", *some_ptr);
	// Dereferencing the Null Pointer will fail to compile, so we don't do it.
	printf("\n");

	// The above shows why you shouldn't use pointers to stack variables.
	// Instead should use pointers to heap memory.

	return EXIT_SUCCESS;
}
