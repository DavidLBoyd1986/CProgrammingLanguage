#include <stdio.h>

int main()
{
	int test_int_var = 87;
	int *ptiv = &test_int_var;

	printf("\ntest_int_var: %i\n", test_int_var);
	printf("\nAddress of test_int_var: %i\n", &test_int_var);
	printf("\nde-referenced pointer to print test_int_var: %i\n\n", *ptiv);

	int x = 1, y = 2, z[10];
	int *ip;	/* ip is a pointer to int */

	printf("x = %i\n", x);
	printf("y = %i\n\n", y);
	ip = &x;	/* ip now points to x */
	printf("'ip = &x' so ip = %i\n\n", ip);

	y = *ip;		/* y is now 1 */
	printf("y = %i : y after de-referencing ip (y = *ip)\n\n", y);

	*ip = 0;	/* x is now 0 */
	printf("x = %i : x after de-referencing ip (*ip = 0)\n\n", x);

	*ip = *ip + 10;
	printf("x = %i : x after *ip = *ip + 10\n", x);

	*ip = *ip + 10;
	printf("x = %i : x after *ip = *ip + 10\n\n", x);

	ip = &z[0];	/* ip now points to z[0] */
	printf("ip = %i : ip after assigning &z[0]\n\n", ip);

}
