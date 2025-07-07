#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct Student {
		char name[20];
		int age;
	};

	struct Student *student_ptr;

	strcpy(student_ptr->name, "David");
	student_ptr->age = 38;

	printf("\nStudent name = %s\n", student_ptr->name);
	printf("Student age = %i\n\n", student_ptr->age);

	return EXIT_SUCCESS;
}
