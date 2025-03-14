#include <stdio.h>
#include <ctype.h>

#define SIZE 10

int getch(void);
void ungetch(int);
float getfloat(float *);
void print_array(float array[], int len);

int main()
{
	int n;
	float array[SIZE], getfloat(float *);

	printf("\nIn main before loop\n");
	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
		;
	printf("\nIn main after loop\n");
	int l = sizeof(array) / sizeof(array[0]);
	print_array(array, l);
}

/* getint; get next integer from input into *pn */
float getfloat(float *pn)
{
	int sign;
	float c;

	while (isspace(c = getch())) /* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);	/* it's not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		c = getch();
		if (!isdigit(c))
			return 0;
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

#define BUFSIZE 100

int buf[BUFSIZE];
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

void print_array(float array[], int len)
{
	int i = 0;
	printf("\n{");
	while (i < len-1) {
		printf("%f, ", array[i]);
		i++;
	}
	printf("%f}\n\n", array[i]);
}
