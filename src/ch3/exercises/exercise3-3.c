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
	// Declare and Initialize test strings
	char input_string_one[DEFAULT_ARRAY_SIZE] = \
		{'E','x','p','a','n','d',' ','t','h','i','s',' ','a' \
		 ,'-','z','.','\0'};
	char output_string_one[DEFAULT_ARRAY_SIZE];
	char input_string_two[DEFAULT_ARRAY_SIZE] = \
		{'E','x','p','a','n','d',' ','t','h','i','s',' ','A' \
		 ,'-','Z','.','\0'};
	char output_string_two[DEFAULT_ARRAY_SIZE];
	char input_string_three[DEFAULT_ARRAY_SIZE] = \
		{'E','x','p','a','n','d',' ','t','h','i','s',' ','0', \
		 '-','9','.','\0'};
	char output_string_three[DEFAULT_ARRAY_SIZE];
	char input_string_four[DEFAULT_ARRAY_SIZE] = \
		{'E','x','p','a','n','d',' ','t','h','i','s',' ','a', \
		 '-','n','.','\0'};
	char output_string_four[DEFAULT_ARRAY_SIZE];
	char input_string_five[DEFAULT_ARRAY_SIZE] = \
		{'E','x','p','a','n','d',' ','t','h','i','s',' ','M', \
		 '-','S','.','\0'};
	char output_string_five[DEFAULT_ARRAY_SIZE];
	char input_string_six[DEFAULT_ARRAY_SIZE] = \
		{'E','x','p','a','n','d',' ','t','h','i','s',' ','a', \
		 '-','n','n','-','t','0','-','5','6','-','9','\0'};
	char output_string_six[DEFAULT_ARRAY_SIZE];
	char input_string_seven[DEFAULT_ARRAY_SIZE] = \
		{'D','o',' ','N','o','t',' ','E','x','p','a','n','d', \
		 ' ','t','h','i','s',' ','a','-','9','-','n','-','T', \
		 '0','-','\0'};
	char output_string_seven[DEFAULT_ARRAY_SIZE];

	// test expand function to copy to output strings
	expand(input_string_one, output_string_one);
	expand(input_string_two, output_string_two);
	expand(input_string_three, output_string_three);
	expand(input_string_four, output_string_four);
	expand(input_string_five, output_string_five);
	expand(input_string_six, output_string_six);
	expand(input_string_seven, output_string_seven);

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
	printf("input_string_seven = %s\n", input_string_seven);
	printf("output_string_seven = %s\n\n", output_string_seven);
}


void expand(char s1[], char s2[])
{
	int i, j, c, valid_expansion;
	i = j = 0;
	valid_expansion = FALSE;

	while ((c = s1[i]) != '\0') {
		if (c == '-') {
			// Check if it is a - that can be expanded
			int expand_start = s1[i-1];
			int expand_end = s1[i+1];
			if (expand_start >= 48 && expand_start < 57 &&
                            expand_end > 48 && expand_end <= 57) {
				valid_expansion = TRUE;
			} else if (expand_start >= 65 && expand_start < 90 &&
			    expand_end > 65 && expand_end <= 90) {
				valid_expansion = TRUE;
			} else if (expand_start >= 97 && expand_start < 122 &&
			    expand_end > 97 && expand_end <= 122) {
				valid_expansion = TRUE;
			}

			if (valid_expansion) {
				while (expand_start < expand_end) {
					s2[j++] = ++expand_start;
				}
				i = i + 2; // skip i past the char after '-'
			} else {
				s2[j] = c;
				i++;
				j++;
			}
		} else {
			s2[j] = c;
			i++;
			j++;
		}
	}
	s2[j] = '\0';
}

