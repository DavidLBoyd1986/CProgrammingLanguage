#include <stdio.h>

/* replace many blanks with one blank */
main()
{
	int character;
	int skipBlanks;
	skipBlanks = 0;

	while ((character = getchar()) != EOF)
	{
		if (character == '\t')
			character = ' ';
		if (character == ' ')
		{
			if (skipBlanks == 0)
				putchar(character);
				skipBlanks = 1;

		}
		if (character != ' ')
		{
			if (skipBlanks == 1)
			{
				putchar(character);
				skipBlanks = 0;
			} else {
				putchar(character);
			}

		}
	}
}
