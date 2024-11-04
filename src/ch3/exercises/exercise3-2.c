#include <stdio.h>

#define MAXSTRING 1000 // Used in char arrays [] for max length

void escape(char s[], char t[]);
void escape_reverse(char s[], char t[]);
int get_lines(char line[], int limit);

int main()
{	
	int lineLength;
	int stringMaxLength;
	char inputString[MAXSTRING];
	char outputString[MAXSTRING];
	char outputStringTwo[MAXSTRING];

	lineLength = get_lines(inputString, stringMaxLength);
	printf("\n\nOriginal line:\n%s\n\n", inputString);
	escape(inputString, outputString);
	printf("\nLine after escape:\n%s\n\n", outputString);
	escape_reverse(outputString, outputStringTwo);
	printf("\nLine after escape_reverse:\n%s\n\n", outputStringTwo);

}

void escape(char s[], char t[])
{
	int i, c, e;
	i = c = e = 0;
	while ((c = s[i]) != '\0') {
		switch (c) {
		case '\t':
			t[e++] = '\\';
			t[e++] = 't';
			break;
		case '\n':
			t[e++] = '\\';
			t[e++] = 'n';
			break;
		default:
			t[e++] = s[i];
			break;
		}
		i++;
	}
	t[e] = '\0';
}

void escape_reverse(char s[], char t[])
{
	int i, c, e;
	i = c = e = 0;
	while ((c = s[i]) != '\0') {
		switch(c) {
		case '\\':
			if (s[i + 1] == 't') {
				i++;
				t[e++] = '\t';
				break;
			}
			if (s[i + 1] == 'n') {
				i++;
				t[e++] = '\n';
				break;
			}
		default:
			t[e++] = s[i];
			break;
		}
		i++;
	}
	t[e] = '\0';
}

int get_lines(char line[], int limit)
{	
	int m, c;

	for (m = 0; m < limit && (c = getchar()) != EOF; ++m) {
		line[m] = c;
	}
	if (c == '\n') {
		line[m] = c;
		++c;
	}
	line[m] = '\0';
	return m;
}
