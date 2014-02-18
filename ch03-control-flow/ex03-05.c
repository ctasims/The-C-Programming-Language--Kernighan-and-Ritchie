/*
 * Exercise 3-5:
 * Write function that converts integer n into base b char representation in string s.
 * In particular, itob(n,s,16) formats n as hex integer in s.
 */

#include <stdio.h>
#include <string.h>


void reverse(char s[]);
void itob(int n,char s[], int b);

int main()
{
    int n1 = 32;
    char s1[50];
    itob(n1, s1, 16);
    printf("%d, %s\n\n", n1, s1);

    return 0;
}


void reverse(char s[])
{
    int i = 0, j = 0;
    char c;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

void itob(int n,char s[], int b)
{
    int i, sign;

    if ((sign = n) < 0)     // record sign
        n = -n;             // make n positive
    i = 0;
    do {                        // generate digits in reverse order
        s[i++] = n % b + '0';  // get next digit
    } while (n /= b);    // delete it
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
