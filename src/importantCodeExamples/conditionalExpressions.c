#include <stdio.h>

int main() {

	int x = 5;
	int y = 21;
	int test = -5;
	int result = 0;

	// Below is a conditional expression written succintely and not as an if/else statement
	result = (test > 0) ? x : y;

	// (test > 0) = The if statement
	// ? x : y; = '?' separates the assignments from the conditional
	// 	x is assigned if was true, y if was false

	printf("\nresult = %i\n", result);

	return 1;
}
