#include <stdio.h>

#define TABINC  8


int main(void){

	int nb, nt, pos, c;

	nb = 0;		/* num of blanks */
	nt = 0;		/* num of tabs	 */

	for (pos = 1; (c = getchar()) != EOF; ++pos){
		
		if (c == ' ') {
			/* Increment nb, except if pos is divisible by num of spaces in TAB - TABINC 
			 * This works because if it was spaces leading up to TABINC,
			 * it will only replace that num of spaces with the tab*/
			if ((pos % TABINC) != 0) {
				++nb;
			} else {
				nb = 0;
				++nt;
			}
		} else {
			/* put in num of Tabs indicated by nt */
			for (; nt > 0; --nt)
				putchar('\t');
			/* If character is a Tab, set nb to 0 because the tab will replace the extra blanks.
			 * If character is not a tab, add in num of blanks indicated with nb */
			if (c == '\t') {
				nb = 0;
			} else {
				for (; nb > 0; --nb)
					putchar(' ');
			}
			/* finally, add the character */
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

