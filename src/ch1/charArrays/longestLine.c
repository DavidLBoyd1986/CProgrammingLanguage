#include <stdio.h>
# define MAXLINE 1000	/* maximum input line size */

int getlines(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
main()
{
	int len;	/* current line length */
	int max;	/* maximum lenth seen so far */
	char line[MAXLINE];	/* current input line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	while ((len = getlines(line, MAXLINE)) > 0){
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)	/* there was a line */
		printf("%s", longest);
	return 0;
}

/* getline: read a line into s, return length */
int getlines(char s[], int lim)
{
	int c, i;

	/* This is just to test the next character is valid to accept: not past limit, not EOF, and not newline. */
	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	/* Does not return s line created because arrays are global and so it does not need returned */
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;	
}
