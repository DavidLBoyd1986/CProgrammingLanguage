#include <stdlib.h>
#include <stdio.h>

int main()
{
	int year = 1921;
	int *year_ptr = NULL;

	printf("year value: %d \n", year);
	printf("year address: %p \n", year_ptr);

	printf("\n");

	year_ptr = &year;
	printf("year address: %p \n", year_ptr);
	printf("\n");

	return EXIT_SUCCESS;
}
