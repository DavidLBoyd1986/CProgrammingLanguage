#include <stdio.h>

int binarySearch(int x, int list[], int len);

int main() {

	int look_for_value = 63;
	int list[1000];
	int length = 100;
	for (int i = 0; i < length; i++) {
		list[i] = i + 1;
	}
	int position_of_value = binarySearch(look_for_value, list, length);
	printf("\n The location of the value in the array is: %i\n", position_of_value);
}


/* binary search to find 'x' in 'list' that is 'len' long */
int binarySearch(int x, int list[], int len) {

	int low, high, mid;
	low = 0;
	high = len - 1;

	while (low <= high) {
		mid = (low + high) / 2;
		if (x < list[mid]) {
			high = mid - 1;
		} else if (x > list[mid]) {
			low = mid + 1;
		} else {
			return mid;
		}
	}
	return -1; /* no match */
}
