#include <stdio.h>

/* print Celsius-Fahrenheit table
 *  for celsius = -20, -15, -10..., 100; float.point version */
main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = -20;	/* lower limit of temperature table */
	upper = 100;	/* upper limit */
	step = 5;	/* step size */

	printf("Cels\tFahr\n");
	celsius = lower;
	while (celsius <= upper) {
		fahr = celsius * (9.0/5.0) + 32.0;
		printf("%3.0f %7.0f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
