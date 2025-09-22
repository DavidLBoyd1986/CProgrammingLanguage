#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABINC 8
#define NUM_DEFAULT_TABSTOPS 5
#define MAXLINE 1000
#define TAB '\t'
#define SPACE ' '
#define TABSPACES 8
#define MAX_TABSTOPS 20

int parse_args(int, char **, int *, int *);
int getlines(char line[], int limit);
int calculate_num_of_spaces(int column, int *tabstops, int tabstop_length);

int main(int argc, char *argv[]) {

	int nb = 0;		/* num of blanks */
	int nt = 0;		/* num of tabs	 */
	int m = 1;
	int n = 8;
	int tabstop_length;
	int tabstops[MAX_TABSTOPS];
	int i, j, k, column;
	char line[MAXLINE];

	// set m and n from supplied arguments
	if (argc > 1 ) {
		if (parse_args(argc, argv, &m, &n) < 0) {
			printf("Error in 'parse_args");
			return -1;
		}
	}

	// Loop through the input
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
					column = 1; /* Reset column on newline) */
				else
					column++;
				putchar(line[i]);
			}
		}
	}
	return 0;
}

int parse_args(int count, char **arg_list, int *m, int *n)
{
	int error = 0;

	while (count > 1) {
		arg_list++;
		if (strcmp(*arg_list, "-m") == 0) {
			if ((*m = atoi(*++arg_list)) < 1) {
				error = 1;
				break;
			}
		} else if (strcmp(*arg_list, "+n") == 0) {
			if ((*n = atoi(*++arg_list)) < 1) {
				error = 1;
				break;
			}
		} else {
			printf("Usage: entab [-m pos] [+n pos]\n");
			return -1;
		}
		count = count - 2; // Arglist moved 2, so deprecate count by 2
	}
	if (error > 0) {
		printf("Invalid position\n");
		return -1;
	}
	return 1;
}

int getlines(char s[], int limit)
{
	int i, c;

	for (i = 0; i < limit - 1 && ((c = getchar()) != EOF && c != '\n'); ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

int calculate_num_of_spaces(int column, int *tabstops, int tabstop_length)
{
	int i;

	/* find next tabsop at or after current column */
	for (i = 0; i < tabstop_length; i++) {
		if (tabstops[i] >= column) {
			return tabstops[i] - column + 1;
		}
	}

	/* If past all defined tabstops, use regular spacing */
	return TABSPACES - ((column -1) % TABSPACES);
}
