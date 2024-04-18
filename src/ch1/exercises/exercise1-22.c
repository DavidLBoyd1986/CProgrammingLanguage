#include <stdio.h>

#define LINELENGTH	 50	/* Length of line to split into more shorter lines */
#define OFFSET		 10	/* This is used to check for Blank chars 10 chars before LineLength */
#define MAXLINE    	1000	/* Man Length of line */
#define TRUE (1 == 1)
#define FALSE !TRUE

int getlines(char line[], int limit);
void foldlines(char in[], char out[], int l);

main(){
	/* Write line in a buffer, so if you have to backtrack to get to previous blank at line input,
	 * you can read from the buffer. */	
	int len;
	char inputLine[MAXLINE];
	char outputLine[MAXLINE];

	while ((len = getlines(inputLine, MAXLINE)) > 0){
		foldlines(inputLine, outputLine, LINELENGTH);
		printf("%s\n", outputLine);
		printf("%i\n", len);
	}
	

}

void foldlines(char in[], char out[], int n_break){
	int i, j;
	int column = 0;
	int split = FALSE;
	int last_blank = 0;

	for(i = 0, j = 0; in[i] != '\0'; ++i, ++j){
		out[j] = in[i];

		if (out[j] == '\n'){
			column = 0;
		}
		
		/* Track position along columns, and starting '\n' at n_break */		
		column++;
		
		/* Track blanks once you reach offset */
		if (column == (n_break - OFFSET)){
			split = TRUE;
		}

		/* Track last blanks after offset */
		if (split && (out[i] == ' ' || out[i] == '\t')){
			last_blank = j;
		}

		/* If last character was blank wrap line, else last char wasn't blank add '-' */
		if (column == n_break){
			if (last_blank){
				out[last_blank] = '\n';
				/* I don't know why column isn't 0, but j - last_blank */
				column = j - last_blank;
				last_blank = 0;
			} else {
				out[j++] = '-';
				out[j] = '\n';
				column = 0;
			}
			split = FALSE;
		}
	}
	out[j] = '\0';
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
