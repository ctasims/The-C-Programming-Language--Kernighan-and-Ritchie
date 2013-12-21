/*
 * =====================================================================================
 *
 *       Filename:  ex01-09.c
 *
 *    Description:  Copy input to output while replacing multiple blanks with single.
 *
 *        Version:  1.0
 *        Created:  11/21/2013 11:58:57 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cianan A. Sims (), ctasims@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

/*  Ex. 1-9: copy input to output. Replace all blanks with single blank. */
main()
{
    int c;
    /*  Keep track of whether or not last char was a blank */
    int cPrev;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            /*  Only prints blank when previous char was not a blank */
            if (cPrev == ' ') {
                ;
            } else {
                printf(" ");
            }
        } else {
            printf("%c", c);
        }
        cPrev = c;
    }

}

