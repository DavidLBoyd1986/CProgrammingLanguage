#include <stdio.h>
#include <stdlib.h>

void strcatpntr(char*, char*);

int main()
{
	char string_1[100] = "string_one";
	char string_2[100] = "_appended_string";
	strcatpntr(string_1, string_2);

	printf("\nstring_1 = %s\n\n", string_1);
}

void strcatpntr(char *s, char *t)
{
	int c;
	int s_pos = 0;
	int t_pos = 0;

	while ((c = s[s_pos]) != '\0') {
		s_pos++; // Get to end of s
	}
	while ((c = t[t_pos]) != '\0') {
		s[s_pos++] = c;
		t_pos++;
	}
	s[s_pos] = '\0';
}
