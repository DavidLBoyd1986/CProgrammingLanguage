#include <stdio.h>
#include <stdlib.h>	 	/* for atof() */
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#define MAXOP	100 		/* max size of operand or opertor */
#define MAXVAL	100		/* maximum depth of val stack */
#define NUMBER_ID '0'	 	/* signal that a number was found */
#define FUNCTION_ID '1' 	/* signal that perform_function() needs ran */
#define EQUAL_ID '2'		/* signal that var_assign() needs ran */
#define VAR_ID '3'		/* signal that var_assign() needs ran */
#define TRUE 1			/* true boolean value */
#define FALSE 0			/* false boolean value */

int getop(char []);
void push(double);
double pop(void);
double perform_function(char [], double, double);
void showch(void);
void duplicatech(void);
void swapchs(void);
void clearstack(void);
void printArray(double []);
void put_var(int, double);
double get_var(int);
int is_var_set(int, int []);

int var_set[MAXVAL];	/* variable name stack */
double var_value[MAXVAL];	/* variable value stack */

// Handling Functions and Variables:
//	2 5 pow ; 5 exp ; 20 sin  
//	x 5 = ; 5 x =

/* reverse polish calculator */
int main()
{
	int type;
	double op2;
	double pop_holder;
	int var_assigned = FALSE;
	char temp_var = -1;
	char position = -1;
	char var_pos = -1;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		position++; // track position in formula
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
			temp_var = s[0]; //hold var name to use if = follows
			if (is_var_set(temp_var, var_set)); {
				push(get_var(temp_var)); // Push the found var
				// Track the var name position for removing the pushed var if assigned
				if (position == 0)
					var_pos = 0;
				else if (position == 1)
					var_pos = 1;
			}
			break;
		case '=':
			if (temp_var == 0) {
				printf("No var_set to assign value to");
			}
			if (var_pos == 1)
				pop();	// delete the pushed found_var
			put_var(temp_var, pop());
			if (var_pos == 0)
				pop();	// delete the pushed found_var
			var_assigned = TRUE;	// Skip printing value on \n case
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
			if (var_assigned == FALSE) {
				pop_holder = pop();
				put_var('z', pop_holder); // Save printed value
				printf("\t%.8g\n", pop_holder);
			} else {
				var_assigned = FALSE;
			}
			temp_var = -1; // reset to default value
			var_pos = -1;  // reset to default value
			position = -1; // reset to default value
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

/* pop: pop and return top value from stack */
double pop(void)
{
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
	static int prevC;

	i = 0; // Not initializing this was a bad bug

	(prevC > 0) ? (c = prevC) : (s[0] = c = getch());

	if (isblank(c)) { // Remove whitespace
		while (isblank(s[0] = c = getch()))
			;
	}
	s[1] = '\0'; 	// Required to make the single char a string
	if (isalpha(c)) {
		if (isalpha(temp = getch())) { // for perform_function()
			s[++i] = temp;
			while (isalpha(c = getch())) {
				s[++i] = c;
			}
			prevC = c;
			s[++i] = '\0';
			return FUNCTION_ID;
		} else if (temp == ' ' ) { 	/* for get_var() */
			return VAR_ID;
		} else {			/* ERROR Handling */
			prevC = c;
			s[0] = '\0';
			//return s;	// Not sure what to return on ERRORs
		}
	}
	if (!isdigit(c) && c != '.' && c != '-') {
		prevC = 0;
		return c;	/* not a number */
	}
	i = 0;
	// Need to return only '-' if it isn't followed by a digit
	if (c == '-')
		if (!isdigit(c = getch())) {
			prevC = c;
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
		prevC = c;
	return NUMBER_ID;
}

#define BUFSIZE 100

char buf[BUFSIZE]; 	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

int getch(void)		/* get a (possibly pushed back) character */
{
	return getchar();
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

void put_var(int i, double value)
{
	var_set[i] = 1;
	var_value[i] = value;
}

double get_var(int i)
{
	return var_value[i];
}

int is_var_set(int i, int array[])
{
	if (array[i] != 0)
		return TRUE;
	return FALSE;
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
