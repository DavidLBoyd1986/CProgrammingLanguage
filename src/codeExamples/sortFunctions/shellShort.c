#include <stdio.h>

#define ARRAYSIZE 1000

int fillArray(int v[]);
void outputArray(int array[], int len);
void shellsort(int v[], int n);

int main() {
	int test_array_length;
	int test_array[ARRAYSIZE];
	test_array_length = fillArray(test_array);

	printf("\n\nOriginal Array");
	outputArray(test_array, test_array_length);
	shellsort(test_array, test_array_length);
	printf("\nSorted Array");
	outputArray(test_array, test_array_length);
	printf("\n");
}


int fillArray(int v[]) {

	int p = 0;
	while (p < ARRAYSIZE) {
		v[p++] = 7;
		v[p++] = 19;
		v[p++] = 32;
		v[p++] = 21;
		v[p++] = 1;
		v[p++] = 12;
		v[p++] = 97;
		v[p++] = 54;
		v[p++] = 3;
		v[p++] = 67;
		v[p++] = 88;
		v[p++] = 35;
		v[p++] = 22;
		v[p++] = 74;
		v[p++] = 7 ;
		v[p++] = 24;
		v[p++] = 35;
		v[p++] = 73;
		v[p++] = 99;
		v[p] = 41;
		break;
	}
	return p;
}


void outputArray(int v[], int n) {

	int p = 0;
	printf("\n[");
	while (p < n - 1) {
		printf("%i,", v[p++]);
	}
	printf("%i", v[p]);
	printf("]\n");
}


void shellsort(int v[], int n) {

	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /= 2) {
		for (i = gap; i < n; i++) {
			// comparison done here v[j] > 
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j = j - gap) {
				// The earlier value v[j] is greater than v[j + gap], so they are swapped
				// j - gap just continues this loop for more comparisons,
				// but it breaks as soon as there is no swap
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
		}
	}
}
