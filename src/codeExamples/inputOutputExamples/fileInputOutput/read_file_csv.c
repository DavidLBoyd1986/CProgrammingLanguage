#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
	char id[15];
	char name[20];
	char department[15];
	int age;

	FILE *file_ptr = fopen("./employee_details.csv", "r");

	if (file_ptr == NULL) {
		printf("The file could not be opened, error number: %d\n", errno);
		printf("Error opening file: %s\n", strerror(errno));
		return EXIT_FAILURE;
	} else {
		printf("The file was opened successfully! %p\n", file_ptr);
	}

	// Read all the characters until the first \n character
	// %* - reads every character
	// [^\n] - makes an exception not to read the newline character
	// \n - reads until it reads the newline character.
	fscanf(file_ptr, "%*[^\n]\n");
	// fscanf matches patterns read in from files
	// (file pointer to read from, pattern read in, pattern_item1, item2, etc... )

	// %[^,] - read every character other than a comma
	// , - skip comma
	// repeat over and over
	while (fscanf(file_ptr, "%[^,],%[^,],%[^,],%d\n", id, name, department, &age) != EOF) {
		putchar('|');
		printf("%s, %s, %s, %d\n", id, name, department, age);
	}

	if (feof(file_ptr)) {
		printf("End of file reached, contents read successfully!\n");
	} else {
		printf("Something went wrong, end of file was not reached.");
	}

	fclose(file_ptr);

	return EXIT_SUCCESS;
}
