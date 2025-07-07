#include <stdio.h>
#include <stdlib.h>

void strcmp_array(char *, char *);
void strcmp_ptr(char *, char *);

int main()
{
	char test_string_array_one[] = "Copy this string";
	char test_string_array_two[] = "This is string one";
	char empty_string_array_one[100];
	char empty_string_array_two[100];
	char empty_string_array_three[100];
	char empty_string_array_four[100];
	char *empty_string_pointer_three = &empty_string_array_three[0];
	char *empty_string_pointer_four = &empty_string_array_four[0];

	strcpy_array(empty_string_array_one, test_string_array_one);
	strcpy_array(empty_string_array_two, test_string_array_two);
	strcpy_ptr(empty_string_pointer_three, test_string_array_one);
	strcpy_ptr(empty_string_pointer_four, test_string_array_two);

	printf("empty_string_array_one after copy = %s\n", empty_string_array_one);
	printf("empty_string_array_two after copy = %s\n", empty_string_array_two);
	printf("empty_string_array_three after copy = %s\n", empty_string_array_three);
	printf("empty_string_array_four after copy = %s\n", empty_string_array_four);
}

void strcmp_array(char *s, char *t)
{
	int i = 0;

	while ((s[i] = t[i]) != '\0') {
		i++;
	}
}

void strcmp_ptr(char *s, char *t)
{
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}

