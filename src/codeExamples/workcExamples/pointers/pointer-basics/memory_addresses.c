#include <stdlib.h>
#include <stdio.h>

int main()
{
	char ch = 'A';
	int num = 45;
	float flt_num = 67.098;
	double dbl_num = 23.3232332;

	printf("\n");
	printf("Address of ch is: %p \n", &ch);
	printf("Address of num is: %p \n", &num);
	printf("Address of flt_num is: %p \n", &flt_num);
	printf("Address of dbl_num is: %p \n", &dbl_num);
	printf("\n");

	return EXIT_SUCCESS;
}
