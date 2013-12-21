/*
 * =====================================================================================
 *
 *       Filename:  ex01-23.c
 *
 *    Description:  Remove all comments from given program.
 *
 *        Version:  1.0
 *        Created:  11/21/2013 2:54:07 PM
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

int getline(char s[], int lim);


int main(void)
{
    int len;                /*  current line length */
    char line[MAXLINE];     /* current input line */
    int t = 0, inQuote = 0, inComment = 0;
    char c;

    while ((len = getline(line, MAXLINE)) > 0) {

        t = 0;
        while (t < len) {
            /* found quote so flip quote tracker */
            if (line[t] == '"') inQuote = 1 - inQuote;

            /* If comment found, flip comment tracker */
            if (line[t] == '/' && line[t+1] == '*' && !inQuote) {
                inComment = 1;
            }

            /* end of comment */
            if (line[t] == '*' && line[t+1] == '/' && !inQuote) {
                inComment = 0;
                t = t + 2;
            }

            /* Only keep char if not in comment */
            if (!inComment) printf("%c", line[t]);
            t++;
        }
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
