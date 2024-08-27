#include <stdio.h>

#define TRUE 0
#define FALSE 1

int invert(int x, int p, int n);


int main(){

	int binaryTest = 0b10101110;
	int position = 7;
	int numOfBitChanged = 2;

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
	int output = 0;

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
		// Create bits the length of bits to copy, and change them to all 1s
		bitMask = ~(~bitMask << p+1-n);
		// Copy the bits by performing an & against xCopy and the all 1 rBits
		copiedRightBits = xCopy & bitMask;
		printf("\nrBits = %b\n", copiedRightBits);
	}

	output = copiedRightBits;

	return output;
}
