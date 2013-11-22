/*
 * =====================================================================================
 *
 *       Filename:  ex01-07.c
 *
 *    Description:  Print value of EOF
 *
 *        Version:  1.0
 *        Created:  11/21/2013 11:57:08 AM
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

        /* 1-7 print value of EOF. It's -1 */
        printf("%d", EOF);
    }
}

