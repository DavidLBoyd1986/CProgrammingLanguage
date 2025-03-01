#include <stdio.h>
#include "getint.h"

#define SIZE 10

void print_array(int array[], int len);

int main()
{
	int n, array[SIZE], getint(int *);
	printf("\nIn main before loop\n");
	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;
	printf("\nIn main after loop\n");
	int l = sizeof(array) / sizeof(array[0]);
	print_array(array, l);
}

void print_array(int array[], int len)
{
	int i = 0;
	printf("\n{");
	while (i < len-1) {
		printf("%i, ", array[i]);
		i++;
	}
	printf("%i}\n\n", array[i]);
}
