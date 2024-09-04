#include <string.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int any(char s1[100], char s2[100]);

int main() {

	// Test One
	char string_1[100] = "hello, world!";
	char string_2[100] = "sd";
	int first_loc = any(string_1, string_2);
	printf("\nTest One - First Location = %i\n", first_loc);

	// Test Two
	char string_3[100] = "hello, world!";
	char string_4[100] = "ed";
	int second_loc = any(string_3, string_4);
	printf("\nTest Two - First Location = %i\n", second_loc);

}

int any(char s1[100], char s2[100]) {

	int i;
	int j;

	for (i = 0; s1[i] != '\0'; i++) {

		int char_found = FALSE;
		int s1_char = s1[i];
		
		for (j = 0; s2[j] != '\0'; j++) {
			
			int s2_char = s2[j];

			if (s1_char == s2_char) {
				char_found = TRUE;
			}
		}

		if (char_found == TRUE) {
			return i;
		}
	}
}
