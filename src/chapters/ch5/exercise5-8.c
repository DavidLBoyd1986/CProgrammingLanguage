#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

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
int test_yearday_one = 241;
int test_yearday_two = 59;

int day_of_year_test_one = day_of_year(test_year_one, test_month_one, test_day_one);
printf("day_of_year_test_one = %i\n", day_of_year_test_one);
int day_of_year_test_two = day_of_year(test_year_two, test_month_two, test_day_two);
printf("day_of_year_test_two = %i\n", day_of_year_test_two);
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}
