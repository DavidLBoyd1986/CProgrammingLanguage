#include <stdio.h>
/* 
#define LOWER	0
#define UPPER	300
#define STEP	30
*/

int tempConvertor(int lower, int upper, int step);

int main() {
	tempConvertor(-20, 400, 20);

	return 0;
}

/* print Fahrenheit-Celsius table */
int tempConvertor(int lower, int upper, int step) {
	int fahr;
	for (fahr = lower; fahr <= upper; fahr = fahr + step)
		printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32));
}
