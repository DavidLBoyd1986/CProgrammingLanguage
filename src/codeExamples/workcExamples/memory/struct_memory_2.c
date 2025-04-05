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

	struct Student student;
	//struct Student* student_ptr = (struct Student*)malloc(sizeof(struct Student));

	// student is a local variable, so . operatior is used
	student.id = (int *)malloc(sizeof(int));;
	student.name = (char *)calloc(20, sizeof(char));
	student.math_score = (float *)malloc(sizeof(float));
	student.english_score = (float *)malloc(sizeof(float));
	// fields are pointers, so malloc/calloc must be used.

	//*student.id - refers to field under student,
	// which is why * is used even though student is local variable.
	*student.id = 111;
	strcpy(student.name, "Janice"); //student.name is already a pointer
	*student.math_score = 67.78;
	*student.english_score = 64.23;

	// NOTE - Arrow -> Operator for accessing struct field when using struct pointer
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
