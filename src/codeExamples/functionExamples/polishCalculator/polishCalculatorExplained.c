#include <stdio.h>
#include <stdlib.h> 	/* for atof() */

#define MAXOP	100 	/* max size of operand or opertor */
#define NUMBER 	'0' 	/* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse polish calculator */
int main()
{
	int type;
	double op2;
	char s[MAXOP];

	/* Main loop that gets each value, and performs an action */
	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

/* Can define values later in the file with no issue */
#define MAXVAL	100	/* maximum depth of val stack */

int sp = 0;		/* next free stack position */
double val[MAXVAL];	/* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f; // Place value in array, then increment
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp]; // Decrement to last placed value, and pop
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* Can include values later in the file with no issue */
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c;

	/* This is designed to get a multi-digit number */
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0'; // Required to make the single char a string
	if (!isdigit(c) && c != '.')
		return c;	/* not a number */
	i = 0;
	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0'; // Again, required to complete the string.

	// If this isn't EOF, ungetch() puts value in the buffer.
	if (c != EOF)
		ungetch(c); // Must get next value to look at it this ungets it

	return NUMBER;
}

#define BUFSIZE 100

/* This is the buffer that holds the ungetch values */
char buf[BUFSIZE]; 	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

/* If buffer has value, take from that, otherwise getchar() */
int getch(void)		/* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* This puts the fetched char in the buffer */
void ungetch(int c)	/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
