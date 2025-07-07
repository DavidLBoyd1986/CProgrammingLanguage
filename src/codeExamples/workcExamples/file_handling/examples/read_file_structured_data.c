#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
	char name[20];
	int age;
	float salary;

	FILE *file_ptr = fopen("./structured_file.txt", "r");

	if (file_ptr == NULL) {
		printf("The file could not be opened, error number: %d\n", errno);
		printf("Error opening file: %s\n", strerror(errno));
		return EXIT_FAILURE;
	} else {
		printf("The file was opened successfully! %p\n", file_ptr);
	}

	// fscanf matches patterns read in from files
	// (file pointer to read from, pattern read in, pattern_item1, item2, etc... )
	// All 'items'/variable need to be pointer types. name is a string (i.e char array)
	// 	so it is already a pointer.
	while (fscanf(file_ptr, "%s %d %f\n", name, &age, &salary) != EOF) {
		putchar('|');
		printf("%s, %d, %f\n", name, age, salary); // print buffer each loop
	}

	if (feof(file_ptr)) {
		printf("End of file reached, contents read successfully!\n");
	} else {
		printf("Something went wrong, end of file was not reached.");
	}

	fclose(file_ptr);

	return EXIT_SUCCESS;
}
