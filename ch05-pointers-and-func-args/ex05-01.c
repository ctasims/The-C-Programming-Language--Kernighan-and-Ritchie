/*
 * Exercise 5.1
 */

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100  //

int getch(void);
void ungetch(int);

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       // next free position in buffer

/* getint: get next integer from input to *pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))  // skip whitespace
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        // ensure value after + or - os valid
        if (!isdigit(c)) {
            ungetch(c);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}


/* getch: get a (possibly pushed back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push char back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int main(void)
{
    int test;
    int status;

    status = getint(&test);
    printf("status: %d\n", status);
    printf("value: %d\n\n", test);

    return 0;
}

