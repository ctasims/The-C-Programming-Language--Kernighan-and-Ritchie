/*
 * =====================================================================================
 *
 *       Filename:  count-lines.c
 *
 *    Description:  Ch. 1, p. 19 - count lines of input
 *
 *        Version:  1.0
 *        Created:  8/3/2013 10:47:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cianan A. Sims (), ctasims@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

main1()
{
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF)
        /*  single-quotes denote a single character (character constant).
         *  Double-quotes create a string literal. */
        if (c == '\n') {
            ++nl;
        }

    printf("%d\n", nl);
}


/*  Ex. 1-8: Count blanks, tabs and newlines. */
main2()
{
    int c, nl;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ') {
            ++nl;
        }
    }
    printf("%d\n", nl);
}


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

