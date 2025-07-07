#include <stdio.h>

int teststrlen(char *);

int main()
{
	char test_string[] = "this is a string";

	int len = teststrlen(test_string);
	printf("\nlen = %d\n", len);
}

/* strlen: return length of string s */
int teststrlen(char *s)
{
	char *p = s;

	while (*p != '\0')
		p++;
	return p - s;
}
