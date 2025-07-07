#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

typedef struct {
	char name[20];
	char city[10];
	int age;
	float salary;
} Employee;

int main()
{
	FILE *file_ptr = fopen("./employee_info.bin", "rb");

	if (file_ptr == NULL) {
		printf("The file could not be opened, error number: %d\n", errno);
		printf("Error opening file: %s\n", strerror(errno));
		return EXIT_FAILURE;
	} else {
		printf("The file was opened successfully! %p\n", file_ptr);
	}

	Employee employee;

	fread(&employee, sizeof(Employee), 1, file_ptr);

	fclose(file_ptr);

	printf("Name: %s\n", employee.name);
	printf("City: %s\n", employee.city);
	printf("Age: %d\n", employee.age);
	printf("Salary: %.2f\n", employee.salary);

	return EXIT_SUCCESS;
}	
