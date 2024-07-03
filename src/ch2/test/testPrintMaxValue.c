#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

void main(){

	//printf(CHAR_MIN);
	printf("Float Type");
	float testfloat = 10.5;
	printf("%f\n\n", testfloat);

	float testOne, testTwo, testThree;
	testOne=4.5;
	testTwo=2.5;
	testThree=testOne+testTwo;
	printf("%f + %f = %f", testOne, testTwo, testThree);

	long testLong = 1234;

	printf("\nlong is : %li", testLong);

	double testDouble = 13245;

	printf("\ndouble is : %lf", testDouble);

	float negativeFloat = -3332221111;

	printf("\nfloat is : %g", negativeFloat);
}
