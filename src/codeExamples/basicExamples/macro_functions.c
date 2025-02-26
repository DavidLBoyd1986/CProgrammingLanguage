#include <stdio.h>

#define SWAP(t, x, y) {t temp = x; x = y; y = temp;}
	// IMPORTANT:
	// The macro needs to be in the braces so it is in a function.
	// This is required so the 't' type passed in is local to the function call
	// If it wasn't local to a function call, a type error would occur for chaing the type of 'temp'
	// Remove braces to see this.

int main()
{
	int q = 5;
	int w = 22;
	SWAP(int, q, w);
	printf("\nq was 5, now q = %i\n", q);
	printf("\nw was 22, now w = %i\n", w);

	char a = 'a';
	char z = 'z';
	SWAP(char, a, z);
	printf("\na was a, now a = %c\n", a);
	printf("\nz was z, now z = %c\n", z);
}
