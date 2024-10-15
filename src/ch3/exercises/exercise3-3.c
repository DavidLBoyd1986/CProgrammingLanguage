#include <stdio.h>

#define DEFAULT_ARRAY_SIZE 1000	// Default size of Arrays 
#define TRUE 1
#define FALSE 0

void expand(char s1[], char s2[]);
void fill_test_array(char s1[]);


int main()
{
	// Declare and Initialilze test strings
	char input_string[DEFAULT_ARRAY_SIZE];
	char output_string[DEFAULT_ARRAY_SIZE];

	fill_test_array(input_string);
	expand(input_string, output_string);

	printf("\n\ninput_string = %s\n", input_string);
	printf("\noutput_string = %s\n\n", output_string);
}


void expand(char s1[], char s2[])
{
	int i, j, c, p;
	i = j = 0;

	while ((c = s1[i]) != '\0') {
		
		if (c == '-') {
			int expand_start = s1[i-1];
			int expand_end = s1[i+1];
			if (expand_start >= 48 && expand_start < 57) {
			 && expand_end > 48 && expand_end <= 57) {
				while (expand_start < expand_end) {
					s2[j++] = expand_start++;
				}
			} else if (expand_start >= 65 && expand_start < 90 && expand_end > 65 && expand_end < 90)
 {
		}
		p = c;
	}
}


void fill_test_array(char s1[])
{
	s1[0] = 'E';
	s1[1] = 'x';
	s1[2] = 'p';
	s1[3] = 'a';
	s1[4] = 'n';
	s1[5] = 'd';
	s1[6] = ' ';
	s1[7] = 't';
	s1[8] = 'h';
	s1[9] = 'i';
	s1[10] = 's';
	s1[11] = ' ';
	s1[12] = 'a';
	s1[13] = '-';
	s1[14] = 'z';
	s1[15] = '.';
	s1[16] = '\0';
}
