#include <stdio.h>

void demonstrate_char_array();
void demonstrate_char_pointer();

int main()
{
	printf("=== How char arrays work with plain numbers ===\n");
	demonstrate_char_array();
	
	printf("\n=== How to achieve similar functionality with char* ===\n");
	demonstrate_char_pointer();
	
	return 0;
}

void demonstrate_char_array()
{
	/* This is like your exercise5-8.c daytab - char array with plain numbers */
	static char daytab[2][13] = {
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},  /* regular year */
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}   /* leap year */
	};
	
	printf("Original char daytab approach:\n");
	printf("daytab[0][1] = %d (Jan days in regular year)\n", daytab[0][1]);
	printf("daytab[1][2] = %d (Feb days in leap year)\n", daytab[1][2]);
	
	/* 
	 * WHY THIS WORKS: 
	 * - char is just a small integer type (typically 1 byte)
	 * - Numbers 0-255 fit in a char without problem
	 * - When you access daytab[leap][i], you get the number as an int
	 * - C automatically promotes char to int in expressions
	 */
	
	int leap = 1;  /* leap year */
	int month = 2; /* February */
	printf("Days in month %d of leap year: %d\n", month, daytab[leap][month]);
}

void demonstrate_char_pointer()
{
	/* Create the same data using char pointers */
	static char regular_year[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	static char leap_year[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	/* Array of char pointers - each points to a row */
	char *daytab[2] = {
		regular_year,  /* daytab[0] points to regular_year array */
		leap_year      /* daytab[1] points to leap_year array */
	};
	
	printf("Using char* daytab approach:\n");
	printf("daytab[0][1] = %d (Jan days in regular year)\n", daytab[0][1]);
	printf("daytab[1][2] = %d (Feb days in leap year)\n", daytab[1][2]);
	
	/*
	 * HOW THIS WORKS:
	 * - daytab is an array of 2 char* (pointers to char)
	 * - daytab[0] points to the first element of regular_year
	 * - daytab[1] points to the first element of leap_year
	 * - daytab[leap][month] works exactly like the 2D array!
	 * - You can still use plain numbers because char holds small integers
	 */
	
	int leap = 1;
	int month = 2;
	printf("Days in month %d of leap year: %d\n", month, daytab[leap][month]);
	
	/* Demonstrate that these are actually pointers */
	printf("\nPointer details:\n");
	printf("daytab[0] points to address: %p\n", (void*)daytab[0]);
	printf("daytab[1] points to address: %p\n", (void*)daytab[1]);
	printf("regular_year address: %p\n", (void*)regular_year);
	printf("leap_year address: %p\n", (void*)leap_year);
}

