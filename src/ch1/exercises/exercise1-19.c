#include <stdio.h>

#define MAXLINE 1000		/* Max Characters in the line */

int getlines(char line[], int lim);
void reverse(char s[], char r[], int e);

main()
{

int len;
char line[MAXLINE];
char reverse_line[MAXLINE];

	while ((len = getlines(line, MAXLINE)) > 0){
		reverse(line, reverse_line, len);
		printf("%s\n", reverse_line);
	}
}

int getlines(char s[], int lim){

	int i, c;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
		s[i] = c;
	}
	if (c == '\n'){
		s[i] = '\n';
		++i;
	}
	s[i] = '\0';
	return i;
}

void reverse(char s[], char r[], int b){
	int i;
	int f = 0;
	printf("%d\n", b);
	for (i = b-1; i >= 0; --i){
		r[f] = s[i];
	        ++f;	
	}
	r[f] = '\n';
	++f;
	r[f] = '\0';
}
