/*
 * =====================================================================================
 *
 *       Filename:  1-6_arrays.c
 *
 *    Description:  Count occurrences of each digit, white-space, and other chars
 *
 *        Version:  1.0
 *        Created:  8/4/2013 9:28:54 PM
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
    int c, i, nwhite, nother;
    int ndigit[10];

    /*  Initialize everything to 0 */
    nwhite = nother = 0;
    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            /*  Track digits */
            ++ndigit[c-'0'];
        } else if (c == ' ' || c == '\n' || c == '\t') {
            /*  Track whitespace */
            ++nwhite;
        } else {
            ++nother;
        }
    }

    printf("digits = ");
    for (i = 0; i < 10; ++i) {
        printf("%d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n", nwhite, nother);
}

