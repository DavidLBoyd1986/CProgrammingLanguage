#include <stdio.h>
#include <stdlib.h>

void print_array(int *, int);
void square_numbers(int *, int);

int main()
{
	int int_array[] = {1, 2, 3, 4};

	print_array(int_array, 4); //Pass in actual array

	square_numbers(int_array, 4);

	print_array(int_array, 4); //Pass in actual array

	return EXIT_SUCCESS;
}

// Where array is passed in, the function uses a *char (char pointer)
void print_array(int *int_ptr, int length)
{
	printf("ADDRESS \t VALUE \n");
	for (int i= 0; i < length; i++) {
		printf("%p \t %i \n", int_ptr + i, *(int_ptr +i));
	}
}

void square_numbers(int *int_ptr, int length)
{
	// i is only for tracking loop,
	// int_ptr is incremented to move pointer forward in array
	for (int i= 0; i < length; i++, int_ptr++) {
		*int_ptr = (*int_ptr) * (*int_ptr); //Parenthesis are style only, NOT syntactically required.
	}
}

// Important - size of array can only be calculated in scope it was created in.
// i.e. - when an array has been passed into a function,
// it's size can NOT be determined inside the function.
