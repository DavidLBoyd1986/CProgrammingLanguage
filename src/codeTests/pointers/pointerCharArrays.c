#include <stdio.h>

int main()
{
	char test[20];
	char *t = test;

	*t++ = 'f';
	*t = '\0';
	printf("t = %s\n", t);	
	*t++ = 'a';
	*t = '\0';
	printf("t = %s\n", t);	
	*t++ = 't';
	*t = '\0';
	printf("t = %s\n", t);	

}
