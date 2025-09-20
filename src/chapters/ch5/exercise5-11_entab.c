#include <stdio.h>
#include <stdlib.h>

#define TABINC 8
#define NUM_DEFAULT_TABSTOPS 5

int main(int argc, char *argv[]) {

	int nb, nt, pos, c;
	int tabstops[argc-1];
	int default_tabstops[NUM_DEFAULT_TABSTOPS] = {8, 16, 24, 32, 40};
	int *tabstop_pointer;
	int tabstop_pos = 0;
	nb = 0;		/* num of blanks */
	nt = 0;		/* num of tabs	 */

	// put args in tabstops, or use default
	if (argc == 1) {
		//TODO - Fix using pointer to default_tabstops[i]
		for (int i = 0; i < NUM_DEFAULT_TABSTOPS; i++) {
			tabstops[i] = default_tabstops[i];
		}
		tabstop_pointer = &tabstops[0];
	} else {
		for (int i = 0; i < argc-1; i++) {
			tabstops[i] = atoi(argv[i+1]);
		}
		tabstop_pointer = &tabstops[0];
	}

	// Loop through the input
	for (pos = 1; (c = getchar()) != EOF; ++pos) {
		
		if (c == ' ') {
			if ((pos % TABINC) != 0) {
				++nb;
			} else if (pos == *tabstop_pointer) {
				nb = 0;
				++nt;
			} else {
				++nb;
			}
		} else {
			for (; nt > 0; --nt)
				putchar('\t');
			if (c == '\t') {
				nb = 0;
			} else {
				for (; nb > 0; --nb)
					putchar(' ');
			}
			putchar(c);
			/* End of line, reset position.
			 * If character was a tab, do magic formula for resetting position */
			if (c == '\n') {
				pos = 0;
				tabstop_pointer = tabstop_pointer - tabstop_pos;
				tabstop_pos = 0;
			} else if (c == '\t') {
				pos = pos + (TABINC - (pos - 1) % TABINC) - 1;
			}
		}
		if ((pos >= *tabstop_pointer) && (tabstop_pos < argc-2)) {
			tabstop_pointer++;
			tabstop_pos++;
		}
		//printf("*tabstop_pointer = %i ; pos = %i, tabstop_pos = %i\n", *tabstop_pointer, pos, tabstop_pos);
	}
	return 0;
}

