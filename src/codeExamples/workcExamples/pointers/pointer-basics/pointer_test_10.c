#include <stdlib.h>
#include <stdio.h>

int main()
{
	int year = 1921;
	int *year_ptr = &year;

	printf("year value: %d \n", year);
	printf("year address: %p \n", year_ptr);
	printf("test case: %d \n", *&year);  //Works!!
	printf("test case: %p \n", &*year_ptr);  //Works!!

	return EXIT_SUCCESS;
}
