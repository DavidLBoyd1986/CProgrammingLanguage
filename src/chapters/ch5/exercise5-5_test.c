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
	char *string6;
	char blankstring[100];
	char *blankstringnew;
	printf("\nstring1 before strncpy = %s\n", string1);
	printf("string2 before strncpy = %s\n", string2);
	string3 = strncpy_new(string1, string2, 4);
	printf("string3 after strncpy = %s\n", string3);
	printf("return value of strncpy_new = %s\n", strncpy_new(blankstring, string2, 3));
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
		printf("\n*t = %c\n", *t);
		*s++ = *t++;
	}
	
	printf("s at end of function = %s\n", s);
	return s_start;
}
