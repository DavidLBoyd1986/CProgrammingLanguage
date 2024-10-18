#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main(){

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

	printf("Float Max: %f\n", FLT_MAX);
	printf("Float Min: %f\n\n", FLT_MIN);
	
	printf("Double Max: %lf\n", DBL_MAX);
	printf("Double Min: %lf\n\n", DBL_MIN);

	printf("Long Double Max: is commented out, it is insanely long\n");	
//	printf("Long Double Max: %Lf\n", LDBL_MAX);
	printf("Long Double Min: %Lf\n\n", LDBL_MIN);

	return 0;
}
