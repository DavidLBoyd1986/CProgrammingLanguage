#include <stdio.h>
#include <string.h>

#define MAXVAL 1000

int getch();
void ungetch(int);
void ungets(char []);

int main()
{
	int c;
	char s[MAXVAL] = "test-";

	ungets(s);
	while ((c = getch()) != EOF) {
		putchar(c);
	}
}

char buf[MAXVAL];
int bufp = 0;

int getch()
{
	if (bufp > 0) {
		return buf[--bufp];
	} else {
		return getchar();
	}
	//return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= MAXVAL)
		printf("Out of space in buffer");
	else
		buf[bufp++] = c;
}

void ungets(char s[])
{
	int l = strlen(s) - 1;
	while (l >= 0) {
		ungetch(s[l--]);
	}
}

