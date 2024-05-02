#include <stdio.h>

#define MAXSTR 10000

#define TRUE (1 == 1)
#define FALSE !TRUE

// This is a test comment

int get_str(char str[], int limit); // This is another test comment.
void remove_comments(char str[], char no_com_str[]);

int main(void)
{
	/**
	 *  This is a multiline
	 *  block
	 *  comment.
	 */

	char str[MAXSTR];
	char no_com_str[MAXSTR];

	get_str(str, MAXSTR);

	remove_comments(str, no_com_str);

	printf("%s", no_com_str);
	return 0;
}

int get_str(char str[], int limit){

	int c, i = 0;

	while (i < limit - 1 && (c = getchar()) != EOF){
		str[i++] = c;
	}
	str[i] = '\0';

	return i;
}

void remove_comments(char str[], char no_com_str[]){

}
