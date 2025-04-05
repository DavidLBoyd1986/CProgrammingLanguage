#include <stdio.h>
#include <stdlib.h>

void print_array(char *, int);

int main()
{
	char char_array[] = {'A', 'B', 'C', 'D', 'E'};

	print_array(char_array, 5); //Pass in actual array

	return EXIT_SUCCESS;
}

// Where array is passed in, the function uses a *char (char pointer)
void print_array(char *char_ptr, int length)
{
	printf("ADDRESS \t VALUE \n");
	for (int i= 0; i < length; i++) {
		printf("%p \t %c \n", char_ptr + i, *(char_ptr +i));
	}
}

// Important - size of array can only be calculated in scope it was created in.
// i.e. - when an array has been passed into a function,
// it's size can NOT be determined inside the function.
