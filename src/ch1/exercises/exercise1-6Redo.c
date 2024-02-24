#include <stdio.h>

/* retrying to print EOF without cheating */
main()
{

	int c;
	char value;
	value = ((c = getchar()) != EOF);
	printf("%i\n", EOF);
	return 0;
}
