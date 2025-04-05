#include <stdio.h>
#include <stdlib.h>

int main()
{
	// calloc has 2 arguments: # of elements, size of elements
	// it is better to use instead of malloc for arrays
	// calloc - returns zeroed out memory as well. So no, dangling pointers.
	// this zeroed out memory causes calloc to be slower than malloc.

	int *emp_salary_ptr = (int *)calloc(1, sizeof(int));

	*emp_salary_ptr = 30000;

	printf("Salary of only employee: %d\n", *emp_salary_ptr);

	free(emp_salary_ptr);
	return EXIT_SUCCESS;
}
