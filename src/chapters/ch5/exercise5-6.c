#include <stdio.h>
#include <string.h>
#include <math.h>

int get_line(char *, int);
int atoi(char *);
char* itoa(int);
char* reverse(char *);
int strindex(char *, char *);
int getop(char *);
int expo(int, int);

/* getline: get line into s, return length */
/* atoi: convert s to integer */
/* itoa: convert n to characters in s */
/* reverse: reverse string s in place */
/* strindex: return index of t in s, -1 if none */
/* getop: get next operator or numeric operand */

int main()
{
	// Test getline()
	char blank_string[100];
	int input_length;
	input_length = get_line(blank_string, 100);
	printf("\nblank_string after getting input: %s\n", blank_string);
	printf("blank_string length: %i\n", input_length);
	// Test atoi()
	char *atoi_test_1 = "394";
	printf("atoi_test_1 = %s\n", atoi_test_1);
	int atoi_result_1 = atoi(atoi_test_1);
	printf("atoi_result_1 = %i\n", atoi_result_1);
}

int get_line(char *s, int limit)
{
	int c;
	int len = 0;
	char *s_start;

	while ((c = getchar()) != '\n' || c != EOF || c != '\0') {
		*s++ = c;
		len++;
		if (c == '`')
			break;
	}
	return len;
}

int expo(int base, int exp)
{
	int total = base;

	while (exp > 0) {
		total = total * base;
		exp--;
	}
	return total;
}

int atoi(char *s)
{
	char *temp_s = &*s;
	int c;
	int len = 0;

	int test_exponent = expo(10, 3);
	while ((c = *s) != '\0') {
		*s++;
		len++;
	}
	int final_val = 0;
	len = len - 2;
	while (len >= 0) {
		c = *temp_s++;
		final_val = final_val + ((c - 48) * expo(10, len));
		len--;
	}
	c = *temp_s;
	final_val = final_val + (c - 48);
	return final_val;
}

