#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct Student {
		char name[20];
		int age;
	};

	struct Student david;

	strcpy(david.name, "David");
	david.age = 38;

	printf("\nStudent name = %s\n", david.name);
	printf("Student age = %i\n\n", david.age);

	return EXIT_SUCCESS;
}
