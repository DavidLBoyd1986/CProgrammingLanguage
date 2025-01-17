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
#define TRUE 1			/* true boolean value */
#define FALSE 0			/* false boolean value */

int get_line(char []);
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
int is_var_set(int, int[]);

int var_set[MAXVAL] = {0};	/* variable name stack */
double var_value[MAXVAL];	/* variable value stack */
// int var_pos = 0;	/* next free variable position */

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

// Bug Fixed: Overwriting existing variables is overwriting the wrong variable
// I'm pretty sure this is because VAR_ID automatically finds the var value
// if the var name exists, and pushes it onto the stack.

// This means the var_name is NOT saved in temp_var
// and temp_var is the last saved var_name that was added
// which then finds the last position in the array.

// Solution - hold temp_var everytime, still push value on stack,
// but pop and remove value when setting variable name.
// This seems very hacky, will look for better solution

// There is still a bug, but it is half fixed.
// It updates the value correctly if the var_name comes first
// Need to handle it if var_name comes second.

// This bug is because the var value was pushed on the stack
// So, if n comes second, then when pop() is used, it pops the
// previous value that was pushed from retrieving the var value.

// Doing a rewrite of var, so instead of using two arrays,
// the array position is determined by the int value of the char
// that is the var_name

/* reverse polish calculator */
int main()
{
	int type;
	double op2;
	int var_found = -1;
	int temp_var = 0;
	double pop_holder;
	int var_assigned = FALSE;
	int position = -1; // added to track the position of each value in formula
	int var_pos = -1; // added to track position where var name was given
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
			temp_var = s[0]; // hold var name to use if = follows 
			var_found = is_var_set(temp_var, var_set);
			if (var_found != 0) { 
				push(get_var(temp_var)); // Pushes the found var
				// Track the var name position for removing the pushed var if assigned
				if (position == 0)
					var_pos = 0;
				else if (position == 1)
					var_pos = 1;
			}
			break;
		case '=':
			if (temp_var == 0) {
				printf("\n/Error - No variable to assign.\n");
			}
			// delete pushed found var before assigning new variable
			if (var_pos == 1)
				pop_holder = pop(); 
			put_var(temp_var, pop());
			var_assigned = TRUE;
			// delete pushed found var after assigning new variable
			if (var_pos == 0)
				pop_holder = pop(); // delete found var pushed
			temp_var = 0;	// reset to default value
			var_found = -1; // reset to default value
			var_pos = -1; // reset to default value
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
			var_found = -1;
			var_pos = -1;
			position = -1;
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


/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, neg, temp;
	static int p, len;

	// static is what made it not reset the line each loop. i.e. fixed it.
	
	// why is static int len == 0, but just int len == 8?
	// static int made (p == len) work but non-static int didn't
	// This is because static int uninitialized is auto set to 0
	// if static isn't used, int's that aren't initialized return junk data
	
	char line[MAXVAL];

	if (p == len) {
		len = get_line(line);
		if (!len)
			return EOF;
		p = 0;
	}

	i = 0;
	while (line[p] == ' ' || line[p] == '\t') // Remove whitespace
			p++;
	
	if (line[p] == '-' && isdigit(line[p + 1]))
		s[i++] = line [p++];

	if (isalpha(line[p])) {
		while (isalpha(line[p]))
			s[i++] = line[p++];
		s[i++] = '\0';
		if (strlen(s) == 1)
			return VAR_ID;
		else
			return FUNCTION_ID;
	}
	if (!isdigit(line[p]) && line[p] != '.') {
		return line[p++];	/* not a number */
	}
	if (isdigit(line[p]))	 {	/* collect integer part */
		while (isdigit(line[p]))
			s[i++] = line[p++];
	}
	if (line[p] == '.') {		/* collect fraction part */
		s[i++] = line[p++]; // Have to move to the next char to get past the .
		while (isdigit(line[p])) {
			s[i++] = line[p++];
		}
	}
	s[i] = '\0';
	return NUMBER_ID;
}

int get_line(char line[])
{
	int i, c;
	i = 0;
	while ((c = getchar()) != '\n' && c != EOF){
		line[i++] = c;
	}
	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
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

