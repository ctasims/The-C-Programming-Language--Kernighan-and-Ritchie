/*
 * Exercise 2-4: Write alternate version of squeeze(s1,s2).
 * It should delete each character in s1 that matches any character in string s2.
 */

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
    char s1[] = "catrugb";
    char s2[] = "hatb";

    squeeze(s1, s2);
    printf("%s\n\n", s1);
    return 0;
}

void squeeze(char s1[], char s2[]) {
    /* k is index of current char being considered.
     * i is index of next empty spot to place acceptable char.
     */
    int i = 0, j = 0, k = 0;
    char c, d;  /* c is current char being analyzed */

    while ((c = s1[k++]) != '\0') {
        j = 0;
        /* compare char in s1 with all chars in s2 */
        while ((d = s2[j++]) != '\0' && c != d)
            ;
        /* If we get to end of s2, then char wasn't found so add it. */
        if (d == '\0')
            s1[i++] = c;
    }
    s1[i] = '\0';
}
