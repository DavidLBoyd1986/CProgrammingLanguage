#include <stdio.h>

#define LINELENGTH	 10		/* Length of line to split into more shorter lines */
#define OFFSET		 LINELENGTH	/* This is used to check for Blank chars 10 chars before LineLength */
#define MAXLINE    	 1000		/* Man Length of line */
#define TRUE (1 == 1)
#define FALSE !TRUE

// IMPORTANT - This works by not breaking words, but by making the line break at the space after,
//	the last non-blank character, so at the last blank character.
//	This requires remembering everything after the last blank, in case it becomes a seperator.


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
	int i, j, b;
	int column = 0;
	int blanks = 0;
	int last_non_blank = 0;
	char buffer[MAXLINE];

	for(i = 0, j = 0, b = 0; in[i] != '\0'; ++i, ++j, ++b) {
		// The program just needs to print the output
		// out needs changed to a temp char array to hold the output.
		//out[j] = in[i];
		out[j] = in[i];
		buffer[b] = in[i];

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
		if (blanks == 0  && (out[i] == ' ' || out[i] == '\t')) {
			last_non_blank = j - 1;
		//	printf("inside check for a blank char while not in string of blanks");
		} else if (blanks > 0 && (out[i] != ' ' && out[i] != '\t')) {
			blanks = 0;
		//	printf("inside check for a non-blank char while in string of blanks");
		}

		/* Check if reached wrap limit */
		if (column >= n_break) {
			printf("\nbuffer = %s\n", buffer);
			// String ends on chars, pushing all chars after last blank to next line
			if (blanks == 0 && last_non_blank > 0) {
				// End first row at last_non_blank
				out[++last_non_blank] = '\n';
				column = 0;
				last_non_blank++;
				// Go through the buffer
				while (last_non_blank < j) {
					out[last_non_blank] = buffer[last_non_blank];
					last_non_blank++;
					column++;
					printf("\nlast_non_blank = %i, j = %i\n", last_non_blank, j);
				}
			// Blanks at the break, just putting /n and restarting column
			} else if (last_non_blank == 0 && blanks > 0) {
				out[++j] = '\n';
				column = 0;
			// No blanks in string, putting '-'
			} else if (blanks == 0 && last_non_blank == 0) {
				out[++j] = '-';
				out[++j] = '\n';
				column = 0;
			} else {
				printf("Error - This should NOT be reached. Previous condition should have been met.");
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
