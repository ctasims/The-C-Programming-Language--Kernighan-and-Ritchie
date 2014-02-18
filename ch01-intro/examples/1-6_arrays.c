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
