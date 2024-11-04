#include <stdio.h>

void itob(int n, char s[], int b);
int power(int n, int e);

int main()
{
	int test_int_one = 53284;
	char test_string_one[100];
	int test_int_two = 3854632;
	char test_string_two[100];
	int test_int_three = 255;
	char test_string_three[100];
	int test_int_four = 15;
	char test_string_four[100];
	int test_int_five = 16;
	char test_string_five[100];
	int test_int_six = 15;
	char test_string_six[100];
	int test_int_seven = 108;
	char test_string_seven[100];

	printf("\ntest_int_one = %i\n", test_int_one);
	printf("Convert to base 16\n");
	itob(test_int_one, test_string_one, 16);
	printf("test_string_one = %s\n\n", test_string_one);

	printf("test_int_two = %i\n", test_int_two);
	printf("Convert to base 16\n");
	itob(test_int_two, test_string_two, 16);
	printf("test_string_two = %s\n\n", test_string_two);

	printf("test_int_three = %i\n", test_int_three);
	printf("Convert to base 16\n");
	itob(test_int_three, test_string_three, 16);
	printf("test_string_three = %s\n\n", test_string_three);

	printf("test_int_four = %i\n", test_int_four);
	printf("Convert to base 16\n");
	itob(test_int_four, test_string_four, 16);
	printf("test_string_four = %s\n\n", test_string_four);

	printf("test_int_five = %i\n", test_int_five);
	printf("Convert to base 16\n");
	itob(test_int_five, test_string_five, 16);
	printf("test_string_five = %s\n\n", test_string_five);

	printf("test_int_six = %i\n", test_int_six);
	printf("Convert to base 2\n");
	itob(test_int_six, test_string_six, 2);
	printf("test_string_six = %s\n\n", test_string_six);

	printf("test_int_seven = %i\n", test_int_seven);
	printf("Convert to base 8\n");
	itob(test_int_seven, test_string_seven, 8);
	printf("test_string_seven = %s\n\n", test_string_seven);
}

void itob(int n, char s[], int b)
{
	int i, div_by, temp_int;
	i = div_by = 0;
	// get the value to divide by: 1, base, base**2, base**3, etc. 
	if (n < b) {
		div_by = 1;
	} else if (n >= b && n < power(b, 2)) {
		div_by = b;
	} else if (n >= power(b, 2)) {
		for (int p = 2; div_by < n; p++) {
			div_by = power(b, p);
		}
		div_by /= b; //Once you pass n, go back one exponentation
	} else {
		printf("ERROR - length of n is not a positive int.");
	}
	// Continually divide n by div_by, getting base value each time
	do {
		temp_int = n / div_by;
		if (temp_int >= 0 && temp_int <= 9) {
			s[i++] = temp_int + '0'; // why do i need " + '0' "?
		} else if (temp_int >= 10 && temp_int <= b) {
			s[i++] = temp_int + 55; //increase int to get a letter
		} else {
			printf("ERROR - Value of conversion not between 0 - b");
		}
		n %= div_by;
	} while ((div_by /= b) > 0);
	s[i] = '\0';
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
