#include <stdio.h>

#define LINELENGTH	 20		/* Length of line to split into more shorter lines */
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
	b = 0;

	for (i = 0, j = 0; in[i] != '\0'; ++i, ++j) {

		// copy to the output array
		out[j] = in[i];

		// buffer is the array that holds all the chars between last_non_blank and line break
		if (in[i] != '\n' || in[i] != '\t') {
			buffer[b] = in[i];
			b++;
		}

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

		/* If a blank char after non_blank char */
		if (blanks == 0  && (out[i] == ' ' || out[i] == '\t')) {
			// Track spot of last non-blank character, and reset buffer
			last_non_blank = j - 1;
			b = 0;
		/* If a non_blank char after blanks, wait for last_non_blank again. */
		} else if (blanks > 0 && (out[i] != ' ' && out[i] != '\t')) {
			blanks = 0;
		}

		/* Check if reached wrap limit */
		if (column >= n_break) {

			column = 0;
			// String ends on non-blank, and there is a last_non_blank.
			if (blanks == 0 && last_non_blank > 0) {

				// End current row at last_non_blank
				out[++last_non_blank] = '\n';
				last_non_blank++;

				// Go through the buffer
				for (int t = 0; t < b; t++) {
					out[last_non_blank] = buffer[t];
					last_non_blank++;
					column++;
				}
			// Blanks at the break, just putting /n and restarting column
			} else if (last_non_blank == 0 && blanks > 0) {
				out[++j] = '\n';

			// No blanks in string, putting '-'
			} else if (blanks == 0 && last_non_blank == 0) {
				out[++j] = '-';
				out[++j] = '\n';

			} else {
				printf("Error - This should NOT be reached.");
			}
			// Reset the buffer 
			b = 0;
			buffer[0] = '\0';
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
		line[m] = c;
		++c;
	}
	line[m] = '\0';
	return m;	
}
