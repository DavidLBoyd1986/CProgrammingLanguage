#include <stdlib.h>
#include <stdio.h>

int main()
{
	int student_ages[] = {13, 14, 11, 10, 12, 11};

	int *student_age_ptr = student_ages;

	printf("Address of student_ages (integer array): %p\n", student_ages);
	printf("Address of student_ages (via pointer): %p\n", student_age_ptr);

	return EXIT_SUCCESS;
}
