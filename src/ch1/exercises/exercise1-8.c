#include <stdio.h>

/* Count blanks, tabs, and newlines */
main()
{
	int character;
	int total;

	while ((character = getchar()) != EOF)
	{
		if (character == '\n')
			++total;
		else if (character == '\t')
			++total;
		else if (character == ' ')
			++total;
	}
	printf("%i\n", total);
}
