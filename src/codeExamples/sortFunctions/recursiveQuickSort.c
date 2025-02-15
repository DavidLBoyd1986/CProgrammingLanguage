#include <stdio.h>

void swap(int v[], int i, int j);
void qsort(int v[], int left, int right);
void print_array(int array[], int len);

void main()
{
	int test_array_one[] = { 4, 55, 23, 3, 77, 345, 23, 6, 4, 98, 44 };
	int array_length = sizeof(test_array_one) / sizeof(test_array_one[0]);
	print_array(test_array_one, array_length);
	qsort(test_array_one, 0, array_length);
	print_array(test_array_one, array_length);
}

/* qsort: sort v[left]...[right] into increasing order */
void qsort(int v[], int left, int right)
{
	int i, last;

	if (left >= right)	/* do nothing if array contains */
		return;		/* fewer than two elements */
	swap(v, left, (left + right)/2); /* move partition elem */
	last = left;			 /* to v[0] */
	for (i = left+1; i <= right; i++)	/* partition */
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);	/* restore partition elem */
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
	printf("\narray_length = %i\n", len);
	printf("\n{");
	for (int i = 0; i < len; i++)
		printf(" %i,", array[i]);
	printf("}\n");
}

