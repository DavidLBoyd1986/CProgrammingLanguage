#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
	FILE *file_ptr = fopen("./employee_details.csv", "w");

	if (file_ptr == NULL) {
		printf("The file could not be opened, error number: %d\n", errno);
		printf("Error opening file: %s\n", strerror(errno));
		return EXIT_FAILURE;
	} else {
		printf("The file was opened successfully! %p\n", file_ptr);
	}

	const int num_records = 3;

	char name[num_records][15];
	char department[num_records][15];
	char id[num_records][15];
	strcpy(name[0], "Alvin Johnson");
	strcpy(name[1], "Deola Vas");
	strcpy(name[2], "Kevin Wilson");
	strcpy(department[0],"Production");
	strcpy(department[1], "Sales");
	strcpy(department[2], "Marketing");
	strcpy(id[0], "EPRO2109");
	strcpy(id[1], "ESAL1901");
	strcpy(id[2], "EMAR1721");
	int age[] = {25, 31, 29};

	fprintf(file_ptr, "ID, Name, Department, Age\n");

	for(int i = 0; i < num_records; i++) {
		//fprintf(file_ptr,"%s, %d\n", name[i], age[i]);
		fprintf(file_ptr,"%s, %s, %s, %d\n", id[i], name[i], department[i], age[i]);
	}

	fclose(file_ptr);

	return EXIT_SUCCESS;
}
