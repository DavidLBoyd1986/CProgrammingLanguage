#include <stdio.h>

int rightrot(int x, int n);

int main() {

	int x = 0b1101101111101;
	int n = 5;
	int output;

	output = rightrot(x, n);

	printf("\nx = %b\n", x);
	printf("n = %i\n", n);
	printf("output = %b\n", output);

}

int rightrot(int x, int n) {

	int xCopy = x;
	int rotatedBits = 0;
	int bitMask = ~(~0 << n);

	// Get rotatedBits 
	rotatedBits = xCopy & bitMask;
	// Shift xCopy to remove rotatedBits
	xCopy = xCopy >> n;

	// Get binary length of xCopy
	int binaryLen = 1;
	int xCopyTemp = xCopy;
	while (xCopyTemp > 1) {
		xCopyTemp = xCopyTemp / 2;
		binaryLen++;
	}
	
	// Left Shift rotatedBits and add xCopy to the right
	rotatedBits = rotatedBits << binaryLen;
	rotatedBits = rotatedBits | xCopy;

	return rotatedBits;
}
