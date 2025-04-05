#include <stdlib.h>
#include <stdio.h>

int main()
{
	int some_uninitialized_var;
	int *some_ptr = &some_uninitialized_var;

	int *another_ptr = (int *)malloc(sizeof(int)); // (int *) is a cast
	// Memory Leak above because this application doesn't free this memory
	// malloc returns (void *), so any type can use, we cast (void *) to (int *)

	printf("\n");
	printf("---------------ADDRESS-----------------\n");
	printf("Address pointed to by some_ptr is: %p \n", some_ptr);
	printf("Address pointed to by another_ptr is: %p \n", another_ptr);

	printf("---------------VALUE-----------------\n");
	// Dereferences an uninitialized value, returns junk data
	printf("Value referenced by some_ptr is: %d \n", *some_ptr);
	printf("Value referenced by another_ptr is: %d \n", *another_ptr);
	printf("\n");

	// The above shows why you shouldn't use pointers to stack variables.
	// Instead should use pointers to heap memory.

	return EXIT_SUCCESS;
}
