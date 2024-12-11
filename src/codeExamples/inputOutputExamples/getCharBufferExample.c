#include <stdio.h>

int main()
{
	char test_array[1000];
	int i = 0;
	char c;

	// getchar() will accept input until a '\n' is input because
	// it will store the input in buffer until a '\n' is input

	// So the loop below won't print out anything
	// until the user hits enter.

	// After the '\n' it will pull each char from the buffer one at a time
	// So, it still prints the loop correctly, as shown when running this
	while ((test_array[i] = c = getchar()) != EOF){
		i++;
		test_array[i + 1] = '\0';
		printf("\nThis is test array - %s\n", test_array);
	}

}
