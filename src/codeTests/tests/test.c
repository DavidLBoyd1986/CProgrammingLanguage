#include <stdio.h>

int main()
{
	int tab = 8;
	int test_offset = 3;
	int temp = test_offset % tab;
	int answer = tab - (test_offset % tab);

	printf("temp = %i\n", temp);
	printf("answer = %i\n", answer);
}
