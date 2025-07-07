#include <stdlib.h>
#include <stdio.h>

int main()
{
	int num = 45;
	int *num_ptr = &num;

	printf("--------------------ADDRESS---------------------\n");
	printf("Address of num is: %p \n", &num);
	printf("Value in num_ptr is: %p \n", num_ptr);
	printf("\n");

	printf("--------------------VALUE---------------------\n");
	printf("Address of num is: %d \n", num);
	printf("Value in num_ptr is: %d \n", *num_ptr);
	printf("\n");

	return EXIT_SUCCESS;
}
