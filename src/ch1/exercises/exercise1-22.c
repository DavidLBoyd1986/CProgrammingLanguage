#include <stdio.h>

#define LINELENGTH	 50	/* Length of line to split into more shorter lines */
#define MAXLINE    	1000	/* Man Length of line */

int getlines(char line[], int limit);

main(){
	/* Write line in a buffer, so if you have to backtrack to get to previous blank at line input,
	 * you can read from the buffer. */	

	int len;
	char inputLine[MAXLINE];
	char outputLine[MAXLINE];

	while ((len = getlines(inputLine, MAXLINE)) > 0){
		printf("%s\n", inputLine);
		printf("%i\n", len);
	}
	
}

int foldlines(char line[], int l){
	int i, j;
	for(i = 0, j = 0; i < l; ++i, ++j){
		
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

/*
		if (previousBlank == 0 && (c == ' ' || c == '\t')){
			lastNonBlank = i - 1;
			previousBlank = 1;
			++l;
			buffer[s] = c;
			++s;
		} else if (c == ' ' || c == '\t') {
			++l;
			buffer[s] = c;
			++s;
		} else {
			if (previousBlank == 1){
				--s;
				while (s > 0){
					output[i] = buffer[s];
					--s;
					++i;
				}
			}
			lastNonBlank = i;
			previousBlank = 0;
			output[i] = c;
			++i;
			++l;
		}	
		if (l == LINELENGTH){
			output[lastNonBlank] = '\n';
			++i;
			l = 0;
		}
	}

	for (a = 0; a < i; a++){
		putchar(output[a]);
	} 
*/
