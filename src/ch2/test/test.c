#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int lower(int c);

int main() {

	char string[40] = "HELLO WORLD";
	char stringOutput[40];
	int i = 0;
	int c = string[0];
	printf("\nc = %c\n", c);
	c = lower(c);
	printf("\nc = %c\n", c);
	stringOutput[i] = c;
	i++;		
	printf("\n%s\n", stringOutput);
}

int lower(int c) {

	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

