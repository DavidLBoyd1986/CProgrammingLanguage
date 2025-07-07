#include <stdio.h>

#define IN  1	/* inside a word */
#define OUT 0	/* outside a word */

/* print input one word per line */
int main() {
	
	int character, state;
	state = OUT;

	while ((character = getchar()) != EOF){
		if (character == ' ' || character == '\t' || character == '\n'){
			if (state == IN){
				putchar('\n');
				state = OUT;
			} else {
				continue;
			}
		}else{
			putchar(character);
			state = IN;
		}
	}
	
	return 0;
}
