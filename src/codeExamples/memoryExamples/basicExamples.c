#include <stdio.h>
#include <stdlib.h>

void print_int_array(int *, int);
void print_float_array(float *, int);

int main()
{
	// Allocate heap memory for a variable of a specific type
	int *test_int = (int *)malloc(sizeof(int));
	float *test_float = (float *)malloc(sizeof(float));
	char *test_char = (char *)malloc(sizeof(char));

	*test_int = 5;
	*test_float = 99.32153;
	*test_char = 'H';

	printf("\n*test_int Address = %p\n", test_int);
	printf("*test_int Value = %d\n", *test_int);
	printf("\n*test_float Address = %p\n", test_float);
	printf("*test_float Value = %.3f\n", *test_float);
	printf("\n*test_char Address = %p\n", test_char);
	printf("*test_char Value = %c\n", *test_char);

	// Allocate heap memory for an array of a specific type
	int *int_array = (int *)malloc(5 * sizeof(int));
	float *float_array = (float *)malloc(10 * sizeof(float));
	char *char_array = (char *)malloc(70 * sizeof(char));

	int temp_num = 58;
	float temp_float = 7.12;
	char temp_char = 62;

	// Add data to int array
	for (int i = 0; i < 5; i++) {
		*(int_array + i) = temp_num;
		temp_num += 59;
	}
	printf("\nint_array:");
	print_int_array(int_array, 5);

	// Add data to float array
	for (int i = 0; i < 10; i++) {
		float_array[i] = temp_float;
		temp_float += 7.73;
	}
	printf("\nfloat_array:");
	print_float_array(float_array, 10);

	// Add data to char array
	for (int i = 0; i < 70; i++) {
		char_array[i] = temp_char;
		temp_char += 1;
	}
	char_array[70] = '\0';
	printf("\nchar_array:");
	printf("\nchar_array = %s\n", char_array);
}

void print_int_array(int *int_ptr, int len)
{
	printf("\n[");
	for (int i = 0; i < len - 1; i++) {
		printf("%d, ", *(int_ptr + i));
	}
	printf("%d]\n", *(int_ptr + (len - 1)));
}

void print_float_array(float *float_ptr, int len)
{
	printf("\n[");
	for (int i = 0; i < len - 1; i++) {
		printf("%.3f, ", *(float_ptr + i));
	}
	printf("%.3f]\n", *(float_ptr + (len - 1)));
}
