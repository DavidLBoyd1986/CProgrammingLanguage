#include <stdio.h>

#define TRUE 1
#define FALSE 0


int main()
{
	int test_true = TRUE;
	int test_false = FALSE;

	if (test_true) {
		printf("\nTrue\n");
	}

	if (test_false) {
		printf("\nFalse - this shouldn't print\n");
	}

}
