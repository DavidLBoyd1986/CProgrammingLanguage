#include <stdio.h>

int main()
{
	int radius = 25;  // Normal int variable
	int* radius_ptr = &radius; // Pointer to memory location of radius int variable
	// radius_ptr is a symbolic representation of the memory address holidng the radius variable.

	// * - indicates this is a pointer to a memory location holding an int value
	// & - indicates this is the address of the variable, not the variable itself

	int* some_ptr = radius_ptr; // Pointer to value of radius_ptr pointer variable

	//int radius_ptr_no_amp = &radius; // Did NOT Work 
	//int* radius_ptr_no_amp = radius; // Did NOT Work
	//Neither of the above worked, seems if * is used, the & must be used as well.
	//But: 'int* some_ptr = radius_ptr;' does work

	//IMPORTANT - int* is a different type than int
	// int expects and int value
	// int* expects a pointer to a memory address holding an int value
	// This is why some_ptr works with int* pointing to radius_ptr
	// but int* does not work when pointing to radius without the &

	// points (int*) are either 32 or 64 bits in length, depending on computer architecture
	// int types are only 4 bytes.

	// %i for print values - Are these junk values since %p prints the address
	printf("\nprint radius using d = %d", radius);
	printf("\nprint radiusptr using d = %d", radius_ptr);
	printf("\nprint some_ptr using d = %d\n", some_ptr);
	//printf("\nradius pointer no amp = %i\n", radius_ptr_no_amp);

	// %p for print values - %p used for printing memory addresses
	printf("\nUsing p as the placeholder\n");
	printf("\nprint radius using p = %p", radius); // int value in hexadecimal
	printf("\nprint &radius using p = %p", &radius); // memory address of radius
	printf("\nprint radius_ptr using p = %p", radius_ptr); // memory address of radius - value held in radius_ptr
	printf("\nprint some_ptr using p = %p", some_ptr); // memory address of radius - value held in radius_ptr
	printf("\nprint &radius_ptr using p = %p", &radius_ptr); // memory address of radius - value held in radius_ptr
	printf("\nprint &some_ptr using p = %p\n", &some_ptr); // memory address of radius - value held in radius_ptr

	// memory address changes each time the program is ran.

	// De-referencing Pointers:

	// use *radius_ptr to dereference a pointer
	printf("\n De-referencing Pointers:\n");
	printf("print *radius_ptr using d = %d\n", *radius_ptr);	
	printf("print *some_ptr using d = %d\n", *some_ptr);	

	// *var - de-referencing variable - takes memory location stored in pointer var, and returns the contents of that memory location.
	// retrieving addresses with '&var' is the inverse of gettign the value from an address using '*var'
	// &var returns the address, and *var returns the value at that address
	
	// Example below, uses '&var' and '*var' together to show '*' pulls the value at '&' address for 'radius'
	printf("\nprint *&radius using d = %d\n", *&radius);
}
