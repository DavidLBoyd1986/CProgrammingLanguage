#include <stdlib.h>
#include <stdio.h>

int increment_counter(int incr)
{
	static int counter = 0;

	counter = counter + incr;

	printf("Value of counter INSIDE function: %d\n", counter);

	return counter;
}

int main()
{
	int counter = increment_counter(10);
	counter = counter + 100;

	printf("Value of counter OUTSIDE function: %d\n", counter);

	counter = increment_counter(10);

	return EXIT_SUCCESS;
}
