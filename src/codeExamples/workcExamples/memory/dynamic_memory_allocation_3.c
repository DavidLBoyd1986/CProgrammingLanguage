#include <stdlib.h>
#include <stdio.h>

int main()
{
	int some_var = 100;
	int *some_ptr = &some_var;

	printf("Value referenced by some_ptr: %d \n", *some_ptr);

	int *another_ptr = (int *)malloc(sizeof(int)); // (int *) is a cast
	// malloc returns (void *), so any type can use, we cast (void *) to (int *)

	if (another_ptr != NULL) {
		*another_ptr = 1000;
		printf("Value referenced by another_ptr: %d \n", *another_ptr);
	}

	free(another_ptr);

	return EXIT_SUCCESS;
}
