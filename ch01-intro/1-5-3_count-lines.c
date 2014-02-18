/*
 * =====================================================================================
 *
 *       Filename:  count-lines.c
 *
 *    Description:  Ch. 1, p. 19 - count lines of input
 *
 *        Version:  1.0
 *        Created:  8/3/2013 10:47:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cianan A. Sims (), ctasims@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

main1()
{
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF)
        /*  single-quotes denote a single character (character constant).
         *  Double-quotes create a string literal. */
        if (c == '\n') {
            ++nl;
        }

    printf("%d\n", nl);
}

