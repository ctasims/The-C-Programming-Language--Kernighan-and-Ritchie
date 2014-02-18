/*
 * Exercise 5-11
 */
#include <stdio.h>
#include <math.h>

#define MAXLINE 1000  /*  maximum input line size. */
#define SPACE ' '
#define TABWIDTH 4


/*  replace blanks with tabs and spaces, preferring tabs. */
int entab(int argc, char *argv[])
{
    int i, c, blanksStart, k;
    int numBlanks = 0, numTabs = 0, numSpaces = 0;
    int inBlanks = 0;
    char line[MAXLINE];

    for (i=0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        if (!inBlanks && (c == '\t' || c == SPACE)) {
            /* Track where blanks begin and start counting. */
            inBlanks = 1;
            blanksStart = i;
            if (c == '\t') numBlanks += TABWIDTH;
            if (c == SPACE) numBlanks++;
        } else {
            /* No more blanks */
            if (inBlanks) {  /* Just coming out of blanks */
                inBlanks = 0;
                /* Modify string with tabs + spaces */
                while (numBlanks > 0) {
                    if (floor(numBlanks/TABWIDTH) > 0) {
                        line[blanksStart++] = '\t';
                        numBlanks -= TABWIDTH;
                    } else {
                        line[blanksStart++] = SPACE;
                        numBlanks--;
                    }
                }
            } 
            line[i] = c;
        }
    }
    line[i] = '\0';
    printf("%s\n", line);
    return i;
}

int detab(int argc, char *argv[])
{
    int i, j, c;

    char line[MAXLINE];  /* line with spaces intead of tabs */

    /* Iterate over input line, replacing tabs */
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        /* char is a tab so replace it */
        if (c == '\t') {
            j = TABWIDTH - (i % TABWIDTH);
            /*if (j == 0) j = 4;*/
            while (j-- != 0) {
                line[i] = SPACE;
                ++i;
            }
            --i;
        } else {
            line[i] = c;
        }
    }
    line[i] = '\0';
    printf("%s\n", line);
    return i;
}

int main(int argc, char *argv[]) {
    entab(argc, argv);

    /*detab(argc, argv);*/
}
