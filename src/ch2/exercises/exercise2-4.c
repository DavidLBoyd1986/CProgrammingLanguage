#include <string.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

void squeeze(char s1[100], char s2[100]);

int main() {

	// Test One
	char string_1[100] = "hello, world!";
	char string_2[100] = "hl !";
	printf("\nTest One\n");
	printf("\nString before the squeeze: %s\n", string_1);
	printf("\nCharacters to remove: %s\n", string_2);	
	squeeze(string_1, string_2);	
	printf("\nString after the squeeze: %s\n\n", string_1);

	// Test Two
	char string_3[100] = "hello, world!";
	char string_4[100] = "eord";
	printf("\nTest Two\n");
	printf("\nString before the squeeze: %s\n", string_3);
	printf("\nCharacters to remove: %s\n", string_4);	
	squeeze(string_3, string_4);
	printf("\nString after the squeeze: %s\n\n", string_3);
}


void squeeze(char s1[100], char s2[100]){

	int t = 0;
	int i;
	int j;

	for (i = 0; s1[i] != '\0'; i++) {

		int s1_char = s1[i];
		int remove_char = FALSE;

		for (j = 0; s2[j] != '\0'; j++) {

			int s2_char = s2[j];

			if (s1_char == s2_char) {
				remove_char = TRUE;
			}
		}
		if (remove_char == TRUE) {
		} else {
			s1[t] = s1[i];
			t++;
		}
	}
	
	s1[t] = '\0';	

}
