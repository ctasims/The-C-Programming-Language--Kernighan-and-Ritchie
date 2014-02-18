/*
 * Exercise 2-5: Write function any(s1,s2) which returns first location in string s1 where any char from string s2 occurs.
 * Return -1 if s1 contains no chars from s2. Similar to strpbrk.
 */
#include <stdio.h>

int any(char s1[], char s2[]);

int main() {
    char s1[] = "catrugb";
    char s2[] = "h";
    printf("%d\n\n", any(s1, s2));

    return 0;
}

/*
 * Return first index in s1 where any char in s2 occurs.
 * Worst-case is O( len_s1 * len_s2).
 */
int any(char s1[], char s2[]) {
    int i = 0, j = 0;
    char c, d;

    /* Iterate over chars in s1, matching against chars in s2. */
    while ((c = s1[i++]) != '\0') {
        j = 0;
        while ((d = s2[j++]) != '\0' && d != c)
            ;
        if (d == c)
            /* Match found so return original index of char c. */
            return i - 1;
    }
    /* Nothing matched. */
    return -1;
}
