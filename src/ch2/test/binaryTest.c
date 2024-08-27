#include <stdio.h>

#define TRUE 0
#define FALSE 1

int invert(int x, int p, int n);


int main(){

	int binaryTest = 0b110110101110;
	int position = 7;
	int numOfBitChanged = 4;

	int result;
	result = invert(binaryTest, position, numOfBitChanged);
	printf("\nbinaryTest = %b\n", binaryTest);
	printf("\nResult = %b\n\n", result);
}

// x = binary to change
// p = position to start change
// n = num of bits to change. 
int invert(int x, int p, int n){

	int xCopy = x;
	//int tempBit;
	int saveRightBits = TRUE;
	int bitMask = 0;
	int copiedRightBits = 0;
	int copiedInvertedBits = 0;
	int copiedLeftBits = 0;
	int output = 0;

	printf("\nOrifinal xCopy = %b\n", xCopy);

	// Verify n <= p
	if (n > p) {
		printf("n can NOT be greater than p, \
		  as p is the maximum number of bits that can be copied.");
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
		printf("\nrBits = %b\n", copiedRightBits);
		// Remove copied bits from xCopy
		xCopy = xCopy >> p+1-n;
	}

	// Copy the Bits and Invert them - SAME METHOD AS ABOVE
	
	// Create the bitMask
	bitMask = 0;
	printf("\nbitMask = %b\n", bitMask);
	printf("\nShortened xCopy = %b\n", xCopy);
	// Copy the bits, and then invert them
	copiedInvertedBits = ~xCopy | bitMask;
	printf("\ncopiedInvertedBits = %b\n", copiedInvertedBits);
	// Actually, just need to invert the bits in xCopy
	xCopy = ~xCopy & bitMask; //TODO - this shortens the left side of the bit array
	printf("\nChanged xCopy = %b\n", xCopy);

	// Add the copiedRightBits back on to xCopy
	
	// LeftShift xCopy
	xCopy = xCopy << p+1-n;
	printf("left Shifted xCopy = %b\n", xCopy);

	xCopy = xCopy | copiedRightBits; 
	printf("final xCopy = %b\n", xCopy);

	output = xCopy;

	return output;
}
