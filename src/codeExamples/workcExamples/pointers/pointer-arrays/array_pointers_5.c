#include <stdlib.h>
#include <stdio.h>

int main()
{
	int arr[10] = {1,56,23,89,44,-11};
	int *arr_ptr = arr;

	printf("Address of arr: %p\n", arr);
	printf("Address of arr_ptr: %p\n", arr_ptr);
	printf("Address of &arr[0]: %p\n", &arr[0]);
	printf("Address of &arr_ptr[0]: %p\n", &arr_ptr[0]);
}
