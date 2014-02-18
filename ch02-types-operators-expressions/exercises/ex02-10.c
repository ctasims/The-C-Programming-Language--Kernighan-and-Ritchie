/*
 * Exercise 2.10:
 * Rewrite function lower with a conditional expression instead of if-else.
 */

/* Original function  which converts char c to lower-case*/
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

int lower(int c)
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
