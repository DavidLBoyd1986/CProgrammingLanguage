#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

void main(){

	printf("Signed Char Max is: %d\n", SCHAR_MAX);
	printf("Signed Char Min is: %d\n", SCHAR_MIN);

	printf("Unsigned Char Max is: %d\n", UCHAR_MAX);
	printf("USigned Char Min is: %d\n", 0); //UCHAR_MIN is not set in the linits.h file, but it says it is 0

	printf("Char Max is: %d\n", CHAR_MAX);
	printf("Char Min is: %d\n", CHAR_MIN);

	printf("Signed Short int Max: %d\n", SHRT_MAX);
	printf("Signed Short int Min: %d\n", SHRT_MIN);
	
	printf("Unsigned Short int Max: %d\n", USHRT_MAX);
	printf("Unsigned Short int Min: %d\n", 0); //USHRT_MIN is not defined in the limits.h file, but it says it is 0
	printf("Signed int Max: %d\n", INT_MAX);
	printf("Signed int Min: %d\n", INT_MIN);

	printf("Unsigned int Max: %d\n", UINT_MAX) //This isn't working;
	printf("UnSigned int Min: %d\n", 0); //UINT_MIN is not defined but in the limits.h file, but it says that it is 0
}
