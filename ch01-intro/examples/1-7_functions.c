/*
 * =====================================================================================
 *
 *       Filename:  1-7_functions.c
 *
 *    Description:  Functions - encapsulate code to clarify, make convenient, re-usable.
 *
 *        Version:  1.0
 *        Created:  8/4/2013 10:15:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cianan A. Sims (), ctasims@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int power(int m, int n);


/*  test power function */
main()
{
    int i;
    for (i = 0; i < 10; ++i) {
        printf("%d %d %d\n", i, power(2,i), power(-3,i));
    }
    return 0;
}


/*  power: raise base to n-th power: n >= 0 */
int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i) {
        p = p * base;
    }
    return p;
}

