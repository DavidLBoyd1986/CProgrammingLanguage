#include <stdlib.h>
#include <stdio.h>

int main(){
	const long int testLong = 124356789;

	printf("\nlong example: %i\n", testLong);

	testLong = 555566677;
	printf("\nlong overwrite: %i\n", testLong);
	
	return 1;
}
