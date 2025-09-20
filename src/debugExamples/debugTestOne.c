#include <stdio.h>
#include <stdlib.h>

int add(int, int);

int main()
{
	int int_one = 1;
	char char_one = 'a';
	int int_two;
	char char_two;
	int int_three = 3;
	char char_three = 3;
	int result;

	printf("int_one = %i\n", int_one);
	printf("char_one = %c\n", char_one);

	result = add(int_one, int_three);
	printf("result = %i\n", result);
}


int add(int a, int b)
{
	int result = a + b;

	return result;
}
