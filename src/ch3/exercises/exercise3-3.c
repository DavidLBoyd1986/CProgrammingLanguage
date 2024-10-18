#include <stdio.h>

#define DEFAULT_ARRAY_SIZE 1000	// Default size of Arrays 
#define TRUE 1
#define FALSE 0

void expand(char s1[], char s2[]);
void fill_test_array_one(char s1[]);
void fill_test_array_two(char s1[]);
void fill_test_array_three(char s1[]);
void fill_test_array_four(char s1[]);
void fill_test_array_five(char s1[]);
void fill_test_array_six(char s1[]);


int main()
{
	// Declare and Initialilze test strings
	char input_string_one[DEFAULT_ARRAY_SIZE];
	char output_string_one[DEFAULT_ARRAY_SIZE];
	char input_string_two[DEFAULT_ARRAY_SIZE];
	char output_string_two[DEFAULT_ARRAY_SIZE];
	char input_string_three[DEFAULT_ARRAY_SIZE];
	char output_string_three[DEFAULT_ARRAY_SIZE];
	char input_string_four[DEFAULT_ARRAY_SIZE];
	char output_string_four[DEFAULT_ARRAY_SIZE];
	char input_string_five[DEFAULT_ARRAY_SIZE];
	char output_string_five[DEFAULT_ARRAY_SIZE];
	char input_string_six[DEFAULT_ARRAY_SIZE];
	char output_string_six[DEFAULT_ARRAY_SIZE];

	// Fill the test input strings
	fill_test_array_one(input_string_one);
	fill_test_array_two(input_string_two);
	fill_test_array_three(input_string_three);
	fill_test_array_four(input_string_four);
	fill_test_array_five(input_string_five);
	fill_test_array_six(input_string_six);

	// test expand function to copy to output strings
	expand(input_string_one, output_string_one);
	expand(input_string_two, output_string_two);
	expand(input_string_three, output_string_three);
	expand(input_string_four, output_string_four);
	expand(input_string_five, output_string_five);
	expand(input_string_six, output_string_six);

	// Print the input/output strings
	printf("\n\ninput_string_one = %s\n", input_string_one);
	printf("output_string_one = %s\n\n", output_string_one);
	printf("input_string_two = %s\n", input_string_two);
	printf("output_string_two = %s\n\n", output_string_two);
	printf("input_string_three = %s\n", input_string_three);
	printf("output_string_three = %s\n\n", output_string_three);
	printf("input_string_four = %s\n", input_string_four);
	printf("output_string_four = %s\n\n", output_string_four);
	printf("input_string_five = %s\n", input_string_five);
	printf("output_string_five = %s\n\n", output_string_five);
	printf("input_string_six = %s\n", input_string_six);
	printf("output_string_six = %s\n\n", output_string_six);
}


void expand(char s1[], char s2[])
{
	int i, j, c, p;
	i = j = 0;

	while ((c = s1[i]) != '\0') {
		if (c == '-') {
			int expand_start = s1[i-1];
			int expand_end = s1[i+1];
			if (expand_start >= 48 && expand_start < 57 &&
                            expand_end > 48 && expand_end <= 57) {
				while (expand_start < expand_end) {
					s2[j++] = ++expand_start;
				}
			} else if (expand_start >= 65 && expand_start < 90 &&
			    expand_end > 65 && expand_end <= 90) {
				while (expand_start < expand_end) {
					s2[j++] = ++expand_start;
				}	
			} else if (expand_start >= 97 && expand_start < 122 &&
			    expand_end > 97 && expand_end <= 122) {
				while (expand_start < expand_end) {
					s2[j++] = ++expand_start;
				}	
			}
			i = i + 2; // skip i past the char after '-'
		} else {
			s2[j] = c;
			i++;
			j++;
		}
	}
	s2[j] = '\0';
}


void fill_test_array_one(char s1[])
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

void fill_test_array_two(char s1[])
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
	s1[12] = 'A';
	s1[13] = '-';
	s1[14] = 'Z';
	s1[15] = '.';
	s1[16] = '\0';
}

void fill_test_array_three(char s1[])
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
	s1[12] = '0';
	s1[13] = '-';
	s1[14] = '9';
	s1[15] = '.';
	s1[16] = '\0';
}

void fill_test_array_four(char s1[])
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
	s1[14] = 'n';
	s1[15] = '.';
	s1[16] = '\0';
}

void fill_test_array_five(char s1[])
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
	s1[12] = 'M';
	s1[13] = '-';
	s1[14] = 'S';
	s1[15] = '.';
	s1[16] = '\0';
}

void fill_test_array_six(char s1[])
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
	s1[12] = '0';
	s1[13] = '-';
	s1[14] = '9';
	s1[15] = '3';
	s1[16] = '-';
	s1[17] = '7';
	s1[18] = 'h';
	s1[19] = '-';
	s1[20] = 'r';
	s1[21] = '.';
	s1[22] = '\0';
}
