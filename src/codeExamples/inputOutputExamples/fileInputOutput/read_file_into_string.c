#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
	FILE *file_ptr = fopen("./existing_file.txt", "r");
	char data_buffer[1048];

	if (file_ptr == NULL) {
		printf("The file could not be opened, error number: %d\n", errno);
		printf("Error opening file: %s\n", strerror(errno));
		return EXIT_FAILURE;
	} else {
		printf("The file was opened successfully! %p\n", file_ptr);
	}

	// fgets reads strings from files
	// 	- (buffer, size of buffer, file pointer to read from)
	while (fgets(data_buffer, 1048, file_ptr) != NULL) {
		// Note: This is to show that we read the file line by line
		// The '|' should be printed before every string we read in
		putchar('|');
		printf("%s", data_buffer); // print buffer each loop

		//outputs the in-memory buffer to stdout (output stream) 
		fflush(stdout);
		//It's a good idea to continualy flush the data manually like this
	}

	// file_ptr represents a stream, as well as having metadata about a file.
	// The stream is a stream marker that indicates where the file pointer is
	// located in the current file (stream of data).
	// When file_ptr reaches end of the stream, the 'feof' flag is set.
	// feof below returns true or false if 'feof' flag is set.
	// i.e. it is telling you if end of the file is reached.
	if (feof(file_ptr)) {
		printf("End of file reached, contents read successfully!\n");
	} else {
		printf("Something went wrong, end of file was not reached.");
	}

	fclose(file_ptr);

	return EXIT_SUCCESS;
}
