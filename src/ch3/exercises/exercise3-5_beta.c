#include <stdio.h>
#include <limits.h>

void itob(int n, char s[], int b);
int power(int n, int e);

int main()
{
	int test_int = 53284;
	char test_string[100];

	printf("\ntest_int = %i\n", test_int);
	itob(test_int, test_string, 16);
	printf("\ntest_string = %s\n\n", test_string);
}

void itob(int n, char s[], int b)
{
	int i, l, copy_n, div_by, temp_int;
	char temp_char;
	i = l = 0;
	copy_n = n;
	
	// Get # of digits in int
	do {
		l++;
	} while ((copy_n /= 10) > 0);
	printf("\nDigits in n = %i\n\n", l);
	
	// get the value to divide by: 1, base, base**2, base**3, etc. 
	if (l == 1) {
		div_by = 1;
	} else if (l == 2) {
		div_by = b;
	} else if (l > 2) {
		div_by = power(b, l-2);
	} else {
	printf("ERROR - length of int is not a positive int.");
		}
	// Continually divide n by div_by, until it reaches 0;
	do {
		printf("div_by at start = %i\n", div_by);
		temp_int = n / div_by;
		printf("temp_int = %i\n", temp_int);
		// convert digit to base value
		if (temp_int >= 0 && temp_int <= 9) {
			temp_char = temp_int + '0';
		} else if (temp_int >= 10 && temp_int <= b) {
			temp_int += 55;
			temp_char = temp_int;
		} else {
			printf("ERROR - Value of conversion not between 0 - b");
		}
		printf("temp_char = %c\n", temp_char);
		s[i++] = temp_char;
		n %= div_by;
	} while ((div_by /= b) > 0);
}

int power(int n, int e)
{
	int increased_val = 1;
	if (e == 0)
		return 1;
	for (int i = 0; i < e; i++) {
		increased_val *= n;
	}
	return increased_val;
}
