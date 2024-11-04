#include <stdio.h>

int binarySearch(int x, int list[], int len);
void outputArray(int array[], int len);
void fillArray(int array[]); 

int main() {

	// Value to look for in Array using Binary Search
	int look_for_value = 63;

	// Test 1
	int list[1000];
	int length = 100;
	for (int i = 0; i < length; i++) {
		list[i] = i + 1;
	}
	printf("\nLooking for value = %i\n", look_for_value);
	outputArray(list, length);
	int position_in_list = binarySearch(look_for_value, list, length);
	printf("\n The location of the value in list is: %i\n", position_in_list);

	// Test 2
	int test_array[1000];
	fillArray(test_array);
	look_for_value = 64;
	printf("\nLooking for value = %i\n", look_for_value);
	outputArray(test_array, 24);
	int position_in_test = binarySearch(look_for_value, test_array, 24);
	printf("\n The location of the value in array is: %i\n", position_in_test);
}


/* binary search to find 'x' in 'list' that is 'len' long */
int binarySearch(int x, int list[], int len) {

	int low, high, mid;
	low = 0;
	high = len - 1;

	// If value isn't found, low passes high, and it breaks loop
	while (low <= high) {
		mid = (low + high) / 2;
		printf("\nmid = %i\n", mid);
		// Compares x (value) to value in the array, this is when comparison is made.
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


/* output the array */
void outputArray(int array[], int len) {

	int p;
	printf("\n[");
	for (p = 0; p < len - 1; p++) {
		printf("%i,", array[p]);
	}
	printf("%i", array[p]);
	printf("]\n");
}

/* pass in an empty array, and fill it with data in this function */
void fillArray(int array[]) {

	array[0] = 3;
	array[1] = 6;
	array[2] = 9;
	array[3] = 13;
	array[4] = 16;
	array[5] = 21;
	array[6] = 27;
	array[7] = 33;
	array[8] = 36;
	array[9] = 39;
	array[10] = 42;
	array[11] = 45;
	array[12] = 48;
	array[13] = 55;
	array[14] = 59;
	array[15] = 64;
	array[16] = 68;
	array[17] = 69;
	array[18] = 71;
	array[19] = 77;
	array[20] = 84;
	array[21] = 89;
	array[22] = 93;
	array[23] = 97;
}
