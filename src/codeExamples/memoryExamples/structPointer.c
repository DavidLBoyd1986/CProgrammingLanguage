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

//	struct Student* struct_ptr = (struct Student*)malloc(sizeof(struct Student));

//	strcpy(struct_ptr->name, "Nolan");
//	struct_ptr->age = 8;

//	printf("\nStudent name = %s\n", struct_ptr->name);
//	printf("Student age = %i\n\n", struct_ptr->age);

	return EXIT_SUCCESS;
}
