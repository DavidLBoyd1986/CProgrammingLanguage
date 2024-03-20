#include <stdio.h>

#define MAXLINE 1000		/* Max Characters in the line */

int getlines(char line[], int lim);
void reverse(char s[], char r[], int e);

main()
{
/* Reverse inputted lines and prints them out. */

int len;
char line[MAXLINE];
char reverse_line[MAXLINE];

	while ((len = getlines(line, MAXLINE)) > 0){
		reverse(line, reverse_line, len);
		printf("%s\n", reverse_line);
	}
}

int getlines(char s[], int lim){
	/*Standard function to get input lines
	 * It gets input until (MAXLINE is reached || (input char == EOF || inputchar == '\n')) */
	int i, c;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
		s[i] = c;
	}
	/* If reached end of line '\n', add '\n' and increment i to add '\0' next */
	if (c == '\n'){
		s[i] = '\n';
		++i;
	}
	s[i] = '\0';
	return i;
}

void reverse(char s[], char r[], int b){
	/* Reverse the input string by saving the chars in reverse order in another string */
	int i;
	int f = 0;
	for (i = b-1; i >= 0; --i){
		r[f] = s[i];
	        ++f;	
	}
	r[f] = '\n';
	++f;
	r[f] = '\0';
}
