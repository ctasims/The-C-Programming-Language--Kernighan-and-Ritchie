/*
 * =====================================================================================
 *
 *       Filename:  ex01-10.c
 *
 *    Description:  Replace tab, backspaces, backslashes visible.
 *
 *        Version:  1.0
 *        Created:  11/21/2013 11:59:34 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cianan A. Sims (), ctasims@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

/*  Ex. 1-10: copy input to output while replacing:
 *      tabs by \t
 *      backspace by \b
 *      backslash by \\. */
main4()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");
        } else if (c == '\b') {
            printf("\\b");
        } else if (c == '\\') {
            printf("\\\\");
        } else {
            printf("%c", c);
        }
    }
}

