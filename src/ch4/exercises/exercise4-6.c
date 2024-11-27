#include <stdio.h>
#include <stdlib.h> 	/* for atof() */
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAXOP	100 		/* max size of operand or opertor */
#define NUMBER_ID 	'0' 	/* signal that a number was found */
#define FUNCTION_ID '1' 	/* signal that perform_function() needs ran */
#define PUT_VAR_ID '2'	/* signal that var_assign() needs ran */
#define GET_VAR_ID '3'		/* signal that var_assign() needs ran */

int getop(char []);
void push(double);
double pop(void);
double perform_function(char []);
void showch(void);
void duplicatech(void);
void swapchs(void);
void clearstack(void);
void printArray(double []);
void put_var(char []);
double get_var(char[]);

// TODO - Exercise 4-5 - Verify function name is valid
//	I will have to push inside the perform function
//	as it will always push something if I push in main
//	unless I add if logic in main, which is bad design

//	Or, I can verify in getop, which is probably the better design

// TODO - Exercise 4-6 - refactor perform_function
//	perform function became sloppy after adding support for variables.

/* reverse polish calculator */
int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER_ID:
			push(atof(s));
			break;
		case FUNCTION_ID:
			push(perform_function(s));
			break;
		case PUT_VAR_ID:
			put_var(s);
			break;
		case GET_VAR_ID:
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
char var_name[MAXVAL];	/* variable name stack */
double var_value[MAXVAL];	/* variable value stack */
int var_pos = 0;	/* next free variable position */

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
	char function[MAXOP] = {};
	int i = 0;
	char temp = 0;
	char temp_string[MAXOP] = {};
	double val_one = 0;
	double val_two = 0;

	while (s[c] != '(') {	/* Get function name */
		function[c] = s[c];
		c++;
	}
	s[c] = '\0';
	/* Get values in function, and perform function */
	if (strcmp(function, "exp") == 0) {
		for (i = 0; (temp = s[++c]) != ')'; i++) {
			if (isalpha(temp) && i == 0) {
				temp_string[i++] = temp;
				temp_string[i] = '\0';
				return exp(get_var(temp_string));
			}
			temp_string[i] = temp;
		}
		temp_string[i] = '\0';
		return exp(atof(temp_string));
	} else if (strcmp(function, "sin") == 0) {
		for (i = 0; (temp =  s[++c]) != ')'; i++) {
			if (isalpha(temp) && i == 0) {
				temp_string[i++] = temp;
				temp_string[i] = '\0';
				return sin(get_var(temp_string));
			}
			temp_string[i] = temp;
		}
		temp_string[i] = '\0';
		return sin(atof(temp_string));
	} else if (strcmp(function, "pow") == 0) {
		for (i = 0; (temp = s[++c]) != ','; i++) {
			if (isalpha(temp)) {
				temp_string[i++] = temp;
				temp_string[i] = '\0';
				val_one = get_var(temp_string);
				temp_string[0] = '\0';
				c++;
				break;
			}
			temp_string[i] = temp;
		}
		if (strlen(temp_string) > 0) {	/* empty string was variable */
			temp_string[i] = '\0';
			val_one = atof(temp_string);
		}
		for (i = 0; (temp = s[++c]) != ')'; i++) {
			if (isalpha(temp)) {
				temp_string[i++] = temp;
				temp_string[i] = '\0';
				val_two = get_var(temp_string);
				temp_string[0] = '\0';
				break;
			}
			temp_string[i] = temp;
		}
		if (strlen(temp_string) > 0) {
			temp_string[i] = '\0';
			val_two = atof(temp_string);
		}
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
	i = 0; // Not initializing this was a bad bug

	while ((s[0] = c = getch()) == ' ' || c == '\t') // Remove whitespace
		;
	s[1] = '\0'; 	// Required to make the single char a string
	if (isalpha(c)) {
		if (isalpha(temp = getch())) { // for perform_function()
			s[++i] = temp;
			while ((s[++i] = c = getch()) != ')') {
				;
			}
			s[++i] = '\0';
			return FUNCTION_ID;
		} else if (temp == '=') { 	/* for put_var() */
			// Does not save '=' to make parsing easier
			while (isdigit(temp = getch()) || temp == '.') {
				s[++i] = temp;
			}
			s[++i] = '\0';
			return PUT_VAR_ID;
		} else if (temp == ' ' ) { 	/* for get_var() */
			ungetch(temp);
			s[++i] = '\0';
			return GET_VAR_ID;
		} else {			/* ERROR Handling */
			ungetch(temp);
			printf("\nThis input is invalid: %s\n", s);
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

void put_var(char s[])
{
	int n = 0;
	int t = 0;
	char temp_name;
	char temp_val_string[MAXVAL];

	if (isalpha(s[n])) {
		temp_name = var_name[var_pos] = s[n++]; /* Get var name */
	}
	while (isdigit(s[n]) || s[n] == '.')
		temp_val_string[t++] = s[n++];	/* Get string of value */
	temp_val_string[t] = '\0';
	n = 0;
	while (n < var_pos) {	/* Check if variable already exists */
		if (var_name[n] == temp_name) {
			var_value[n] = atof(temp_val_string);
			return;
		}
		n++;
	}
	var_value[var_pos++] = atof(temp_val_string);
}

double get_var(char s[])
{
	int n = 0;
	char find_var = s[0];

	while (n < var_pos) {
		if (var_name[n] == find_var) {
			return var_value[n];
		} else {
			n++;
		}
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
