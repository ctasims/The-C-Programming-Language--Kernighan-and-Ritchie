/*
 * =====================================================================================
 *
 *       Filename:  temp-for.c
 *
 *    Description:  temp table with for loop
 *
 *        Version:  1.0
 *        Created:  7/26/2013 10:48:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cianan A. Sims (), ctasims@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
/*  symbolic constants may be stored in text, but compiler-dependent */
#define LOWER 0

main() {
    int fahr;

    for (fahr = LOWER; fahr <= 300; fahr = fahr + 20) {
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}

/*  1-5 Just switch the fahr values and decrement. */
