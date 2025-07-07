#include <stdlib.h>
#include <stdio.h>

float* get_array()
{
	float arr[] = {12.4, 4.5, 6.7, 3.44};

	return arr;
}

int main()
{
	float* float_ptr = get_array(); // BAD - it will warn you.
}
