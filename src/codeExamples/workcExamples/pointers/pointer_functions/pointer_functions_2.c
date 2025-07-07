#include <stdlib.h>
#include <stdio.h>

void swap(char *, char *);

int main()
{
	char first_char = 'X';
	char second_char = 'Q';

	printf("BEFORE swap first_char: %.c and second_char: %c \n",
		first_char, second_char);

	swap(&first_char, &second_char); // Pass in address

	printf("AFTER swap first_char: %.c and second_char: %c \n",
		first_char, second_char);

	return EXIT_SUCCESS;
}

void swap(char *char_ptr_1, char *char_ptr_2)
{
	char temp;

	temp = *char_ptr_1;
	*char_ptr_1 = *char_ptr_2;
	*char_ptr_2 = temp;
}
