/*
 * =====================================================================================
 *
 *       Filename:  copy-2.c
 *
 *    Description:  copy, minimal
 *
 *        Version:  1.0
 *        Created:  7/26/2013 11:03:41 PM
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

        /* 1-7 print value of EOF. It's -1 */
        printf("%d", EOF);
    }


}
