#include <stdio.h>

int testBinary = 0b11011001;

int testOctal = 07757;

int testHex = 0xff;

int main() {

	printf("Print int of testBinary: %i\n", testBinary);
	printf("Print int of testOctal: %i\n", testOctal);
	printf("Print int of testHex: %i\n", testHex);

	printf("\nTesting Binary Operators\n");

	// Bitwise Operators
	// &  = bitwise AND
	// |  = bitwise inclusive OR
	// ^  = bitwise exclusive OR
	// << = Left Shift
	// >> = Right Shift
	// ~  = One's Complement (unary)
	
	int test_one = 0b1100;
	int test_two = 0b0011;
	int test_three = 0b1111;
	int test_four = 0b0000;
	
	int test_one_answer = test_three & test_three;
	printf("\nPrint int of 1111 & 1111: %i\n", test_one_answer);
	printf("Print binary of 1111 & 1111: %b\n", test_one_answer);

	int test_two_answer = test_three & test_four;
	printf("\nPrint int of 1111 & 0000: %i\n", test_two_answer);
	printf("Print binary of 1111 & 0000: %b\n", test_two_answer);
	
	int test_three_answer = test_four & test_four;
	printf("\nPrint int of 0000 & 0000: %i\n", test_three_answer);
	printf("Print binary of 0000 & 0000: %b\n", test_three_answer);
	
	int test_four_answer = test_one & test_two;
	printf("\nPrint int of 1100 & 0011: %i\n", test_four_answer);
	printf("Print binary of 1100 & 0011: %b\n", test_four_answer);
	printf("Output is truncated, the binary is: 0000\n");
	
	int test_five_answer = test_three | test_three;
	printf("\nPrint int of 1111 | 1111: %i\n", test_five_answer);
	printf("Print binary of 1111 | 1111: %b\n", test_five_answer);

	int test_six_answer = test_three | test_four;
	printf("\nPrint int of 1111 | 0000: %i\n", test_six_answer);
	printf("Print binary of 1111 | 0000: %b\n", test_six_answer);
	
	int test_seven_answer = test_four | test_four;
	printf("\nPrint int of 0000 | 0000: %i\n", test_seven_answer);
	printf("Print binary of 0000 | 0000: %b\n", test_seven_answer);
	
	int test_eight_answer = test_one | test_two;
	printf("\nPrint int of 1100 | 0011: %i\n", test_eight_answer);
	printf("Print binary of 1100 | 0011: %b\n", test_eight_answer);
	
	int test_nine_answer = test_three ^ test_three;
	printf("\nPrint int of 1111 ^ 1111: %i\n", test_nine_answer);
	printf("Print binary of 1111 ^ 1111: %b\n", test_nine_answer);

	int test_ten_answer = test_three ^ test_four;
	printf("\nPrint int of 1111 ^ 0000: %i\n", test_ten_answer);
	printf("Print binary of 1111 ^ 0000: %b\n", test_ten_answer);
	
	int test_eleven_answer = test_four ^ test_four;
	printf("\nPrint int of 0000 ^ 0000: %i\n", test_eleven_answer);
	printf("Print binary of 0000 ^ 0000: %b\n", test_eleven_answer);
	
	int test_twelve_answer = test_one ^ test_two;
	printf("\nPrint int of 1100 ^ 0011: %i\n", test_twelve_answer);
	printf("Print binary of 1100 ^ 0011: %b\n", test_twelve_answer);
	
	int test_thirteen_answer = test_three << test_three;
	printf("\nPrint int of 1111 << 1111: %i\n", test_thirteen_answer);
	printf("Print binary of 1111 << 1111: %b\n", test_thirteen_answer);

	int test_fourteen_answer = test_three << test_four;
	printf("\nPrint int of 1111 << 0000: %i\n", test_fourteen_answer);
	printf("Print binary of 1111 << 0000: %b\n", test_fourteen_answer);
	
	int test_fifteen_answer = test_four << test_four;
	printf("\nPrint int of 0000 << 0000: %i\n", test_fifteen_answer);
	printf("Print binary of 0000 << 0000: %b\n", test_fifteen_answer);
	
	int test_sixteen_answer = test_one << test_two;
	printf("\nPrint int of 1100 << 0011: %i\n", test_sixteen_answer);
	printf("Print binary of 1100 << 0011: %b\n", test_sixteen_answer);
	
	int test_seventeen_answer = test_three >> test_three;
	printf("\nPrint int of 1111 >> 1111: %i\n", test_seventeen_answer);
	printf("Print binary of 1111 >> 1111: %b\n", test_seventeen_answer);

	int test_eighteen_answer = test_three >> test_four;
	printf("\nPrint int of 1111 >> 0000: %i\n", test_eighteen_answer);
	printf("Print binary of 1111 >> 0000: %b\n", test_eighteen_answer);
	
	int test_nineteen_answer = test_four >> test_four;
	printf("\nPrint int of 0000 >> 0000: %i\n", test_nineteen_answer);
	printf("Print binary of 0000 >> 0000: %b\n", test_nineteen_answer);
	
	int test_twenty_answer = test_one >> test_two;
	printf("\nPrint int of 1100 >> 0011: %i\n", test_twenty_answer);
	printf("Print binary of 1100 >> 0011: %b\n", test_twenty_answer);
	
}
