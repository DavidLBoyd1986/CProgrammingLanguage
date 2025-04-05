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

	struct Student *student_ptr = (struct Student *)malloc(sizeof(struct Student));

	student_ptr->id = (int *)malloc(sizeof(int));
	student_ptr->name = (char *)calloc(20, sizeof(char));
	student_ptr->math_score = (float *)malloc(sizeof(float));
	student_ptr->english_score = (float *)malloc(sizeof(float));

	*student_ptr->id = 123;
	strcpy(student_ptr->name, "David");
	*student_ptr->math_score = 96.23;
	*student_ptr->english_score = 55.34;

	printf("Student ID: %d\n", *student_ptr->id);
	printf("Student Name: %s\n", student_ptr->name);
	printf("Student Name: %.2f\n", *student_ptr->math_score);
	printf("Student Name: %.2f\n", *student_ptr->english_score);

	free(student_ptr->id);
	free(student_ptr->name);
	free(student_ptr->math_score);
	free(student_ptr->english_score);
	free(student_ptr);

	return EXIT_SUCCESS;
}
