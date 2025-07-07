#include <stdlib.h>
#include <stdio.h>

int main()
{
	int num = 33;
	int *num_ptr = &num;

	printf("Address of num is: %p \n", &num);
	printf("Address stored in num_ptr is: %p \n", num_ptr);
	printf("Value pointed to by num_ptr is: %d \n", *num_ptr);

	printf("\n");

	printf("-------------------UPDATE VALUE------------------ \n");

	*num_ptr = *num_ptr * 100; // De-reference pointer to get contents of variable on both sides of the equation.

	printf("Address of num is (no change): %p \n", &num);
	printf("Address stored in num_ptr is (no change): %p \n", num_ptr);
	printf("Value pointed to by num_ptr is: %d \n", *num_ptr);

	return EXIT_SUCCESS;
}
