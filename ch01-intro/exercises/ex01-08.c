/*
 * =====================================================================================
 *
 *       Filename:  ex01-08.c
 *
 *    Description:  Count blanks, tabs and newlines.
 *
 *        Version:  1.0
 *        Created:  11/21/2013 11:58:36 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cianan A. Sims (), ctasims@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

main()
{
    int c, nl;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ') {
            ++nl;
        }
    }
    printf("%d\n", nl);
}

