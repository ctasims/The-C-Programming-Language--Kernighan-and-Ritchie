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

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* Print longest input line */
main()
{
    int len;                /*  current line length */
    int max;                /* max length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }

    if (max > 0)    /* there was a line */
        printf("%s", longest);
    return 0;
}


/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    /* get next char if it's not end of file or newline (check for overflow) */
    for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;
    /* If newline, copy it and bump iter */
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}


/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    /* copy array values(?). Doesn't check for overflow since we know lengths. */
    while ((to[i] = from[i]) != '\0')
        ++i;
}
        
