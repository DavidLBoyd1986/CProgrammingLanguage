#include <stdlib.h>
#include <stdio.h>

int main()
{
	int num = 221;
	int *num_ptr = &num;
	int *another_ptr = num_ptr; //* on type declaration is NOT a de-referencing operator. It is indicating the type, Pointer to Int.

	printf("--------------ADDRESS----------------\n");
	printf("Address of num is: %p\n", &num);
	printf("Address stored in num_ptr is: %p\n", num_ptr);
	printf("Address stored in another_ptr is: %p\n", another_ptr);

	printf("\n");

	printf("--------------ADDRESS----------------\n");
	printf("Value in num is: %d\n", num);
	printf("Value pointed to by num_ptr is: %d\n", *num_ptr);
	printf("Value pointed to by another_ptr is: %d\n", *another_ptr);
}
