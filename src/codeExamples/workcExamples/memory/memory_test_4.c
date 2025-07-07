#include <stdio.h>
#include <stdlib.h>

void print_array(int* emp_salary_ptr, int length)
{
	printf("ADDRESS \t VALUE \n");
	for (int i = 0; i < length; i++) {
		printf("%p \t %d \n", &emp_salary_ptr[i], emp_salary_ptr[i]);
	}
}

int main()
{
	// calloc has 2 arguments: # of elements, size of elements
	// it is better to use instead of malloc for arrays
	// calloc - returns zeroed out memory as well. So no, dangling pointers.
	// this zeroed out memory causes calloc to be slower than malloc.

	int *emp_salary_ptr = (int *)calloc(3, sizeof(int));

	if (emp_salary_ptr == NULL) {
		printf("Memory not allocated! \n");
		return EXIT_FAILURE;
	}

	emp_salary_ptr[0] = 120000;
	emp_salary_ptr[1] = 100000;
	emp_salary_ptr[2] = 95000;

	print_array(emp_salary_ptr, 3);

	emp_salary_ptr = (int *)realloc(emp_salary_ptr, 5 * sizeof(int));

	if (emp_salary_ptr == NULL) {
		printf("Memory not allocated! \n");
		return EXIT_FAILURE;
	}

	print_array(emp_salary_ptr, 5);

	free(emp_salary_ptr);

	return EXIT_SUCCESS;
}
