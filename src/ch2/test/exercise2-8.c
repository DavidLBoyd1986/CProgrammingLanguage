#include <stdio.h>

int rightrot(int x, int n);

int main() {

	int x = 0b11011011;
	int n = 4;
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

	rotatedBits = xCopy & bitMask;
	printf("\nrotatedBits = %b\n", rotatedBits);

	xCopy = xCopy >> n;

	printf("\nxCopy = %b\n", xCopy);

	int binaryLen = 1;
	int xCopyTemp = xCopy;
	while (xCopyTemp > 1) {
		xCopyTemp = xCopyTemp / 2;
		binaryLen++;
	}
	printf("\nbinaryLen = %i\n", binaryLen);
	rotatedBits = rotatedBits << binaryLen;
	rotatedBits = rotatedBits | xCopy;

	return rotatedBits;
}
