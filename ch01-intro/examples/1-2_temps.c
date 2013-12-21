/*
 * =====================================================================================
 *
 *       Filename:  temps.c
 *
 *    Description:  print temperatures in C and F
 *
 *        Version:  1.0
 *        Created:  7/26/2013 12:27:21 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cianan A. Sims (), ctasims@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

/* print Fahrenheit-Celsius table for fahr = 0, 20, ... 300 */
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /*  lower limit */
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5.0 * (fahr-32.0) / 9.0;
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

}
