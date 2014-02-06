/*
 * Exercise 4-13.
 */
#include <string.h>
#include <stdio.h>

/* Original reverse function */
/*void reverse(char s[]) {*/
    /*int c, i, j;*/
    /*for (i = 0, j = strlen(s)-1; i < j; i++, j--)*/
        /*c = s[i], s[i] = s[j], s[j] = c;*/
/*}*/


/*
 * recursive reverse
 */
void reverse(char s[], int i, int j)
{
    int c;
    if (i < j) {
        c = s[i], s[i] = s[j], s[j] = c;
        i++;
        j--;
        reverse(s, i, j);
    }
}

int main() {
    char test[] = "test";
    reverse(test, 0, strlen(test)-1);
    printf("%s\n", test);
    return 0;
}
