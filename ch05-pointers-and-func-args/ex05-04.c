/* Exercise 5-4: strend */

#include <stdio.h>
#include <string.h>


/* strend: checks if t occurs at end of s */
int strend(char *s, char *t)
{
    int len_diff = strlen(s) - strlen(t);
    s += len_diff;
    return !strcmp(s, t) ? 1 : 0;
}


int main(void)
{
    char *s = "testtwo";
    char *s2 = "testtwotest";
    char *t = "two";

    printf("%d, %d\n", strend(s, t), strend(s2, t));

    return 0;    
}
