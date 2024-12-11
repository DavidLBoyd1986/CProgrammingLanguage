#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main()
{
	char test_array_one[100] = {'2', '1', '3', '.', '7', '8'};
	printf("\ntest_array_one = %s\n", test_array_one);
	double test_output_one = atof(test_array_one);
	printf("\ntest_output_one = %g\n", test_output_one);
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
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	return sign * val / power;
}
