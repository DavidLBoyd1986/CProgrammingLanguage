#include <stdio.h>
# define MAXLINE 1000		/* MAX size of Char Arrays */
# define ENDBLANKS 1		/* Line has not seen a non-white space character */
# define NOTENDBLANKS 0		/* Line has seen a non-white space character */

int get_lines(char line[], int limit);
void remove_trailing_white_space(char line[], int i);

main()
{
	char line[MAXLINE];
	int len;
	while ((len = get_lines(line, MAXLINE)) > 0){
		printf("%s\n", line);
		printf("%d\n", len);
	}

}

int get_lines(char s[], int lim){
	int end_blanks = NOTENDBLANKS;
	int i, c, e;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
		s[i] = c;
		if (c == ' ' || c == '\t'){
			if (end_blanks == NOTENDBLANKS) {
				e = i;
			}
			end_blanks = ENDBLANKS;
		} else {
			end_blanks = NOTENDBLANKS;
		}
	}
	if (end_blanks == ENDBLANKS){	
	remove_trailing_white_space(s, e);
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	if (end_blanks == ENDBLANKS){
		return e;
	} else if (end_blanks == NOTENDBLANKS){
		return i;
	}
}

void remove_trailing_white_space(char s[], int e){
	if (e == 0){
		s[e] = '\n';
	} else {
		s[e] = '\0';
	}
}
