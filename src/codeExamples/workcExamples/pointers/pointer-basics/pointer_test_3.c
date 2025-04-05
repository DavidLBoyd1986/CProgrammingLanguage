#include <stdlib.h>
#include <stdio.h>

int main()
{
	char ch = 'A';
	int num = 45;
	float flt_num = 67.098;
	double dbl_num = 23.3232332;

	char *ch_ptr = &ch;
	int * num_ptr = &num;
	float* flt_num_ptr = &flt_num;
	double *dbl_num_ptr = &dbl_num;

	printf("-------------ADDRESS---------------\n");
	printf("Address of ch is: %p \n", ch_ptr);
	printf("Address of num is: %p \n", num_ptr);
	printf("Address of flt_num is: %p \n", flt_num_ptr);
	printf("Address of dbl_num is: %p \n", dbl_num_ptr);

	printf("\n");

	printf("-------------VALUE---------------\n");
	printf("Value of ch is: %c \n", *ch_ptr);
	printf("Value of num is: %d \n", *num_ptr);
	printf("Value of flt_num is: %f \n", *flt_num_ptr);
	printf("Value of dbl_num is: %lf \n", *dbl_num_ptr);

	printf("\n");
}
