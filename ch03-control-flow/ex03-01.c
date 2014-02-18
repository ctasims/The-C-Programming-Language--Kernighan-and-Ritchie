/*
 * Exercise 3-1:
 * Write a version of binary search with only one test inside the loop.
 * Measure the difference in run-time between this and the K&R version.
 */

#include <stdio.h>
#include <time.h>
#define MAX_ELEMENT 20000

/*
 * K & R version:
 * binsearch: find x in sorted v
 */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else  /* found match */
            return mid;
    }
    return -1;  /* no match */
}


int binsearch2(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high) {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    if (x == v[mid])
        return mid;
    else
        return -1;  /* no match */
}


/*
 * No idea how to time these so I used Paul Griffith's code from:
 * http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_3:Exercise_1
 */
int main() {
    /* initial testing */
    /*int n = 9;*/
    /*int v[9] = {0, 3, 6, 10, 15, 22, 23, 24, 30};*/
    /*int x = 23;*/
    /*printf("%d\n\n", binsearch2(x, v, n));*/

    int test_data[MAX_ELEMENT];
    int index;                      /* index of found elem in test data. */
    int n = -1;                     /* elem to search for. */
    int i;
    clock_t time_taken;

    /* init test data */
    for (i=0; i < MAX_ELEMENT; ++i)
        test_data[i] = i;

    /* output approximation of time taken for 100,000 iterations of binsearch. */
    for (i=0, time_taken=clock(); i < 100000; ++i) {
        index = binsearch(n, test_data, MAX_ELEMENT);
    }

    time_taken = clock() - time_taken;

    if (index < 0)
        printf("Elem %d not found.\n", n);
    else
        printf("%d found at index %d.\n", n, index);

    printf("binsearch() took %lu clocks (%lu seconds)\n",
            (unsigned long) time_taken,
            (unsigned long) time_taken / CLOCKS_PER_SEC);


    /* Output approx of time taken for 100,000 iterations of binsearch2 */
    for (i=0, time_taken=clock(); i < 100000; ++i) {
        index = binsearch2(n, test_data, MAX_ELEMENT);
    }

    time_taken = clock() - time_taken;

    if (index < 0)
        printf("Elem %d not found.\n", n);
    else
        printf("%d found at index %d.\n", n, index);

    printf("binsearch2() took %lu clocks (%lu seconds)\n",
            (unsigned long) time_taken,
            (unsigned long) time_taken / CLOCKS_PER_SEC);


    return 0;
}
