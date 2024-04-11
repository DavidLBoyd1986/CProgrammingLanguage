#include <stdio.h>

#define LINELENGTH	 50	/* Length of line to split into more shorter lines */
#define MAXLINE    	1000	/* Man Length of line */

int getlines(char line[], int limit);

main(){
	/* Write line in a buffer, so if you have to backtrack to get to previous blank at line input,
	 * you can read from the buffer. */	

	int c, i, b, a, l, s;
	char output[MAXLINE];
	char buffer[MAXLINE];

	i = l = b = 0;
	int previousBlank = 0;
	int lastNonBlank;

	while ((c = getchar()) != EOF){
		/* fold long lines into two or more lines shorter lines after the last non-blank character
		 * that occurs before the n-th column of input. For really long lines force break the line */
		if (previousBlank == 0 && (c == ' ' || c == '\t')){
			lastNonBlank = i - 1;
			previousBlank = 1;
			buffer[i] = c;
			++b;
		} else if (c == ' ' || c == '\t') {
			buffer[i] = c;
			++b;
		} else {
			lastNonBlank = i;
			previousBlank = 0;
			output[i] = c;
			b = 0;
			++i;
		}	
		if (l == LINELENGTH && previousBlank == 0){
			output[lastNonBlank] = '\n';
			++i;
			l = 0;
		} else if (l == LINELENGTH && previousBlank == 1){
			for (s = 0; s < b; s++){
				output[i] = buffer[s];
				++i;
			}
			output[lastNonBlank] = '\n';
			++i;
			l = 0;
		}
		++l;
	}

	/* This won't get ran until you stop input wiht ctrl+d */
	for (a = 0; a < i; a++){
		putchar(output[a]);
	}	
}

int getlines(char line[], int limit){

	int m, c;
	for (m = 0; m < limit && (c = getchar()) != EOF && c != '\n'; ++m){		
		line[m] = c;
	}
	if (c == '\n'){
		line[m] == c;
		++c;
	}
	line[m] = '\0';
	return m;	
}
