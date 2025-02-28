#include <stdio.h>

#define INWORD	 1	 /* Pointer is inside word */
#define OUTWORD  0	 /* Pointer is outside word */

/* output the frequency of words by word lenght */
int main() {
	int c, i, length, output;
	length = 0;
	int ndigit[20];
	int pointer = OUTWORD;

	for (i = 1; i < 21; ++i){
		ndigit[i] = 0;
	}

	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\t' || c == '\n'){
			if (length > 0){
				++ndigit[length];
				length = 0;
				pointer = OUTWORD;
			}
		} else{
			++length;
			if (pointer == OUTWORD){
				pointer = INWORD;
			}
		}
	}
	for (i = 1; i < 21; ++i){
		printf("%d:",i);
		for (output = 0; output < ndigit[i]; ++output){
			printf("#");
		}
		printf("\n");	
	}

	return 0;
}
