#include <stdio.h>

#define MAXLINE 1000	/* The max input for Strings (Char Arrays) */
#define TABSPACES 8	/* The number of spaces that are used in a tab */
#define SPACE ' '	/* The space character */
#define TAB '\t'	/* the tab character */

int getlines(char line[], int limit);
int calculate_num_of_spaces(int offset, int tab_size);

int main(void){

	char line[MAXLINE];
	int i, j, k, l, s;

	while (getlines(line, MAXLINE) > 0){
		for (i = 0, l = 0, s = 0; line[i] != '\0'; i++){
			/* Delete spaces that pop up
			 * Track spaces, and add them back in when a non-space character appears
			 * If spaces tracked = 8, add a tab, and reset spaces tracked to 0 */
			if (s == 8){
				putchar(TAB);
				s = 0;
			} else if (line[i] == SPACE){
				++s;
			}
			else if (line[i] == TAB){
				putchar(TAB);
				/*
				j = calculate_num_of_spaces(l, TABSPACES);
				for(k = 0; k < j; k++){
					putchar(SPACE);
					l++; 
				}
				*/
			} else {
				while (s >= 0){
					putchar(SPACE);
				}
				s = 0;
				putchar(line[i]);
				/* l++; increase offset, why is offset required? */
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
