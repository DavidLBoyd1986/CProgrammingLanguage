#include <stdio.h>

int lower(int c);

int main()
{
	char testString[100] = "A StRiNG WItH somE CapITaL LeTTErS";
	printf("\ntestString = %s\n", testString);

	char resultString[100];

	for (int i = 0; testString[i] != '\0'; i++) {
		resultString[i] = lower(testString[i]);
	}
	printf("\nresultString = %s\n\n", resultString);
}

int lower(int c)
{
	// Could have both on one line with return, but I think this is easier to read.
	int lower_c = (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
	return lower_c;
}

int lower_original(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}
