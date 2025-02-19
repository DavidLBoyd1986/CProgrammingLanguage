#include <string.h>
#include <stdio.h>

int main(){

	char testStringDash[100];
	testStringDash[0] = '-';
	printf("\ntestStringDash = %s\n", testStringDash);

	char testString[100] = "Hello World";
	int testStringLength;
	printf("\nString Output: %s\n", testString);
	testStringLength = strlen(testString);
	printf("\nString Length: %i\n", testStringLength);

	char testCharInt = 122;
	printf("\nChar Int Example: %c\n", testCharInt);

	char testCharValue = 't';
	printf("\nChar Value Example: %c\n", testCharValue);
	return 0;

}
