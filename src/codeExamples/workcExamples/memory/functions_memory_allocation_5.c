#include <stdlib.h>
#include <stdio.h>

// The caller of the function is responsible for freeing the memory of the returned pointer
void print_lap_times(float* float_ptr, int length)
{
	printf("ADDRESS \t VALUE \n");
	for (int i = 0; i < length; i++) {
		printf("%p \t %.2f \n", &float_ptr[i], float_ptr[i]);
	}

}

int main()
{
	float *lap_times_ptr = (float *)malloc(3 * sizeof(float));
	float *cpy_ptr = lap_times_ptr;

	if (lap_times_ptr == NULL) {
		printf("Memory not allocated! \n");
		return EXIT_FAILURE;
	}

	lap_times_ptr[0] = 12.2;
	lap_times_ptr[1] = 10.3;
	lap_times_ptr[2] = 13.3;

	print_lap_times(lap_times_ptr, 3);
	print_lap_times(cpy_ptr, 3);

	//free(lap_times_ptr); // Not including this would be a memory leak
	//free(cpy_ptr); // Freeing pointer twice causes crash - cpy_ptr is a copy of lap_times_ptr

	return EXIT_SUCCESS;
}
