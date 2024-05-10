#include <stdio.h>
#include <stdlib.h>

int main(){

	if ('a' == 'a'){
		printf(" a = a ; true works for char equality\n");
	}

	printf("%d\n", 'a');

	if ('a' == 97){
		printf(" a = 97 ; true works for int to str comparison\n");
	}

	char str[100];

	str[0] = 'a';

	printf("%d\n", str[0]);


	if (str[0] == 'a'){
		printf("str[0] == 'a' ; true works for char array item to str comparison\n");
	}
	return 0;

}
