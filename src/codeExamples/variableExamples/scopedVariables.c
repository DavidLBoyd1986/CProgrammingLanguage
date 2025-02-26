#include <stdio.h>
#include <stdlib.h>

int external_variable = 5;

int main() {

	int local_variable = 8;
	int x = 77;
	int y = 99;

	printf("\nexternal_variable = %i\n", external_variable);
	printf("\nlocal_variable = %i\n", local_variable);

	if (external_variable == 5) {
		int local_variable = 22; // different from outer local_variable
		printf("\nin if, local_variable = %i\n", local_variable);
		int external_variable = 245;
		printf("\nin if, external_variable = %i\n", external_variable);
	}

	printf("\nafter if, external_variable = %i\n", external_variable);
	printf("\nafter if, local_variable = %i\n", local_variable);

	printf("\nx = %i\n", x);
	printf("\ny = %i\n", y);

	if (external_variable == 5) {
		int x = 789; // different from outer local_variable
		printf("\nin if, x = %i\n", x);
		int y = 654;
		printf("\nin if, y = %i\n", y);
	}

	printf("\nx = %i\n", x);
	printf("\ny = %i\n", y);
}

