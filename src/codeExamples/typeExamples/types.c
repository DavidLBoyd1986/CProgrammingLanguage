#include <stdio.h>
#include <string.h>

int main(){
	
	// Chars
	char testChar = 'g';
	signed char testSignedChar = -64;
	unsigned char testUnsignedChar = 64;

	// Int
	int testInt = 4567000;
	signed int testSignedInt = -3456000;
	unsigned int testUnsignedInt = 45678000;

	// Short
	short testShort = 25000;
	signed short testSignedShort = -28000;
	unsigned short testUnsignedShort = 55000;

	// Long
	long testLong = 987654321000;
	signed long testSignedLong = -98765432100000;
	unsigned long testUnsignedLong = 987654321987654321;

	// Long Long
	long long testLongLong = 1122334455667788990;
	signed long long testSignedLongLong = -1234567890;
	unsigned long long testUnsignedLongLong = 1234567890;

	// Double
	double testDouble = 65438.123;
	long double testLongDouble = 1234567.89;
	long double testLongDoubleTwo = 987653.123;
	
	// Float
	float testFloat = 9.54321;

	// Boolean
	_Bool testTrue = 33;
	_Bool testFalse = 0;

	// Print Chars
	printf("\nTest Char: %c\n", testChar);
	printf("\nTest Signed Char: %c\n", testSignedChar);
	printf("\nTest Unsigned Char: %c\n", testUnsignedChar);

	// Print Ints
	printf("\nTest Int: %i\n", testInt);
	printf("\nTest Signed Int: %d\n", testSignedInt);
	printf("\nTest Unsigned Int: %u\n", testUnsignedInt);

	// Print Shorts
	printf("\nTest Short: %i\n", testShort);
	printf("\nTest Signed Short: %i\n", testSignedShort);
	printf("\nTest Unsigned Short: %i\n", testUnsignedShort);

	// Print Longs
	printf("\nTest Long: %li\n", testLong);
	printf("\nTest Signed Long: %lli\n", testSignedLong);
	printf("\nTest Unsigned Long: %lu\n", testUnsignedLong);

	// Print Long Long
	printf("\nTest Long Long: %lli\n", testLongLong);
	printf("\nTest Signed Long Long: %lli\n", testSignedLongLong);
	printf("\nTest Unsigned Long Long: %llu\n", testUnsignedLongLong);

	// Print Doubles
	printf("\nTest Double: %lf\n", testDouble);
	printf("\nTest Long Double: %Lf\n", testLongDouble);
	printf("\nTest Long Double Two: %Lf\n", testLongDoubleTwo);

	// Print Floats
	printf("\nTest Float: %.3f\n", testFloat);
	printf("\nTest Float with precision: %g\n", testFloat);

	// Print Booleans
	if (testTrue) {
		printf("\ntestTrue is true\n");
	}

	if (testFalse) {
		printf("\ntestFalse is true\n");
	}

	return 1;
}
