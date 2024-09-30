#include <stdio.h>

#define LINELENGTH 20
#define MAXLINE 1000

int getlines(char input[], int maxline);

// Was trying to fold lines as they were being entered.

int main() {

	int len;
	char inputLine[MAXLINE];
	char outputLine[MAXLINE];

	while ((len = getlines(inputLine, MAXLINE)) > 0) {
		printf("%s\n", inputLine);
		printf("%i\n", len);
	}
}

int getlines(char line[], int limit) {

	int m, c;
	int b = 0;
	int col = 0;
	int last_blank = 0;
	int linewrap = LINELENGTH;
	char buffer[MAXLINE];

	for (m = 0; m < limit && (c =getchar()) != EOF && c != '\n'; m++) {
		line[m] = c;

		// Update the buffer and col based on char
		if (c != ' ' ||  c != '\t') {
			buffer[b] = c;
			b++;
			col++;
		} else if (c == '\t') {
			col += 8;
		} else if (c == ' ') {
			col++;
		}
		
		// Reset the buffer when a space is reached
		if (c == '\t' || c == ' ') {
			buffer[0] = '\0';
			b = 0;
			last_blank = m;
		}

		// linewrap limit reached, perform linewrap
		if (col >= linewrap) {

			// If buffer exists, and last_blank > 0
			if (b > 0 && last_blank > 0) {
				line[last_blank++] = '\n';
				for (int i = 0; i <= b; i++) {
					line[last_blank++] = buffer[i];
				}
				m = last_blank;
				last_blank = 0;
			} else {
				line[m++] = '\n';
			}
			b = 0;
			buffer[0] = '\0';
			col = 0;
		}

	}

	if (c == '\n') {
		line[m] = c;
		++c;
	}
	line[m] = '\0';

	return m;
}
