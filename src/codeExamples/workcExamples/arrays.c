#include <stdio.h>
#include <stdlib.h>

int main()
{
	int int_array[5] = {2, 4, 6, 8, 10};
	char char_array[100] = {'t', 'e', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g'};

	printf("\n\nSize of int_array = %i\n", sizeof(int_array));
	printf("Actual int int_array = {");
	for (int i = 0; i < 5; i++) {
		printf("'%i'", int_array[i]);
		if (i < 4) {
			printf(",");
		} else {
			printf("}\n\n");
		}
	}
	printf("Size of char_array = %i\n", sizeof(char_array));
	printf("Actual char_array = %s\n\n", char_array);

	return 0;
}
