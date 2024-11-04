#include <stdio.h>

int main()
{

	// Test of stdin
	char test_input[100];

	fgets(test_input, 100, stdin);
	printf("\ntest_input = %s", test_input);

	// Test of FILE input
	char line[100];
	FILE *file;

	file = fopen("/home/david/Projects/CProgrammingLanguage/src/codeExamples/inputOutputExamples/testFileInput.txt", "r");

	if (file == NULL) {
		perror("Error opening file");
		return 1;
	}

	while (fgets(line, sizeof(line), file)) {
		printf("%s", line);
	}

	fclose(file);

	return 0;
}
