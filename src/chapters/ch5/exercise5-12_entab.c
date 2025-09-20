#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABINC 8
#define NUM_DEFAULT_TABSTOPS 5

int parse_args(int, char **, int *, int *);

int main(int argc, char *argv[]) {

	int nb, nt, pos, c;
	nb = 0;		/* num of blanks */
	nt = 0;		/* num of tabs	 */
	int m = 4;
	int n = 1;

	// set m and n from supplied arguments
	if (argc > 1 ) {
		if (parse_args(argc, argv, &m, &n) < 0) {
			printf("Error in 'parse_args");
			return -1;
		}
	}

	// Loop through the input
	for (pos = 1; (c = getchar()) != EOF; ++pos) {
		
		if (c == ' ') {
			if ((pos % TABINC) != 0) {
				++nb;
		// TODO - If pos % TABINC == 0 and nb == m
			} else { 
				++nt;
				nb = 0;
			}
		} else {
			while (nt > 0) {
				--nt;
				putchar('\t');
			}
			if (c == '\t') {
				nb = 0;
			} else {
				while (nb > 0) {
					--nb;
					putchar(' ');
				}
			}
			putchar(c);
			/* End of line, reset position.
			 * If character was a tab, do magic formula for resetting position */
			if (c == '\n') {
				pos = 0;
			} else if (c == '\t') {
				pos = pos + (TABINC - (pos - 1) % TABINC) - 1;
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

