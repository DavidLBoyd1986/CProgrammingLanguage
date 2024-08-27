#include <stdio.h>
#include <string.h>

int setbits(int x, int p, int n, int y);


int main() {

	int output;

	// Binary Value = 11110001
	int test_x = 0b100000000;
	int test_y = 0b111000111;

	printf("\n x = %b\n", test_x);
	printf("\n p = %i\n", 5);
	printf("\n n = %i\n", 6);
	printf("\n y = %b\n", test_y);
	output = setbits(test_x, 5, 6, test_y);

	printf("\noutput = %b\n", output);
}


// input x, change bits starting at position p.
// change base on input y, righmost bits for n.
// x = input & output.
// p = position from the right in x to start changing bits
// n = number of bits to change, and take from rightmost bits of p
// y = int binary to take bits from changed values

int setbits(int x, int p, int n, int y) {

	int binaryResult = x;

	// Right Shift x by p, to remove current bits
	binaryResult = binaryResult >> p;
	
        for (int i = 0; i < n; i++) {
		// save last bit of y, and right shift to move to next bit
		int tempBit = y & 1;
		y = y >> 1;
		// left shift x, and set new last bit to match saved bit from y
		binaryResult = binaryResult << 1;
		binaryResult = binaryResult | tempBit;
	}	
	
	printf("\nFinal binaryResult = %b\n", binaryResult);
	
	return binaryResult;
}

