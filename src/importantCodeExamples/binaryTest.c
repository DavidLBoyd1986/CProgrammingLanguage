#include <stdio.h>

int testBinary = 0b11011001;

int testOctal = 07757;

int testHex = 0xff;

int main() {

	printf("Print int of testBinary: %i\n", testBinary);
	printf("Print int of testOctal: %i\n", testOctal);
	printf("Print int of testHex: %i\n", testHex);

	printf("Testing Binary Operators");

	// Bitwise Operators
	// &  = bitwise AND
	// |  = bitwise inclusive OR
	// ^  = bitwise exclusive OR
	// << = Left Shift
	// >> = Right Shift
	// ~  = One's Complement (unary)
	
	int test1100 = 0b1100;
	printf("Print int of test1100: %i\n", test1100);

	int testAnd = test1100 & 0011;
	printf("Value of above & 0011: %i\n", testAnd);
	
	printf("Print binary of test1100: %b\n", test1100);
	printf("Print binary of bitwise AND - valueAbove & 0011: %b\n", testAnd);

}
