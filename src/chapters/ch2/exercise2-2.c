#include <stdio.h>

int main()
{
	int c;
	int i;
	int lim = 400;
	char inputString[lim];

	for (i = 0; i < lim -1; ++i){
		c = getchar();
		inputString[i] = c;
		if (c == '\n') {
			break;
		}
	        if (c == EOF) {
			break;
		}
	}
	printf("inputString = %s", inputString);
	return 0;
}
