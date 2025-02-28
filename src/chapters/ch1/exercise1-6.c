#include <stdio.h>

/* test if 'getchar() != EOF' is 0 or 1' */
int main()
{
	int c;
	char value;
	value = ((c = getchar()) != EOF);
	printf("%i\n", value);
	return 0;
}
