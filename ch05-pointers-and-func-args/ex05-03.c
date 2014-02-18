/* Exercise 5-3. strcat */

#include <stdio.h>
#include <string.h>


/* strcat: copy string t onto end of string s */
void strcat2(char *s, char *t)
{
    while (*s++)
        ;
    *s--;
    while (*s++ = *t++)
        ;
}

int main(void)
{
    char s[100] = "test";
    char *t = "two";

    strcat2(s, t);
    printf("%s\n", s);

    return 0;
}

