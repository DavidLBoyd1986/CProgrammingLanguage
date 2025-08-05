#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int, int, int *, int *);

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main()
{
int test_year_one = 2004;
int test_year_two = 2005;
int test_month_one = 5;
int test_month_two = 2;
int test_day_one = 28;
int test_day_two = 31;
int test_year_three = 2008;
int test_year_four = 2009;
int test_yearday_one = 241;
int test_yearday_two = 59;
int month, day;
int *month_pointer = &month;
int *day_pointer = &day;

// Example of creating and using an int pointer
int test = 120;		// Need to create the int to point to
int *pntr = &test;
printf("pntr = %i\n", *pntr);
int *test_month_pointer;
test_month_pointer = &test;
printf("test_month_pointer = %i\n", *test_month_pointer);

// Actual functions
int day_of_year_test_one = day_of_year(test_year_one, test_month_one, test_day_one);
printf("day_of_year_test_one = %i\n", day_of_year_test_one);
int day_of_year_test_two = day_of_year(test_year_two, test_month_two, test_day_two);
printf("day_of_year_test_two = %i\n", day_of_year_test_two);
month_day(test_year_three, test_yearday_one, month_pointer, day_pointer);
printf("month_pointer = %i, day_pointer = %i\n", *month_pointer, *day_pointer);
month_day(test_year_four, test_yearday_two, month_pointer, day_pointer);
printf("month_pointer = %i, day_pointer = %i\n", *month_pointer, *day_pointer);

// Test Error Handling
int bad_year_one = -3;
int year_zero = 0;
int bad_month_one = 0;
int bad_month_two = 14;
int bad_day_one = 0;
int bad_day_two = 32;
int bad_yearday_one = 0;
int bad_yearday_two = 367;

// day_of_year error handling tests
int bad_year_test_one = day_of_year(bad_year_one, test_month_one, test_day_one);
printf("bad_year_test_one = %i\n", bad_year_test_one);
int bad_year_test_two = day_of_year(year_zero, test_month_one, test_day_one);
printf("bad_year_test_two = %i\n", bad_year_test_two);
int bad_month_test_one = day_of_year(test_year_one, bad_month_one, test_day_one);
printf("bad_month_test_one = %i\n", bad_month_test_one);
int bad_month_test_two = day_of_year(test_year_one, bad_month_two, test_day_one);
printf("bad_month_test_two = %i\n", bad_month_test_two);
int bad_day_test_one = day_of_year(test_year_one, test_month_one, bad_day_one);
printf("bad_day_test_one = %i\n", bad_day_test_one);
int bad_day_test_two = day_of_year(test_year_one, test_month_two, bad_day_two);
printf("bad_day_test_two = %i\n", bad_day_test_two);

// month_day error handling tests
month_day(test_year_one, bad_yearday_one, month_pointer, day_pointer);
month_day(test_year_one, bad_yearday_two, month_pointer, day_pointer);
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;

	if (year < 0) {
		printf("year = %i - is less than 0\n", year);
		return 1;
	}
	if (month < 1 || month > 12) {
		printf("month = %i - is not between 1 and 12\n", month);
		return 1;
	}
	if (day < 1 || day > 31) {
		printf("day = %i - is not between 1 and 31\n", day);
		return 1;
	}
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	if (year < 0) {
		printf("year = %i - is less than 0\n", year);
	}
	if (yearday < 1 || yearday > 366) {
		printf("yearday = %i - is not between 1 - 366\n", yearday);
		*pmonth = -1;
		*pday = -1;
		return;
	}
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}
