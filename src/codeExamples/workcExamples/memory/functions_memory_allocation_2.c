#include <stdlib.h>
#include <stdio.h>

// The caller of the function is responsible for freeing the memory of the returned pointer
char* get_grades(int* scores, int length)
{
	char* grades = (char *)malloc(length * sizeof(char));

	for (int i = 0; i < length; i++) {
		int score = *(scores + i);

		if (score >= 90) {
			*(grades + i) = 'A';
		} else if (score >= 70) {
			*(grades + i) = 'B';
		} else if (score >= 50) {
			*(grades + i) = 'C';
		} else if (score >= 30) {
			*(grades + i) = 'D';
		} else {
			*(grades + i) = 'F';
		}
	}

	return grades;
}

int main()
{
	int student_scores[10] = {85, 40, 60, 29, 49, 10, 100, 23, 85, 70};

	char* grades = get_grades(student_scores, 10);

	for (int i = 0; i < 10; i++) {
		printf("Student grade for score %d = %c\n", *(student_scores + i), *(grades + i));
	}

	free(grades); // Frees the memory at pointer location: grades

	return EXIT_SUCCESS;
}
