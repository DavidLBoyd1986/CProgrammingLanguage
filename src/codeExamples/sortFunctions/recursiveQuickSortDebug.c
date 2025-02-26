#include <stdio.h>

void swap(int v[], int i, int j);
void qsort(int v[], int left, int right);
void print_array(int array[], int len);

// TODO - figure out why swap inside the loop is the same when printed out.

void main()
{
	int test_array_one[] = { 4, 55, 23, 3, 77, 345, 23, 6, 4, 98, 44 };
	int array_length = sizeof(test_array_one) / sizeof(test_array_one[0]);
	printf("\nInitial Array: ");
	print_array(test_array_one, array_length);
	printf("\n");
	qsort(test_array_one, 0, array_length - 1);
	printf("\nFinal Sorted Array: ");
	print_array(test_array_one, array_length);
	printf("\n");
}

/* qsort: sort v[left]...[right] into increasing order */
void qsort(int v[], int left, int right)
{
	int i, last;

	if (left >= right)	/* do nothing if array contains */
		return;		/* fewer than two elements */
	printf("qsort - initial array: ");
	print_array(v, right);
	swap(v, left, (left + right)/2); /* move partition elem */
	printf("qsort - after initial swap: ");
	print_array(v, right);
	last = left;			 /* set 'left/[0]' to last */
	// Loop through 'v' swap 'i' with 'left/[0]' if 'left/[0] is greater
	for (i = left+1; i <= right; i++) {
		if (v[i] < v[left]) {
			swap(v, ++last, i); // swap with last, and increment it
			printf("   swap inside loop; v = ");
			print_array(v, right); 
		}
	}
	swap(v, left, last);	/* restore partition elem */
	printf("qsort - after initial sort: ");
	print_array(v, right);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap:   interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void print_array(int array[], int len)
{
	printf("{%i,", array[0]);
	for (int i = 1; i < len - 1; i++)
		printf(" %i,", array[i]);
	printf(" %i}\n", array[len-1]);
}

