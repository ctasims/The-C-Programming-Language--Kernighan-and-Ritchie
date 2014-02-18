/*
 * =====================================================================================
 *
 *       Filename:  ex01-06.c
 *
 *    Description:  Verify EOF
 *
 *        Version:  1.0
 *        Created:  11/21/2013 11:56:41 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cianan A. Sims (), ctasims@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

main() {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);

        /*  1-6 verify expression is 0 or 1 */
        printf("%f", c != EOF);
    }


}

