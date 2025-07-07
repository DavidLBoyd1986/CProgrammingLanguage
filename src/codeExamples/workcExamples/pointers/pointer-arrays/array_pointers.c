#include <stdlib.h>
#include <stdio.h>

int main()
{
	int student_age = 15;

	int student_ages[] = {13, 14, 11, 10, 12, 11};

	printf("Address of student_age (integer): %p\n", &student_age);
	printf("Address of student_ages (integer): %p\n", student_ages); //No & needed

	return EXIT_SUCCESS;
}
