#include <stdio.h>

int binsearch(int x, int v[], int n);
int binsearch_updated(int x, int v[], int n);

int main()
{
	// Create Test Values to search for
	int test_value_one = 63;
	int test_value_two = 64;

	// Create test arrays
	int array_one[1000];
	int array_two[1000];
	int length = 100;

	// Initialize test array one
	for (int i = 0; i < length; i++) {
		array_one[i] = i + 1;
	}
	// Initialize test array two
	int j = 0;
	for (int i = 0; i < length; i++) {
		if (i % 2 == 0) {
			array_two[j++] = i;
		}
	}

	// Test one on both Binary Methods - value one in array one
	int result_test_one_og = binsearch(test_value_one, array_one, length);
	printf("\nPosition of value = %i\n", result_test_one_og);
	int result_test_one_up = binsearch_updated(test_value_one, array_one, length);
	printf("\nPosition of value = %i\n", result_test_one_up);

	// Test two on both Binary Methods - value one in array two
	int result_test_two_og = binsearch(test_value_one, array_two, length);
	printf("\nPosition of value = %i\n", result_test_two_og);
	int result_test_two_up = binsearch_updated(test_value_one, array_two, length);
	printf("\nPosition of value = %i\n", result_test_two_up);

	// Test three on both Binary Methods - value two in array two
	int result_test_three_og = binsearch(test_value_two, array_two, length);
	printf("\nPosition of value = %i\n", result_test_three_og);
	int result_test_three_up = binsearch_updated(test_value_two, array_two, length);
	printf("\nPosition of value = %i\n", result_test_three_up);
}

int binsearch_updated(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	
	while (low <= high) {
		mid = (low + high) / 2;
		if (x <= v[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	if (x == v[mid]) {
		return mid;
	} else {
		return -1;
	}
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;

	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid]) {
			high = mid - 1;
		} else if (x > v[mid]) {
			low = mid + 1;
		} else {
			return mid;
		}
	}
	return -1;
}
