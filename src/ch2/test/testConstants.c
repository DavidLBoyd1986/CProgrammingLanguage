#include <stdlib.h>
#include <stdio.h>

#define BELL '\007' /* ASCI bell character */
#define VTAB '\013'

#define HBELL '\xb' /* ASCI bell character */
#define HVTAB '\xf'

const int testBinary = 0b1101101101;

const int testOctal = 07757;

const int testHex = 0xff;

int main(){

	char testChar = 'x';
	
	printf("\nchar example: %c\n", testChar);
	
	const char testCharConst = 'x';

	printf("\nchar example: %c\n", testCharConst);

	printf("\nTestBinary: %i\n", testBinary);

	printf("\ntestOctal: %i\n", testOctal);

	printf("\ntestHex: %i\n", testHex);

	const int testInt = 123456UL;
	printf("\n%d\n", testInt);
	
	printf("\n%d\n", 1234L);

	const int testUnsigned = 13245U;

	const int testLong = 13245L;

	const int testUnsignedLong = 0xFFUL;

	printf("\nSuffix Unsigned Contant: %i\n", testUnsigned);
	printf("\nSuffix Long Contant: %i\n", testLong);
	printf("\nSuffix UnsignedLong Contant: %i\n", testUnsignedLong);
	
	printf("\nTesting Trailing Suffixes:\n");
	int testTrailing = 1234U - 12345U;
	printf("Test Trailing Suffix: %i", testTrailing);

	printf("\nChar Constants:\n");
	char testZero = '\0';

	printf("\ntest Zero Char: %c\n", testZero);

	printf("\nDefined byte-sized octal: %c", BELL);
	printf("\nDefined byte-sized octal: %c", VTAB);
	printf("\nDefined byte-sized octal: %c", HBELL);
	printf("\nDefined byte-sized octal: %c", HVTAB);

	const char verticalTab = '\013';
	printf("\nPrints a Vertical Tab Character: %c", verticalTab);

	printf("\n");

	return 1;
}
