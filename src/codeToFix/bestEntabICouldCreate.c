#include <stdio.h>

#define MAXLINE 1000	/* The max input for Strings (Char Arrays) */
#define TABSPACES 8	/* The number of spaces that are used in a tab */
#define SPACE ' '	/* The space character */
#define TAB '\t'	/* the tab character */


int getlines(char line[], int limit);
int calculate_num_of_spaces(int offset, int tab_size);

int main(void) {

	char line[MAXLINE];
	int i, s, t, a, e, h;

	e =  1;

	while (getlines(line, MAXLINE) > 0){
		for (i = 0, s = 0, t = 0; line[i] != '\0'; i++){
			
			a = 0; /* tracks if spaces were added, if so add an extra space before adding char so position is accurate */

			 /* Track spaces, and add them back in when you get enough for tab, or a non-space character appears */
			if (line[i] == SPACE){
			 	++s;
				/* If spaces tracked = 8, add a tab, and reset spaces tracked to 0 */
				if (s == 8){
					++t;
					s = 0;
				}
			} else if (line[i] == TAB){
				++t;
			} else {
				if (t > 0)
					a = 1;
				while (t > 0){
					putchar(TAB);
					--t;
				}
				while (s > 0){
					putchar(SPACE);
					--s;
				}
				if (a == 1){
					putchar(SPACE);
				}
				putchar(line[i]);
				
			}
		}
	}
	return 0;
}


int getlines(char s[], int limit)
{
	int i, c;

	for (i = 0; i < limit - 1 && ((c = getchar()) != EOF && c != '\n'); ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

int calculate_num_of_spaces(int offset, int tab_size)
{
	return tab_size - (offset % tab_size); 
}

