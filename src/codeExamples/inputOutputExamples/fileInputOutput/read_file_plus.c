#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
	FILE *file_ptr = fopen("./quotes_file.txt", "r+");

	if (file_ptr == NULL) {
		printf("The file could not be opened, error number: %d\n", errno);
		printf("Error opening file: %s\n", strerror(errno));
		return EXIT_FAILURE;
	} else {
		printf("The file was opened successfully! %p\n", file_ptr);
	}

	char data_buffer[1048];
	while (fgets(data_buffer, 1048, file_ptr) != NULL){
		printf("%s", data_buffer);
		fflush(stdout);
	}

	fputs("I find that the harder I work, the moreluck I seem to have."
	"\n-Thomas Jefferson\n", file_ptr);
	fputs("I never dreamed about success, I worked for it. \n-Estee Lauder\n", file_ptr);

	fclose(file_ptr);

	return EXIT_SUCCESS;
}
