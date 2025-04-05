#include <stdlib.h>
#include <stdio.h>

int* increment_counter(int incr)
{
	static int counter = 0; //static is very IMPORTANT
	// If not static it will get a new address every function call
	// So, returning &counter will return a new address each call
	// With static &counter returns same address every call
	// static maintains the same 'counter' variable 
	// and memory address with each function call.

	counter = counter + incr;

	printf("Value of counter INSIDE function: %d\n", counter);

	return &counter;
}

int main()
{
	int *counter_ptr = increment_counter(10);
	*counter_ptr = *counter_ptr + 100;

	printf("Value of counter OUTSIDE function: %d\n", *counter_ptr);

	counter_ptr = increment_counter(10);

	return EXIT_SUCCESS;
}
