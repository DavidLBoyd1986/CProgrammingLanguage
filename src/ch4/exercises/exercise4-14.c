#include <stdio.h>

#define SWAP(t, x, y) if (sizeof((x)) == sizeof(t) && sizeof((y)) == sizeof(t)) \
	{t temp = x; x = y; y = temp;}

int main()
{
	char a = 'a';
	char z = 'z';
	SWAP(char, a, z);
	printf("\na was a, now a = %c\n", a);
	printf("\nz was z, now z = %c\n", z);

	int q = 5;
	int w = 22;
	SWAP(int, q, w);
	printf("\nq was 5, now q = %i\n", q);
	printf("\nw was 22, now w = %i\n", w);
}
