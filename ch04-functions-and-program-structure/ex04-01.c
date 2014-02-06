/*
 * Exercise 04-01.
 * Write func strrindex(s,t) which returns position of rightmost occurrence of t in s, or -1 if there is none.
 */

#include <stdio.h>
#define MAXLINE 1000  /* max input line length */

int getline(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";  /* pattern to search for */


/* Find all lines matching pattern. */
main()
{
    char line[MAXLINE];
    int found = 0;

    while (getline(line, MAXLINE) > 0)
        if (strrindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    return found;
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strrindex: return index of rightmost t in s, -1 if none */
int strrindex(char s[], char t[])
{
    int i, j, k, indx = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            indx = i;
    }
    return indx;
}

