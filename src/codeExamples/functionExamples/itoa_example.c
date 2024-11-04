#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void reverse(char s[]);

/* itoa can't handle the largest negative number because two's complement inverses the binary of the number, and adds one. Once the negative sign is removed in itoa, it ends up as INT_MAX + 1.
* 
* The fix is to check if the int value == INT_MIN and handle that special case.
*
*/

int main()
{
	int test_int = 54728;
	int test_int_max = 2147483647;;
	int test_int_max_plus_one = 2147483648;;
	int test_int_min = -2147483648;
	int test_int_min_two = -2147483648;
	char test_array[100];
	char test_array_int_max[100];
	char test_array_three[100];
	char test_array_int_min[100];

	printf("\nitoa test output:\n");
	printf("-----------------\n");
	printf("Binary of int max = %b\n", test_int_max);
	printf("Binary of int max + 1 = %b\n", test_int_max_plus_one);
	printf("Int of int max + 1 = %i\n\n", test_int_max_plus_one);

	printf("Binary of int min = %b\n", test_int_min);
	printf("Int of int min = %i\n\n", test_int_min);
	test_int_min_two = -test_int_min_two;
	printf("Binary of inverted int min = %b\n", test_int_min_two);
	printf("Int of inverted int min = %i\n\n", test_int_min_two);
	int test_int_max_copy = test_int_max;
	test_int_max_copy = test_int_max_copy / 10;
	printf("Binary of divided int max = %b\n", test_int_max_copy);
	printf("Int of divided int max = %i\n\n", test_int_max_copy);

	int divided_int_max_min = test_int_min_two / 10;
	printf("Binary of divided inverted int max min = %b\n", divided_int_max_min);
	printf("Int of divided inverted int max min = %i\n", divided_int_max_min);

	itoa(test_int, test_array);
	printf("\ntest_array = %s\n", test_array);
	
	itoa(test_int_max, test_array_int_max);
	printf("\ntest_array_int_max = %s\n", test_array_int_max);
	
	itoa(test_int_min, test_array_int_min);
	printf("\ntest_array_int_min = %s\n\n", test_array_int_min);

	return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
	int i, sign;
	i = 0;
	// test if it's an int_min edge case
	if (n == INT_MIN) {
		s[i++] = '8';
		n /= 10;
	}
	if ((sign = n) < 0)	/* record sign */
		n = -n;		/* make n positive */
	do {		/* generate digits in reverse order */
		s[i++] = n % 10 + '0';	/* get next digit, the '0' makes the int a char */
	} while ((n /= 10) > 0);	/* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
