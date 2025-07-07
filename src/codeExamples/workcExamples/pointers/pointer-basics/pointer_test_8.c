#include <stdlib.h>
#include <stdio.h>

int main()
{
	int year = 1921;
	int *year_ptr = &year;

	printf("year value: %d \n", year);
	printf("year address: %p \n", year_ptr);
	printf("year pointer address: %p \n", &year_ptr);

	return EXIT_SUCCESS;
}
