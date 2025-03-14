#include <stdio.h>
#include <ctype.h>

#define SIZE 10

int getch(void);
void ungetch(int);
int getint(int *pn);
void print_array(int array[], int len);

int main()
{
	int n, array[SIZE], getint(int *);
	printf("\nIn main before loop\n");
	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;
	printf("\nIn main after loop\n");
	int l = sizeof(array) / sizeof(array[0]);
	print_array(array, l);
}

/* getint; get next integer from input into *pn */
int getint(int *pn)
{
	int c, temp, sign;

	while (isspace(c = getch())) /* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);	/* it's not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		c = getch();
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void print_array(int array[], int len)
{
	int i = 0;
	printf("\n{");
	while (i < len-1) {
		printf("%i, ", array[i]);
		i++;
	}
	printf("%i}\n\n", array[i]);
}
