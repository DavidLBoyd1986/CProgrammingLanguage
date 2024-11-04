#include <stdio.h>

void fill_array(char s[]);

int main()
{
	char test_string[1000];
	fill_array(test_string);
	int i, c;
	i = c = 0;

	printf("\n");
	while ((c = test_string[i]) != '\0') {
		if (c == 48) {
			int j = c;
			while (j < 57) {
				printf("Values b/w: %i = %c\n", j, j);
				j++;
			}
		}
		i++;
	}
}


void fill_array(char s1[])
{
	s1[0] = 'a';
	s1[1] = '-';
	s1[2] = 'z';
	s1[3] = 'A';
	s1[4] = '-';
	s1[5] = 'Z';
	s1[6] = '0';
	s1[7] = '-';
	s1[8] = '9';
	s1[9] = '\0';
}
