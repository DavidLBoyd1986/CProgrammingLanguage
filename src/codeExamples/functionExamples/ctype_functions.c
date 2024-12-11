#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char test_one = 's';
char test_two = 4;
char test_three = '(';

int main()
{

if (isalpha(test_one)) {
	printf("\ntest_one is alpha\n");
} else {
	printf("\ntest_one is not alpha\n");
}

if (isalpha(test_two)) {
	printf("\ntest_two is alpha\n");
} else {
	printf("\ntest_two is not alpha\n");
}

if (isalpha(test_three)) {
	printf("\ntest_three is alpha\n");
} else {
	printf("\ntest_three is not alpha\n");
}

return 0;
}
