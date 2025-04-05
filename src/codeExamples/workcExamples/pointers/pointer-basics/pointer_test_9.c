#include <stdlib.h>
#include <stdio.h>

int main()
{
	int year = 1921;
	int *year_ptr = &year;
	int *another_ptr = year_ptr;

	printf("year value: %d \n", year);
	printf("dereference year value through year_ptr: %d \n", *year_ptr);
	printf("dereference year value through another_ptr: %d \n", *another_ptr);

	return EXIT_SUCCESS;
}
