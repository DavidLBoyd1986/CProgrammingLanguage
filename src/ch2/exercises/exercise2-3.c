#include <stdio.h>
#include <string.h>

#define HEX_BASE 16; /* Hex Base */

int main() {

	char hex_string[50] = "3d4f";
	int str_length = strlen(hex_string);
	
	int i;
	long long temp_str_value;
	long long str_value = 0;

	int hex_multiplier = 1;


	printf("\n Hex String: %s", hex_string);

	for (i = str_length - 1; i >= 0; i--){
		
		if (hex_string[i] == '0') {
			temp_str_value = hex_multiplier * 0;
		} else if (hex_string[i] == '1') {
			temp_str_value = hex_multiplier * 1;
		} else if (hex_string[i] == '2') {
			temp_str_value = hex_multiplier * 2;
		} else if (hex_string[i] == '3') {
			temp_str_value = hex_multiplier * 3;
		} else if (hex_string[i] == '4') {
			temp_str_value = hex_multiplier * 4;
		} else if (hex_string[i] == '5') {
			temp_str_value = hex_multiplier * 5;
		} else if (hex_string[i] == '6') {
			temp_str_value = hex_multiplier * 6;
		} else if (hex_string[i] == '7') {
			temp_str_value = hex_multiplier * 7;
		} else if (hex_string[i] == '8') {
			temp_str_value = hex_multiplier * 8;
		} else if (hex_string[i] == '9') {
			temp_str_value = hex_multiplier * 9;
		} else if (hex_string[i] == 'a') {
			temp_str_value = hex_multiplier * 10;
		} else if (hex_string[i] == 'b') {
			temp_str_value = hex_multiplier * 11;
		} else if (hex_string[i] == 'c') {
			temp_str_value = hex_multiplier * 12;
		} else if (hex_string[i] == 'd') {
			temp_str_value = hex_multiplier * 13;
		} else if (hex_string[i] == 'e') {
			temp_str_value = hex_multiplier * 14;
		} else if (hex_string[i] == 'f') {
			temp_str_value = hex_multiplier * 15;
		} else {
			printf("Invalid Value - Exiting");
			return 0;
		}
		// Increase hex_multiplier
		hex_multiplier = hex_multiplier * 16;
		str_value += temp_str_value;
	}
	printf("\nHex String Value: %lli\n", str_value);	
}
