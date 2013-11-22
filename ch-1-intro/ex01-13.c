/*
 * =====================================================================================
 *
 *       Filename:  ex01-13.c
 *
 *    Description:  Print histogram of lengths of words.
 *
 *        Version:  1.0
 *        Created:  11/21/2013 12:01:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cianan A. Sims (), ctasims@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

/*  Ex. 1-13: Print histogram of lengths of words in input.
 *  Draw bars horizontally. */

/*  State constants for whether we're inside word or not. */
#define IN 1
#define OUT 0

main2()
{
    int c, i, j, nchars, state;
    int word_lengths[20];  /*  max word length is 20 */

    c = i = j = nchars = state = 0;
    for (i = 0; i < 20; ++i) {
        word_lengths[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            if (nchars != 0) {
                /*  word completed so update length counter */
                ++word_lengths[nchars];
            }
        } else if (state == OUT) {
            /*  entering a new word... */
            state = IN;
            ++nchars;
            nchars = 1;  /*  reset word-length counter */
        } else {
            ++nchars;
        }
    }

    /*  Print histogram */
    for (i = 0; i < 20; ++i) {
        for (j = 0; j < word_lengths[i]; ++j) {
            printf("|");
        }
        printf("\n");
    }
}


