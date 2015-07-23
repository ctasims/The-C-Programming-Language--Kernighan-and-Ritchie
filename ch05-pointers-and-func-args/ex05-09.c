/*
 * Exercise 5-9
 */

#include <stdio.h>


static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* set day of year from month and day */
int day_of_year(int year, int month, int day) {
    int i, leap;
    char *p;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    // catch inputs outside acceptable range of values
    p = &daytab[leap][0];
    if (year < 1752 || month < 1 || month > 12 || day < 1 ||
            day > *(p+month)) {
        return -1;
    }

    for (i=1; i < month; i++)
        day += *(p+i);

    return day;
}

/* set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;
    char *p, *p2;

    leap = (year % 4 == 0 && year % 1000 != 0) || year % 400 == 0;

    // check for bad inputs
    if (year < 1752 || yearday < 1 || (leap && yearday > 366) ||
            (yearday > 365)) {
        *pmonth = -1;
        *pday = -1;
    } else {
        p = &daytab[leap][1];
        p2 = p;
        while (yearday > *p++)
            yearday -= *p;

        *pmonth = p-p2;
        *pday = yearday;
    }
}

int main(void) {
    int y1 = 1986, yd1 = 115;
    int pm = 0, pd = 0;

    printf("%d, %d\n",
            day_of_year(1986, 12, 27), day_of_year(2014,2,17));


    month_day(y1, yd1, &pm, &pd);

    printf("%d, %d\n", pm, pd);

    return 0;
}

