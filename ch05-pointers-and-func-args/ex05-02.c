/*
 * Exercise 5.2
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define BUFSIZE 100  //

int getch(void);
void ungetch(int);

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       // next free position in buffer

/* getint: get next integer from input to *pn */
int getfloat(float *pn)
{
    int c, sign, i;

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
    // get whole number
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    if (c == '.')
        c = getch();
    else {
        // no decimal part
        *pn *= sign;
        if (c != EOF)
            ungetch(c);
        return c;
    }

    // get decimal part
    for (i=1; isdigit(c); c = getch(), i++)
        *pn = *pn + (c - '0')/pow(10.0, i);

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
    /*char *t = "450.4";*/
    float test;
    int status;

    status = getfloat(&test);
    printf("status: %d\n", status);
    printf("value: %f\n\n", test);

    return 0;
}

