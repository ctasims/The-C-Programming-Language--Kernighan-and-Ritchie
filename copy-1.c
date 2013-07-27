/*
 * =====================================================================================
 *
 *       Filename:  copy-1.c
 *
 *    Description:  copy input to output with while loop
 *
 *        Version:  1.0
 *        Created:  7/26/2013 10:57:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cianan A. Sims (), ctasims@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

main()
{
    int c;  /*  use int so we can handle EOF */

    c = getchar();
    /*  look, a symbolic constand from the standard library! */
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}
