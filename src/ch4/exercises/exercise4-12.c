#include <stdio.h>
#include <stdio.h>

void recursive_itoa(int, char[]);

int main()
{
	int test_one_int = 2345;
	printf("\ntest_one_int = %i\n", test_one_int);
	char test_one_string[100];
	recursive_itoa(test_one_int, test_one_string);
	printf("\ntest_one_string = %s\n", test_one_string);
}

void recursive_itoa(int n, char s[])
{
	static int string_position = 0;
	int sign;
	char int_char;

	printf("\nTop of recursive_itoa; n = %i", n);
	printf("\nTop of recursive_itoa; s = %s", s);
	if ((sign = n) < 0) {
		n = -n;
		s[string_position++] = '-';
	}
	int_char = n % 10 + '0';
	n /= 10;
	printf("\nMiddle of recursive_itoa; n = %i", n);
	if (n > 0)
		recursive_itoa(n, s);
	s[string_position++] = int_char;
	printf("\nTop of recursive_itoa; n = %i", n);
	printf("\nTop of recursive_itoa; s = %s", s);
} 
