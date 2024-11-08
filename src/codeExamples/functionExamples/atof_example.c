#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main()
{
	char test_array_one[100] = {'2', '1', '3', '.', '7', '8'};
	printf("\ntest_array_one = %s\n\n", test_array_one);
	double test_output_one = atof(test_array_one);
	printf("\n\ntest_output_one = %g\n", test_output_one);
	
	char test_array_two[100] = {'-', '5', '3', '1', '.', '9', '9'};
	printf("\ntest_array_two = %s\n\n", test_array_two);
	double test_output_two = atof(test_array_two);
	printf("\n\ntest_output_two = %g\n", test_output_two);
}

/* atof: convert string s to double */
double atof(char s[])
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++)	 /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		printf("val before decimal: %g\n", val);
	}
	if (s[i] == '.') /* added back when val is divided by power at end */
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0'); /* continues adding val */
		printf("\nval after decimal: %g\n", val);
		power *= 10.0; /* power to divide by and add back in '.' */
		printf("power after decimal: %g",power);
	}
	return sign * val / power; /* Add back in sign and power */
}
