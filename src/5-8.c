/*
 * There is no erroc checking in day_of_year or month_day. Remedy this defect.
 */
#include <stdio.h>

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
  int i, leap;

  if (year < 0 || month < 1 || month > 12 || day < 28 || day > 31)
    return -1;
  leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
  for (i = 1; i < month; i++)
    day += daytab[leap][i];
  return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;

  if (year < 0 || yearday < 1 || yearday > 365) {
    *pmonth = -1;
    *pday = -1;
  }
  else {
    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
      yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
  }
}

int main() {

  int pmonth;
  int pday;

  printf("day_of_year: March 1 1988 (leap year): %d\n", day_of_year(1988, 3, 1));
  printf("day_of_year: March 1 1989 (non leap year): %d\n", day_of_year(1989, 3, 1));

  month_day(1988, 60, &pmonth, &pday);
  printf("month_day: 1988 60: m=%d d=%d\n", pmonth, pday);
}
