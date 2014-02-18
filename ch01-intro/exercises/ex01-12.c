/*
 * =====================================================================================
 *
 *       Filename:  ex01-12.c
 *
 *    Description:  Print input one word per line.
 *
 *        Version:  1.0
 *        Created:  11/21/2013 12:00:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cianan A. Sims (), ctasims@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

/*
 * Ex. 1-12: Print input one word per line
 */
main()
{
    int c, state;

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            printf("\n");
        } else if (state == OUT) {
            state = IN;
            printf("%c", c);
        } else {
            printf("%c", c);
        }
    }
}

