/*
 * =====================================================================================
 *
 *       Filename:  ex01-21.c
 *
 *    Description:  Fold long input lines.
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
#define COLWIDTH 79

int fold(void);

main() 
{
    char i;
    i = fold();

    return 0;
}

/* fold long line into multiple lines.
 * If line longer than 79, insert newline into first previous blank.
 * If No blanks, insert hyphen at column 78.
 **/ 
int fold(void)
{
    int i, j, c, linelength, blank = -1;
    char line[MAXLINE];

    for (i=0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        /* Store most recent blank encountered */
        if (c == ' ' || c == '\t') {
            blank = i;

        /* Reset counters on new line */
        } else if (c == '\n') {
            linelength = 0;
            blank = -1;
        }

        /* Break the line */
        if (linelength == 80) {
            printf("\n break \n");
            if (blank == -1) {
                /* no blank encountered so manually break line. */
                line[i++] = '-';
                line[i++] = '\n';
                line[i] = c;
            } else {
                /* Backtrack to recent blank and break line */
                line[blank] = '\n';
                line[i] = c;
            }
            blank = -1;
            linelength = 0;
        } else {
            line[i] = c;
        }
        linelength++;
    }
    line[i] = '\0';
    printf("\n%s\n", line);
    return 0;
}

