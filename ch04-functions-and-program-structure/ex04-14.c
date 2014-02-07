/*
 * Exercise 4-14.
 */
#include <stdio.h>

/* Macro swap(t,x,y) to interchange two args of type t. */
#define swap(t,x,y) do { t temp; temp = x; x = y; y = temp; } while (0);

int main(void)
{
    int x, y;
    double dx, dy;

    x = 30;
    y = 45;
    printf("%d, %d\n", x, y);
    swap(int, x, y);
    printf("%d, %d\n", x, y);

    dx = 44.4;
    dy = 33.3;
    printf("%g, %g\n", dx, dy);
    swap(double, dx, dy);
    printf("%g, %g\n", dx, dy);
    return 0;
}

