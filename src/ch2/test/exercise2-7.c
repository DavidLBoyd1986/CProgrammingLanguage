#include <stdio.h>

int invert(int x, int p, int n);

#define TRUE 0
#define FALSE 1

int main(){

	int binaryOne = 0b11111010;
	int position = 7;
	int numOfBitChanged = 2;

	int result;
	result = invert(binaryOne, position, numOfBitChanged);

	int testOne = 0b1110;
	int testTwo = 0b0000;
	int answer = testOne | testTwo;
	printf("\nAnswer = %b\n", answer);
	//printf("\nResult = %b\n\n", result);
}

// x = binary to change
// p = position to start change
// n = num of bits to change. 
int invert(int x, int p, int n){

	printf("\nx = %b\n", x);
	printf("\np = %i\n", p);
	printf("\nn = %i\n", n);

	int xCopy = x;
	int tempBit;
	int saveRightBits = TRUE;
	int output = 0;

	// Verify n <= p
	if (n > p) {
		printf("n can NOT be greater than p, \
		  as p is the maximum number of bits that can be copied");
		return 1;
	}

	// If x == p, can skip saving right bits.
	if (n == p) {
		saveRightBits = FALSE;
	}

	if (saveRightBits == TRUE) {

		int xCopyRightBits = xCopy;
		int xCopyTest = xCopy;
		int xRightBits = 0;

		// OLD METHOD THAT DOES NOT WORK
		for (int i = 0; i < p-n; i++) {
			tempBit = xCopyRightBits & 1;
			printf("\nTemp Bit = %b\n", tempBit);
			xCopyRightBits = xCopyRightBits >> 1;
			xRightBits = xRightBits | tempBit;
			output = xRightBits & tempBit;
			xRightBits = xRightBits << 1;
		}
		// THIS IS HOW YOU DO IT!!!!!!!!!!!!!!!!!!!!!!!!!!
		printf("\nxRightBits = %b\n", xRightBits);
		printf("\nTesting copying bits\n");
		int rBits = 0;
		rBits = ~(~rBits << p+1-n);
		printf("\nrBits = %b\n", rBits);
		printf("\nCopyRightBits = %b\n", xCopyTest);
		int copiedRightBits = xCopyTest & rBits;
		printf("\ncopiedRightBits = %b\n", copiedRightBits);
	}

	// Create int that starts at end of bits to copy
	xCopy = (xCopy >> (p+1-n));
	int xCopiedBits = 0b0;

	// Copy the bits
	// FLIP THE BITS IN THE SECTION THEY NEED FLIPPED
	for (int i = 0; i < n; i++) {
		tempBit = xCopy & 1;
		printf("\nTemp Bit = %b\n", tempBit);
		xCopy = xCopy >> 1;
		xCopiedBits = xCopiedBits | tempBit;
		xCopiedBits = xCopiedBits << 1;
	}
	
	printf("\nxCopiedBits = %b\n", xCopiedBits);
	
	// Invert xCopiedBits
	xCopiedBits = ~xCopiedBits;

	// Add xCopiedBits to output;
	for (int i = 0; i < n; i++) {
		tempBit = xCopiedBits & 1;
		output = xCopiedBits | tempBit;
		xCopiedBits = xCopiedBits >> 1;
	}
	printf("\noutput = %b\n", output);
	// Combine all the Bits to return x with the xCopiedBits flipped.
	
	return output;

}
