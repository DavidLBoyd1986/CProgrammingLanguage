#include <stdio.h>

#define MAXLINE 1000	/* The max input for Strings (Char Arrays) */
#define TABSPACES 6	/* The number of spaces that are used in a tab */


int getlines(char line[], int limit);
void detab(char line[], int index);

main(){

	int len;
	char line[MAXLINE];

	while ((len = getlines(line, MAXLINE)) > 0){
		printf("%d\n", len);
		printf("%s\n", line);
	}
}

int getlines(char s[], int limit)
{
	int i, c;

	for (i = 0; i < limit -1 && ((c = getchar()) != EOF && c != '\n'); ++i){
		if (c == '\t'){
			detab(s, i);
			i = i + TABSPACES;
		} else {
			s[i] = c;
		}
	}
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void detab(char s[], int index)
{
	int t = index;
	for (t; t < index + TABSPACES; ++t) {
		s[t] = ' ';
	}
}
