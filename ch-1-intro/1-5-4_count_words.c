/*
 * =====================================================================================
 *
 *       Filename:  1-5-4_count_words.c
 *
 *    Description:  Count lines, words and characters
 *
 *        Version:  1.0
 *        Created:  8/3/2013 11:29:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cianan A. Sims (), ctasims@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#define IN 1   /*  inside a word */
#define OUT 0   /*  outside a word */

/*  Count lines, words and characers in input. */
main1()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}


/*
 * Ex. 1-11: How would you test this? What kinds of input are best for uncovering bugs?
 * I would use complicated input with tabs and newlines to ensure the state updates correctly.
 * Give it blank input.
 * Give it one word only.
 */


/*
 * Ex. 1-12: Print input one word per line
 */
main()
{
    int c, state;

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            printf("\n");
        } else if (state == OUT) {
            state = IN;
            printf("%c", c);
        } else {
            printf("%c", c);
        }
    }
}
