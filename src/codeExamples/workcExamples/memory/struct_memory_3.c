#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct Student {
		int* id;
		char* name;
		float* math_score;
		float* english_score;
	};

	struct Student* student_ptr = (struct Student*)malloc(sizeof(struct Student));

	// student_ptr is a pointer so -> operatior is used
	student_ptr->id = (int *)malloc(sizeof(int));;
	student_ptr->name = (char *)calloc(20, sizeof(char));
	student_ptr->math_score = (float *)malloc(sizeof(float));
	student_ptr->english_score = (float *)malloc(sizeof(float));
	// fields are pointers, so malloc/calloc must be used.

	//*student->id - refers to field under student_ptr,
	*student_ptr->id = 111;
	strcpy(student_ptr->name, "Janice"); //student.name is already a pointer
	*student_ptr->math_score = 67.78;
	*student_ptr->english_score = 64.23;

	// NOTE - Arrow -> Operator for accessing struct field when using struct pointer
	printf("Student id: %d\n", *student_ptr->id);
	printf("Student name: %s\n", student_ptr->name);
	printf("Student math_score: %.2f\n", *student_ptr->math_score);
	printf("Student english_score: %.2f\n", *student_ptr->english_score);

	free(student_ptr->id);
	free(student_ptr->name);
	free(student_ptr->math_score);
	free(student_ptr->english_score);

	free(student_ptr);

	return EXIT_SUCCESS;
}
