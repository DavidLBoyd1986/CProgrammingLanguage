#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct Student {
		int id;
		char name[20];
		float math_score;
		float english_score;
	};

	struct Student student;
	struct Student* student_ptr = &student;

	student.id = 111;
	strcpy(student.name, "Janice");
	student.math_score = 67.78;
	student.english_score = 64.23;

	// NOTE - Arrow -> Operator for accessing struct field when using struct pointer
	printf("Student id: %d\n", student_ptr->id);
	printf("Student name: %s\n", student_ptr->name);
	printf("Student math_score: %.2f\n", student_ptr->math_score);
	printf("Student english_score: %.2f\n", student_ptr->english_score);

	return EXIT_SUCCESS;
}
