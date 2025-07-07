#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
	FILE *file_ptr = fopen("./employee_details.csv", "rb");

	if (file_ptr == NULL) {
		printf("The file could not be opened, error number: %d\n", errno);
		printf("Error opening file: %s\n", strerror(errno));
		return EXIT_FAILURE;
	} else {
		printf("The file was opened successfully! %p\n", file_ptr);
	}

	char name[20];
	char city[10];
	int age;
	float salary;

	fread(name, sizeof(char), 20, file_ptr);
	fread(city, sizeof(char), 10, file_ptr);
	fread(&age, sizeof(int), 1, file_ptr);
	fread(&salary, sizeof(float), 1, file_ptr);

	fclose(file_ptr);

	printf("Name: %s\n", name);
	printf("City: %s\n", city);
	printf("Age: %d\n", age);
	printf("Salary: %.2f\n", salary);

	return EXIT_SUCCESS;
}	
