#include <stdlib.h>
#include <stdio.h>

int main()
{
	int student_ages[] = {13, 14, 11, 10, 12, 11};
	int *student_age_ptr = student_ages;

	printf("Address of student_ages (integer array): %p\n", student_ages);
	printf("Address of student_ages (via pointer): %p\n", student_age_ptr);

	printf("address of student_ages): %p\n", student_age_ptr);
	printf("value of student_ages): %i\n", *student_age_ptr);
	student_age_ptr += 2;
	printf("address of student_ages + 2): %p\n", student_age_ptr);
	printf("value of student_ages + 2): %i\n", *student_age_ptr);
	return EXIT_SUCCESS;
}
