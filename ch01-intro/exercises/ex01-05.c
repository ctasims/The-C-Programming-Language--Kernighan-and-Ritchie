/*
 * =====================================================================================
 *
 *       Filename:  ex01-05.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/21/2013 11:55:19 AM
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

    for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}

/*  Just switch the fahr values and decrement. */

