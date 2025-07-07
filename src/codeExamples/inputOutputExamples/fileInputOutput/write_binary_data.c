#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
	FILE *file_ptr = fopen("./employee_details.csv", "wb");

	if (file_ptr == NULL) {
		printf("The file could not be opened, error number: %d\n", errno);
		printf("Error opening file: %s\n", strerror(errno));
		return EXIT_FAILURE;
	} else {
		printf("The file was opened successfully! %p\n", file_ptr);
	}

	char name[20] = "James Darwin";
	char city[10] = "Seattle";
	int age = 29;
	float salary = 123000.34;

	fwrite(name, sizeof(char), 20, file_ptr);
	fwrite(city, sizeof(char), 10, file_ptr);
	fwrite(&age, sizeof(int), 1, file_ptr);
	fwrite(&salary, sizeof(float), 1, file_ptr);

	fclose(file_ptr);

	return EXIT_SUCCESS;
}	
