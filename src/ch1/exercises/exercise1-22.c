#include <stdio.h>

#define LINELENGTH	 50	/* Length of line to split into more shorter lines */
#define OFFSET		 10	/* This is used to check for Blank chars 10 chars before LineLength */
#define MAXLINE    	1000	/* Man Length of line */
#define TRUE (1 == 1)
#define FALSE !TRUE

// I'm assuming this is how they expect the program to operate.
// The instructions are extremely unclear.
// Per exercise - This will put the wrap '-' after the last non-blank character
// It keeps blanks after the wrap because exercise isn't clear how to handle them.

int getlines(char line[], int limit);
void foldlines(char in[], char out[], int l);

int main() {
	/* Write line in a buffer, so if you have to backtrack to get to previous blank at line input,
	 * you can read from the buffer. */	
	int len;
	char inputLine[MAXLINE];
	char outputLine[MAXLINE];

	while ((len = getlines(inputLine, MAXLINE)) > 0) {
		foldlines(inputLine, outputLine, LINELENGTH);
		printf("%s\n", outputLine);
		printf("%i\n", len);
	}
}

void foldlines(char in[], char out[], int n_break) {
	int i, j;
	int column = 0;
	int last_non_blank = 0;

	for(i = 0, j = 0; in[i] != '\0'; ++i, ++j) {
		out[j] = in[i];

		/* If new newline, reset column count */
		if (out[j] == '\n') {
			column = 0;
			continue;
		}

		/* Increment column, If character is a '\t' update column by 8 'characters' */
		if (out[j] == '\t') {
			column = column + 8;
		} else {
			column++;
		}

		/* If not already, Track spot of last non-blank character */
		if (last_non_blank == 0  && (out[i] == ' ' || out[i] == '\t')) {
			last_non_blank = j;
		//	printf("inside check for a blank char while not in string of blanks");
		} else if (last_non_blank > 0 && (out[i] != ' ' && out[i] != '\t')) {
			last_non_blank = 0;
		//	printf("inside check for a non-blank char while in string of blanks");
		}

		/* Check if reached wrap limit */
		if (column >= n_break) {
			if (last_non_blank) {
				out[++last_non_blank] = '-';
				/*  column isn't 0, but j - last_non_blank */
				out[++last_non_blank] = '\n';
				j = last_non_blank+3;
				column = 0;
				last_non_blank = 0;
			} else {
				out[++j] = '-';
				out[++j] = '\n';
				column = 0;
			}
		}
	}
	out[j] = '\0';
}

int getlines(char line[], int limit) {

	int m, c;
	for (m = 0; m < limit && (c = getchar()) != EOF && c != '\n'; ++m) {
		line[m] = c;
	}
	if (c == '\n') {
		line[m] == c;
		++c;
	}
	line[m] = '\0';
	return m;	
}
