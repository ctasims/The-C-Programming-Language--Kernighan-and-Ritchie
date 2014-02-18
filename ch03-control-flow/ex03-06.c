/*
 * Exercise 3-6:
 * Write version of itoa that pads converted number with blanks on left.
 */

#include <stdio.h>
#include <string.h>


void reverse(char s[]);
void itoa3(int n,char s[], int f);

int main()
{
    int n1 = 32;
    char s1[50];
    itoa3(n1, s1, 16);
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

void itoa3(int n,char s[], int f)
{
    int i, sign;
    int num_blanks;

    if ((sign = n) < 0)     // record sign
        n = -n;             // make n positive
    i = 0;
    do {                        // generate digits in reverse order
        s[i++] = n % 10 + '0';  // get next digit
    } while (n /= 10);    // delete it
    if (sign < 0)
        s[i++] = '-';

    // pad with blanks, if needed
    num_blanks = 16 - strlen(s);
    while (num_blanks > 0) {
        s[i++] = ' ';
        num_blanks--;
    }

    s[i] = '\0';
    reverse(s);
}
