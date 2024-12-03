#include <stdio.h>
#include <stdlib.h> 	/* for atof() */
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAXOP	100 		/* max size of operand or opertor */
#define MAXVAL	100		/* maximum depth of val stack */
#define NUMBER_ID '0'	 	/* signal that a number was found */
#define FUNCTION_ID '1' 	/* signal that perform_function() needs ran */
#define PUT_VAR_ID '2'		/* signal that var_assign() needs ran */
#define GET_VAR_ID '3'		/* signal that var_assign() needs ran */

int getop(char []);
void push(double);
double pop(void);
double perform_function(char [], double, double);
void showch(void);
void duplicatech(void);
void swapchs(void);
void clearstack(void);
void printArray(double []);
void put_var(char [], double);
double get_var(char[]);

char var_name[MAXVAL];	/* variable name stack */
double var_value[MAXVAL];	/* variable value stack */
int var_pos = 0;	/* next free variable position */

// TODO - Create an updated program that correctly
//	handles functions and variables. It should
//	work like the polish method.
//	2 5 pow  :  5 exp  : 20 sin  
//	x 5 =	: for assignment of variables

// IMPORTANT - The reason it waits on getop
// is it's  because I'm removimg the \n from end of array.
// SOLUTION - I had to add an ungetch in getop()
// It was removing the \n after getting the function name

// IMPORTANT - getchar function provided by C stdio.h
// stores the input in a buffer until a /n or EOF is reached.
// This is why the print statements don't appear until you
// input \n.

/* reverse polish calculator */
int main()
{
	int type;
	double op2;
	double temp_val;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		printf("\ntop of main loop, type = %i\n", type);
		switch (type) {
		case NUMBER_ID:
			push(atof(s));
			break;
		case FUNCTION_ID:
			op2 = pop();
			if (strcmp(s, "pow") == 0) {
				push(perform_function(s, pop(), op2));
			} else {
				push(perform_function(s, op2, 0));
			}
			break;
		case PUT_VAR_ID:
			printf("\nInside PUT_VAR_ID\n");
			put_var(s, pop());
			break;
		case GET_VAR_ID:
			printf("\nInside GET_VAR_ID\n");
			push(get_var(s));
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
			// I need to update put_var to take in the char and double value
			temp_val = pop();
			var_name[var_pos] = 'p';
			var_value[var_pos++] = temp_val;
			printf("\t%.8g\n", temp_val);
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}


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
	double temp_val;

	if (sp > 0) {
		return val[--sp];
	} else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include <math.h>

/* perform the math function provided */
double perform_function(char s[], double op1, double op2)
{
	if (strcmp(s, "exp") == 0) {
		return exp(op1);
	} else if (strcmp(s, "sin") == 0) {
		return sin(op1);
	} else if (strcmp(s, "pow") == 0) {
		return pow(op1, op2);
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
	i = 0; // Not initializing this was a bad bug

	printf("\nInside getop\n");
	while ((s[0] = c = getch()) == ' ' || c == '\t') { // Remove whitespace
		;
	}
	printf("\nInside getop, after clearing white space\n");
	s[1] = '\0'; 	// Required to make the single char a string
	if (isalpha(c)) {
		//printf("\ngetp, after first isalpha, c = %i\n", c);
		if (isalpha(temp = getch())) { // for perform_function()
			s[++i] = temp;
			//printf("\ninside 2nd isalpha, s = %s\n", s);
			while (isalpha(c = getch())) {
				s[++i] = c;
			}
			ungetch(c);
			s[++i] = '\0';
			//printf("\nfinal string in getop, s = %s\n", s);
			return FUNCTION_ID;
		} else if (temp == ' ' ) { 	/* for get_var() */
			//printf("\ntemp == ' ', temp = %i\n", temp);
			ungetch(temp);
			//s[++i] = '\0';
			return GET_VAR_ID;
		} else {			/* ERROR Handling */
			ungetch(temp);
			printf("\nThis input is invalid: %s\n", s);
			s[0] = '\0';
			//return s;	// Not sure what to return on ERRORs
		}
	}
	if (temp == '=') { 	/* for put_var() */
		return PUT_VAR_ID;
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
	return NUMBER_ID;
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

void put_var(char s[], double value)
{
	char find_var = s[0];

	for (int i = 0; i < var_pos; i++) {	/* Check if variable already exists */
		if (var_name[i] == find_var) {
			var_value[i] = value;
			return;
		}
	}
	var_value[var_pos++] = value;
}

double get_var(char s[])
{
	int n = 0;
	char find_var = s[0];

	for (int i = 0; i < var_pos; i++) {
		if (var_name[i] == find_var)
			return var_value[i];
	}
	printf("\nERROR - Variable not found.");
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
