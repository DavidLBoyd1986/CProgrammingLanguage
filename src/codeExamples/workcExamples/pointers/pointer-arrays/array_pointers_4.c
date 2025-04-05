#include <stdlib.h>
#include <stdio.h>

int main()
{
	int student_ages[] = {13, 14, 11, 10, 12, 11};
	int *student_age_ptr = student_ages;

	size_t len = sizeof(student_ages) / sizeof(int);

	//type of size_t is an alias for an unsigned int

	// IMPORTANT - sizeof(student_age_ptr) would be different than the above,
	// 		it would return the num of bytes in the pointer.
	// 		This is one exception to the arrays being pointers rule

	for (int i = 0; i < len; i++) {
		printf("Student age at index %d = %d\n", i, student_age_ptr[i]);
	}

	return EXIT_SUCCESS;
}
