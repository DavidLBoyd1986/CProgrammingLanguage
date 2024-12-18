#include <stdio.h>
#include <string.h>

#define MAXVAL 1000

int getch();
void ungetch(int);
void ungets(char []);

int buf;

int main()
{
int c;
	ungetch(EOF);
	printf("\nEOF in buf as int = %i\n", buf);
	printf("%c", getch());
	ungetch('l');
	printf("\nl in buf as int = %i\n", buf);
	printf("%c", getch());
	ungetch('A');
	printf("\nA in buf as int = %i\n", buf);
	printf("%c", getch());
	ungetch('8');
	printf("\n8 in buf as int = %i\n", buf);
	printf("%c\n", getch());
}

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
