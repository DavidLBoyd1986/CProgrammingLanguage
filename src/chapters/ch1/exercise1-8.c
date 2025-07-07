#include <stdio.h>

/* Count blanks, tabs, and newlines */
int main()
{
	int character;
	int total = 0;
	int newlines = 0;
	int tabs = 0;
	int spaces = 0;

	while ((character = getchar()) != EOF) {

		if (character == '\n') {
			++total;
			++newlines;
		} else if (character == '\t') {
			++total;
			++tabs;
		} else if (character == ' ') {
			++total;
			++spaces;
		}
	}
	printf("\nNewlines = %i\n", newlines);
	printf("Tabs = %i\n", tabs);
	printf("Spaces = %i\n", spaces);
	printf("Total = %i\n", total);

	return 0;
}
