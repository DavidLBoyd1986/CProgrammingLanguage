#include <stdio.h>

int main() {
	float testFloat =.0001;

	for(float f = -167.3456; f < 0; f = f + testFloat){
		printf("float f = %f\n", f);
	}
	
	//for(float f = 16777000; f > 0; f = f + testFloat){
	//	printf("float f = %f\n", f);
	//}
}
