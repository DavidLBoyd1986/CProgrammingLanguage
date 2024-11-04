#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[], int l);
void reverse(char s[]);

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

	printf("\nitoa tests:\n");
	printf("-----------------\n");
	printf("test_array input = %i\n", test_int);
	printf("test_array_int_max input = %i\n", test_int_max);
	printf("test_array_int_min input = %i\n", test_int_min);

	itoa(test_int, test_array, 9);
	printf("\ntest_array = %s\n", test_array);
	
	itoa(test_int_max, test_array_int_max, 18);
	printf("\ntest_array_int_max = %s\n", test_array_int_max);
	
	itoa(test_int_min, test_array_int_min, 21);
	printf("\ntest_array_int_min = %s\n\n", test_array_int_min);

	return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[], int l)
{
	int i, sign;
	i = 0;

	if (n == INT_MIN) { /* handle INT_MIN edge case */
		n++;
		s[i++] = ((-n % 10) + 1) + '0';
		n /= 10;
	}
	if ((sign = n) < 0)	/* record sign */
		n = -n;		/* make n positive */
	do {		/* generate digits in reverse order */
		s[i++] = n % 10 + '0';	/* get next digit, the '0' makes the int a char */
	} while ((n /= 10) > 0);	/* delete it */
	if (sign < 0)
		s[i++] = '-';
	while (i < l) {		/* add padding, if necessary */
		s[i++] = ' ';
	}
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
