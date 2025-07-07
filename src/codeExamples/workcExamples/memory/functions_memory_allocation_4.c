#include <stdlib.h>
#include <stdio.h>

int main()
{
	char *ptr;

	// Inner Scope with local variables
	{
		char name[10] = "Alice";
		ptr = name;
	}
	// The above is rarely used, but loops have same inner scope,
	// really anything with {} have an inner scope.

	ptr = NULL; // This is the fix to the Security Risk below;

	printf("(Security risk, accessing dellocated memory!) Name: %s\n", ptr);

	return EXIT_SUCCESS;
}
