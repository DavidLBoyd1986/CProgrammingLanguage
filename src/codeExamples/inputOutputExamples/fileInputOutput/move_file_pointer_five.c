#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
	FILE *file_ptr = fopen("./quotes_file.txt", "r");

	if (file_ptr == NULL) {
		printf("The file could not be opened, error number: %d\n", errno);
		printf("Error opening file: %s\n", strerror(errno));
		return EXIT_FAILURE;
	} else {
		printf("The file was opened successfully! %p\n", file_ptr);
	}

	char data_buffer[1048];

	printf("Start position of file_ptr: %ld\n", ftell(file_ptr));

	fgets(data_buffer, 1048, file_ptr);
	printf("%s", data_buffer);

	printf("Current Position of file_ptr: %ld\n", ftell(file_ptr));

	printf("Seeking offset 0 from start...\n");
	rewind(file_ptr);

	printf("Back to start position of file_ptr: %ld\n", ftell(file_ptr));
	printf("%s" , data_buffer);

	fclose(file_ptr);

	return EXIT_SUCCESS;
}
