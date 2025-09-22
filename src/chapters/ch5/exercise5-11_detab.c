#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000	/* The max input for Strings (Char Arrays) */
#define TABSPACES 8	/* The number of spaces that are used in a tab */
#define SPACE ' '	/* The space character */
#define TAB '\t'	/* the tab character */
#define MAX_TABSTOPS 20

int getlines(char line[], int limit);
int calculate_num_of_spaces(int column, int *tabstops, int tabstop_length);

int main(int argc, char *argv[]) {

	char line[MAXLINE];
	int tabstops[MAX_TABSTOPS];
	int default_tabstops[] = {8, 16, 24, 32, 40, 48, 56, 64};
	int tabstop_length;
	int i, j, k, column;

	/* Set up tabstops array */
	if (argc == 1) {
		/* Use default tabstops */
		for (int i = 0; i < 8; i++) {
			tabstops[i] = default_tabstops[i];
		}
		tabstop_length = 8;
	} else {
		/* Use command line arguments */
		tabstop_length = argc - 1;
		for (int i = 0; i < tabstop_length; i++) {
			tabstops[i] = atoi(argv[i+1]);
		}
	}

	while (getlines(line, MAXLINE) > 0) {
		for (i = 0, column = 1; line[i] != '\0'; i++) {
			if (line[i] == TAB) {
				/* Calculate spaces needed to reach next tabstop */
				j = calculate_num_of_spaces(column, tabstops, tabstop_length);
				for (k = 0; k < j; k++) {
					putchar(SPACE);
					column++;
				}
			} else {
				if (line[i] == '\n')
					column = 1;  /* Reset column on newline */
				else
					column++;
				putchar(line[i]);
			}
		}
	}

	return 0;
}

int getlines(char s[], int limit) {

	int i, c;

	for (i = 0; i < limit - 1 && ((c = getchar()) != EOF && c != '\n'); ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

int calculate_num_of_spaces(int column, int *tabstops, int tabstop_length) {

	int i;
	
	/* Find next tabstop at or after current column */
	for (i = 0; i < tabstop_length; i++) {
		if (tabstops[i] >= column) {
			return tabstops[i] - column + 1;
		}
	}
	
	/* If past all defined tabstops, use regular spacing */
	return TABSPACES - ((column - 1) % TABSPACES);
}

