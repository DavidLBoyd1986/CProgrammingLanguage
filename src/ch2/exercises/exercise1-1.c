#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int test_int = 1;

int test_int_max = 2147483645;
int test_int_min = -2147483645;

// Can also be written "short test_short_max = ########"

short int test_short_int_max = 32765;
short int test_short_int_min = -32765;


void main(){

	printf("\nStops at 'int' max");	
	while (test_int_max >= 0){
		printf("%d\n", test_int_max);
		test_int_max++;
	}
	
	printf("\nStops at 'int' min");	
	while (test_int_min <= 0){
		printf("%d\n", test_int_min);
		test_int_min--;
	}
	
	printf("\nStops at 'short int' max");	
	while (test_short_int_max >= 0){
		printf("%d\n", test_short_int_max);
		test_short_int_max++;
	}
	
	printf("\nStops at 'short int' max");	
	while (test_short_int_min <= 0){
		printf("%d\n", test_short_int_min);
		test_short_int_min--;
	}
}
