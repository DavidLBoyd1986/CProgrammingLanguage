#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int get_line(char *, int);
int tatoi(char *);
char* titoa(int);
char* titoa_test(int);
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
	int atoi_result_1 = tatoi(atoi_test_1);
	printf("atoi_result_1 = %i\n", atoi_result_1);
	char *atoi_test_2 = "-438923";
	printf("atoi_test_2 = %s\n", atoi_test_2);
	int atoi_result_2 = tatoi(atoi_test_2);
	printf("atoi_result_2 = %i\n", atoi_result_2);
	int itoa_test_1 = 394;
	printf("itoa_test_1 = %i\n", itoa_test_1);
	char *itoa_result_1 = titoa(itoa_test_1);
	printf("itoa_result_1 = %s\n", itoa_result_1);
	int itoa_test_2 = 394;
	printf("itoa_test_2 = %i\n", itoa_test_2);
	char *itoa_result_2 = titoa_test(itoa_test_2);
	printf("itoa_result_2 = %s\n", itoa_result_2);
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

int tatoi(char *s)
{
	int c;
	int len = 0;
	int sign = 0;
	int final_val = 0;

	// Save sign
	if ((c = *s)  == '-') {
		sign = '-';
		s++;
	}
	char *temp_s = s; //Copy the string pointer before getting length
	// Get length of s
	while ((c = *s) != '\0') {
		s++;
		len++;
	}
	len = len - 2;
	// Turn string into an int in final val
	while (len >= 0) {
		c = *temp_s++;
		final_val = final_val + ((c - 48) * expo(10, len));
		len--;
	}
	c = *temp_s;
	final_val = final_val + (c - 48);
	// Add sign back in
	if (sign == '-')
		final_val *= -1;

	return final_val;
}

char* titoa(int n)
{
	char temp_string[20];
	char *s = temp_string;
	int p;
	char c;
	int len = 0;

	// Copy into a string - copies it in reverse
	while ((p = n % 10) > 0) {
		c = p + 48;
		*s++ = c;
		len++;
		n /= 10;
	}
	*s = '\0';
	// Reverse temp_string into final_string
	char final_string[20];
	char *final_s = final_string;
	for (int i = 0, e = len-1; i < len; i++, e--) {
		*(final_s + i) = *(temp_string + e);
	}
	*(final_s + len) = '\0';
	return final_s;

}

// TODO:

// Problems:
// exponent in % is NOT working

// I don't know the length of int n
// 	so, I still have two loops


char* titoa_test(int n)
{
	int int_val = n;
	char string_val[20];
	char *s_start = string_val;
	char *s = string_val;
	int temp_int;
	int len = 0;

	// Get length of string
	while ((n = n / 10) > 0) {
		len++;
	}
	len++;
	printf("len = %i\n", len);
	// Copy each int into a string
	while (len > 0) {
		printf("expo test = %i\n", int_val % (expo(10, len)));
		if (len == 1) {
			temp_int = int_val;
		} else {
			temp_int = int_val % (expo(10, len-1));
			int_val = int_val / (expo(10, len-1));
		}
		printf("temp_int = %i\n", temp_int);
		*s++ = int_val + 48;
		len--;
	}
	*s = '\0';
	return s_start;

}
