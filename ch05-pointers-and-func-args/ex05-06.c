/*
 * Exercise 5-6: rewrite functions to use pointers.
 */


#include <stdio.h>
#include <string.h>

#define STRMAX 1000
#define NUMBER 1


int getline(char *, int);
int atoi(char *);
void reverse(char *);
void itoa(int, char *);
int strindex(char *, char *);
int getop(char *s);

int main(void) {
    int lim = 10;
    char str1[STRMAX];
    int length;

    length = getline(str1, lim);
    printf("%d\n", length);

    char *str2 = "1234";
    printf("%d\n", atoi(str2));

    char str3[] = "teststring";
    reverse(str3);
    printf("%s\n", str3);

    int n = 1002;
    char s[STRMAX];
    itoa(n, s);
    printf("%s\n", s);

    char s4[] = "biglong string";
    char s5[] = "long";
    printf("%d\n", strindex(s4, s5));
}


/* read line into s, return length */
int getline(char *s, int lim)
{
    int c, i;
    char *s2 = s;

    while ((c=getchar()) != EOF && c != '\n') {
        *s++ = c;
    }
    if (c == '\n') {
        *s++ = c;
    }
    *s = '\0';
    return s - s2;
}


/* convert s to integer */
int atoi(char *s) {
    int n = 0;
    int sign;

    while (isspace(*s)) {
        s++;
    }

    sign = (*s == '-') ? -1 : 1;
    while (*s >= '0' && *s <= '9')
        n = 10 * n + (*s++ - '0');
    return sign*n;
}


/* reverse string s in place */
void reverse(char *s) {
    int i, j;
    char c;

    for (i=0, j=strlen(s)-1; i < j; i++, j--) {
        c = *(s+i);
        *(s+i) = *(s+j);
        *(s+j) = c;
    }
    return;
}

/* convert n to characters in s */
void itoa(int n, char *s)
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        *s++ = '-';
    s = '\0';
    // s is readonly so this will fail.
    reverse(s);
}


/* return index of t in s, -1 if none */
int strindex(char *s, char *t)
{
    int i, j, k;

    for (i=0; *(s+i) != '\0'; i++) {
        for (j=i, k=0; *(t+k) != '\0' && *(s+j) == *(t+k); j++, k++)
            ;
        if (k > 0 && *(t+k) == '\0')
            return i;
    }
    return -1;
}

/* get next operator or numeric operand */
int getop(char *s) {
    int i, c;
    char *p;
    p = s;

    while ((*p = c = getch()) == ' ' || c == '\t')
        ;

    p++;
    *p = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    p = s;
    if (isdigit(c))
        while (isdigit(*p++ = c = getch()))
            ;
    if (c == '.')
        while (isdigit(*p++ = c = getch()))
            ;
    p = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
