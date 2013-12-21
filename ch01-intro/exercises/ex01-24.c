/*
 * =====================================================================================
 *
 *       Filename:  ex01-24.c
 *
 *    Description:  check syntax errors: unbalanced () [] {} "" ''
 *
 *        Version:  1.0
 *        Created:  12/16/2013
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

int getline(char s[], int lim);


int main(void)
{
    int len, t;
    char line[MAXLINE];
    int s_quote = 1, d_quote = 1, parens = 0, brackets = 0, braces = 0;
    char c;

    while(len = getline(line, MAXLINE)) {

        t = 0;
        while (t < len) {
            /* Track unbalanced items with bool. 1 if unbalanced.
             */

            if (line[t] == '\'')
                s_quote *= -1;
            if (line[t] == '"')
                d_quote *= -1;
            if (line[t] == '[')
                braces++;
            if (line[t] == ']')
                braces--;
            if (line[t] == '(')
                parens++;
            if (line[t] == ')')
                parens--;
            if (line[t] == '{')
                brackets++;
            if (line[t] == '}')
                brackets--;

            t++;
        }
    }
    if (braces != 0 || brackets != 0 || parens != 0 || s_quote == -1 || d_quote == -1) {
        printf ("Error Found!\n");
        printf ("%d %d %d\n", braces, brackets, parens);

        if (braces != 0)
            printf ("Unmatched brace.\n");
        if (brackets != 0)
            printf ("Unmatched bracket.\n");
        if (parens != 0)
            printf ("Unmatched parens.\n");
        if (s_quote == -1)
            printf ("Unmatched single-quote.\n");
        if (d_quote == -1)
            printf ("Unmatched double-quote.\n");
    } else {
        printf("Everything looks good!\n");
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
