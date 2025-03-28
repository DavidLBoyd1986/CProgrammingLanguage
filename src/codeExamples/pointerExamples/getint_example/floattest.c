#include <stdio.h>
#include <stdlib.h>

int main()
{

float testfloat = 12;
float incrementer = .1;
float temp;

printf("testfloat = %f\n", testfloat);

// Set value for first decimal position
temp = incrementer * 4;
printf("incrementer: %f\n", incrementer);
testfloat = testfloat + temp;

// move incrementer to next position
incrementer = incrementer * .1;

// Set value for second decimal position
temp = incrementer * 8;
printf("incrementer: %f\n", incrementer);
testfloat = testfloat + temp;

// move incrementer to next position
incrementer = incrementer * .1;

// Set value for third decimal position
temp = incrementer * 3;
printf("incrementer: %f\n", incrementer);
testfloat = testfloat + temp;

// move incrementer to next position
incrementer = incrementer * .1;

// Set value for fourth decimal position
temp = incrementer * 1;
printf("incrementer: %f\n", incrementer);
testfloat = testfloat + temp;

// Print final value
printf("testfloat updated = %f\n", testfloat);
}
