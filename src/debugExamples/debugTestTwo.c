#include <stdio.h>
#include <stdlib.h>

int add(int, int);

int main(int argc, char *argv[])
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

	printf("argc = %i\n", argc);
	printf("*argv = %s\n", *argv);
	printf("*argv + 1 = %s\n", *++argv);
	printf("*argv + 2 = %s\n", *++argv);
}


int add(int a, int b)
{
	int result = a + b;

	result = 4;
	result = 9;
	result = a + b;
	return result;
}
