#include <stdio.h>
#include "getint_pointer.h"

#define SIZE 100

int getint (int *pn);

int main()
{
	int n, array[SIZE], getint(int *);

	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;
}


