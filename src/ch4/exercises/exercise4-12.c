#include <stdio.h>
#include <stdio.h>

int recursive_itoa(int, char[], int);

int main()
{
	int test_one_int = 2345;
	printf("\ntest_one_int = %i\n", test_one_int);
	char test_one_string[100];
	recursive_itoa(test_one_int, test_one_string, 0);
	printf("test_one_string = %s\n", test_one_string);
	
	int test_two_int = -6789;
	printf("\ntest_two_int = %i\n", test_two_int);
	char test_two_string[100];
	recursive_itoa(test_two_int, test_two_string, 0);
	printf("test_two_string = %s\n\n", test_two_string);
}

int recursive_itoa(int n, char s[], int i)
{
	//static int i = 0;
	char int_char;

	if (n < 0) {
		s[i++] = '-';
		n = -n;
	}
	if (n / 10)
		i = recursive_itoa(n / 10, s, i);
	s[i++] = n % 10 + '0';
	s[i] = '\0';
	return i;
} 
