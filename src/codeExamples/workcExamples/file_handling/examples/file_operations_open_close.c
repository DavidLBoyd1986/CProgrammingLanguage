#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
	//FILE* file_ptr = fopen("./existing_file.txt", "r");
	FILE* file_ptr = fopen("./non_existing_file.txt", "r"); //Wrong file

	if (file_ptr == NULL) {
		printf("The file could not be opened, error number: %d\n", errno);
		printf("Error opening file: %s\n", strerror(errno));
		return EXIT_FAILURE;
	} else {
		printf("The file was opened successfully! %p\n", file_ptr);
	}

	fclose(file_ptr);

	return EXIT_SUCCESS;
}
