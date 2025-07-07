#include <stdio.h>
#include <stdlib.h>

void print_array(int*, int length);

int main()
{
	int num = 123;
	int *num_ptr = &num;

	printf("\nnum = %p\n", &num);
	printf("num_ptr = %p\n", num_ptr);

	printf("\nnum = %i\n", num);
	printf("num_ptr = %i\n", *num_ptr);

	int num_array[] = {0,1,2,3,4,5,6,7,8,9};
	size_t array_length = sizeof(num_array) / sizeof(num_array[0]);

	printf("\nnum_array[1] = %i\n", num_array[1]);

	printf("\nAll of the below uses %%p for prints\n");
	printf("num_array = %p\n", num_array);
	printf("&num_array = %p\n", &num_array);
	printf("\nnum_array[0] = %p\n", num_array[0]);
	printf("&num_array[0] = %p\n", &num_array[0]);

	printf("\nAll of the below uses %%i for prints\n");
	printf("\nnum_array[1] = %i\n", num_array[1]);
	printf("*&num_array[1] = %i\n", *&num_array[1]);
	printf("*(num_array + 1) = %i\n", *(num_array + 1));

	printf("\nImportant difference between pointers and arrays:\n");
	printf("Arrays aren't variables, so you can't assign a new value to it\n");
	printf("	Invalid - num_array = num\n");
	printf("Arrays can't be incremented\n");
	printf("	Invalid - num_array++\n");
	printf("Both of the above works for pointers because they are variables");

	printf("\nArray length = %i\n", array_length);
	//TODO - Passing pointers and arrays into functions.
	print_array(num_array, array_length);
	print_array(num_array + 2, array_length - 2);
	print_array(&num_array[0], array_length - 5);
}

void print_array(int *arr_ptr, int length)
{
	printf("\n");
	for (int i = 0; i < length; i++, arr_ptr++) {
		printf("Address = %p,\t Value = %i\n",
			arr_ptr, *arr_ptr);
	}
}
