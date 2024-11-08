#include <stdio.h>
#include <ctype.h>

double atof(char s[]);
double exponent(double base, int n);

int main()
{
	char test_array_one[100] = {'2', '1', '3', '.', '7', '8'};
	printf("\ntest_array_one = %s\n", test_array_one);
	double test_output_one = atof(test_array_one);
	printf("test_output_one = %g\n", test_output_one);
	
	char test_array_two[100] = {'-', '5', '3', '1', '.', '9', '9'};
	printf("\ntest_array_two = %s\n", test_array_two);
	double test_output_two = atof(test_array_two);
	printf("test_output_two = %g\n", test_output_two);
	
	char test_array_three[100] = {'1', '2', '.', '5', 'e', '5'};
	printf("\ntest_array_three = %s\n", test_array_three);
	double test_output_three = atof(test_array_three);
	printf("test_output_three = %g\n", test_output_three);

	char test_array_four[100] = {'1', '2', '.', '5', 'e', '-', '5'};
	printf("\ntest_array_four = %s\n", test_array_four);
	double test_output_four = atof(test_array_four);
	printf("test_output_four = %g\n\n", test_output_four);
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
	}
	if (s[i] == '.') /* added back when val is divided by power at end */
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0'); /* continues adding val */
		power *= 10.0; /* power to divide by and add back in '.' */
	}
	val = sign * val / power; /* Add back in sign and power */
	if (s[i] == 'e' || s[i] == 'E') { /* check for exponent */
		i++;
	} else {
		return val;
	}
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	int exp_val = 0;
	while (isdigit(s[i])) { 
		if (exp_val != 0)
			exp_val *= 10;
		exp_val = exp_val + (s[i++] - '0');
	}
	if (sign == -1) {
		val = 1/(exponent(val, exp_val));
	} else if (sign == 1) {
		val = exponent(val, exp_val);
	}
	return val;
}

double exponent(double base, int n)
{
	int i;
	double p = 1;
	for (i = 1; i <= n; ++i)
		p = p * base;
	return p;
}
