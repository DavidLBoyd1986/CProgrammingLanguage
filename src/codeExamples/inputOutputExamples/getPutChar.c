#include <stdio.h>

int main() {
	char character;

	printf("Enter a character: ");
	character = getchar();

	printf("You entered: ");
	putchar(character);
	printf("\n");

	return 0;
}
