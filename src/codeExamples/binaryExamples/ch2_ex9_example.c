#include <stdio.h>

int bitcount(unsigned x);

int main()
{
	int test_bin_one = 0b1101;
	int test_bin_two = 0b11010010;
	int test_bin_three = 0b1101110111101;

	printf("\ntest_bin_one = %b\n", test_bin_one);
	printf("test_bin_two = %b\n", test_bin_two);
	printf("test_bin_three = %b\n", test_bin_three);

	// Begin Example

	/*
	* These delete the rightmost 1-bit in the binary.
	* This is because the 'x - 1' will move the rightmost 1-bit to the rightmost spot
	* This means neither the original rightmost 1-bit or the new one will match '&'
	* with the original x value.
	*/

	int test_val_one = test_bin_one & (test_bin_one - 1);
	int test_val_two = test_bin_two & (test_bin_two - 1);
	int test_val_three = test_bin_three & (test_bin_three - 1);	
	printf("\nexample_bin_one = %b\n", test_val_one);
	printf("example_bin_two = %b\n", test_val_two);
	printf("example_bin_three = %b\n", test_val_three);

	// End Example

	int test_bin_one_answer = bitcount(test_bin_one);
	int test_bin_two_answer = bitcount(test_bin_two);
	int test_bin_three_answer = bitcount(test_bin_three);
	printf("\ntest_bin_one_answer: %i\n", test_bin_one_answer);
	printf("test_bin_two_answer: %i\n", test_bin_two_answer);
	printf("test_bin_three_answer: %i\n\n", test_bin_three_answer);
}

// Count 1 bits in binary
int bitcount(unsigned x)
{
	int b;
	// Works by removing all the 1-bits, loop ends when all 1-bits are removed and the int is 0
	for (b = 0; x != 0; x &= (x - 1)) {
		b++;
	}
	return b;
}

// Count 1 bits in binary
int bitcount_og(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1) {
		if (x & 01)
			b++;
	}
	return b;
}
