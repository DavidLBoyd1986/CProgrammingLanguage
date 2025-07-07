#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct Student {
		int *id;
		char *name;
		float *math_score;
		float *english_score;
	};

	struct Student student;

	student.id = (int *)malloc(sizeof(int));
	student.name = (char *)calloc(20, sizeof(char));
	student.math_score = (float *)malloc(sizeof(float));
	student.english_score = (float *)malloc(sizeof(float));

	// *student.id refers to id under student being a pointer
	*student.id = 111;
	strcpy(student.name, "David");
	*student.math_score = 98.23;
	*student.english_score = 99.99;

	printf("Student id: %d\n", *student.id);
	printf("Student name: %s\n", student.name);
	printf("Student math_score: %.2f\n", *student.math_score);
	printf("Student english_score: %.2f\n", *student.english_score);

	free(student.id);
	free(student.name);
	free(student.math_score);
	free(student.english_score);

	return EXIT_SUCCESS;
}

