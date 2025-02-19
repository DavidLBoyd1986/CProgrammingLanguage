#include <stdio.h>
#include <stdio.h>

void recursive_itoa(int, char[]);

int main()
{
	int test_one_int = 2345;
	printf("\ntest_one_int = %i\n", test_one_int);
	char test_one_string[100];
	recursive_itoa(test_one_int, test_one_string);
	printf("\n\ntest_one_string = %s\n", test_one_string);
	
	int test_two_int = -6789;
	printf("\ntest_two_int = %i\n", test_two_int);
	char test_two_string[100];
	recursive_itoa(test_two_int, test_two_string);
	printf("\ntest_two_string = %s\n", test_two_string);
}

void recursive_itoa(int n, char s[])
{
	static int i = 0;
	int sign;
	char int_char;

	printf("\nTop of recursive_itoa; n = %i, s = %s", n, s);
	if (n < 0) {
		s[i++] = '-';
		n = -n;
		printf("\ns = %s", s);
		printf("\nn = %i\n", n);
	}
	int_char = n % 10 + '0';
	n /= 10;
	printf("\nMiddle of recursive_itoa; n = %i, s = %s", n, s);
	if (n > 0)
		recursive_itoa(n, s);
	s[i++] = int_char;
	printf("\nBottom of recursive_itoa; n = %i, s = %s", n, s);
} 
