#include <stdio.h>
#include <stdlib.h>

int main()
{

float testfloatone = 345;
float testfloattwo = 8678.995;
float testfloatthree = 12;

printf("testfloatone = %f\n", testfloatone);
printf("testfloattwo = %f\n", testfloattwo);
printf("testfloatthree = %f\n", testfloatthree);

float incrementer = .1;
printf("incrementer: %f\n", incrementer);
incrementer = incrementer * 4;

testfloatthree = testfloatthree + incrementer;
printf("testfloatthree updated = %f\n", testfloatthree);

incrementer = .1;
incrementer = incrementer * .1;
incrementer = incrementer * 7;
testfloatthree = testfloatthree + incrementer;
printf("incrementer: %f\n", incrementer);
printf("testfloatthree updated = %f\n", testfloatthree);

}
