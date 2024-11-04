#include <stdio.h>

#define TRUE 0
#define FALSE 1

int invert(int x, int p, int n);

int main()
{
	int binaryTest = 0b110000101110;
	int position = 8;
	int numOfBitChanged = 6;
	int result;

	int binaryTestOne = 0b110000101110;
	int positionOne = 8;
	int numOfBitChangedOne = 9;
	int resultOne;

	result = invert(binaryTest, position, numOfBitChanged);

	printf("\nPosition = %i", position);
	printf("\nNumber of bits to change = %i", numOfBitChanged);
	printf("\nOriginalt = %b\n", binaryTest);
	printf("Result =    %b\n\n", result);

	resultOne = invert(binaryTestOne, positionOne, numOfBitChangedOne);

	printf("\nPosition = %i", positionOne);
	printf("\nNumber of bits to change = %i", numOfBitChangedOne);
	printf("\nOriginalt = %b\n", binaryTestOne);
	printf("Result =    %b\n\n", resultOne);
	return 0;
}

/*
* x = binary to change
* p = position to start change
* n = num of bits to change.
*/
int invert(int x, int p, int n)
{
	int xCopy = x;
	int saveRightBits = TRUE;
	int bitMask = 0;
	int copiedRightBits = 0;
	int copiedInvertedBits = 0;
	int output = 0;

	// Verify n <= p
	if (n > p) {
		printf("\n\nERROR - n can NOT be greater than p, " \
		       "p is the max number of bits that can be copied.\n\n");
		return 1;
	}

	// If n == p, can skip saving right bits
	if (n == p) {
		saveRightBits = FALSE;
	}

	// Save Bits to the right of the word to be copied
	if (saveRightBits == TRUE) {
		// Create bitmask the length of bits to copy, and change them to all 1s
		bitMask = ~(~bitMask << p+1-n);
		// Copy the bits by performing an & against xCopy and the all 1 rBits
		copiedRightBits = xCopy & bitMask;
		// Remove copied bits from xCopy
		xCopy = xCopy >> p+1-n;
	}

	// Copy the Bits and Invert them - SAME METHOD AS ABOVE
	
	// Create the bitMask
	bitMask = 0;
	bitMask = ~(~bitMask << n);
	// Copy the bits, and then invert them
	copiedInvertedBits = ~xCopy & bitMask;
	// Remove copied bits from xCopy
	xCopy = xCopy >> n;

	// Add the copiedInvertedBits back onto xCopy
	xCopy = xCopy << n;
	xCopy = xCopy | copiedInvertedBits;

	// Add the copiedRightBits back onto xCopy
	xCopy = xCopy << p+1-n;
	xCopy = xCopy | copiedRightBits;

	output = xCopy;

	return output;
}
