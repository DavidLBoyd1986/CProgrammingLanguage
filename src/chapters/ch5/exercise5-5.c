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

	printf("\nstring6 before strncpy = %s\n", string6);
	printf("string7 before strncpy = %s\n", string7);
	printf("return value of strncpy_new(string6, string7, 8) = %s\n", strncpy_new(string6, string7, 8));

	printf("------------------------------------------------");

	char str1[100] = "test_string_one";
	char str2[100] = "start";
	char *str3;
	char *str4 = "test_string_one";
	char *str5 = "start";
	char blankstr[100];
	char str6[100] = "test_string_one";
	char str7[100] = "start";

	printf("\nstr1 before strncat = %s\n", str1);
	printf("str2 before strncat = %s\n", str2);
	str3 = strncat_new(str1, str2, 4);
	printf("str3 after strncat(str1, str2, 4) = %s\n", str3);

	// Below shows you can pass a "char []" into a function parameter for "char *"
	printf("return value of strncat(blankstr, str2, 3) = %s\n", strncat_new(blankstr, str2, 3));

	printf("\nstr4 before strncat = %s\n", str4);
	printf("str5 before strncat = %s\n", str5);
	// Below doesn't work. Why doesn't it work when passing in char* but does with char[].
	//printf("return value of strncat_new(str4, str5, 4) = %s\n", strncat_new(str4, str5, 4));

	printf("\nstr6 before strncat = %s\n", str6);
	printf("str7 before strncat = %s\n", str7);
	printf("return value of strncat_new(str6, str7, 8) = %s\n", strncat_new(str6, str7, 8));

	printf("------------------------------------------------");

	char st1[100] = "test_string_one";
	char st2[100] = "test_string_two";
	char *st3 = "test_string_one";
	char *st4 = "test_string_two";
	char st5[100] = "test_string_one";
	char st6[100] = "test";
	char blankst[100];

	printf("\nst1 before strncmp = %s\n", st1);
	printf("st2 before strncmp = %s\n", st2);
	int ans1 = strncmp_new(st1, st2, 9);
	printf("Comparison result of strncmp_new(st1, st2, 9) = %i\n", ans1);

	printf("\nst3 before strncmp = %s\n", st3);
	printf("st4 before strncmp = %s\n", st4);
	// Below doesn't work. Why doesn't it work when passing in char* but does with char[].
	//printf("return value of strncmp_new(str3, str4, 9) = %s\n", strncmp_new(str3, str4, 9));

	printf("\nst5 before strncmp = %s\n", st5);
	printf("st6 before strncmp = %s\n", st6);
	printf("return value of strncmp_new(st5, st6, 4) = %i\n", strncmp_new(st5, st6, 4));
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

char* strncat_new(char *s, char *t, int n)
{
	char *s_start = s;

	while (*s != '\0')
		s++;
	while (*t != '\0')
		*s++ = *t++;
	*s = '\0';
	return s_start;
}

int strncmp_new(char *s, char *t, int n)
{
	int i = 0;

	while (*s != '\0' && *t != '\0' && i < n) {
		if (*s == *t) {
			s++;
			t++;
			continue;
		} else {
			return (*s - *t);
		}	
	}

	// Return values based on reach end of string
	if (*s == '\0' && *t == '\0')
		return 0;
	if (*s == '\0')
		return -1;
	if (*t == '0')
		return 1;
}

