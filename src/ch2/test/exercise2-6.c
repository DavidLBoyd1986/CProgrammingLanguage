#include <stdio.h>
#include <string.h>

int setbits(int x, int p, int n, int y);


int main() {

	int output;

	// Binary Value = 11110001
	int test_x = 0b100000000;
	int test_y = 0b111000111;

	output = setbits(test_x, 3, 9, test_y);

}


// input x, change bits starting at position p.
// change base on input y, righmost bits for n.
// x = input & output.
// p = position in x to start changing bits - Need to decide if pos starts from left or right
// n = number of bits to change, and take from rightmost bits of p
// y = int binary to take bits from changed values

int setbits(int x, int p, int n, int y) {

	int binaryResult = x;

	// Right Shift x by p, to remove current bits
	binaryResult = binaryResult >> p;
	
	// For loop:
	//  - Check last bit in binaryTwo (y)
	//  - Save it in tempBinary
	//  - Right shift binaryTwo (y) to move to next bit.
	//  - Left shift binaryOne(x)
	//  - Change last bit to match bit in binaryOne (x) checked in binaryTwo (y).
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

int setbitstest(int x, int p, int n, int y) {

	int binaryOne = 0b11101011;
	int binaryTwo = 0b11110111;

	int binaryResult = binaryOne;

	// Right Shift x by p, to remove current bits
	binaryResult = binaryResult >> 3;
	
	// For loop:
	//  - Check last bit in binaryTwo (y)
	//  - Save it in tempBinary
	//  - Right shift binaryTwo (y) to move to next bit.
	//  - Left shift binaryOne(x)
	//  - Change last bit to match bit in binaryOne (x) checked in binaryTwo (y).
        for (int i = 0; i < n; i++) {
		// save last bit of y, and right shift to move to next bit
		int tempBit = binaryTwo & 1;
		binaryTwo = binaryTwo >> 1;
		// left shift x, and set new last bit to match saved bit from y
		binaryResult = binaryResult << 1;
		binaryResult = binaryResult | tempBit;
	}	
	
	printf("\nFinal binaryResult = %b\n", binaryResult);
	
	return 1;
}
