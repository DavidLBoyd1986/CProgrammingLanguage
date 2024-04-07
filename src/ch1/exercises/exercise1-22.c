#include <stdio.h>

#define LINELENGTH	 50	/* Length of line to split into more shorter lines */
#define MAXLINE    	1000	/* Man Length of line */

int getlines(char line[], int limit);

main(){
	/* Write line in a buffer, so if you have to backtrack to get to previous blank at line input,
	 * you can read from the buffer. */	

	int c, i, b, a;
	char output[MAXLINE];
	char buffer[MAXLINE];

	i = 0;

	while ((c = getchar()) != EOF){
		output[i] = c;
		buffer[i] = c;
		++i;
	}

	for (a = 0; a < i; a++){
		printf("%d\n", output[a]);
	}	
}

int getlines(char line[], int limit){

}
