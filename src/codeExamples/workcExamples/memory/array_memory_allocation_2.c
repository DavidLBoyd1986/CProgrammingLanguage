#include <stdlib.h>
#include <stdio.h>

int main()
{
	// How to create an int array using dynamic memory
	int *student_age_ptr = (int *)malloc(5 * sizeof(int));

	if (student_age_ptr == NULL) {
		printf("Memory not allocated! \n");
		return EXIT_FAILURE;
	}

	// C lets us use this pointer to a memory block as an array
	student_age_ptr[0] = 12;
	student_age_ptr[1] = 10;
	student_age_ptr[2] = 13;
	student_age_ptr[3] = 14;
	student_age_ptr[4] = 11;

	printf("ADDRESS \t VALUE \n");

	//size_t len = sizeof(student_ages) /sizeof(int);

	// Below is same as if pointer to dynamic memory was a stack array.
	for (int i = 0; i < 5; i++) {
		printf("%p \t %d \n", &student_age_ptr[i], student_age_ptr[i]);
	}

	free(student_age_ptr);

	return EXIT_SUCCESS;
}
