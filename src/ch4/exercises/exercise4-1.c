#include <stdio.h>
#define MAXLINE 1000	/* maximum input line length */

int getlines(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; 	/* pattern to search for */

/* find all lines matching pattern */
int main()
{
	char line[MAXLINE];
	int found = 0;

	while (getlines(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	return found;
}

/* getline: get line into s, return length */
int getlines(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
	int i, j, k, match, pos;
	match = 0;

	for (i = 0; s[i] != '\0'; i++) {
		/* k loops through the pattern, and compares it to string */
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0') { /* if '\0' reached, it's a match */
			pos = i + k; /* this returns position at the end of the match */
			match = 1;
		}
	}
	if (match) {
		printf("\nThe position is %i\n", pos);
		return pos;
	} else {
		return -1;
	}
}
