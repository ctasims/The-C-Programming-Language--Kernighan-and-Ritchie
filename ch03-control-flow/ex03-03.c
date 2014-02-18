/*  
 *  Exercise 3.3:
 *  Expand shorthand notation into complete list.
 *  a-z becomes abc...xyz, etc.
 *  */

#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[]);

/*  Test the function */
int main()
{
    char s1[] = "a-z";
    char s2[100];

    expand(s1, s2);
    printf("%s\n\n", s2);

    char s3[] = "a-b-c";
    char s4[100];

    expand(s3, s4);
    printf("%s\n\n", s4);

    char s5[] = "A-Z0-9";
    char s6[100];

    expand(s5, s6);
    printf("%s\n\n", s6);

    return 0;
}

/*  Expand shorthand into range of chars or digits. */
void expand(char s1[], char s2[])
{
    // Use two indexes to track boundaries.
    int i = 0, j = 0;
    // current char we're writing.
    int k = 0;
    // s2 index to track where next char goes.
    int i2 = 0;
    // char range start and end.
    char a, b;

    // iterate over shorthand notation.
    // Get start and end, expand, then increment indexes.
    while (i < strlen(s1) && j < strlen(s1)) {
        if (i == j)
            j++;
        if (s1[i] == '-')
            i++;
        if (s1[j] == '-')
            j++;

        a = s1[i];
        b = s1[j];

        // iterate over range and store chars.
        for (k = a; k <= b; k++) {
            // avoid repeating, e.g. a-b-c
            if (k != s2[i2-1])
                s2[i2++] = k;
        }
        i++;
        j++;
    }
    s2[i2] = '\0';

}
