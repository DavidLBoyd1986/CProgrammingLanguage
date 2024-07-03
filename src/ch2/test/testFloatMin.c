#include <stdio.h>

int main() {
	float testFloat = 1;

	for(float f = -16700000; f < 0; f = f - testFloat){
		printf("float f = %f\n", f);
	}
	
	//for(float f = 16777000; f > 0; f = f + testFloat){
	//	printf("float f = %f\n", f);
	//}
}
