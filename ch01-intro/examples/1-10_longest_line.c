/*
 * =====================================================================================
 *
 *       Filename:  1-9_longest_line.c
 *
 *    Description:  Print the longest line of a given set of lines.
 *
 *        Version:  1.0
 *        Created:  9/2/2013 9:08:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cianan A. Sims, ctasims@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#define MAXLINE 1000  /*  maximum input line size. */

int max;                /*  maximum length seen so far. */
char line[MAXLINE];     /*  current input line */
char longest[MAXLINE];  /*  longest line  saved here */

int getline(void);
void copy(void);

/* Print longest input line */
main()
{
    int len;                /*  current line length */
    extern int max;         /* max length seen so far */
    extern char longest[];    /* longest line saved here */

    max = 0;
    while ((len = getline()) > 0)
        if (len > max) {
            max = len;
            copy();
        }

    if (max > 0)    /* there was a line */
        printf("%s", longest);
    return 0;
}


/* getline: read a line into s, return length */
int getline(void)
{
    int c, i;
    extern char line[];

    /* get next char if it's not end of file or newline (check for overflow) */
    for (i=0; i < MAXLINE - 1 && (c=getchar()) != EOF && c!='\n'; ++i)
        line[i] = c;
    /* If newline, copy it and bump iter */
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}


/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(void)
{
    int i;
    extern char line[], longest[];

    i = 0;
    /* copy array values(?). Doesn't check for overflow since we know lengths. */
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
        
