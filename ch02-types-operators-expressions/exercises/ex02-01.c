/*
 * Exercise 2-1. Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation.
 * Harder if you compute them; determine the ranges of the various floating-point types.
 */

#include <stdio.h>
#include <float.h>
#include <limits.h>

int main() {
    printf("char  - %d to %d | signed: %d to %d | unsigned: %u\n\n",
            CHAR_MIN, CHAR_MAX, SCHAR_MAX, (unsigned) UCHAR_MAX);

    printf("short - signed: %d to %d | unsigned: %u\n\n",
            SHRT_MIN, SHRT_MAX, (unsigned) USHRT_MAX);

    printf("int   - signed: %d to %d | unsigned: %u\n\n",
            INT_MIN, INT_MAX, (unsigned) UINT_MAX);

    printf("long  - signed: %d to %d | unsigned: %lu\n\n",
            LONG_MIN, LONG_MAX, ULONG_MAX);

    printf("float - signed: %f to %f\n\n",
            FLT_MIN, FLT_MAX);

    printf("double - signed: %f to %f\n\n",
            DBL_MIN, DBL_MAX);

    return 0;
}

