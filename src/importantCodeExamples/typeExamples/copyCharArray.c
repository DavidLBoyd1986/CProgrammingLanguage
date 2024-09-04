#include <stdio.h>

int lower_original(int c);

int main() {

	char testString[100] = "A StRiNG WItH somE CapITaL LeTTErS";
	printf("\ntestString = %s\n", testString);

	// There is no way to make resultString = testString, have to copy in a loop.
	char resultString[100];

	// The below loop copies the char array, and performs lower on it.
	for (int i = 0; testString[i] != '\0'; i++) {
		resultString[i] = lower_original(testString[i]);
	}
	printf("\nresultString = %s\n\n", resultString);
}

int lower_original(int c) {
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}
