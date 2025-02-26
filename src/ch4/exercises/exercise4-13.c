#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void reverse_string(char s[], int i, int p);

int main()
{
	char test_one[100] = "test one";
	printf("\n\ntest_one = %s\n", test_one);
	reverse(test_one);
	printf("test_one(reversed) = %s\n", test_one);

	char test_two[100] = "how is it now";
	printf("\n\ntest_two = %s\n", test_two);
	reverse(test_two);
	printf("test_two(reversed) = %s\n", test_two);
}

void reverse(char s[])
{
	int i = 0;
	int p = strlen(s);

	reverse_string(s, i, p);
}

void reverse_string(char s[], int i, int p)
{
	char t;

	t = s[i++];
	p--;
	if (s[i] != '\0')
		reverse_string(s, i, p);
	s[p] = t;
}
