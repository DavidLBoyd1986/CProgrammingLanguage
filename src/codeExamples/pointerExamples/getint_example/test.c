#include <stdio.h>
#include <stdlib.h>

int main()
{
	float incrementer = .1;

	for (int pos = 1; pos <=5; pos++){
		incrementer *= .1;
		printf("incrementer = %f\n", incrementer);
	}
}
