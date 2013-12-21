/*
 * Exercise 2-8: 
 * Write a function that returns the value of the integer x rotated to the right by n bit positions.
 */
#include <stdio.h>

unsigned rightrot(unsigned x, int n)
{
    /* Take modulo of n in-case it's larger than word size.
     * To rotate, handle in two sections: the shifted part and the wraparound.
     * Shifted part is easy - just shift!
     * For wraparound, mask it out and then left-shift it over.
     */
    n = n % (sizeof(x)*8);
    return ((x & ~(~0 << n+1)) << (sizeof(x)*8-n)) | (x >> n);
}

/* From K & R. */
unsigned getbits(unsigned x, int p, int n)
{
   return (x >>(p+1-n)) & ~(~0 << n);
}

/*
 * Display number as bits.
 * Taken from http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_2:Exercise_6.
 * Written by Pilcrow.
 */
void asbits(unsigned x, size_t s, int nl)
{
	int i;

	for(i = s*8-1; i>=0; i--) {
		 getbits(x, i, 1)? putchar('1') : putchar('0');
		 if(!(i%4))putchar(' ');
	}
	if(nl)putchar('\n');
}

int main() {
    int offset = 34;
    unsigned x = 0x12345678;
    asbits(x, sizeof(x), 1);
    asbits(rightrot(x, offset), sizeof(x), 1);
    printf("%u\n\n", rightrot(x, offset));
    return 0;
}
