/*
 * =====================================================================================
 *
 *       Filename:  ex01-14.c
 *
 *    Description:  Print histogram of character frequencies.
 *
 *        Version:  1.0
 *        Created:  11/21/2013 12:02:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cianan A. Sims (), ctasims@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

/*  Ex. 1-14: Print histogram of frequencies of different characters in input. */
main()
{
    int c, i, j;
    int freqs[255] = { 0 };  /*  One counter for every ASCII character */

    c = i = j = 0;

    while ((c = getchar()) != EOF) {
        ++freqs[c];
    }

    for (i = 0; i < 255; ++i) {
        printf("%c: ", i);
        for (j = 0; j < freqs[i]; ++j) {
            printf("|");
        }
        printf("\n");
    }

}
