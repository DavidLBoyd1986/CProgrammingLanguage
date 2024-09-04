#include <stdio.h>

int get_lines(char line[], int lim);

int main() {

	int lineLength;
	int stringMaxLength = 400;
	char line[stringMaxLength];
	lineLength = get_lines(line, stringMaxLength);
	printf(line);

}

int get_lines(char line[], int lim) {
	
	int c;
	int i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;

	return i;

}
