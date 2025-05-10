#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

char* strncpy_new(char*, char*, int);
char* strncat_new(char*, char*, int);
int strncmp_new(char*, char*, int);

int main()
{
	char string1[100] = "test_string_one";
	char string2[100] = "start";
	char *string3;
	char *string4 = "test_string_one";
	char *string5 = "start";
	char blankstring[100];
	char string6[100] = "test_string_one";
	char string7[100] = "start";

	printf("\nstring1 before strncpy = %s\n", string1);
	printf("string2 before strncpy = %s\n", string2);
	string3 = strncpy_new(string1, string2, 4);
	printf("string3 after strncpy(string1, string2, 4) = %s\n", string3);

	// Below shows you can pass a "char []" into a function parameter for "char *"
	printf("return value of strncpy(blankstring, string2, 3) = %s\n", strncpy_new(blankstring, string2, 3));

	printf("\nstring4 before strncpy = %s\n", string4);
	printf("string5 before strncpy = %s\n", string5);
	// Below doesn't work. Why doesn't it work when passing in char* but does with char[].
	//printf("return value of strncpy_new(string4, string5, 4) = %s\n", strncpy_new(string4, string5, 4));

	printf("\nstring4 before strncpy = %s\n", string6);
	printf("string5 before strncpy = %s\n", string7);
	printf("return value of strncpy_new(string6, string7, 8) = %s\n", strncpy_new(string6, string7, 8));

	return 0;
}


char* strncpy_new(char *s, char *t, int n)
{
	char *s_start = s;

	for (int i = 0; i < n; i++) {
		if (*t == '\0') {
			*s++ = '\0';
			break;
		}
		*s++ = *t++;
	}
	return s_start;
}
