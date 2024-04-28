#include <stdio.h>

#define MAXSTR 10000
#define TRUE (1 == 1)
#define FALSE !TRUE

int get_str(char str[], int limit);
void check_syntax(char str[]);

int main(void)
{
	char str[MAXSTR];

	get_str(str, MAXSTR);
	check_syntax(str);

	return 0;
}

int get_str(char str[], int limit)
{
	int c, i = 0;

	while (i < limit - 1 && (c == getchar()) != EOF)
	{
		str[i++] = c;
	}
	str[i] = '\0';

	return i;
}

void check_syntax(char str[])
{
	int parantheses = 0;
	int brackets = 0;
	int braces = 0;

	int single_quotes = FALSE;
	int double_quotes = FALSE;

	int block_comment = FALSE;
	int line_comment = FALSE;

	int i = 0;

	while (str[i] != '\0' && parentheses >= 0 && brackets >= 0 && braces >= 0){

		if (!line_comment && !block_comment && !single_quotes && !double_quotes){
			if (str[i] == '('){
				++parantheses;
			} else if (str[i] == ')'){
				--parantheses;
			}
			
			if (str[i] == '['){
				++brackets;
			} else if (str[i] == ']'){
				--brackets;
			}

			if (str[i] == '{'){
				++braces;
			} else if (str[i] == '}'){
				--braces;
			}
		}
	/* block comment */
	//line comment
		if (!line_comment && !block_comment){
			if (str[i] == '\' && !single_quotes && !double_quotes){
				single_quotes = TRUE;
			} else if (single_quotes && str[i] == '\'' && (str[i - 1] != '\\' || str[i - 2] == '\\'))
		}

	
	}


}
