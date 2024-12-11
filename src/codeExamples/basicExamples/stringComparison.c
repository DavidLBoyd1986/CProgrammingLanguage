#include <stdio.h>
#include <string.h>

#define MAXOP 100

int main()
{
	/* When declaring strings, declare them to be empty!! */
	char emptyString[MAXOP] = {};
	char testString[MAXOP] = {'t','e','s','t'};

	/* == and != don't work for comparing strings */
		// For strings (== and !=) compare addresses
	printf("\n testString = %s\n", testString);
	if (testString == "test")
		printf("\nStrings matched\n");
	else
		printf("\nStrings did NOT match\n");

	/* strcmp returns 0 (int 0) if the strings match */
		// Which is dumb since true is a value >= 1 and 0 is false
	int result = strcmp(testString, "test");

	printf("\nresult = %i\n", result);
	if (result == 0)
		printf("\nStrings matched\n");
	else if (result != 0)
		printf("\nStrings did NOT match\n");
	else
		printf("\nError - error\n");

	int result_two = strcmp(testString, "fest");

	printf("\nresult_two = %i\n", result_two);
	if (result_two == 0)
		printf("\nStrings matched\n");
	else if (result_two != 0)
		printf("\nStrings did NOT match\n");
	else
		printf("\nError - error\n");

	return 0;

}
