/*
 * =====================================================================================
 *
 *       Filename:  char-count.c
 *
 *    Description:  Ch. 1, p. 18 - count characters in input
 *
 *        Version:  1.0
 *        Created:  8/3/2013 10:40:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cianan A. Sims (), ctasims@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

/*  Count characters in input. v1 */
main()
{
    /*  Machine-dependent, but long holds 32-bits while int sometimes caps at 16 */
    long nc;

    nc = 0;

    while (getchar() != EOF)
        ++nc;
    /*  %ld tells printf that we're using long integer. */
    printf("%ld\n", nc);
}

main2()
{
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        /*  Use null statement since for-loop must have a body. */
        ;
    printf("%.0f\n", nc);
}
