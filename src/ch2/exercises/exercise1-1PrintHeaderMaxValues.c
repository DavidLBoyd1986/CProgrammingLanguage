#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>


int test_int_max = 2147483645;
int test_int_min = -2147483645;

// Can also be written "short test_short_max = ########"
short int test_short_int_max = 32765;
short test_short_int_min = -32765;

// Can also be written "long test_long_max = ########"
long int test_long_int_max = 2147483645;
long test_long_int_min = -2147483645;

// Can also be written "signed test_signed_int_max = ########"
signed int test_signed_int_max = 2147483645;
signed int test_signed_int_min = -2147483645;

// Can also be written "long test_unsigned_int_max = ########"
unsigned int test_unsigned_int_max = 2147483645;
unsigned int test_unsigned_int_min = -2147483645;

void main(){

	// Prints the min and max for int
	printf("\nStops at 'int' max\n");	
	while (test_int_max >= 0){
		printf("%d\n", test_int_max);
		test_int_max++;
	}
	
	printf("\nStops at 'int' min\n");	
	while (test_int_min <= 0){
		printf("%d\n", test_int_min);
		test_int_min--;
	}
	
	printf("\nStops at 'short int' max\n");	
	while (test_short_int_max >= 0){
		printf("%d\n", test_short_int_max);
		test_short_int_max++;
	}
	
	printf("\nStops at 'short int' max\n");	
	while (test_short_int_min <= 0){
		printf("%d\n", test_short_int_min);
		test_short_int_min--;
	}
	
	int n = 0;
	printf("\nLoops around after 'long int' max to 'long int' min\n");	
	while (n < 8){
		printf("%d\n", test_long_int_max);
		test_long_int_max++;
		n++;
	}

	n = 0;
	printf("\nLoops around after 'long int' min to 'log int' min\n");	
	while (n < 8){
		printf("%d\n", test_long_int_min);
		test_long_int_min--;
		n++;
	}

	// signed and unsigned int
	n = 0;
	printf("\nStops at 'signed int' min\n");	
	while (n < 8){
		printf("%d\n", test_signed_int_min);
		test_signed_int_min--;
		n++;
	}

	n = 0;
	printf("\nStops at 'unsigned int' max\n");	
	while (n < 8){
		printf("%d\n", test_unsigned_int_max);
		test_unsigned_int_max++;
		n++;
	}

	n = 0;
	printf("\nStopa at 'char' max\n");
	while (n < 300){
		char c = n;
		printf("%i = %c, ", n, c);
		n++;
	}
	printf("\nChar seems to be 256 bits it loops back after that.\n");

}
