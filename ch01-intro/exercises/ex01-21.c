/*
 * =====================================================================================
 *
 *       Filename:  ex01-21.c
 *
 *    Description:  replace blanks with tabs and spaces, preferring tabs.
 *
 *        Version:  1.0
 *        Created:  11/21/2013 1:14:32 PM
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

int entab(void);

main() 
{
    char i;
    i = entab();

    return 0;
}

/*  replace blanks with tabs and spaces, preferring tabs. */
int entab(void)
{
    int i, c, blanksStart, k;
    int numBlanks = 0, numTabs = 0, numSpaces = 0;
    int inBlanks = 0;
    char line[MAXLINE];

    for (i=0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        if (!inBlanks && (c == '\t' || c == SPACE)) {
            /* Track where blanks begin and start counting. */
            inBlanks = 1;
            blanksStart = i;
            if (c == '\t') numBlanks += TABWIDTH;
            if (c == SPACE) numBlanks++;
        } else {
            /* No more blanks */
            if (inBlanks) {  /* Just coming out of blanks */
                inBlanks = 0;
                /* Modify string with tabs + spaces */
                while (numBlanks > 0) {
                    if (floor(numBlanks/TABWIDTH) > 0) {
                        line[blanksStart++] = '\t';
                        numBlanks -= TABWIDTH;
                    } else {
                        line[blanksStart++] = SPACE;
                        numBlanks--;
                    }
                }
            } 
            line[i] = c;
        }
    }
    line[i] = '\0';
    printf("%s\n", line);
    return i;
}

