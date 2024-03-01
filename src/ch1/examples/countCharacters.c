#include <stdio.h>

/* print histogram of the frequency of different characters */

main()
{
	int c, i, p;
	int freqTracker[128];
	int strArray[2];
	strArray[1] = '\0';

	for (i = 0; i < 128; ++i){
		freqTracker[i] = 0;
	}

	while((c = getchar()) != EOF) {
		++freqTracker[c];
	}

	for (i = 0; i < 128; ++i){
		strArray[0] = i;
		printf("%s: ", strArray);
		for (p = 0; p < freqTracker[i]; ++p){
			printf("#");
		}
		printf("\n");
	}
}
