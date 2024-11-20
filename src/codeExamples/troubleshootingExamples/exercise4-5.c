#include <stdio.h>
#include <stdlib.h> 	/* for atof() */
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAXOP	100 	/* max size of operand or opertor */
#define NUMBER 	'0' 	/* signal that a number was found */
#define IDENTIFIER '1' 	/* signal that perform_function() needs ran */

// Problem - pow() works once, but throws a seg fault when ran again.
// I put prints, but it doesn't even seem to run perform_function again

// It only happens after a pow() has been popped.
// I can run pow() multiple times and push it.
// But once it has been popped once, I can't run perform_function again
// When I run perform_function after popping a pushed pow(),
// it throws the seg fault, and won't run the first line of perform_function

// The problem is in getop(), 100%, there is some array issue
// it won't happen if pow() is later in the command
// it only happens after running pow() once, 
// and it is the first command in next run

int getop(char []);
void push(double);
double pop(void);
double perform_function(char []);
void showch(void);
void duplicatech(void);
void swapchs(void);
void clearstack(void);
void printArray(double []);

/* reverse polish calculator */
int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case IDENTIFIER:
			push(perform_function(s));
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
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push((int) pop() % (int) op2);
			else
				printf("error: zero divisor\n");
			break;
		case '?':
			showch();
			break;
		case '&':
			duplicatech();
			break;
		case '#':
			swapchs();
			break;
		case '!':
			clearstack();
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

#define MAXVAL	100	/* maximum depth of val stack */

int sp = 0;		/* next free stack position */
double val[MAXVAL];	/* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: po and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include <math.h>

/* perform the math function provided */
double perform_function(char s[])
{
	int c = 0;
	int i = 0;
	char temp = 0;
	char temp_string[MAXOP] = {};
	double val_one = 0;
	double val_two = 0;
	char function[MAXOP] = {};
	
	while (s[c] != '(') {	/* Get function name */
		function[c] = s[c];
		c++;
	}
	s[c] = '\0';
	if (strcmp(function, "exp") == 0) {
		for (i = 0; (temp = s[++c]) != ')'; i++) {
			temp_string[i] = temp;
		}
		temp_string[i] = '\0';
		return exp(atof(temp_string));
	} else if (strcmp(function, "sin") == 0) {
		for (i = 0; (temp =  s[++c]) != ')'; i++) {
			temp_string[i] = temp;
		}
		temp_string[i] = '\0';
		return sin(atof(temp_string));
	} else if (strcmp(function, "pow") == 0) {
		for (i = 0; (temp = s[++c]) != ','; i++) {
			temp_string[i] = temp;
		}
		temp_string[i] = '\0';
		val_one = atof(temp_string);
		for (i = 0; (temp = s[++c]) != ')'; i++) {
			temp_string[i] = temp;
		}
		temp_string[i] = '\0';
		val_two = atof(temp_string);
		return pow(val_one, val_two);
	}
}

// The below functions getop(), getch(), ungetch() all get the user input:
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c, neg, temp;
	i = 0; //Added as possible fix

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0'; 	// Required to make the single char a string
	printf("\ngetop, past while loop to remove whitespace\n");
	if (isalpha(c)) { 	/* check if alpha, followed by another alpha */
		printf("\ngetop, inside first if isalpha()\n");
		if (isalpha(temp = getch())) {
			printf("\ngetop, inside second if isalpha()\n");
			printf("\ngetop, 2nd alpha, temp = %c\n", temp);
			printf("\ngetop, 2nd alpha, s = %s\n", s); // In output
			printf("\ni = %i\n", i);
			s[++i] = temp;
			printf("\ngetop, 2nd alpha after temp, s = %s\n", s); // Not in output
			while ((s[++i] = c = getch()) != ')') {
				printf("\ngetop, inside while of second isalpha()\n");
				printf("\ni = %i\n", i);
				;
			}
			s[++i] = '\0';
			return IDENTIFIER;
		} else {
			ungetch(temp);
		}
	}
	if (!isdigit(c) && c != '.' && c != '-')
		return c;	/* not a number */
	i = 0;
	// Need to return only '-' if it isn't followed by a digit
	if (c == '-')
		if (!isdigit(c = getch())) {
			ungetch(c);
			return '-';
		} else {
			s[++i] = c;
		}
	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; 	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

int getch(void)		/* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)	/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

// All the below functionw work with the val array:

void showch(void)	/* ? = show the top element of the array */
{
	printf("\nTop element in stack: %g\n", val[sp - 1]);
}

void duplicatech(void) /* & = duplicate, pop w/o removing top element */
{
	double tempVal = val[sp - 1];
	push(tempVal);
}

void swapchs(void)	/* # = swap top two chars in array. */
{
	double tempValOne = val[sp - 1];
	double tempValTwo = val[sp - 2];
	val[sp - 2] = tempValOne;
	val[sp - 1] = tempValTwo;
}

void clearstack(void)	/* ! = clear the stack */
{
	// Don't think buffer needs cleared
	val[0] = '\0';
}

void printArray(double array[])
{
	int i = 0;

	printf("\n{");
	while (array[i] != '\0') {
		printf("%g,", array[i++]);
	}
	printf("}");
}
