#include <stdlib.h>
#include <stdio.h>

int main()
{
	int *int_ptr = (int *)malloc(sizeof(int));
	float *float_ptr = (float *)malloc(sizeof(float));
	char *char_ptr = (char *)malloc(sizeof(char));
	double *double_ptr = (double *)malloc(sizeof(double));

	if (int_ptr != NULL) {
		*int_ptr = 1000;
		printf("Value referenced by int_ptr: %d \n", *int_ptr);
	}
	free(int_ptr);

	if (float_ptr != NULL) {
		*float_ptr = 234.12;
		printf("Value referenced by float_ptr: %f \n", *float_ptr);
	}
	free(float_ptr);

	if (char_ptr != NULL) {
		*char_ptr = 'm';
		printf("Value referenced by char_ptr: %c \n", *char_ptr);
	}
	free(char_ptr);

	if (double_ptr != NULL) {
		*double_ptr = 12098.23;
		printf("Value referenced by double_ptr: %lf \n", *double_ptr);
	}
	free(double_ptr);

	return EXIT_SUCCESS;
}
