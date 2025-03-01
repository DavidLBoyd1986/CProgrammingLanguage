#include <stdio.h>

#define SIZE 10

void print_array(int array[], int len);
void update_array(int *pn);

int main()
{
	int n;

	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	printf("\nOrignal Array: ");
	print_array(array, 10);
	printf("\n");
	for (n = 0; n < SIZE; n++)
		array[n] = array[n] + 10;
	printf("\nUpdated Array, without pointers: ");
	print_array(array, 10);
	printf("\n");
	for (n = 0; n < SIZE; n++)
		update_array(&array[n]);
	printf("\nUpdated Array, without pointers: ");
	print_array(array, 10);
	printf("\n");
}

void update_array(int *pn)
{
	*pn += 33;
}
void print_array(int array[], int len)
{
	int i = 0;
	printf("\n{");
	while (i < len-1) {
		printf("%i, ", array[i]);
		i++;
	}
	printf("%i}\n\n", array[i]);
}
