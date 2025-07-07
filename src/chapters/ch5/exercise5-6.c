#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int get_line(char *, int);
int atoi_ptr(char *);
char* itoa_ptr_one(int);
char* itoa_ptr_two(int);
char* reverse(char *);
int strindex(char *, char *);
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
	// Test atoi_ptr()
	char *atoi_test_1 = "394";
	printf("atoi_test_1 = %s\n", atoi_test_1);
	int atoi_result_1 = atoi_ptr(atoi_test_1);
	printf("atoi_result_1 = %i\n", atoi_result_1);
	char *atoi_test_2 = "-438923";
	printf("atoi_test_2 = %s\n", atoi_test_2);
	int atoi_result_2 = atoi_ptr(atoi_test_2);
	printf("atoi_result_2 = %i\n", atoi_result_2);
	// Test itoa_ptr()
	int itoa_test_1 = 394;
	int itoa_test_2 = -438923;
	// Test itoa_ptr_one()
	printf("itoa_one_test_1 = %i\n", itoa_test_1);
	char *itoa_one_result_1 = itoa_ptr_one(itoa_test_1);
	printf("itoa_one_result_1 = %s\n", itoa_one_result_1);
	printf("itoa_one_test_2 = %i\n", itoa_test_2);
	char *itoa_one_result_2 = itoa_ptr_one(itoa_test_2);
	printf("itoa_one_result_2 = %s\n", itoa_one_result_2);
	// Test itoa_ptr_two()
	printf("itoa_two_test_1 = %i\n", itoa_test_1);
	char *itoa_two_result_1 = itoa_ptr_two(itoa_test_1);
	printf("itoa_two_result_1 = %s\n", itoa_two_result_1);
	printf("itoa_two_test_2 = %i\n", itoa_test_2);
	char *itoa_two_result_2 = itoa_ptr_two(itoa_test_2);
	printf("itoa_two_result_2 = %s\n", itoa_two_result_2);
	// Test reverse()
	char reverse_test_1[20] = "testone";
	char *reverse_test_1_result;
	printf("reverse_test_1 = %s\n", reverse_test_1);
	reverse_test_1_result = reverse(reverse_test_1);
	printf("reverse_test_1_result = %s\n", reverse_test_1_result);
	char reverse_test_2[50] = "reverse all of this as a test";
	char *reverse_test_2_result;
	printf("reverse_test_2 = %s\n", reverse_test_2);
	reverse_test_2_result = reverse(reverse_test_2);
	printf("reverse_test_2_result = %s\n", reverse_test_2_result);
	// Test strindex()
	char strindex_test[40] = "This is a really long string";
	char strindex_test_find[40] = "ally";
	printf("strindex_test = %s\n", strindex_test);
	printf("strindex_test_find = %s\n", strindex_test_find);
	int strindex_result = strindex(strindex_test, strindex_test_find);
	printf("strindex_result = %i\n", strindex_result);
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
	while (exp > 1) {
		total = total * base;
		exp--;
	}
	return total;
}

int atoi_ptr(char *s)
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
		final_val = final_val + ((c - 48) * expo(10, len+1));
		len--;
	}
	c = *temp_s;
	final_val = final_val + (c - 48);
	// Add sign back in
	if (sign == '-')
		final_val *= -1;

	return final_val;
}

char* itoa_ptr_one(int n)
{
	char sign;
	int len = 0;
	char temp_string[20];
	char *s = temp_string;
	char final_string[20];
	char *final_s = final_string;

	// Get the sign
	if (n < 0) {
		sign = '-';
		n *= -1;
	} else {
		sign = ' ';
	}
	// Copy into a string - copies it in reverse
	while ((n % 10) > 0) {
		*s++ = (n % 10) + 48;
		len++;
		n /= 10;
	}
	*s = '\0';
	// Reverse temp_string into final_string
	for (int i = 0, e = len-1; i < len; i++) {
		if (i == 0 && sign == '-') {
			*final_s = '-';
			len++;
		} else {
			*(final_s + i) = *(temp_string + e);
			e--;
		}
	}
	*(final_s + len) = '\0';
	return final_s;
}

char* itoa_ptr_two(int n)
{
	int n_copy = n;
	char string_val[20];
	char *s = string_val;
	char *s_start = string_val;
	int len = 1; 		//TODO - Find way to not set this to 1, but 0
	int int_val;

	// Get the sign, and if - add it to start of string
	if (n_copy < 0) {
		*s++ = '-';
		n_copy = n *= -1;
	}
	// Get length of string
	while ((n = n / 10) > 0) {
		len++;
	}
	// Copy each int into a string
	while (len > 0) {
		if (len == 1) {
			int_val = n_copy;
		} else {
			int_val = n_copy / (expo(10, len-1));
			n_copy = n_copy % (expo(10, len-1));
		}
		*s++ = int_val + 48;
		len--;
	}
	*s = '\0';
	return s_start;
}

char* reverse(char *s)
{
	int len = 0;

	// Get length of string
	while (*s != '\0') {
		len++;
		s++;
	}
	// Create the return string
	char return_string[len];
	char *return_string_pntr = return_string;
	while (len-- > 0) {
		*return_string_pntr++ = *--s;
	}
	// Reset pntr and return it
	return_string_pntr = return_string;
	return return_string_pntr;
}

int strindex(char *s, char *t)
{
	int i, j, k;

	for (i = 0; *(s + i) != '\0'; i++) {
		for (j = i, k = 0; *(t + k) != '\0' && *(s + j) == *(t + k); j++, k++)
			; // Loops through a section separately to find a match
		if (k > 0 && *(t + k) == '\0')
			return i;
	}
	return -1;
}

// I'm not changing getop to pointers, it's just not worth the trouble.
