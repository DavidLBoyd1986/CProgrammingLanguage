#include <stdio.h>
#include <stdlib.h> 	/* for atof() */
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAXOP	100 		/* max size of operand or opertor */
#define MAXVAL	100		/* maximum depth of val stack */
#define NUMBER_ID '0'	 	/* signal that a number was found */
#define FUNCTION_ID '1' 	/* signal that perform_function() needs ran */
#define EQUAL_ID '2'		/* signal that var_assign() needs ran */
#define VAR_ID '3'		/* signal that var_assign() needs ran */

int getop(char []);
void push(double);
double pop(void);
double perform_function(char [], double, double);
void showch(void);
void duplicatech(void);
void swapchs(void);
void clearstack(void);
void printArray(double []);
void put_var(char, double);
double get_var(int);
int find_val_in_array(char, char[]);

char var_name[MAXVAL];	/* variable name stack */
double var_value[MAXVAL];	/* variable value stack */
int var_pos = 0;	/* next free variable position */

// Handling Functions and Variables:
//	2 5 pow ; 5 exp ; 20 sin  
//	x 5 = ; 5 x =

// Variables:
// 1. Return string with the variable name as the only char.
// 2. In case for found variable, Search in array for value:
//	a. return -1 if not found.
// 	b. return pos if found.
// 3-1. If found get variable value, and push on stack.
// 3-2. If not found, save char value of variable name in temp variable.
// 4. If '=' appears, pop() value and assign variable / update variable arrays.
// 5. if an 'op' (-,+,/,*) appears while temp variable is assigned.
//	a. Error, variable is not assigned, clear temp_var, and pop value.

// IMPORTANT - The reason it waits on getop
// is it's because I'm removimg the \n from end of array.
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
	int found_var;
	char temp_var = 0;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
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
		case VAR_ID:
			found_var = find_val_in_array(s[0], var_name);
			if (found_var == -1)
				temp_var = s[0];
			else
				push(get_var(found_var));
			break;
		case '=':
			if (temp_var == 0)
				printf("No var_name to assign value to");
			else
				put_var(temp_var, pop());
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

	while ((s[0] = c = getch()) == ' ' || c == '\t') { // Remove whitespace
		;
	}
	s[1] = '\0'; 	// Required to make the single char a string
	if (isalpha(c)) {
		if (isalpha(temp = getch())) { // for perform_function()
			s[++i] = temp;
			while (isalpha(c = getch())) {
				s[++i] = c;
			}
			ungetch(c);
			s[++i] = '\0';
			return FUNCTION_ID;
		} else if (temp == ' ' ) { 	/* for get_var() */
			return VAR_ID;
		} else {			/* ERROR Handling */
			ungetch(temp);
			s[0] = '\0';
			//return s;	// Not sure what to return on ERRORs
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

void put_var(char c, double value)
{
	int n = find_val_in_array(c, var_name);
	if (n == -1) {
		var_name[var_pos] = c;
		var_value[var_pos++] = value;
	} else {
		var_value[n] = value;
	}
}

double get_var(int i)
{
	return var_value[i];
}

int find_val_in_array(char c, char array[])
{
	for (int i = 0; i <= var_pos; i++) {
		if (array[i] == c)
			return i;
	}
	return -1;
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
