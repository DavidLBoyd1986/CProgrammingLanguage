#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
	FILE *file_ptr = fopen("./quotes_file.txt", "w");

	if (file_ptr == NULL) {
		printf("The file could not be opened, error number: %d\n", errno);
		printf("Error opening file: %s\n", strerror(errno));
		return EXIT_FAILURE;
	} else {
		printf("The file was opened successfully! %p\n", file_ptr);
	}

	// int return type so we can check if EOF is returned
	char quote[] = "Life is a long lesson in humility. \n -James M. Barrie\n";

	// loop through quote string until reach end of string
	for (int i = 0; quote[i] != '\0'; i++) {
		fputc(quote[i], file_ptr); // put string char into file
		//fputc automatically increments the file_ptr
	}

	fclose(file_ptr);

	return EXIT_SUCCESS;
}
