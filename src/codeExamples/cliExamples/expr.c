#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ARRAY 100
#define NUMBER_ID '0'

float expr(char *[]);
float pop();
void push(float);

static float stack[MAX_ARRAY];
static int stack_pointer = 0;

int main(int argc, char *argv[])
{
	int argp = 1;
	int c;
	float d, op2, val;

	while (argc-- > 1) {
		c = *argv[argp]; // Get arg pointer
		if (isdigit(c)) {
			c = NUMBER_ID;
		}
		switch (c) {
			case NUMBER_ID:
				d = atof(argv[argp]);
				push(d);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '*': // Needs to be in quotes or escaped
				push(pop() * pop());
				break;
			case '/':
				op2 = pop();
				push(pop() / op2);
				break;
			default:
				printf("Operation not supported\n");
				break;
		}
		argp++;
	}
	val = pop();
	printf("%.2f\n", val);
	return 0;
}

float pop()
{
	if (stack_pointer <= 0)
		printf("Stack is empty, can't pop anything!");
	else
		return stack[--stack_pointer];
}

void push(float c)
{
	if (stack_pointer >= MAX_ARRAY)
		printf("Stack is full, can't push anything!");
	else
		stack[stack_pointer++] = c;
}

