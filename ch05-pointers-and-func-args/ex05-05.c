/* Exercise 5-5: n versions of strcpy, strcat, strcmp */

#include <stdio.h>
/*#include <string.h>*/

void strcpy(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}

/* copy n chars of t onto s. */
void strncpy(char *s, char *t, int n)
{
    while ((*s++ = *t++) && --n>0)
        ;
}

/* append n chars of t to end of s */
void strncat(char *s, char *t, int n)
{
    while (*s++)
        ;
    *s--;
    while ((*s++ = *t++) && --n>0)
        ;
}

int strcmp(char *s, char *t)
{
    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

/* return <0 if s<t, 0 if s==t, >0 if s>t */
int strncmp(char *s, char *t, int n)
{
    char t2[n];
    strncpy(&t2[0], t, n);
    return strcmp(s, &t2[0]);
}


int main(void)
{
    char s1[100] = "test";
    char *t1 = "longstring";
    strncpy(s1, t1, 3);
    printf("%s\n", s1);

    char s2[100] = "test2";
    char *t2 = "longstring2";
    strncat(s2, t2, 3);
    printf("%s\n", s2);

    char *s3 = "test3";
    char *t3 = "test3123";
    printf("%d\n", strncmp(s3, t3, 3));
    printf("%d\n", strncmp(s3, t3, 5));
    printf("%d\n", strncmp(s3, t3, 7));

    return 0;
}
