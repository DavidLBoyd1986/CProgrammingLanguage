#include <stdio.h>

int power(int b, int n);

main(){
	int base, n, answer;
	/* base = 6;
	n = 3; */
	answer = power(6, 10);
	printf("%d\n", answer);
}

/* power: raise base to n-th power; n>=0; version 2 */
int power(int base, int n)
{
	int p;

	for (p = 1; n > 0; --n)
		p = p * base;
	return p;
}
