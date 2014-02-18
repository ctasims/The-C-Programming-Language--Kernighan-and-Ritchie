/*
 * Exercise 4-12.
 */
#include <stdio.h>
#include <string.h>


/* Original reverse function */
void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

/* Original version of itoa: */
/*  itoa: convert n to characters in s */
void itoa_old(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)     // record sign
        n = -n;             // make n positive
    i = 0;
    do {                        // generate digits in reverse order
        s[i++] = n % 10 + '0';  // get next digit
    } while ((n /= 10) > 0);    // delete it
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}


/* itoa: recursive version */
void itoa(int n, char s[])
{
    // track # recursions
    static int depth = 1;
    static int indx = 0;

    if (n < 0) {
        s[indx++] = '-';
        n = -n;
    }
    if (n / 10) {
        depth++;
        itoa(n/10, s);
    }
    depth--;
    s[indx++] = n % 10 + '0';

    if (depth == 0)
        s[indx] = '\0';
}


int main() {
    int test = 1234;
    char result[100];
    itoa(test, result);
    /*itoa_old(test, result);*/
    printf("%s\n", result);

    return 0;
}
