#include <stdio.h>
#include <string.h>

#define TRUE 0
#define FALSE 1

int setbits(int x, int p, int n, int y);


int main() {

	int output;

	int test_x = 0b11100011;
	int position = 5;
	int numOfBitChanged = 3;
	int test_y = 0b111000001;

	output = setbits(test_x, position, numOfBitChanged, test_y);

	printf("\nPosition = %i", position);
	printf("\nNumber of bits to change = %i", numOfBitChanged);
	printf("\ny = %b", test_y);
	printf("\nOriginal = %b\n", test_x);
	printf("Result =   %b\n", output);
}

// Replace n bits in x, starting at p (from right), with n bits off right of y
// x = binary to change
// p = position to start change at, position from the right with right most bit being 0
// n = number of bits to change, and num of bits to take from rightmost bits of y
// y = int binary to take bits from changed values
int setbits(int x, int p, int n, int y) {

	int xCopy = x;
	int saveRightBits = TRUE;
	int bitMask = 0;
	int copiedRightBits = 0;
	int copiedBits = 0;

	printf("\nOriginal xCopy = %b\n", xCopy);
	
	// Verify n <= p
	if (n > p) {
		saveRightBits = FALSE;
	}

	// If n == p, can skip saving right bits
	if (n == p) {
		saveRightBits = FALSE;
	}

	// Save Bits to the right of the word to be copied
	if (saveRightBits == TRUE) {
		// Create bitmask the length of bits to copy, and change them all to 1s
		bitMask = ~(~bitMask << p+1-n);
		// Copy the bits by performing an & against xCopy and the all 1 bitMask
		copiedRightBits = xCopy & bitMask;
		printf("\ncopiedRightBits = %b", copiedRightBits);
		// Remove copied bits from xCopy
		xCopy = xCopy >> p+1-n;
	}

	// Copy the Bits from the end of y
	bitMask = ~(~bitMask << n);
	// Copy the bits by performing an & against y and the all 1 bitMask
	copiedBits = y & bitMask;
	printf("\ncopiedBits = %b\n", copiedBits);

	// Right Shift xCopy to remove the bits that will be changed
	xCopy = xCopy >> n;

	// Add the copiedBits back onto xCopy
	xCopy = xCopy << n;
	xCopy = xCopy | copiedBits;
	printf("\nxCopy - copiedBits added back = %b\n", xCopy);

	// Add the copiedRightBits back onto xCopy
	xCopy = xCopy << p+1-n;
	xCopy = xCopy | copiedRightBits;
	printf("xCopy - copiedRightBits added back = %b\n", xCopy);

	return xCopy;
}

