/*
 * =====================================================================================
 *
 *       Filename:  ex01-20.c
 *
 *    Description:  replace tabs with spaces.
 *
 *        Version:  1.0
 *        Created:  11/21/2013 10:49:24 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cianan A. Sims (), ctasims@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#define MAXLINE 1000  /*  maximum input line size. */
#define SPACE ' '
#define TABWIDTH 4

int detab(void);

main() 
{
    char i;
    i = detab();

    return 0;
}

/*  replace tabs in input with spaces, assuming tab stops are every 4 columns. */
int detab(void)
{
    int i, j, c;

    char line[MAXLINE];  /* line with spaces intead of tabs */

    /* Iterate over input line, replacing tabs */
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        /* char is a tab so replace it */
        if (c == '\t') {
            j = TABWIDTH - (i % TABWIDTH);
            /*if (j == 0) j = 4;*/
            while (j-- != 0) {
                line[i] = SPACE;
                ++i;
            }
            --i;
        } else {
            line[i] = c;
        }
    }
    line[i] = '\0';
    printf("%s\n", line);
    return i;
}

/* The ideal n value should be changeable at run-time, so variable is ideal. */
