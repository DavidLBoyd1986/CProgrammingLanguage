#include <stdio.h>

int main(){
	int n = 33;
	while (n < 127){
		char c = n;
		printf("%i = %c  ;  ", n, c);
		n++;
	}
}
