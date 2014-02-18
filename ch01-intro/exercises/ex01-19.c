/*
 * =====================================================================================
 *
 *       Filename:  ex01-19.c
 *
 *    Description:  reverse input one line at a time.
 *
 *        Version:  1.0
 *        Created:  9/2/2013 9:57:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cianan A. Sims (), ctasims@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <string.h>

#define MAXLINE 1000  /*  maximum input line size. */

int getline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char s[]);


/* Print longest input line */
main()
{
    int len;                /*  current line length */
    int max;                /* max length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > 0) {
            reverse(line);
            printf("%s", line);
        }
            
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


/* reverse string in-place */
void reverse(char s[])
{
    size_t len = strlen(s);
    char temp[len];
    int j;

    /* make temp copy of input array */
    copy(temp, s);

    /* copy it back into s, in reverse order */
    j = 0;
    while (len > 0) {
        s[j] = temp[len-1];
        --len;
        ++j;
    }
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
        
