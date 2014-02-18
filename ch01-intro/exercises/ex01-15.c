/*
 * =====================================================================================
 *
 *       Filename:  ex01-15.c
 *
 *    Description:  Rewrite temp conversion with function.
 *
 *        Version:  1.0
 *        Created:  11/21/2013 12:03:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cianan A. Sims (), ctasims@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

float fahr_to_celsius(float fahr);

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
        celsius = fahr_to_celsius(fahr);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

}

float fahr_to_celsius(float fahr)
{
    return 5.0 * (fahr-32.0) / 9.0;
}
