#include <stdio.h>

void swap_int(int a, int b);
void swap_int_pointer(int *a, int *b);

int main()
{
	int five = 5;
	int thirty = 30;
	int* fp = &five;
	int* tp = &thirty;

	printf("\nfive = %i\n", five);
	printf("thirty = %i\n", thirty);
	printf("*fp = %i\n", *fp);
	printf("*tp = %i\n", *tp);

	swap_int_pointer(fp, tp);

	printf("\nAfter swap_int_pointer(fp, tp)\n");
	printf("\nfive = %i\n", five);
	printf("thirty = %i\n", thirty);
	printf("*fp = %i\n", *fp);
	printf("*tp = %i\n", *tp);

	swap_int(five, thirty);
	printf("\nAfter swap_int(five, thirty)\n");
	printf("\nfive = %i\n", five);
	printf("thirty = %i\n", thirty);
	printf("*fp = %i\n", *fp);
	printf("*tp = %i\n", *tp);
	printf("\nNo change because swap_int only swaps value inside the function.\n" \
		"Function arguments are Passed-by-value.\n" \
		"So, only the value is passed into the function, not the variable\n\n");
}

void swap_int_pointer(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/* Below runs, but only changes value locally, and so no change shows in main() print functions */
void swap_int(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

/* Below won't work because argument is int, and I try to use a pointer to an int
   This is why I need a separate 'swap_int_pointer' function.

void swap_wrong(int a, int b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
*/
