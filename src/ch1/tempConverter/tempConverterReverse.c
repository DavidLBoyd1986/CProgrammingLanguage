#include <stdio.h>

/* Print Fahrenheit to Celsius table, from high to low */
main()
{
	int fahr;
	for (fahr = 300; fahr >= 0; fahr = fahr - 20)
		printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32));
}
