#include <stdio.h>
#include <stdlib.h>

void strcatpntr(char*, char*);

int main()
{
	char string_1[100] = "string_one";
	char string_2[100] = "_appended_string";
	strcatpntr(string_1, string_2);

	printf("\nstring_1 = %s\n\n", string_1);
}

void strcatpntr(char *s, char *t)
{
	int c;

	while ((*s) != '\0') {
		*s++; // Get to end of s
	}
	while ((*t) != '\0') {
		*s++ = *t++;
	}
	*s = '\0';
}
