#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *emp_salary_ptr = (int *)malloc(5 * sizeof(int));

	if (emp_salary_ptr == NULL) {
		printf("Memory not allocated! \n");
		return EXIT_FAILURE;
	}

	emp_salary_ptr[0] = 120000;
	emp_salary_ptr[1] = 100000;
	emp_salary_ptr[2] = 95000;
	emp_salary_ptr[3] = 56000;
	emp_salary_ptr[4] = 44000;

	printf("ADDRESS \t VALUE \n");
	for (int i = 0; i < 5; i++) {
		printf("%p \t %d \n", &emp_salary_ptr[i], emp_salary_ptr[i]);
	}

	free(emp_salary_ptr);
	return EXIT_SUCCESS;
}
