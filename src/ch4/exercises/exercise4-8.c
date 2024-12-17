#include <stdio.h>
#include <string.h>

#define MAXVAL 1000

int getch();
void ungetch(int);
void ungets(char []);

int main()
{
	ungetch('s');
	ungetch('l');
	printf("%c", getch());
	ungetch('A');
	printf("%c", getch());
	ungetch('8');
	printf("%c\n", getch());
}

int buf;

int getch()
{
	int c;
	if (buf) {
		c = buf;
	} else {
		c = getchar();
	}
	buf = 0;
	return c;
}

void ungetch(int c)
{
	if (buf)
		printf("\nBuf is alrady filled\n");
	else
		buf = c;
}
