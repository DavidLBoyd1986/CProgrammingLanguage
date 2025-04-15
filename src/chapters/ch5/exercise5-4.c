#include <stdio.h>
#include <stdlib.h>

int strend(char*, char*);

int main()
{
	char string_1[100] = "string_one";
	char string_2[100] = "one";
	char string_3[100] = "string_two";
	char string_4[100] = "onet";
	char string_5[100] = "lee";
	char string_6[100] = "ne";
	char string_7[100] = "_ne";
	int match;
	match = strend(string_1, string_2);
	printf("\ntest_one match = %i\n\n", match);
	match = strend(string_1, string_3);
	printf("\ntest_two match = %i\n\n", match);
	match = strend(string_1, string_4);
	printf("\ntest_three match = %i\n\n", match);
	match = strend(string_1, string_5);
	printf("\ntest_four match = %i\n\n", match);
	match = strend(string_1, string_6);
	printf("\ntest_five match = %i\n\n", match);
	match = strend(string_1, string_7);
	printf("\ntest_six match = %i\n\n", match);
}

int strend(char *s, char *t)
{
	int c;
	int s_pos = 0;
	int t_pos = 0;

	while ((c = s[s_pos++]) != '\0') {
		if (c != t[t_pos++]) {
			t_pos = 0;
			continue;
		}
	}

	if (t_pos > 0 && t[t_pos] == '\0')
		return 1;
	else
		return 0;
}

