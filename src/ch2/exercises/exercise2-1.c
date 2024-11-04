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

int main()
{
// Printing values for Max and Min of char types
///-------------------------------------------------------------------

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

//--------------------------------------------------------------------------
// Print Max and Min Type variables
	printf("\nChar seems to be 256 bits it loops back after that.\n");

        printf("\n\n");
        printf("Signed Char Max is: %d\n", SCHAR_MAX);
        printf("Signed Char Min is: %d\n\n", SCHAR_MIN);

        printf("Unsigned Char Max is: %u\n", UCHAR_MAX);
        printf("USigned Char Min is: %u\n\n", 0); //UCHAR_MIN is not set in the linits.h file, but it says it is 0
        printf("Signed Short int Max: %d\n", SHRT_MAX);
        printf("Signed Short int Min: %d\n\n", SHRT_MIN);

        printf("Unsigned Short int Max: %u\n", USHRT_MAX);
        printf("Unsigned Short int Min: %u\n\n", 0); //USHRT_MIN is not defined in the limits.h file, but it says it is 0
        printf("Signed int Max: %d\n", INT_MAX);
        printf("Signed int Min: %d\n\n", INT_MIN);

        printf("Unsigned int Max: %u\n", UINT_MAX);
        printf("UnSigned int Min: %u\n\n", 0); //UINT_MIN is not defined but in the limits.h file, but it says that it is 0
        printf("Signed long int Max: %ld\n", LONG_MAX);
        printf("Signed long int Min: %ld\n\n", LONG_MIN);

        printf("Unsigned long int Max: %lu\n", ULONG_MAX);
        printf("Unsigned long int Min: %lu\n\n", 0); //ULONG_MIN is not defined but in the limits.h file, but it says that it is 0
        printf("Signed long long int Max: %lli\n", LLONG_MAX);
        printf("Signed long long int Min: %lld\n\n", LLONG_MIN);

        printf("Unsigned long long int Max: %llu\n", ULLONG_MAX);
        printf("Unsigned long long int Min: %d\n\n", 0); //ULLONG_MIN is not defined but in the limits.h file, but it says that it is 0

	printf("float Max : Scientific Notation output = %.10e\n", FLT_MAX);
	printf("float Min : Scientific Notation output = %.10e\n", FLT_MIN);
	printf("float Max : Float output = %f\n", FLT_MAX);
	printf("float Min : Float output = %f\n", FLT_MIN);
///-----------------------------------------------------------------------
	return 0;
}

