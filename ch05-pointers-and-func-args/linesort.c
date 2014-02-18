#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort2(char *lineptr[], int left, int right);
int getline(char *, int);
char *alloc(int);

/* sort input lines */
main()
{
    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort2(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}


/* read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';  // delete newline
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}


/* write output lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    /* get next char if it's not end of file or newline (check for overflow) */
    for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;
    /* If newline, copy it and bump iter */
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}


/*
 * qsort2: sort v[left]...v[right] into increasing order.
 */
void qsort2(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)  // do nothing if array contains < 2 elems
        return;
    // move partition elem to v[0]
    swap(v, left, (left + right)/2);
    last = left;

    for (i = left+1; i <= right; i++)  // partition
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);                // restore partition elem
    qsort2(v, left, last-1);
    qsort2(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
