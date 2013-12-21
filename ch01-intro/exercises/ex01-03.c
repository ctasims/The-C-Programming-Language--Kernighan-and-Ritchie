/*
 * =====================================================================================
 *
 *       Filename:  ex01-03.c
 *
 *    Description:  temps with heading
 *
 *        Version:  1.0
 *        Created:  11/21/2013 11:54:05 AM
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

    printf("Temperatures, in Fahrenheit and Celsius\n\n");
        

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5.0 * (fahr-32.0) / 9.0;
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    printf("\n\n");
    
    celsius = lower;
    while (celsius <= upper) {
        fahr = ((9.0/5.0) * celsius) +32.0;
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        celsius = celsius + step;
    }

}

