#include <stdio.h>
#include <string.h>

#define MAXVAL 1000

int getch();
void ungetch(int);
void ungets(char []);
void printArray(int []);

int buf[MAXVAL];
int bufp = 0;

int main()
{
	ungetch('l');
	printf("\nl in buftest = %i\n", buf[bufp - 1]);
	printf("%c", getch());
	ungetch('A');
	printf("\nA in buftest = %i\n", buf[bufp - 1]);
	printf("%c", getch());
	ungetch(EOF);
	printf("\nEOF in buftest = %i\n", buf[bufp - 1]);
	printf("%c", getch());
	ungetch('8');
	printf("\n8 in buftest = %i\n", buf[bufp - 1]);
	printf("%c\n", getch());

	// Test this in a loop
	ungetch(EOF);
	ungetch('l');
	ungetch('A');
	ungetch('8');

	printArray(buf);
	int c;
	while ((c = getch()) != EOF) {
		putchar(c);
	}
}

int getch()
{
	int c;
	if (bufp > 0) {
		c = buf[--bufp];
	} else {
		c = getchar();
	}
	return c;
}

void ungetch(int c)
{
	if (bufp >= MAXVAL)
		printf("\nBuftest is alrady filled\n");
	else
		buf[bufp++] = c;
}

void printArray(int array[])
{
	int i = 0;
	printf("\n{");
	while (array[i] != '\0') {
		printf("%i,", array[i++]);
        }
	printf("}");
}
